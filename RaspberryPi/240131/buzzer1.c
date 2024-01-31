#include <stdio.h>
#include <wiringPi.h>

int freg[8]={523,587,659,698,784,880,988,1047};

int main(void){
    const int buzzer_pin =1;

    wiringPiSetup();

    pinMode(buzzer_pin,PWM_OUTPUT);

    pwmSetClock(19);

    pwmSetMode(PWM_MODE_MS);

    int cnt;
    for(cnt=0,cnt<=2;cnt++;){
        pwmSetRange(1000000/freg[0]);
        pwmWrite(buzzer_pin,1000000/freg[0]/2);
        delay(1000);
        pwmSetRange(1000000/freg[1]);
        pwmWrite(buzzer_pin,1000000/freg[1]/2);
        delay(1000);
    }
}


