#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[]){

	int fd1;
	int fd2;
	if((fd1 =open(argv[1],O_RDWR))==-1)
		printf("파일열기 오류\n");
	else printf("파일 %s 열기성공:%d\n",argv[1],fd1);

	if((fd2 =open(argv[2],O_RDWR))==-1)
		printf("파일열기 오류\n");
	else printf("파일 %s 열기성공:%d\n",argv[2],fd2);
	close(fd1);
	close(fd2);
	exit(0);
}

