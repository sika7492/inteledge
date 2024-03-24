/*
 * SSK_P_1_11015_4.c
 *
 * Created: 2023-11-15 오후 2:45:29
 * Author: user
 */

#include <mega128a.h>


typedef unsigned char U8;
typedef unsigned int U16;


U16 pwm=0x0200;
U8  EINT4_FLAG_BIT=0;
U8  EINT5_FLAG_BIT=0;
U8  EINT6_FLAG_BIT=0;
U8  EINT7_FLAG_BIT=0;

void main(void)
{
    DDRB = 0xFF; // OC1C(PB7) 핀 출력방향설정
    DDRG = 0xFF; // 7-세그먼트 ON/OFF 제어 포트
    PORTG = 0x0F; 
    
    EIMSK = 0b11110000;
   
    EICRB = 0b10101010;
    
    TCCR1A=0x0B;    //0b0000 1011
    TCCR1B=0x04;   // 256주기 0x04 1024 0x05
    TCCR1C=0x00;
   
    TCNT1H=0x00;
    TCNT1L=0x00;
    
    OCR1CH= (pwm&0xFF00)>>8;
    OCR1CL=(pwm&0x00FF);
    SREG|=0x80;

    
while (1)
    {
       
     
    if( EINT4_FLAG_BIT==1){
         EINT4_FLAG_BIT=0;
         if(pwm < 0x03B0){ pwm += 0x0040; // 0x03B0보다 작으면 증가
            OCR1CH = (pwm & 0xFF00) >> 8; // OCR1C 값 갱신
            OCR1CL = pwm & 0x00FF;} 
        }
     if( EINT5_FLAG_BIT==1){
         EINT5_FLAG_BIT=0;
         if(pwm > 0x0050){ pwm -= 0x0040; // 0x0050보다 크면 감소
         OCR1CH = (pwm & 0xFF00) >> 8; // OCR1C 값 갱신
            OCR1CL = pwm & 0x00FF;} 
        }
      if( EINT6_FLAG_BIT==1){
         EINT6_FLAG_BIT=0;
          TCCR1B=0x05;      ///1024 
        }
     if( EINT7_FLAG_BIT==1){
         EINT7_FLAG_BIT=0;
          TCCR1B=0x03;      ///64 
        }   
        

    }
}



interrupt [EXT_INT4] void external_int4(void) 
{ 
    SREG &= 0x7F; // All Interrupt disable
    
    EINT4_FLAG_BIT=1;
    
    SREG |= 0x80; // All Interrupt enable
}
interrupt [EXT_INT5] void external_int5(void) 
{ 
    SREG &= 0x7F; // All Interrupt disable
    
    EINT5_FLAG_BIT=1;
    
    SREG |= 0x80; // All Interrupt enable
}
interrupt [EXT_INT6] void external_int6(void) 
{ 
    SREG &= 0x7F; // All Interrupt disable
    
    EINT6_FLAG_BIT=1;
    
    SREG |= 0x80; // All Interrupt enable
}
interrupt [EXT_INT7] void external_int7(void) 
{ 
    SREG &= 0x7F; // All Interrupt disable
    
    EINT7_FLAG_BIT=1;
    
    SREG |= 0x80; // All Interrupt enable
}