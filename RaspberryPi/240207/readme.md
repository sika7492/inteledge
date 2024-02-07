# RaspberryPi3 --  casaos 및 PI-Hosted & WordPress

## Casaos 설치 및 실행 


install Casaos

  sudo curl -fsSL https://get.casaos.io | sudo bash
  
run Casaos 

	https://user_ip
 
## Casaos 실행화면

![Casaos_homepage](https://github.com/sika7492/inteledge/assets/154478957/07aff958-c8c7-418b-9d87-7008347beb52)


## PI-Hosted 설치 및 실행

install docker

    wget -qO- https://raw.githubusercontent.com/pi-hosted/pi-hosted/master/install_docker.sh | bash


install Portainer.io
	
    wget -qO- https://raw.githubusercontent.com/pi-hosted/pi-hosted/master/install_portainer.sh | bash

run PI-Hosted

    https:user_ip:9000

RaspberryPi3 setting     
        -- Settings > App templates > url

    https://raw.githubusercontent.com/pi-hosted/pi-hosted/master/template/portainer-v2-arm32.json
    
## PI-Hosted 실행화면
![PI-host](https://github.com/sika7492/inteledge/assets/154478957/4eb07e69-3e66-41cf-8b06-7ceacb2cfc6c)

## PI-Hosted 세팅화면 

![PI-host_setting](https://github.com/sika7492/inteledge/assets/154478957/15fec7d1-aab0-4cf3-9689-1dedef86adb9)


## PI-Hosted - WordPress

WordPress
--App templates 

## WordPress 세팅

![wordpress_setting](https://github.com/sika7492/inteledge/assets/154478957/a6abee78-9264-4a9a-90d4-291734f5d2f1)

Container list

--wordpress 의 포트 확인 

https://user_ip:wordpress_port

![wordpress_setting2](https://github.com/sika7492/inteledge/assets/154478957/55f5b4b8-4564-4653-a383-29af7455485a)


## WordPress 홈페이지 편집 화면

![wordpress_home](https://github.com/sika7492/inteledge/assets/154478957/0a8e677c-aad5-4d40-9f8c-05a809ea22b3)

## WordPress 홈페이지 화면

![wordpress_home2](https://github.com/sika7492/inteledge/assets/154478957/78ebabc9-07b2-4f55-b574-d812d92f2af8)





