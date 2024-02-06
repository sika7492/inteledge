#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

#define SW1 3
#define SW2 4
#define SW3 5

volatile sig_atomic_t flag = 0;
void handle_sigint(int sig) {
    flag = 1;
}




int main(void){
    int i,ret=2;
    const int Buzzer = 1;
    if(wiringPiSetup()==-1)
        return 1;
    
    pinMode(SW1,INPUT);
    pinMode(SW2,INPUT);
    pinMode(SW3,INPUT);
    


    pinMode(Buzzer, PWM_OUTPUT);

        pwmSetClock(19);
        pwmSetMode(PWM_MODE_MS);

        const int melody[] = {
                523, 587, 659, 698, 784, 880, 988, 1047
        };
    // 비행기 동요 음계 배열  
    const int airplane[] = { 2,1,0,1,2,2,2,1,1,1,2,2,2,2,1,0,1,2,2,2,1,1,2,1,0};
    
        
        
        
        
        
        
        
        
    const int twinkle[] = { 0,0,4,4,5,5,4,3,3,2,2,1,1,0,4,4,3,3,2,2,1,4,4,3,3,2,2,1,0,0,4,4,5,5,4,3,3,2,2,1,1,0};
    const int butterfly[]={4,2,2,3,1,1,0,1,2,3,4,4,4,4,2,2,2,3,2,2,0,2,4,4,2,2,2,1,1,1,1,1,2,3,2,2,2,2,2,3,4,4,2,2,3,1,0,0,2,4,4,2,2,2}; 
             
                  
               
                  //13 12
               //17
                 //20 19
               //24
                //27 26
                //31
                 //34 33
               //38
                  //41 40
                  //44 43
                //47 46
                //51
                  //54 53

  

    signal(SIGINT, handle_sigint);

    while(1){
        ret=digitalRead(SW1);
        if(ret==0){
            printf("SW1 Button push\n");
            for(int note=0;note<42;note++) {
                if (flag) {
                    printf("Interrupt received, stopping...\n");
                    pwmWrite(Buzzer, 0);
                    return 0;
                }
                pwmSetRange(1000000/melody[twinkle[note]]);
                pwmWrite(Buzzer, 1000000/melody[twinkle[note]]/10);
                if (note==6 || note==13 || note==20 || note==27 || note==34 || note==41){
                    delay(1000);
                              
                }
                else delay(500);
               
            }//end of for
           

        }//end of if sw1

        ret=digitalRead(SW2);
        if(ret==0)
        {
            printf("SW2 Button push\n");
            for(int note=0;note<24;note++) {
                if (flag) {
                    printf("Interrupt received, stopping...\n");
                    pwmWrite(Buzzer, 0);
                    return 0;
                }
                pwmSetRange(1000000/melody[airplane[note]]);
                pwmWrite(Buzzer, 1000000/melody[airplane[note]]/10);
                if (note == 6 || note == 9 || note == 12 || note == 19 ){
                    delay(1000);           
                }
                else delay(500);
                    
            }//end of for
            
            
        }//end of if sw2

        ret=digitalRead(SW3);
        if(ret==0)
        {
            //printf("SW3 Button push\n");
            printf("aq");
            for(int note=0;note<53;note++) {
                if (flag) {
                    printf("Interrupt received, stopping...\n");
                    pwmWrite(Buzzer, 0);
                    return 0;
                }
                pwmSetRange(1000000/melody[butterfly[note]]);
                pwmWrite(Buzzer, 1000000/melody[butterfly[note]]/10);
                if (note == 2|| note == 5 || note == 12 || note == 19|| note == 26|| note == 33|| note == 40|| note == 46|| note == 53 ){
                    delay(1000);            
                }
                else delay(500);
                    
            }//end of for
        }//end of if sw3
    }
    return 0;
}

