from serial.tools import list_ports

import pydobot



class dobot():
  # xyzr초기화
  x = 0
  y = 0
  z = 0
  r = 0
  # 속도, 가속도 세팅
  velocity = 1000
  acceleration = 1000
  
  
  def __init__(self) -> None:
    # 사용가능한 포트 확인
    available_ports = list_ports.comports()
    print(f'available ports: {[x.device for x in available_ports]}')
    #사용가능한 포트중 dobot의 포트를 설정함 : available_ports[ dobot의 포트]
    port = available_ports[2].device
    port2 = available_ports[3].device


    # 주어진 직렬 포트에 연결된 두봇의 인스턴스를 생성합니다.
    # verbose=True 지속적으로 정보를 확인 verbose=False 로하면 정보를 보지 않음
    self.device = pydobot.Dobot(port=port, verbose=False)

    self.device2 = pydobot.Dobot(port=port2, verbose=False)

    # 현재위치를 x,y,z,r 로 정의함
    # 홈위치로 이동
    #(self.x, self.y, self.z, self.r, _, _, _, _) = self.device.pose()
    self.device.move_to(200, 0, 58, 0, wait=False)
    (self.x, self.y, self.z, self.r, _, _, _, _) = self.device.pose()
    self.device2.move_to(200, 0, 58, 0, wait=False)
    (self.x, self.y, self.z, self.r, _, _, _, _) = self.device2.pose()
  # 두봇 초기화
  def dobot_init(self):
    # 흡입 켜기
    self.device.suck(False)
    # 속도 세팅
    self.device.speed(self.velocity, self.acceleration)
    # 홈위치로 이동
    self.device.move_to(190, 0, 58, 0, wait=False)
  # 두봇 2 초기화
  def dobot2_init(self):
    # 흡입 켜기
    self.device2.suck(False)
    # 속도 세팅
    self.device2.speed(self.velocity, self.acceleration)
    # 홈위치로 이동
    self.device2.move_to(188, 0, 58, 0, wait=False)

  #  device의 분류 동작
  def pick(self):
    # 대기시간  2500ms
    self.device.suck(True)
    self.device.wait(900)
    self.device.move_to(190, 0, 39, 0, wait=True)
    self.device.move_to(190, 0, 58, 0, wait=False)
    self.device.move_to(300, 0, 58, 0, wait=False)
    self.device.suck(False)
    self.device.move_to(190, 0, 58, 0, wait=False)
    # self.device.suck(True)

  #  device2의 분류 동작
  def pick2(self):
    self.device2.suck(True)
    self.device2.wait(2000)
    self.device2.move_to(188, 0, 37, 0, wait=True)
    self.device2.move_to(188, 0, 58, 0, wait=False)
    self.device2.move_to(300, 0, 58, 0, wait=False)
    self.device2.suck(False)
    self.device2.move_to(188, 0, 58, 0, wait=False)

  # 디바이스 1과 2의 대기 시간 설정  각 분류의 타이밍 필요
  def wait(self, t):
    self.device.wait(t)

  def wait2(self, t):
    self.device2.wait(t)

  # 각디바이스의  종료
  def end(self):
    self.device.suck(False)
    self.device.close()
    print("종료")
  def end2(self):
    self.device2.suck(False)
    self.device2.close()



