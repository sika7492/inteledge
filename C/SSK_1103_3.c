/*
 * SSK_1103_3.c
 *
 * Created: 2023-11-03 ¿ÀÈÄ 2:42:48
 * Author: user
 */

#include <mega128a.h>
#include <delay.h>

const unsigned char led[8]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};

void main(void)
{
unsigned char i;
DDRC=0xFF;
while (1)
    {
     for(i=0;i<8;i++){
        if (i%2==0){
            PORTC=led[i];
        }
        else {
            PORTC=led[i]&led[i-1];
        } 
        
        delay_ms(500);
        }
     }

    

    }


