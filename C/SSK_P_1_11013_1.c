/*                                    */
/* SSK_P_1_11013_1.c                  */
/*                                    */
/* Created: 2023-11-13 오전 11:36:26   */
/* Author: user                       */
/*                                    */

/*************************************************************************************/
#include <mega128a.h>
#include <delay.h>



typedef unsigned char U8;



const U8 seg_pat[10]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

/*************************************************************************************/
//U8 led = 0xFE;
U8 EINT4_FLAG_BIT=0;
U8 EINT5_FLAG_BIT=0;
U8 EINT6_FLAG_BIT=0;
U8 EINT7_FLAG_BIT=0;
U8 num[5]={0};
U8 time=0;


U8 POS=0;

void seg(U8 N);
void Seg_count(U8 N);
void time_count(void);
/*************************************************************************************/
void main(void)
{
DDRB |= 0xF0;
DDRD |= 0xF0; 
DDRG |= 0x0F; 


SREG|=0x80;

EIMSK=0xF0;

EICRB=0b10101010;//0xEE

/*************************************************************************************/

while (1)
    {    
    
    
        Seg_count(3);
        Seg_count(2);
        Seg_count(1);
        Seg_count(0);
        time++;
        
        if(time>49){
            time=0;
            num[4]++;    
           }// end of if                         
               
        
       
        if(EINT4_FLAG_BIT==1){
            EINT4_FLAG_BIT=0;
           num[POS]++;
           
    
        }//end of FLAG4 
        if(EINT5_FLAG_BIT==1){
            EINT5_FLAG_BIT=0;
            POS=(POS+1)%4;
   
        }//end of FLAG5

        if(EINT6_FLAG_BIT==1){
            EINT6_FLAG_BIT=0;
            if(num[POS]>0)num[POS]--;
         }//end of FLAG6

        if(EINT7_FLAG_BIT==1){
            EINT7_FLAG_BIT=0;
            
           
         }//end of FLAG7

       time_count();              //
       
        
    } //end of while
} //end of main




/*************************************************************************************/


interrupt [EXT_INT4] void external_int4(void) 
{ 
        SREG &= 0x7F; // All Interrupt disable
    EINT4_FLAG_BIT=1;
        SREG |= 0x80; // All Interrupt enable
}

interrupt [EXT_INT5] void external_int5(void) 
{ 
        SREG &= 0x7F; 
    EINT5_FLAG_BIT=1;
        SREG |= 0x80; 
}

interrupt [EXT_INT6] void external_int6(void) 
{ 
        SREG &= 0x7F; 
    EINT6_FLAG_BIT=1;
        SREG |= 0x80; 
}

interrupt [EXT_INT7] void external_int7(void) 
{ 
        SREG &= 0x7F; 
    EINT7_FLAG_BIT=1;
        SREG |= 0x80; 
}


/*************************************************************************************/


void seg(U8 N){
PORTD = ((seg_pat[N] & 0x0F) << 4) | (PORTD & 0x0F); // A, B, C, D 표시
PORTB = (seg_pat[N] & 0x70 ) | (PORTB & 0x0F); // E, F, G 표시
}

void Seg_count(U8 N){
    
    U8 SEG[4]={0x08,0x04,0x02,0x01};
     PORTG=SEG[N];
            seg(num[N]);
            if(POS == N){ 
                PORTB |= 0x80;
                }                 //end POS위치 체크                           
            delay_ms(5);
     


 } //end of Seg_count 
 
void time_count(void){
    
            if(num[4]>60){
                num[4]=0;
                num[0]++;
            }             //sec  
            if (num[0]>9){
                    num[0]=0;
                    num[1]++;
            }             //min 
            if (num[1]>5){
                    num[1]=0;
                    num[2]++;
            }             //10min
            if (num[2]>9){
                    
                    num[2]=0;
                    num[3]++;
            }              //1hour
            
            if (num[3]==2){
                if(num[2]>4){
                    num[2]=0;
                    num[3]++;
                    if((num[1]+num[0])!=0){
                        num[2]=0;
                        num[3]=0;
                    }//24시간이면 
              }//20시간이 넘는다면 4시간만 표시      
            
            }// 10시간
            if (num[3]>2)num[3]=0;  
    
    }