/**********************************************************************************************/
/* project2.c                                                                          */
/*                                                                                            */
/* Created: 2023-11-20 ���� 12:13:58                                                           */
/* Author: SONG_SI_KYEONG                                                                               */
/*                                                                                            */
/**********************************************************************************************/
#include <mega128a.h>
#include <delay.h>

/**********************************************************************************************/

typedef unsigned char U8;
typedef unsigned short U16; 
typedef unsigned int U32;

const U8 seg_pat[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
const U8 set_seg[4] = {0x08,0x04,0x02,0x01};

U8 EINT4_FLAG_BIT=0;  
U8 EINT5_FLAG_BIT=0;  
U8 EINT6_FLAG_BIT=0;  
U8 EINT7_FLAG_BIT=0;

U8 TIM2_OVF_INT_BIT=0;
U8 tim1_comp_bit=0;

U32 ad6_val=0;
U32 ad7_tem=0;

U8 seg_dip_flag=0;
U8 timer1_cnt=0;
U8 TIM2_CNT=0;
U8 UART_RESULT_FLAG=0;

U8 i=0;

void segment(U8 N);

void number(U8 N1000, U8 N100, U8 N10, U8 N1);


void AD7_input(void);                    //TIM2_OVF�� ���� �۵��ϰ� AD7�� ���� �޾Ƶ��̰� AD7_disp�Լ��� �����Ű�� �Լ� 
void UART_AD6_PC (void);                 //TIM1_COMPA�� ���� �۵��ϰ� AD6�� ���� �޾Ƶ��̰� AD6_disp�Լ��� �����Ű�� �Լ� 
void AD7_disp(int val);                  //�޾Ƶ��� ad7�� ���� segment�� ǥ���ϴ� 
void AD6_disp(int val);                  //�޾Ƶ��� ad6�� ���� pc�� ǥ���ϴ� �Լ� 

void EINT4_timer2(void);
void EINT5_timer1(void);
void EINT6_timer3(void);
void EINT7_timer3(void);
void UART_enable(void);                   //UART�� ���۽�Ű�� �Լ�



//U8 UART_end[] = "end\r";
//U8 UART_start[] = "start\r";
//char *pstr;
//void Putch(char data); 
//void UART_unenable(void);

/**********************************************************************************************/

void main(void)
{   
    DDRC=0xFF;     //led set
    PORTC=0xFF;     //all led off
    
    DDRB|=0xF0;
    DDRD|=0xF0;
    DDRG|=0x0F;
    
    EIMSK = 0b11110000; // �ܺ� ���ͷ�Ʈ4 enable
    EICRB = 0b10111011; // �ܺ� ���ͷ�Ʈ4 level trigger 
    
    SREG|=0x80;

    for(i=0;i<100;i++)number(1,9,9,3); 
    for(i=0;i<100;i++)number(0,1,2,1);

while (1)
    {
        if(seg_dip_flag==0)number(0,1,2,1);
            else  AD7_disp(ad7_tem);
     
        AD7_input();
        UART_AD6_PC();

        if(EINT4_FLAG_BIT==1){        
                EINT4_FLAG_BIT=0;
                EINT4_timer2();   
        }//end of EINT4_FLAG
        
        if(EINT5_FLAG_BIT==1){
        
                EINT5_FLAG_BIT=0;
                EINT5_timer1();  
              
        }//end of EINT5_FLAG 
        
        if(EINT6_FLAG_BIT==1){
                EINT6_FLAG_BIT=0;
                EINT6_timer3();    
        }//end of EINT6_FLAG 
        
        if(EINT7_FLAG_BIT==1){
                EINT7_FLAG_BIT=0;
                EINT7_timer3();
        }//end of EINT7_FLAG   
        
       
        
        
        
    }//end of while
}//end of if
/**********************************************************************************************/
void segment(U8 N){
    
    PORTD = ((seg_pat[N] & 0x0F) << 4) | (PORTD & 0x0F);
    PORTB = (seg_pat[N] & 0x70 ) | (PORTB & 0x0F);
 
} // end of segment

/*void Putch(char data){ // �� ����Ʈ �۽�

        while((UCSR0A & 0x20) == 0x0); //UDRE0[5] = 1 �۽��غ�Ϸ� �� ������ ���
        UDR0 = data; // ������ ����
}// end of Putch 
*/
void number(U8 N1000, U8 N100, U8 N10, U8 N1){
    
           segment(N1000);
           PORTG=set_seg[3];
           delay_ms(5);
          
           segment(N100);
           PORTG=set_seg[2];
           delay_ms(5);
          
           segment(N10);
           PORTG=set_seg[1];
           delay_ms(5);
           
           segment(N1);
           PORTG=set_seg[0];
           delay_ms(5);
}//end of number

/**********************************************************************************************/
void AD7_disp(int val) { 
        
        float fVal;
        U32 iVal, buf;
        U8 V100, V10, V1; 

        fVal = (float)val * 5.0 / 1023.0; // ���а����� ��ȯ
        iVal = (int)(fVal * 1000.0 + 0.5); // �ݿø� �� ����ȭ
        V100 = iVal / 100; // ������ ����
        buf = iVal % 100; 
        V10 = buf / 10; // �Ҽ� ù° �ڸ� ����
        V1 = buf % 10; // �Ҽ� ��° �ڸ� ����

        PORTG = 0b00001000; // PG3=1, �Ҽ� ��° �ڸ�
        segment(V1);
        delay_ms(5);
        
        PORTG = 0b00000100;
        PORTB = 0x80;
        PORTD = 0x00;
        delay_ms(5);  
        
        PORTG = 0b00000010; // PG2=1, �Ҽ� ù° �ڸ�
        segment(V10); 
        delay_ms(5);
         
        PORTG = 0b00000001; // PG1=1, ������
        segment(V100);
        delay_ms(5); 
         
}//end of ad7_disp
void AD7_input(void){
   
   if(TIM2_OVF_INT_BIT==1){            //1ms*121 = 121ms
        TIM2_OVF_INT_BIT=0;
        TIM2_CNT++;
            
        if(TIM2_CNT==121){       
        
                ADMUX = 0x07; // ADC7 �ܱؼ� �Է� ����   
                ADCSRA = 0xE7;     //div 128  ,
                delay_us(300);     //200us �ϰ�� ������ �޾Ƶ����� ���� 
                ad7_tem =(int)ADCL + ((int)ADCH << 8);
                seg_dip_flag++;
                
                if(seg_dip_flag==10){          //10ȸ�ݺ�  1210ms
                        seg_dip_flag=0;               // ��¥ 
                        TCCR2=0x00;                   //Timer2 off                     
                 }//end of seg_dip_flag    
        }//end of ad7_input 
    
   }//TIM2_OVF_INT
    
   

}



void AD6_disp(int val) { 
        
        float fval;
        U32 ival, buf;
        U8 N100, N10, N1;

        fval = (float)val * 5.0 / 1023.0; // ���а����� ��ȯ
        ival = (int)(fval * 100.0 + 0.5); // �ݿø� �� ����ȭ
        N100 = ival / 100; // ������ ����
        buf = ival % 100; 
        N10 = buf / 10; // �Ҽ� ù° �ڸ� ����
        N1 = buf % 10; // �Ҽ� ��° �ڸ� ����
    
        UART_enable();
        
        while((UCSR0A & 0x20) == 0x0);
        UDR0=N100+0x30;
        while((UCSR0A & 0x20) == 0x0);
        UDR0='.';
        while((UCSR0A & 0x20) == 0x0);
        UDR0=N10+0x30;
        while((UCSR0A & 0x20) == 0x0);
        UDR0=N1+0x30;
        while((UCSR0A & 0x20) == 0x0);
        UDR0='V';
        while((UCSR0A & 0x20) == 0x0);
        UDR0=' ';
      
}// AD6_disp

void UART_AD6_PC (void){
       if(tim1_comp_bit==1){     //121ms*50   
            tim1_comp_bit=0; 
            timer1_cnt++; 
            if(timer1_cnt==50){           
                timer1_cnt=0;
                ADMUX = 0x06; // ADC6 �ܱؼ� �Է� ����
                ADCSRA = 0xC7;
                while((ADCSRA & 0x10) == 0); 
                ad6_val =(int)ADCL + ((int)ADCH << 8);
                UART_RESULT_FLAG++;
                AD6_disp(ad6_val); 
                if(UART_RESULT_FLAG==10){
                        UART_RESULT_FLAG%=10;  
                        TCCR1B=0x00;
                    }//end of if UART_RESULT_FLAG    
            }//end of if AD6_input_flag        
        }//end of if tim1_comp_bit      
} //end of UART_AD6_PC


void EINT4_timer2(void){

            TIMSK|=0x40;
            TCCR2=0x03;         //div=64
            TCNT2=6;            //1clock=1ms  1ms*121
            
}// end of eint4_timer2 


void EINT5_timer1(void){
            
            TIMSK=0x10;
            
            TCCR1A=0b00000000;       //CTC A
            TCCR1B=0b00001011;       //div 64
            TCCR1C=0x00;
            
            TCNT1H=0x00;
            TCNT1L=0x00;
            
            OCR1AH=0x76;              //0x7629 121ms
            OCR1AL=0x29;
            
}//end of eint5_timer1 
void EINT6_timer3(void){

            TCCR3A=0x82;   //0b10000010   A ����¸�� 
            TCCR3B=0x0D;   //0b00001101 mode 6  div 1024 
            TCCR3C=0x00;
             
            TCNT3H=0x00;
            TCNT3L=0x00; 
              
            OCR3AH=0x00;              //pwm 21%  108 =0x006C
            OCR3AL=0x6C;
            
            DDRE |= 0x08;            //pe3�� ��� 
            
            
}//end of eint6_timer3 

void EINT7_timer3(void){
            
            TCCR3A=0x82;   //0b10000010   A ����¸�� 
            TCCR3B=0b00000101;         //mode2 
            TCCR3C=0x00;
            
            TCNT3H=0x00;
            TCNT3L=0x00; 
            
            OCR3AH=0x00;              //pwm 21%  108 =0x006C
            OCR3AL=0x6C;
            DDRE |= 0x08;             //pe3�� ��� 
            
}//end of eint7_timer3

void UART_enable(void){
            UCSR0A = 0x00; // USART �ʱ�ȭ (251p)
            UCSR0B = 0b00001000; // �۽� �ο��̺� TXEN = 1 (253p)
            UCSR0C = 0b00000110; // �񵿱�[7], ������ 8��Ʈ ��� (253,4p)
            UBRR0H = 0; // X-TAL = 16MHz �϶�, BAUD = 9600
            UBRR0L = 103;
           
}// end of UART_enable

/*void UART_unenable(void){
            UCSR0A = 0x0;
            UCSR0B =0x00;
}// end of UART_unenable
*/
/**********************************************************************************************/

interrupt [EXT_INT4] void external_int4(void){ 
    
    SREG &= 0x7F; // All Interrupt disable    
    EINT4_FLAG_BIT=1;    
    SREG |= 0x80; // All Interrupt enable 
    
}//end of EXT_INT4

interrupt [EXT_INT5] void external_int5(void){ 
    
    SREG &= 0x7F; // All Interrupt disable    
    EINT5_FLAG_BIT=1;
    SREG |= 0x80; // All Interrupt enable
    
}//end of EXT_INT5

interrupt [EXT_INT6] void external_int6(void) { 
    
    SREG &= 0x7F; // All Interrupt disable
    EINT6_FLAG_BIT=1;
    SREG |= 0x80; // All Interrupt enable 
    
}//end of EXT_INT6

interrupt [EXT_INT7] void external_int7(void){ 
    
    SREG &= 0x7F; // All Interrupt disable
    EINT7_FLAG_BIT=1;
    SREG |= 0x80; // All Interrupt enable
    
}//end of EXT_INT7



interrupt [TIM2_OVF] void timer_ovf2(void){ 
    
    TCNT2 = 6;
    SREG &= 0x7F; // All Interrupt disable
    TIM2_OVF_INT_BIT=1;
    SREG |= 0x80; // All Interrupt enable

}//end of TIM2_OVF

interrupt [TIM1_COMPA] void timer1_compa(void){   

    TCNT1H=0x00;
    TCNT1L=0x00;
    SREG&=0x7F;
    tim1_comp_bit=1;
    SREG|=0x80;
}//end of TIM1_COMPA
 
