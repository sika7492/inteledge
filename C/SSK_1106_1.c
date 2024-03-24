/*
 * SSK_1106_1.c
 *
 * Created: 2023-11-06 ¿ÀÀü 9:03:20
 * Name= SONG_SI_KYEONG
 * Grupe= 2
 */

#include <mega128a.h>


void main(void)
{

unsigned char old_sw,new_sw,led;
unsigned char state=0; 
DDRC=0xFF;
DDRE=DDRE&0x0F;
PORTC=0xFE;
led=0xFE;
old_sw=0xF0;




while (1)
    {
    new_sw=PINE&0xF0;
    if((old_sw==0XF0)&&(new_sw==0xE0)){
        state =1;
        led=(led<<state)+0x01;
        PORTC=led;
        }//end if
    if((old_sw==0XF0)&&(new_sw==0xD0)){
        state =2;
        led=(led<<state)+0x03;
        PORTC=led;
        } //end  if
    if((old_sw==0XF0)&&(new_sw==0xB0)){
        state =3;
        led=(led<<state)+0x07;
        PORTC=led;
        } //endif 
    if((old_sw==0XF0)&&(new_sw==0x70)){
        state =4;
        led=(led<<state)+0x0F;
        PORTC=led;} //endif
    if(PORTC==0xFF){
        led=0xFE;} 
     old_sw=new_sw;     
    }//end of while
}//end of main

