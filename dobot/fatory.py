from keras.models import load_model  # TensorFlow is required for Keras to work
import cv2  # Install opencv-python
import numpy as np
from enum import Enum
import time

from from_serial import dobot
import threading
import queue


class Product(Enum):
  # 각 물품의 상태
  Nothing = "None"
  Normal = "Normal"
  error = "error"

class factory:

  def __init__(self):
    # 시간 및 fps 설정
    self.prev_time = 0
    self.FPS = 5
    self.total_capture = 0
    self.prev_product = Product.Nothing   # 이전 물체 상태
    self.current_product = Product.Nothing  # 현재 물체 상태

    # 물체 상태에 따른 카운트를 저장하는 딕셔너리
    self.product_dict = {
      Product.Normal.name: 0,
      Product.error.name: 0,
    }

    # dobot 객체 생성
    self.bot = dobot()

    # Disable scientific notation for clarity
    np.set_printoptions(suppress=True)

    # 모델 로드
    self.model = load_model("keras_Model.h5", compile=False)

    # 라벨 로드
    self.class_names = open("labels.txt", "r").readlines()

    # 카메라 인풋을 받음
    self.camera = cv2.VideoCapture(1)

    # dobot 초기화
    self.bot.dobot_init()
    self.count = 0

    # pick  , pick 플래그 설정
    self.pick_flag = True
    self.pick2_flag = True

    # 큐 생성
    self.q = queue.Queue()
    self.q2 = queue.Queue()

    # pick ,pick2 스레드 생성 및 시작
    self.pick_thread = threading.Thread(target=self.bot_pick, args=(self.q,))
    self.pick_thread.start()
    self.pick2_thread = threading.Thread(target=self.bot_pick2, args=(self.q2,))
    self.pick2_thread.start()


  # 두봇 1의 분량 분류 작업
  def bot_pick(self, q):
    while True:
      flag = q.get()
      # q가 True면 분량 검출 작업시작 False면 전체 작업종료
      if flag == True:
        if self.pick2_flag == False:
          self.bot.wait(750)
          self.bot.pick()
          self.pick_flag = True
        else:
          self.bot.wait(750)
          self.bot.pick()
          self.pick_flag = True
      elif flag == False:
        self.bot.end()
        break
      q.task_done()

  # 두봇 2의 분량 분류 작업
  def bot_pick2(self, q2):
    while True:
      flag = q2.get()
      # q2가 True면 분량 검출 작업시작 False면 전체 작업종료
      if flag == True:
        if self.pick_flag == False:
          self.bot.wait2(940)
          self.bot.pick2()
          self.pick2_flag = True
        else:
          self.bot.wait2(940)
          self.bot.pick2()
          self.pick2_flag = True
      elif flag == False:
        self.bot.end2()
        break
      q2.task_done()

  # 두봇 의 작업 종료 합수
  def end(self):
    self.q.join
    self.pick_thread.join
    self.q2.join
    self.pick2_thread.join

  def run(self):
    # 작업 시작 및 종료 함수
    self.start()
    self.end()


  def start(self):
    # 작업 시작 함수
    while True:
        # Grab the webcamera's image.
        try:
          ret, image = self.camera.read()
          current_time = time.time() - self.prev_time

          # if (ret == True) and (current_time > 1. / self.FPS):
          if ret == True:
            prev_time = time.time()

            # 이미지 리사이즈
            image = cv2.resize(image, (224, 224), interpolation=cv2.INTER_AREA)

            # cv2를 이용하여 화면 출력
            cv2.imshow("Webcam Image", image)

            # 모델이 맞게 이미지 전처리
            image = np.asarray(image, dtype=np.float32).reshape(1, 224, 224, 3)
            image = (image / 127.5) - 1

            # Predicts the model
            prediction = self.model.predict(image, verbose=None)
            index = np.argmax(prediction)

            # 검출된 이름과 신뢰도
            class_name = self.class_names[index]
            confidence_score = prediction[0][index]

            # Print prediction and confidence score
            confidence = np.round(confidence_score * 100)
            current_class = class_name[2:].split("\n")[0]
            # print(current_class,":", confidence)

            # 신뢰도가 97% 보다 높으면 검출된 것을 current_product에 집어넣음
            # 그렇지 않다면 continue 하여 밑의 내용을 무시함
            if confidence >= 97:
              if current_class == Product.error.value:
                self.current_product = Product.error
              elif current_class == Product.Normal.value:
                self.current_product = Product.Normal

              elif current_class == Product.Nothing.value:
                self.current_product = Product.Nothing
            else :
              continue

            # 현재 클랙스 테스트
            # print(self.current_product)

            # prev_product와  current_product가 같다면 카운트가 증가한다.
            # 검출 불량이나 에러를 잡는데 사용
            if self.current_product == self.prev_product and self.current_product != Product.Nothing:
              self.count += 1
            # 불량이 연속적으로 검출었다가 불량이 아닌것이 검출된다면 작동
            # 만약 이미 불량뷴로가 작동중이라면 카운트가 0으로 바뀜
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
            # 정상이 연속적으로 검출었다가 논이 검출된다면 작동
            # 만약 이미 정상분류가 작동중이라면 카운트가 0으로 바뀜
            elif (self.current_product == Product.Nothing) and (self.prev_product == Product.Normal)  and self.count > 3:
                if self.pick2_flag == True:
                  self.count = 0
                  self.pick2_flag = False
                  self.q2.put(True)
                  print("정상")
                else:
                  self.count = 0

            # 이 모델이 컨베이어 벨트에서 작동할때 반듯이 불량을 검출하기전 노말을 검출함 그때를 위해서 카운트를 초기화함
            elif (self.current_product == Product.error) and (self.prev_product == Product.Normal):
                self.count = 0
            
            self.prev_product = self.current_product


            # 키보드 입력 esc면 종료 q가 입력되면 동작 테스트 기능 실행
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


