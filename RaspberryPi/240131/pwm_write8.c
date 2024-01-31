#include <stdio.h>
#include <wiringPi.h>
int main(){
    const int led_pin=1;

    wiringPiSetup();

    pinMode(led_pin,PWM_OUTPUT);

    pwmSetClock(19);
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(1000000/1000);
    pwmWrite(led_pin,1000000/2/1000);


}

