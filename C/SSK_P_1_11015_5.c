/*
 * SSK_P_1_11015_5.c
 *
 * Created: 2023-11-15 ¿ÀÈÄ 4:21:36
 * Author: user
 */

#include <mega128a.h>
#include <delay.h>



typedef unsigned char U8;
typedef unsigned int U16;

const U8 seg_pat[10]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
const U8 set_seg[4]={0x08,0x04,0x02,0x01};
U8 TIMER1_OVF_INT_BIT=0;
U8 ext_int5_bit=0;
U8 ext_int4_bit=0;
U8 min=0;
U8 min10=0;
U8 hour=0;
U8 hour10=0;
U8 POS=0;
U8 time=0x0BDC;

void time_cnt (void);
void segment(U8 N);

void main(void)
{

    DDRB=0xF0;
    DDRD=0xF0;
    DDRG=0x0F;
    
    EIMSK=0x30;
    EICRB=0x0A;
    
    TIMSK=0x04;
    
    TCCR1A=0x00;
    TCCR1B=0x04;    //div=256
    TCCR1C=0x00;
    
    TCNT1H=(time|0xFF00)>>8;
    TCNT1L=(time|0x00FF);
    
    SREG|=0x80;
    
    
while (1)
    {  segment(min);
       
      
       
       if (ext_int4_bit==1)
       {   ext_int4_bit=0;
           if(POS==0)min++;
            else if (POS==1) min10++;
                else if (POS==2) hour++;
                    else if (POS==3) hour10++;
    
       } //sw4
       
       if (ext_int5_bit==1)
       {   ext_int5_bit=0;
           POS=(POS+1)%4;
       
     
       } //sw5
       
       
       if(TIMER1_OVF_INT_BIT==60){
             TIMER1_OVF_INT_BIT=0;
             min++;
        }//end of time1_ovf 
        
      //time_cnt(); 
       
       
       
       
    }
}




 
 void segment(U8 N){
 PORTD = ((seg_pat[N] & 0x0F) << 4) | (PORTD & 0x0F);
 PORTB = (seg_pat[N] & 0x70 ) | (PORTB & 0x0F);


 }
 






