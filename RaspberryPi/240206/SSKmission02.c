#include <stdio.h>
#include <wiringPi.h>
#include <signal.h>



volatile sig_atomic_t flag = 0;



void handle_sigint(int sig) {
    flag = 1;
}



int main(void) {
        const int Buzzer = 1;

        wiringPiSetup();

        pinMode(Buzzer, PWM_OUTPUT);

        pwmSetClock(19);
        pwmSetMode(PWM_MODE_MS);

        const int melody[] = {
                523, 587, 659, 698, 784, 880, 988, 1047
        };
        signal(SIGINT, handle_sigint);
        const int twinkle[] = { // 작은 별 노래 배열
                4,2,2,
                3,1,1,
                0,1,2,3,4,4,4,
                4,2,2,2,3,1,1,
                0,2,4,4,2,2,2,
                1,1,1,1,1,2,3,
                2,2,2,2,2,3,4,
                4,2,2,
                3,1,1,
                0,2,4,4,2,2,2
        };
        
        for(int note=0;note<54;note++) {
            if (flag) {
                printf("Interrupt received, stopping...\n");
                pwmWrite(Buzzer, 0);
                return 0;
                }
            pwmSetRange(1000000/melody[twinkle[note]]);
            pwmWrite(Buzzer, 1000000/melody[twinkle[note]]/10);
            if (note == 2 || note == 5 || note == 12 || note == 19 || note == 26 || note == 33 || note == 40 || note == 43 || note == 46 || note == 53){
                    delay(1000);
                               
                }
            else delay(500);
                
            }

        pwmWrite(Buzzer, 0);
}