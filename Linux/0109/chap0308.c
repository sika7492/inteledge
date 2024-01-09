#include<stdio.h>
#include<string.h>
#define MAXLINE 100

char line[MAXLINE];
char longest[MAXLINE];
void copy(char from[],char to[]);

int main(){
	int len, max=0;
	
	while(fgets(line,MAXLINE,stdin) !=NULL){	//^d
		len =strlen(line);
		if(len>max){
			max=len;
			copy(line,longest);
		}	//end of if
	}	//end of while
	if(max>0) //입력줄이 있다면
		printf("%s",longest);
	return 0;
}	//end of main

void copy (char from[],char to[]){
	int i;
	i=0;
	while((to[i]=from[i]) !='\n')
		++i;
}	//end of copy


