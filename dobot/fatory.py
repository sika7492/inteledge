from keras.models import load_model  # TensorFlow is required for Keras to work
import cv2  # Install opencv-python
import numpy as np
from enum import Enum
import time

from from_serial import dobot
import threading
import queue

# 시간 및 fps 설정
class Product(Enum):
  Nothing = "None"
  Normal = "Normal"
  error = "error"

class factory:

  def __init__(self):
    self.prev_time = 0
    self.FPS = 5
    self.total_capture = 0
    self.prev_product = Product.Nothing
    self.current_product = Product.Nothing

    self.product_dict = {
      Product.Normal.name: 0,
      Product.error.name: 0,
    }

    self.bot = dobot()

    # Disable scientific notation for clarity
    np.set_printoptions(suppress=True)

    # Load the model
    self.model = load_model("keras_Model.h5", compile=False)

    # Load the labels
    self.class_names = open("labels.txt", "r").readlines()

    # CAMERA can be 0 or 1 based on default camera of your computer
    self.camera = cv2.VideoCapture(1)

    self.bot.dobot_init()
    self.count = 0

    self.pick_flag = True
    self.pick2_flag = True
    self.q = queue.Queue()
    self.q2 = queue.Queue()
    self.pick_thread = threading.Thread(target=self.bot_pick, args=(self.q,))
    self.pick_thread.start()
    self.pick2_thread = threading.Thread(target=self.bot_pick2, args=(self.q2,))
    self.pick2_thread.start()

  def bot_pick(self, q):
    # global bot, pick_flag
    while True:
      flag = q.get()
      if flag == True:
        if self.pick2_flag == False:
          self.bot.wait(750)
          self.bot.pick()
          # print("대기3끝")
          self.pick_flag = True
        else:
          self.bot.wait(750)
          self.bot.pick()
          # print("대기3끝")
          self.pick_flag = True
      elif flag == False:
        self.bot.end()
        break
      q.task_done()

  def bot_pick2(self, q2):
    # global bot, pick_flag
    while True:
      flag = q2.get()
      if flag == True:
        if self.pick_flag == False:
          self.bot.wait2(940)
          self.bot.pick2()
          # print("대기2끝")
          self.pick2_flag = True
        else:
          self.bot.wait2(940)
          self.bot.pick2()
          # print("대기2끝")
          self.pick2_flag = True
      elif flag == False:
        self.bot.end2()
        break
      q2.task_done()


  def end(self):
    self.q.join
    self.pick_thread.join
    
  def run(self):
    self.start()
    self.end()
  def start(self):
    while True:
        # Grab the webcamera's image.
        try:
          ret, image = self.camera.read()
          current_time = time.time() - self.prev_time

          # if (ret == True) and (current_time > 1. / self.FPS):
          if ret == True:
            prev_time = time.time()

            image = cv2.resize(image, (224, 224), interpolation=cv2.INTER_AREA)
            cv2.imshow("Webcam Image", image)

            image = np.asarray(image, dtype=np.float32).reshape(1, 224, 224, 3)
            image = (image / 127.5) - 1

            # Predicts the model
            prediction = self.model.predict(image, verbose=None)
            index = np.argmax(prediction)

            class_name = self.class_names[index]
            confidence_score = prediction[0][index]

            # Print prediction and confidence score
            confidence = np.round(confidence_score * 100)
            current_class = class_name[2:].split("\n")[0]
            # print(current_class,":", confidence)
            if confidence >= 97:
              if current_class == Product.error.value:
                self.current_product = Product.error
              elif current_class == Product.Normal.value:
                self.current_product = Product.Normal
               # print("정상")
              elif current_class == Product.Nothing.value:
                self.current_product = Product.Nothing
                # print("없음")
            else :
              continue
            # print(self.current_product)
            if self.current_product == self.prev_product and self.current_product != Product.Nothing:
              self.count += 1
            if (self.current_product!= Product.error) and (self.prev_product == Product.error) and self.count > 3:
              if self.pick_flag == True:
                self.count = 0
                self.pick_flag = False
                self.q.put(True)
                print("불량")
              else :
                self.count = 0
                # self.prev_product = self.current_product
                # continue
            elif (self.current_product == Product.Nothing) and (self.prev_product == Product.Normal)  and self.count > 3:
                if self.pick2_flag == True:
                  self.count = 0
                  self.pick2_flag = False
                  self.q2.put(True)
                  print("정상")
                else:
                  self.count = 0
            elif (self.current_product == Product.error) and (self.prev_product == Product.Normal):
                self.count = 0




            self.prev_product = self.current_product



            if cv2.waitKey(1) == 27:
              self.q.put(False)
              self.q2.put(False)
              self.pick_flag = False
              self.pick2_flag = False
              print("프로그램을 종료합니다.")
              break
            elif cv2.waitKey(1) == ord('q'):
              self.q.put(True)
              print("동작 테스트 실행")
           # yield image

        except Exception as e:
          print(e)


test = factory()
test.run()


