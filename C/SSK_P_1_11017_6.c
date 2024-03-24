/*
 * SSK_P_1_11017_6.c
 *
 * Created: 2023-11-17 오후 4:43:00
 * Author: user
 */
/*******************************************************************************/
#include <mega128a.h>

typedef unsigned char U8;

flash U8 seg_pat[16]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d,
0x07,0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

U8 out[4]={0};
U8 seg_pos[4]={0x08,0x04,0x02,0x01};

U8 caps=0;
U8 usart0_rx_bit=0;

char string[] = "  menu\r1.number\r2.position\r3.default ";
                                                              
U8 input=0;
U8 pos=0;
U8 LED_bit=0;

U8 ext_int4_bit=0;
                                                              
U8 *menu;
U8 tim0_ovf=0;
U8 time=0;

void Putch(U8 data);
void main_menu (void);
void seg (U8 N);
/*******************************************************************************/
void main(void)
{
  DDRB=0xF0;               
  DDRD=0xF0;
  DDRG=0x0F;
  
  EIMSK=0xF0;              // all sw on
  EICRB=0xAA;              //all sw falling
  
  
 
    
    TIMSK = 0x01; // TOIE0 = 1(overflow interrupt enable)
    TCCR0 = 0x07; // 일반모드, 1024분주
    TCNT0 = 100; // 타이머/카운터0 레지스터 초기값
    SREG |= 0x80; // 전역 인터럽트 enable 비트 I set
  
  
  SREG|=0x80;
/*******************************************************************************/
while (1)
    { 
      seg(time);
      
    
      switch (input)
             {
             case'1':
               out[pos]=(out[pos]+1)%16;
               main_menu();
             input=0;
             break;
             case'2':
                pos++;
                main_menu();
                input=0;
             break;

             case '3':
                out[0]=0;
                out[1]=0;
                out[2]=0;
                out[3]=0;
                
                pos=0;
                main_menu();
                input=0;
             break; 
             default:
             break;
             }
       
    if (ext_int4_bit==1)
       {ext_int4_bit=0;
        main_menu();
         UCSR0A=0x00;
  UCSR0B=0x98;
  UCSR0C=0x06;
  
  
  UBRR0H=0x00;              // 9600 bps   
  UBRR0L=103;
       }
       
    if(tim0_ovf==1)
    {tim0_ovf=0;
    time=(time+1)%4;   
    }
    
    
}
}

/*******************************************************************************/
interrupt [USART0_RXC] void usart0_rx (void)
{ SREG&=0x7F;
  input=UDR0;           // interrupt 짧게  
  SREG|=0x80;
}

interrupt [EXT_INT4] void external_int4(void)
{  SREG&=0x7F;
  ext_int4_bit=1;           // interrupt 짧게  
  SREG|=0x80;
}

interrupt [TIM0_OVF] void timer_int0(void) 
{ TCNT0 = 100; // 초기값 재설정(0인 경우 생략가능)
  SREG&=0x7F;
  tim0_ovf=1;
  SREG|=0x80;

}

/*******************************************************************************/
void seg (U8 N){
 PORTB=((seg_pat[out[N]] & 0x70 ) | (PORTB & 0x0F)); 
 PORTD=((seg_pat[out[N]] & 0x0F) << 4) | (PORTD & 0x0F); 
 if (caps==1)PORTB|=0x08;
 PORTG=seg_pos[N];
}

void Putch(U8 data) // 한 바이트 송신
{
while((UCSR0A & 0x20) == 0x0); 

UDR0 = data; 
}

void main_menu (void)
{

 menu=string;
while((*menu!=0))Putch(*menu++);
}
