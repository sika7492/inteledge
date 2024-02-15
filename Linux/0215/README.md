# GitHub

## What is GitHub?

* Website:https://github.com
* Hosts Git service
* Provides
	* Branch protection
	* Issue tracking
	* PR creation/review/merge
	* Release/tag creation
	* GitHub workflow(CI/CD)
	* Online modification
	* Any many
## GitHub Interacting Options

* GitHub desktop
* GitHub CLI
* Octoki

## Opt#1 GitHub SSH

### Add a New Key

*Create a new ED25519 key pair

```
ssh-keygen -t ed25519 -C <your_email>
ls -l ~/.ssh/
```

* Add a New SSH key to GitHub
* Profile -> Settings -> SSH and GPG Keys -> New SSH Key
* Make sure  the SSH key waring is gone under SSh tab

## Opt#2 GitHub HTTPS -PAT

* Get a PAT from GitHub
> porfile -> setting > Developer setting -> Personal access tokens -> Generate new token(clasic)

## Opt#3 GitHub CLI

*Install GitHub CLI

```
# https://github.com/cli/cli

type -p curl >/dev/null || (sudo apt update && sudo apt install curl -y)
curl -fsSL https://cli.github.com/packages/githubcli-archive-keyring.gpg | sudo dd of=/usr/share/keyrings/githubcli-archive-keyring.gpg \
&& sudo chmod go+r /usr/share/keyrings/githubcli-archive-keyring.gpg \
&& echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/githubcli-archive-keyring.gpg] https://cli.github.com/packages stable main" | sudo tee /etc/apt/sources.list.d/github-cli.list > /dev/null \
&& sudo apt update \
&& sudo apt install gh -y

```

* use GitHub CLI
```
gh auth login
```

## Submit an Issue

### HW#1 : Issue Submission Practice
![HW#1](https://github.com/sika7492/inteledge/assets/154478957/9cd6b015-f82e-4910-85cd-4f0e30274465)

Milestone을 설정하고 각자의 이름으로 issue 제줄하고 close 하기

```
다음의 내용으로 Issue ticket을 생성하고 milestone 등을 설정합니다.

- [ ] Issue ticket을 생성하고 다음 내용을 작성
    * Name:  <name>
    * Github ID: <Gihub_id>
    * My repo: <github_repo>
- [ ] Assignee를 본인에게 할당
- [ ] Milestone을 "[Class01 HW#1] Github Issue 실습"으로 설정
```
<링크>
```
https://github.com/pskcci/intel-01/issues/16
```

## PR: Pull Requset

* Pull Requset is proposal to merge a set of changes from  one branch into another
	* git commit >> git push >> git Pull Requset >> git merge
* Pull requsets 간의 차이점을 보여준다 
* merge 버튼은 누르는것은 PR을 생성한 사람이 하는게 좋다.

### HW#2:PR Creation Practic

* Pull the lastest class
* Create commits with follwing changes
	* Create a topic branch with a fllowing naming convention
		* class-01-hw2-sika7492
		
	* Create folder and readme.md
	* add and commit push
* GitHub PR 
	* check main_branch /your_branch 
	* chose Reviewers
	* commit
	* select Development
* 승인을 받으면 merge를 한다.
	* deleted branch
<링크>
```
https://github.com/pskcci/intel-01/issues/24
```
	
### Ground Rules

>> Create an issue >>Topic branch >> Add &Commit >> push >> Create PR >>  merge




