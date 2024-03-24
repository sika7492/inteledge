/*******************************************************************************/
 /* SSK_P_1_11014_1.c                  */
 /*                                    */
 /* Created: 2023-11-14 오전 11:38:54   */
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
    DDRC=0xFF;              //포트c출력
    PORTC=led;              //포트c초기값 
    
    TIMSK = 0x01;            //
    TCCR0=0x07;             //일반모드 
    TCNT0=37;               //
    SREG|=0x80;


while (1)
    {
    if(TIMER0_OVER_CNT==100){
        TIMER0_OVER_CNT=0;
        led=led<<1;
        led = led | 0x01; // 최하위 비트 set
        if(led == 0xFF) led = 0xFE; // 모두 off이면 초기값 재설정
        PORTC = led; 
      }//end of timer0
    }
}//end of main


interrupt [TIM0_OVF] void TIMER0_OVER (void)
{   TCNT0=37;       //초기값은 반듯이 서비스 루틴에 입력해야됨 
    SREG &=0x7F;   //글로벌 인터럽트 차단 
    TIMER0_OVER_CNT++  ;
    SREG |=0x80;  //글로벌 인터럽트 허용 
}






/*******************************************************************************/