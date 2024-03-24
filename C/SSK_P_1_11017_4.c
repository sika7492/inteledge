/*
 * SSK_P_1_11017_3.c
 *
 * Created: 2023-11-17 오후 12:30:56
 * Author: user
 */

#include <mega128a.h>
#include <delay.h>


typedef unsigned char U8;

flash U8 seg_pat[16]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d,
0x07,0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

flash U8 seg_pos[4]={0x08,0x04,0x02,0x01};




U8 input=0;
U8 out[4]={0};

U8 ext_int4_bit=0;
U8 pos=0;
void Seg (U8 N);
void main(void)
{
    DDRB=0xF0;
    DDRD=0xF0;
    DDRG=0x0F;
    
    EIMSK=0xF0;
    EICRB=0xAA;
    
    
                //우측 세그먼트 
    
    UCSR0A=0x00;
    UCSR0B=0b00010000;    //
    UCSR0C=0x06;
    UBRR0H=0x00;              // 9600 bps
    UBRR0L=103;
    
    SREG|=0x80;
    

while (1){
    while ((UCSR0A&0x80)==0x0)
    {Seg(0);
    delay_ms(5);
    
    Seg(2);
    delay_ms(5);
    Seg(3);
    delay_ms(5);
    Seg(1);
    delay_ms(5);
     if (ext_int4_bit==1){
       ext_int4_bit=0;
       pos=(pos+1)%4;     
    }
    
    input=UDR0; 
    
    
    if((input>='0')&&(input<='9'))out[pos]=input-'0';
    else if ((input>='A')&&(input<='F'))out[pos]=input-'A'+10;
    else if ((input>='a')&&(input<='f'))out[pos]=input-'a'+10;  
   
    }                           
}
}

void Seg (U8 N)
{
PORTD =((seg_pat[out[N]] & 0x0F) << 4) | (PORTD & 0x0F); 
PORTB = (seg_pat[out[N]] & 0x70 ) | (PORTB & 0x0F);
if(pos==N)PORTB|=0x80;
PORTG=seg_pos[N];

   
}                        

interrupt [EXT_INT4] void external_int4 (void)
{  SREG&=0x7F;
   ext_int4_bit=1;
   SREG|=0x80;
   
}