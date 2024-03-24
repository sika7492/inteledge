
#include <mega128.h> 
#include <delay.h>
typedef unsigned char u_char;
const u_char seg_pat[10]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};


u_char tem[5]={0,0,0x2E,0,0x0D};
char *pStr; 
u_char N100, N10, N1;



int ad_val;

void AD_disp(int); // A/D ��ȯ�� ǥ��
void Putch(char data);
u_char tim1_ovf_bit=0;


void main(void)
{ 

DDRB = 0xF0; // ��Ʈ B ���� 4��Ʈ ��� ����
DDRD = 0xF0; // ��Ʈ D ���� 4��Ʈ ��� ����
DDRG = 0x0F; // ��Ʈ G ���� 4��Ʈ ��� ����
ADMUX = 0x07; // ADC6 �ܱؼ� �Է� ����
ADCSRA = 0x87; // ADEN=1, ADSC=1, ADFR=1, 16MHz, 256���� -> 125kHz
 
 TIMSK=0x04;
    
 TCCR1A=0x00;
 TCCR1B=0x04;    //div=256
 TCCR1C=0x00;
    
 TCNT1H=0x0B;
 TCNT1L=0xDC; 
 
 UCSR0A = 0x0; // USART �ʱ�ȭ (251p)
UCSR0B = 0b00001000; // �۽� �ο��̺� TXEN = 1 (253p)
UCSR0C = 0b00000110; // �񵿱�[7], ������ 8��Ʈ ��� (253,4p)
UBRR0H = 0; // X-TAL = 16MHz �϶�, BAUD = 9600
UBRR0L = 103;
 
 SREG|=0x80;





delay_ms(5);
while(1)
{
ADCSRA = 0xC7;
if (tim1_ovf_bit==1){
tim1_ovf_bit=0;
tem[0]=N100+0x30;
tem[1]=N10+0x30;
tem[3]=N1+0x30;
pStr = tem;

while(*pStr != 0) Putch(*pStr++);

ad_val = (int)ADCL + ((int)ADCH << 8); // A/D�� �б�

}
AD_disp(ad_val); // A/D�� ǥ��
delay_ms(2);





}
}


void AD_disp(int val) { 
float fval;
int ival, buf; 

fval = (float)val * 5.0 / 1023.0; // ���а����� ��ȯ
ival = (int)(fval * 1000.0 + 0.5); // �ݿø� �� ����ȭ
N100 = ival / 100; // ������ ����
buf = ival % 100; 
N10 = buf / 10; // �Ҽ� ù° �ڸ� ����
N1 = buf % 10; // �Ҽ� ��° �ڸ� ����
PORTG = 0b00001000; // PG3=1, �Ҽ� ��° �ڸ�
PORTD = ((seg_pat[N1] & 0x0F) << 4) | (PORTD & 0x0F);
PORTB = (seg_pat[N1] & 0x70 ) | (PORTB & 0x0F);
delay_ms(1);
PORTG = 0b00000100; // PG2=1, �Ҽ� ù° �ڸ�
PORTD = ((seg_pat[N10] & 0x0F) << 4) | (PORTD & 0x0F);
PORTB = (seg_pat[N10] & 0x70 ) | (PORTB & 0x0F);
PORTB = PORTB | 0x80; // DP on(�Ҽ���)  
delay_ms(1); 
PORTG = 0b00000010; // PG1=1, ������
PORTD = ((seg_pat[N100] & 0x0F) << 4) | (PORTD & 0x0F);
PORTB = (seg_pat[N100] & 0x70 ) | (PORTB & 0x0F); 

delay_ms(1);
}


interrupt [TIM1_OVF] void timer1_ovf(void)
{  SREG&=0x7F;
    tim1_ovf_bit=1;
   SREG|=0x80;
}

void Putch(char data) // �� ����Ʈ �۽�
{
while((UCSR0A & 0x20) == 0x0); //UDRE0[5] = 1 �۽��غ�Ϸ� �� ������ ���
UDR0 = data; // ������ ����
} 