/*
 * SSK_P_1_11015_3.c
 *
 * Created: 2023-11-15 오후 12:24:44
 * Author: user
 */

#include <mega128a.h>


typedef unsigned char U8;
typedef unsigned int U16;

U8 led1=0;
U8 led3=0;
U8 timer_ovf1_bit=0;
U8 timer_compa3_bit=0;

void main(void)
{
      DDRC=0xFF;
      PORTC=0xFF;
      
      TIMSK=0x04;
      ETIMSK=0x10;
      
      TCCR1A=0x00;
      TCCR1B=0x03;      //64  분주기 
      TCCR1C=0x0;
      
      TCCR3A=0x40;      //CTC mode compA3 0b01000000
      TCCR3B=0X0C;      //256 분주기 
      TCCR3C=0x0;
      
      
      TCNT1H=0x9E;     //9E58 0.1ms
      TCNT1L=0x58; 
      
      
      TCNT3H=0x00;
      TCNT3H=0x00;
      
      OCR3AH=0xF4;  //F423 1ms
      OCR3AL=0x23;
      
      
      
      SREG|=0x80;


while (1)
    {
       if(timer_ovf1_bit==3){
         timer_ovf1_bit=0;
         if(led1==0) {
				PORTC=0xAA;
				led1=1;
			}
			else {
				PORTC=0x55;
				led1=0;
         }
        }
      
      
        if(timer_compa3_bit==3){
         timer_compa3_bit=0;
        if(led3==0) {
				PORTC=0xF0;
				led3=1;
			}
			else {
				PORTC=0x0F;
				led3=0;
        
        }  

    }
}

}
interrupt [TIM1_OVF] void timer_ovf1(void)
{   TCNT1H=0x80;
    TCNT1L=0x00;
    SREG&=0x7F;
    timer_ovf1_bit++;
    SREG|=0x08;
}

interrupt [TIM3_COMPA] void timer_compa3(void)
{   TCNT3H=0x00;
    TCNT3H=0x00;
    SREG&=0x7F;
    timer_compa3_bit++;
    SREG|=0x08;
}


