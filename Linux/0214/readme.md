# Git


## 프로그램 개발 과정

Requirement > Desien > Development > Test > Deployment > Maintenace(Hotfix)

과거엔 위과정을  각 부분의 소프트웨어를 단순하게 합쳤는데 그 과정에서 오류가 많았다.

이후에 개발된 순으로 코드를 미리 합치면서 진행한다.

code >commit >build >Unit Tset> intergration Tests> Review > Staging > production

Benefits /위험성 하락 / 고객의 요구사항에 맞추기 쉬움 / 개발과정을 알기가 쉬워 차후 다른 개발자가 참여가 쉬움/ 그에 따른 인력분배에 이득이 있음

Waterfall(시간을 두고 알아서 한번에 통합) /Agile(기능별 잘게 분리하여 개발하고 주단위로 통합 리뷰를 하며 개발을 진행 )

현재는 Agile 방식을 채택을 많이함



## Softeware VC (Version Control)

Version control tools 
(cvs, svn, GIT, Mecurial, Bazaar)


## Git 이란

A free and open-source version control system

난잡하게 개발되던 오픈 소스 프로그램을 편리하고 간편하게 협력하여 개발하기 위해 만들어진 툴이다.


## git getting started

#### check git version (if the version is confiremed , skip the installation)

$ git --version     

#### install git
  
$ sudo apt-get update
$ sudo apt-get update git

#### set name & email
$ git config --global user.name "username"
$ git config --global user.email useremail

#### check git settings

$ cat ~/.gitconfig


## git commands

#### git clone
>git파일 복사

>git clone url

#### git status
>git 상태 확인 

>git 상태의 변화가 있다면 해당 상황을 변경하기 위한 명령어를 가르쳐준다.

![git_status](https://github.com/sika7492/inteledge/assets/154478957/e063da6b-e5e5-4087-a637-ea66be24882a)


#### git log
>해당 git의 로그를 확인하는 명령어

![git_log](https://github.com/sika7492/inteledge/assets/154478957/105f3d29-5c22-45da-b82d-ccd806c75c68)



#### git log --oneline
>--oneline 옵션은 각 log의 변경사항을 한줄로 표시한것을 보여준다.

![git_log_oneline](https://github.com/sika7492/inteledge/assets/154478957/4c379730-a169-47af-a4f8-2cb62717be59)


#### git show <10_chars_commit_id>
>commit-id로 그사람의 로그를 확인한다

![git_log_oneline_select](https://github.com/sika7492/inteledge/assets/154478957/625804d7-6645-47be-8d76-5bc2eaa4a82e)


#### git log -p

![git_log-p](https://github.com/sika7492/inteledge/assets/154478957/fc120956-a9e5-4103-a364-f39d685206c5)


#### git branch


>git branch

>git branch -a

![git_branch](https://github.com/sika7492/inteledge/assets/154478957/9022b768-130e-48b7-8833-0372dbd3621a)


>git branch -d <branch>

![git_branch_-d](https://github.com/sika7492/inteledge/assets/154478957/500e5dd0-990a-4207-bd3a-4dd5fa67e2f5)


#### git checkout <branch>

>브랜치 전환

#### git diff <branch_1> <branch_2>

#### git init

#### git commit

Modified 된 파일을 Staged 상태로 커밋하기 위하여 아래의 명령어를 실행합니다.


### git 이해하기

HEAD란 내가 작업하고 있는 위치(currnet branch)

git show HEAD
git show HEAD^  	//헤드 이전 commit id
git show HEAD~num 	//헤드  num 숫자만큼 이전의 comit_id의 정보를 보여줌

git checkout HEAD~num 	//헤드 이전 숫자만큼의  commit_id의 브랜치로 전환


branch

목적과 상황에 따라서 각 branch를 생성하고 사용을한다.

### Creation and Managin Local Repositories






### ex1

$ mkdir central-repo.git 			//폴더 생성

$ cd central-reop.git  			//폴더이동

$ git init --bare				//bare 라는 branch

$ cd ..					//상위폴더로

$ git clone central-repo.git/ developerA	//developerA 라는 폴더 생성

$ cd developerA/				//폴더이동

$ touch hello.py				//hello.py 생성

$ vi hello.py					//hello.py 수정

$ git add hello.py				//hello.py를  Untracked 상태에서 Tracked 상태로 변경

$ git commit -m "1st commit"			//수정사항을 commit한다 

 hello.py를 수정하고 9~10을 3번 반복 

 $ git puch					//여기까진 master branch에서 작업함

$ git checkout -b <branch_name>		//새롭게 branch를 생성하고 변경한다.

hello.py를 수정하고 9~10을 반복

$ cd ../

$ git clone central-repo.git/ developerB

$ cd developerB/

$ git log --oneline 				//log를 확인하면 14번에서 한 log는 뜨지 않음 새롭게 생성한 branch에 종속됨

$ cd ../developerA				//

$ git checkout master

$ git merge <branch_name>

$ git push					//

$ cd ../developerB

$ git pull					

### 여기까지 강의

#### 실습 

developerb에서 새로운 branch를 생성하고 master에 병합하기 






