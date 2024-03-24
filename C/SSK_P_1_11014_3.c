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

#define CLK_HIGH    PORTD |= 0x01   // PD.0=1      
#define CLK_LOW     PORTD &= 0xFE   // PD.0=0
#define DAT_HIGH    PORTD |= 0x02   // PD.1=1
#define DAT_LOW     PORTD &= 0xFD   // PD.1=0
    
#define SCL_OUT     DDRD |= 0x01    // PD.0=1
#define SDA_IN      DDRD &= 0xFD    // PD.1=0
#define SDA_OUT     DDRD |= 0x02    // PD.1=1
#define N   10


typedef unsigned char U8;



/***************************************************************/
U8 EINT4_FLAG_BIT=0;  
U8 EINT5_FLAG_BIT=0;  
U8 EINT6_FLAG_BIT=0;  
U8 EINT7_FLAG_BIT=0;  

U8 TIMER2_COMPARE_INT_BIT =0;
U8 TIMER0_OVF_INT_BIT =0;

U8 BLINK2=0;
//U8 BLINK0=0;

U8 DEV_ADD_W=0xA0;                                                          // data address(256~511)= 0xA2 data address(512~1023)= 0xA4
U8 IIC_ADD=0xAA;                                                            // 어드레스 지정
U8 IIC_DAT=0x55;  
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
    
    while(1){ 
        SCL_OUT;                     
        SDA_OUT; 
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
            SW6=(SW6+1)%2;
            
        }
        if(EINT7_FLAG_BIT==1) {
            EINT7_FLAG_BIT=0;
            TCCR0 = 0x06; // 
            TCNT0 = 6; // OVF 4ms
            TIMSK |= 0x01;
            SW7=(SW7+1)%2;
                if(SW7==1)TCCR0=0;
        }
        
        if(SW6==1)byte_write();
        
        
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
        if(TIMER0_OVF_INT_BIT==125) {   //500ms
            TIMER0_OVF_INT_BIT=0;
            byte_write();
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

void IIC_START(void)
{
    DAT_HIGH;
    delay_us(6);
    CLK_HIGH; 
    delay_us(6);
    DAT_LOW;
    delay_us(6);
    CLK_LOW;
    delay_us(6);
    
}//end of IIC_START

void IIC_STOP(void)
{
    DAT_LOW;
    delay_us(6);
    CLK_HIGH;
    delay_us(6);
    DAT_HIGH;
    delay_us(6);
    CLK_LOW;
    delay_us(6);
    
}//end of IIC_STOP

/***************************************************************/
void Process_8data(U8 value)
{
    U8 i_8bit;
    U8 value_buffer;
    
    value_buffer=value; 
    
    for(i_8bit=0;i_8bit<7;i_8bit++){
        if((value_buffer&0x80)==0x80)
            DAT_HIGH;
        else
            DAT_LOW;
            
        delay_us(6);
        CLK_HIGH;
        delay_us(6);
        CLK_LOW;
        delay_us(6);  
        value_buffer<<=1; 
    
    }//end of for 
    
    if((value_buffer&0x80)==0x80)
            DAT_HIGH;
        else
            DAT_LOW;
            
        delay_us(6);
        CLK_HIGH;
        delay_us(6);
        CLK_LOW;
        delay_us(6); 
        
        if(value_buffer==0x80) DAT_LOW;           // data high 이면 ACK값이 clk이 high일때 입력받으므로  
        delay_us(6);                              // clk low 일때 데이터가 변경되는 파형모양을 위해 clk high 되기전 data 인위적으로로 low 해줌  
             
} //end of Process_8data




void ACK_write(void){               // ACK 함수 slave ->  master      
    U8 i;
    SDA_IN;
    CLK_HIGH;  
    
    for(i=10;i>0;i--){                       
        if((PIND & 0x02) == 0x00){
        i=1;
        PORTC=0xF1;
        }//end of if
        
        else PORTC=0xFE;//
          
    }//end of for
    
        delay_us(6);
        CLK_LOW;
        delay_us(6);
        SDA_OUT;

} //end of ACK_write

void byte_write(void)
{       
    IIC_START();
        Process_8data(DEV_ADD_W);
    ACK_write();
        Process_8data(IIC_ADD);
    ACK_write();
        Process_8data(IIC_DAT);
    ACK_write();
        IIC_STOP();
        
}//end of byte_write









