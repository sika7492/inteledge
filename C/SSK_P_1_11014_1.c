/*******************************************************************************/
 /* SSK_P_1_11014_1.c                  */
 /*                                    */
 /* Created: 2023-11-14 ���� 11:38:54   */
 /* Author: user                       */
 /*                                    */
/*******************************************************************************/
#include <mega128a.h>

typedef unsigned char U8;


U8 led=0xFE;
U8 TIMER0_OVER_CNT=0;





/*******************************************************************************/
void main(void)
{
    DDRC=0xFF;              //��Ʈc���
    PORTC=led;              //��Ʈc�ʱⰪ 
    
    TIMSK = 0x01;            //
    TCCR0=0x07;             //�Ϲݸ�� 
    TCNT0=37;               //
    SREG|=0x80;


while (1)
    {
    if(TIMER0_OVER_CNT==100){
        TIMER0_OVER_CNT=0;
        led=led<<1;
        led = led | 0x01; // ������ ��Ʈ set
        if(led == 0xFF) led = 0xFE; // ��� off�̸� �ʱⰪ �缳��
        PORTC = led; 
      }//end of timer0
    }
}//end of main


interrupt [TIM0_OVF] void TIMER0_OVER (void)
{   TCNT0=37;       //�ʱⰪ�� �ݵ��� ���� ��ƾ�� �Է��ؾߵ� 
    SREG &=0x7F;   //�۷ι� ���ͷ�Ʈ ���� 
    TIMER0_OVER_CNT++  ;
    SREG |=0x80;  //�۷ι� ���ͷ�Ʈ ��� 
}






/*******************************************************************************/