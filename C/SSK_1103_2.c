/*
 * SSK_1103_2.c
 *
 * Created: 2023-11-03 ¿ÀÈÄ 2:17:49
 * NAME: SONG_SI_KYEONG
 */

#include <mega128a.h>
#include <delay.h>


void main(void)
{

unsigned char i;
unsigned char led;

DDRC = 0xFF;

while (1)
    { led=0xFE;
    for(i=0;i<8;i++){ 
        PORTC=led;
        delay_ms(500);
        if((i%2)==1){
            led= led<<2;
            led |= 0x02;
        }
        
    }
    }
}
