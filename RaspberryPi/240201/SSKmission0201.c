#include<stdio.h>
#include<stdlib.h>
#include<wiringPi.h>
#include<unistd.h>
#include<time.h>

#define PIR_D 2

int main(void){
    int pir_val,i;
    const int buzzer_pin=1;
    
    if(wiringPiSetup()==-1)
        return -1;

    pinMode(PIR_D,INPUT);
    pinMode(buzzer_pin,OUTPUT);
    pwmSetClock(19);
    pwmSetMode(PWM_MODE_MS);
    printf("aa;");
    for(i=0<i;i<20;i++){
        pir_val =digitalRead(PIR_D);
        if(pir_val==1){
            pwmSetRange(1000000/262);
            pwmWrite(buzzer_pin, 1000000/262/2);
            printf("bb;");
            sleep(1);
        }
        else    
            pwmWrite(buzzer_pin,0);
            printf("cc;");
            sleep(1);
    }
    return 0;
}