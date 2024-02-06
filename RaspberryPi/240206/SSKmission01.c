#include <wiringPi.h>
#include <stdio.h>

// LED 핀 번호 설정
#define LED_RED 7
#define LED_GREEN 21
#define LED_BLUE 22



int main(void){
    int j,i;
    wiringPiSetup();
    pinMode(LED_RED,OUTPUT);
    pinMode(LED_BLUE,OUTPUT);
    pinMode(LED_GREEN,OUTPUT);
    
    //led가 순서대로 꺼졌다가 켜기는 것을 10회 반복한다;
    for(j=0;j<10;j++){
                
               
                    digitalWrite(LED_RED,HIGH);
                    digitalWrite(LED_GREEN,HIGH);
                    digitalWrite(LED_BLUE,HIGH);
                    delay(1000);
                    digitalWrite(LED_RED,LOW);
                    digitalWrite(LED_GREEN,LOW);
                    digitalWrite(LED_BLUE,LOW);
                    delay(1000);
                

    }
    
}