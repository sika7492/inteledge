#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <time.h>
#define STEP_OUTA 27
#define STEP_OUTB 0
#define STEP_OUT2A 1
#define STEP_OUT2B 24
#define SW1 3
#define SW2 4
#define SW3 5
#define SW4 6



void stepMotor(degree);


int main(void){
    int i,ret=2;
    if(wiringPiSetup()==-1)
        return 1;
    pinMode(SW1,INPUT);
    pinMode(SW2,INPUT);
    pinMode(SW3,INPUT);
    pinMode(SW4,INPUT);
       
    pinMode(STEP_OUTA,OUTPUT);
    pinMode(STEP_OUTB,OUTPUT);
    pinMode(STEP_OUT2A,OUTPUT);
    pinMode(STEP_OUT2B,OUTPUT);
    digitalWrite(STEP_OUTA,0);
    digitalWrite(STEP_OUTB,0);
    digitalWrite(STEP_OUT2A,0);
    digitalWrite(STEP_OUT2B,0);
    printf("%d",ret);
    while(1){
        ret=digitalRead(SW1);
        if(ret==0){
            printf("SW1 Button push\n");
            stepMotor(65);
        }
        ret=digitalRead(SW2);
        if(ret==0)
        {
            printf("SW2 Button push\n");
            stepMotor(130);
        }
        ret=digitalRead(SW3);
        if(ret==0)
        {
            printf("SW3 Button push\n");
            stepMotor(260);
        }
    }
    return 0;
}



void stepMotor(int degree){
    int i;
    for(i=0;i<degree;i++){

                digitalWrite(STEP_OUTA,1);
                usleep(2000);
                digitalWrite(STEP_OUTA,0);
                digitalWrite(STEP_OUTB,1);
                usleep(2000);
                digitalWrite(STEP_OUTB,0);
                digitalWrite(STEP_OUT2A,1);
                usleep(2000);
                digitalWrite(STEP_OUT2A,0);
                digitalWrite(STEP_OUT2B,1);
                 usleep(2000);
                digitalWrite(STEP_OUT2B,0);
        }
        
}