/*
 * SSK_P_1_11014_3.c
 *
 * Created: 2023-11-14 오후 12:40:27
 * Author: user
 */
/**************************************************************/


/***************************************************************/
#include <mega128.h> 
#include <delay.h> 
/***************************************************************/


typedef unsigned char U8;



/***************************************************************/
U8 EINT4_FLAG_BIT=0;  
U8 EINT5_FLAG_BIT=0;  
U8 EINT6_FLAG_BIT=0;  
U8 EINT7_FLAG_BIT=0;  

U8 TIMER2_COMPARE_INT_BIT =0;
U8 TIMER0_OVF_INT_BIT =0;

U8 BLINK2=0;
U8 BLINK0=0;


U8 SW6=0;
U8 SW7=0;

/***************************************************************/
void IIC_START(void);
void IIC_STOP(void);

void Process_8data(U8 value);

void ACK_write(void);
void byte_write(void);

/***************************************************************/
void main(void)
{ 
    DDRC = 0xFF; // 포트 C 출력 설정
    PORTC = 0xFF; // 포트 C에 초기값 출력
    
    EIMSK = 0b111110000; // 외부 인터럽트4 enable
    EICRB = 0b10101110; // 외부 인터럽트4 level trigger
    SREG |= 0x80; // 전역 인터럽트 enable-bit set
    SCL_OUT;                     
    SDA_OUT; 
    while(1){ 
        
        if(EINT4_FLAG_BIT==1) {
            EINT4_FLAG_BIT=0;
            TCCR2 = 0x0D; // compare match 0704-7.04
            OCR2 = 109; 
            TCNT2 = 0x0; // 타이머/카운터0 레지스터 초기값
            TIMSK |= 0x80;
        }//timer2 on
        if(EINT5_FLAG_BIT==1) {
            EINT5_FLAG_BIT=0;
            TCCR2 &= 0xF8;
            PORTC=0xFF;
        }//timer2off
         if(EINT6_FLAG_BIT==1) {
            EINT6_FLAG_BIT=0;
            
           
            SW6=(SW6+1)%2;
             if(SW6==1){PORTC=0x0F;
        }
        else PORTC=0xFF;
                
        }
       
        
         if(EINT7_FLAG_BIT==1) {
            EINT7_FLAG_BIT=0;
            TCCR0 = 0x07; // 프리스케일 = CK/1024
			TCNT0 = 0x00; // 타이머/카운터0 레지스터 초기값
			TIMSK |= 0x01;
        }
        
        
        if(TIMER2_COMPARE_INT_BIT==100) {
            TIMER2_COMPARE_INT_BIT=0;
            if(BLINK2==0) {
                PORTC=0xAA;
                BLINK2=1;
            }
            else {
                PORTC=0x55;
                BLINK2=0;                
            }
        }
        if(TIMER0_OVF_INT_BIT==31) {   //500ms
            TIMER0_OVF_INT_BIT=0;
            
                        
            }    
        }        
    }

/***************************************************************/
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

/***************************************************************/


interrupt [TIM2_COMP] void timer_comp2(void) 
{ 
    TCNT2 = 0x0;
    SREG &= 0x7F; // All Interrupt disable
    TIMER2_COMPARE_INT_BIT++;
    SREG |= 0x80; // All Interrupt enable

}
interrupt [TIM0_OVF] void timer_ovf0(void) 
{ 
    TCNT0 = 6;
    SREG &= 0x7F; // All Interrupt disable
    TIMER0_OVF_INT_BIT++;
    SREG |= 0x80; // All Interrupt enable
}

/***************************************************************/


/***************************************************************/



