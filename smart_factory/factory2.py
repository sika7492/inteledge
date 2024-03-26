#!/usr/bin/env python3

import os
import openvino as ov
import threading
from argparse import ArgumentParser
from queue import Empty, Queue
from time import sleep

import cv2
import numpy as np
from openvino.inference_engine import IECore

from iotdemo import FactoryController, MotionDetector , ColorDetector

FORCE_STOP = False


def thread_cam1(qMotion: Queue)->None:
    # TODO: MotionDetector
    mDetect = MotionDetector()
    mDetect.load_preset('resources/motion.cfg')
    
    # TODO: Load and initialize OpenVINO
    core = ov.Core()
    model = core.read_model(model='resources/model.xml')
    compiled_model = core.compile_model(model=model, \
                                        device_name='CPU')
    input_layer = compiled_model.input(0)
    output_layer = compiled_model.output(0)
    print(input_layer.shape)
    print(output_layer.shape)
    # TODO: HW2 Open video clip resources/conveyor.mp4 instead of camera device.
    cap = cv2.VideoCapture('resources/conveyor.mp4')
    while not FORCE_STOP:
        sleep(0.03)
        _, frame = cap.read()
        if frame is None:
            break
        
        # TODO: HW2 Enqueue "VIDEO:Cam1 live", frame info
        qMotion.put(("VIDEO:Cam1 live", frame))

        # TODO: Motion detect
        detected  = mDetect.detect(frame)

        if detected is None:
            continue

        # TODO: Enqueue "VIDEO:Cam1 detected", detected info.
        qMotion.put(("VIDEO:Cam1 detected", detected))

        # abnormal detect
        # frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        # reshaped = detected[:, :, [2, 1, 0]]
        # np_data = np.moveaxis(reshaped, -1, 0)
        # preprocessed_numpy = [((np_data / 255.0) - 0.5) * 2]
        # batch_tensor = np.stack(preprocessed_numpy, axis=0)

        # image format change
        
        model_in2 = np.expand_dims(detected, 0)
       
        model_in = np.transpose(model_in2, (0, 3, 1, 2))
        # TODO: Inference OpenVINO
        
        predict = compiled_model([model_in])[output_layer]
        # TODO: Calculate ratios
        circle_ratio , x_ratio = predict.reshape(-1)
        print(f"X = {x_ratio*100:.2f}%, Circle = {circle_ratio*100:.2f}%")

        # TODO: in queue for moving the actuator 1
        if x_ratio > circle_ratio:
            qMotion.put(("PUSH", 1))

    cap.release()
    qMotion.put(('DONE', None))
    exit()


def thread_cam2(qColor: Queue)->None:
   # TODO: MotionDetector
    
    mDetect = MotionDetector()
    mDetect.load_preset('resources/motion.cfg')

    cDetect = ColorDetector()
    cDetect.load_preset('resources/color.cfg')
    
    # TODO: Load and initialize OpenVINO
    core = ov.Core()
    model = core.read_model(model='/home/ssk/workspace/classification-task/outputs/20240305_141410_export/openvino/openvino.xml')
    compiled_model = core.compile_model(model=model, device_name='CPU')
    input_layer = compiled_model.input(0)
    output_layer = compiled_model.output(0)
    # print(input_layer.shape)
    # print(output_layer.shape)
    # TODO: HW2 Open video clip resources/conveyor.mp4 instead of camera device.
    cap = cv2.VideoCapture('resources/conveyor.mp4')
    while not FORCE_STOP:
        sleep(0.03)
        _, frame = cap.read()
        if frame is None:
            break
        qColor.put(("VIDEO:Cam2 live", frame))

        # TODO: Motion detect
        detected  = mDetect.detect(frame)

        if detected is None:
            continue

        qColor.put(("VIDEO:Cam2 detected", detected))
       
        # TODO: Enqueue "VIDEO:Cam2 detected", detected info.
        pred = cDetect.detect(detected)
        name, ratio = pred[0]
       

        # TODO: Detect color

        # TODO: Compute ratio
        print(f"{name}: {ratio:.2f}%")

        if name == 'blue':
            qColor.put(("PUSH",2))

        # TODO: Enqueue to handle actuator 2

    cap.release()
    qColor.put(('DONE', None))
    exit()


def imshow(title, frame, pos=None):
    cv2.namedWindow(title)
    if pos:
        cv2.moveWindow(title, pos[0], pos[1])
    cv2.imshow(title, frame)


def main():
    global FORCE_STOP

    parser = ArgumentParser(prog='python3 factory.py',
                            description="Factory tool")

    parser.add_argument("-d",
                        "--device",
                        default=None,
                        type=str,
                        help="Arduino port")
    args = parser.parse_args()

    # TODO: HW2 Create a Queue
    queue = Queue()
    # TODO: HW2 Create thread_cam1 and thread_cam2 threads and start them.
    # thread_cam1(queue)
    # thread_cam2(queue)

    
    MDetecting = threading.Thread(target=thread_cam1, args=(queue,))
    CDetecting = threading.Thread(target=thread_cam2, args=(queue,))

    # Start threads
    MDetecting.start()
    CDetecting.start()

    with FactoryController(args.device) as ctrl:
        while not FORCE_STOP:
            if cv2.waitKey(10) & 0xff == ord('q'):
                break
            
            # thread_cam1(queue)
            # thread_cam2(queue)
            # TODO: HW2 get an item from the queue.
            # You might need to properly handle exceptions.
            # de-queue name and data
            # TODO: HW2 show videos with titles of 'Cam1 live' and 'Cam2 live' respectively.
            # TODO: Control actuator, name == 'PUSH'
            try:
                event = queue.get_nowait()
            except Empty:
                continue
            name, data = event
            if name[11:] == "live":
                # CAMERA OUTPUT
                # "VIDEO:Cam1 live"
                cv2.imshow(name[6:], data)
            elif name == "PUSH":
                ctrl.push_actuator(data)
            elif name == 'DONE':
                FORCE_STOP = True

            queue.task_done()

    cv2.destroyAllWindows()


if __name__ == '__main__':
    try:
        main()
    except Exception:
        os._exit()
