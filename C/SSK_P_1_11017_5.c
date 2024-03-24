#include <mega128.h> 
#include <delay.h> 

unsigned char EINT4_FLAG_BIT=0;  
unsigned char EINT5_FLAG_BIT=0;  
unsigned char EINT6_FLAG_BIT=0;  
unsigned char EINT7_FLAG_BIT=0;  

unsigned char TIMER2_COMPARE_INT_BIT =0;
unsigned char TIMER0_OVF_INT_BIT =0;

unsigned char BLINK2=0;
unsigned char BLINK0=0;

unsigned char  string1[]="Menu display\r"; 
unsigned char  string2[]="1:LED Blink\r";
unsigned char  string3[]="2:writ without you\r";
unsigned char  string4[]="pless the number\r";


unsigned char  string5[]="No I can't forget this evening,\rOr your face as you were leaving.\rBut I guess that's just the way The story goes.\rYou always smile but in your eyes.\rYour sorrow shows Yes it shows.\rNo I can't forget tomorrow\rWhen I think of all my sorrow \rWhen I had you there But then I let you go And now it's only fair.\rThat I should let you know What you should know\r";

unsigned char  *pStr1;
unsigned char  *pStr2;
unsigned char  *pStr3;
unsigned char  *pStr4;
unsigned char  *pStr5;


//unsigned char usart0_rxc_bit=0;
unsigned char input=0;

void Putch(char data);
void main_menu(void);
 
void main(void)
{ 
    DDRC = 0xFF; // 포트 C 출력 설정
    PORTC = 0xFF; // 포트 C에 초기값 출력
    
    EIMSK = 0b11110000; // 외부 인터럽트4 enable
    EICRB = 0b10101110; // 외부 인터럽트4 level trigger
    SREG |= 0x80; // 전역 인터럽트 enable-bit set
    
   
    
       
    
    while(1){
    
    if (BLINK0==1)
       {PORTC=0x0F;
       BLINK0=0;

       }    
        
    switch (input){
           case '1':
                if(BLINK0==0){
                PORTC=0xF0;
                BLINK0=1;}
                input=0;
                main_menu();
           break;
           case '2' :
           pStr5 = string5;
           while(*pStr5 != 0) Putch(*pStr5++);
             input=0;
             main_menu(); 
           break;
           default:
            break;
           }

    
    

    
     
    
    
        if(EINT4_FLAG_BIT==1) {
            EINT4_FLAG_BIT=0;
            TCCR2 = 0x0D; // compare match 0704-7.04
            OCR2 = 109; 
            TCNT2 = 0x0; // 타이머/카운터0 레지스터 초기값
            TIMSK |= 0x80;
        }
        if(EINT5_FLAG_BIT==1) {
            EINT5_FLAG_BIT=0;
            TCCR2 &= 0xF8;
        }
        if(EINT6_FLAG_BIT==1) {
            EINT6_FLAG_BIT=0;
            UCSR0A=0x00;
            UCSR0B=0b10011000;
            UCSR0C=0x06;
            UBRR0H = 0; // X-TAL = 16MHz 일때, BAUD = 9600
            UBRR0L = 103; 
            main_menu();
        }
        if(EINT7_FLAG_BIT==1) {
            EINT7_FLAG_BIT=0;
            
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
        
       
    }//end of while
}//end of main

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

interrupt [TIM2_COMP] void timer_comp2(void) 
{ 
    TCNT2 = 0x0;
    SREG &= 0x7F; // All Interrupt disable
    TIMER2_COMPARE_INT_BIT++;
    SREG |= 0x80; // All Interrupt enable

}
interrupt [TIM0_OVF] void timer_ovf0(void) 
{ 
    TCNT0 = 175;
    SREG &= 0x7F; // All Interrupt disable
    TIMER0_OVF_INT_BIT++;
    SREG |= 0x80; // All Interrupt enable
}

interrupt [USART0_RXC] void usart0_rx(void)
{   SREG&=0x7F;
    input=UDR0;
    SREG|=0x80;

}
void Putch(char data) // 한 바이트 송신
{
while((UCSR0A & 0x20) == 0x0); //UDRE0[5] = 1 송신준비완료 될 때까지 대기
UDR0 = data;    // 데이터 전송
} 

void main_menu(void)
{ pStr1 = string1;
while(*pStr1 != 0) Putch(*pStr1++);
pStr2 = string2; 
while(*pStr2 != 0) Putch(*pStr2++);
pStr3 = string3; 
while(*pStr3 != 0) Putch(*pStr3++); 
pStr4 = string4;
while(*pStr4 != 0) Putch(*pStr4++);

}
