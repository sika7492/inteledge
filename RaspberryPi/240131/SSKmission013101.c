#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <time.h>


//핀 포트 지정

#define LED_RED 7
#define LED_GREEN 21
#define LED_BLUE 22

void title();
void select();

//핀모드 설정
if(wiringPiSetup () == -1)                  
		return 1;
	pinMode(LED_RED,OUTPUT);
	pinMode(LED_GREEN,OUTPUT);
	pinMode(LED_BLUE,OUTPUT);
int colors[3]={LED_RED,LED_GREEN,LED_BLUE};
int random_colors[2]={0,0};
int number=0;
int answer=0

int main(){
    //rand 설정
    srand(time(NULL));     
    //타이틀 출력 
    title();
    random_colors[0]=colors[rand()%3]
    random_colors[1]=colors[rand()%3]
    while(random_colors[0]==random_colors[1]){
       random_colors[1]=colors[rand()%3]
    }
    


    //선택창 출력
    select();
    printf("숫자를 입력하세요: \n");
    scanf("%d",number);






}



void title(){
    printf("--------------------------------------------------------------------\n");
    printf("                            빛의 삼원색 게임                         \n");
    printf("        -색을 확인하고 합쳐지면 어떤 색이 되는지 맞춰보자-              \n");
    printf("--------------------------------------------------------------------\n");
}



void select(){
    printf("--------------------------------------------------------------------\n");
    printf("1. yellow\n2.magenta\n3.cyan\n4.whhie\n");
    printf("--------------------------------------------------------------------\n");
}

