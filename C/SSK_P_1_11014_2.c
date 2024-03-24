/******************************************************************/
/* SSK_P_1_11014_2.c                                              */
/*                                                                */
/* Created: 2023-11-14 ¿ÀÈÄ 12:14:12                               */
/* Author: user                                                   */
/******************************************************************/

#include <mega128a.h>

typedef unsigned char U8;


U8 led=0xFE;
U8 timer0_comp_int_bit=0;


/******************************************************************/
void main(void)
{
    DDRC=0xFF;
    PORTC=led;
    
    TIMSK=0x02;
    TCCR0=0x0F;
    TCNT0=0x00;
    OCR0=249;
    
    SREG|=0x80;
    
    
while (1)
    {
                                 
      if (timer0_comp_int_bit==100)
         {timer0_comp_int_bit=0;
         led= led << 1;
         led= led | 0x01;
         if(led==0xFF)led=0xFE;
         PORTC=led;

         }
    }
}


/******************************************************************/


interrupt [TIM0_COMP] void timer0_com (void)
{   
    TCNT0=0x00;
    SREG&=0x7F;
    timer0_comp_int_bit++;
    SREG|=0x80;
}