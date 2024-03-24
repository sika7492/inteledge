
#include <mega128.h> 
#include <delay.h>
typedef unsigned char u_char;
const u_char seg_pat[10]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};


u_char tem[5]={0,0,0x2E,0,0x0D};
char *pStr; 
u_char N100, N10, N1;



int ad_val;

void AD_disp(int); // A/D 변환값 표시
void Putch(char data);
u_char tim1_ovf_bit=0;


void main(void)
{ 

DDRB = 0xF0; // 포트 B 상위 4비트 출력 설정
DDRD = 0xF0; // 포트 D 상위 4비트 출력 설정
DDRG = 0x0F; // 포트 G 하위 4비트 출력 설정
ADMUX = 0x07; // ADC6 단극성 입력 선택
ADCSRA = 0x87; // ADEN=1, ADSC=1, ADFR=1, 16MHz, 256분주 -> 125kHz
 
 TIMSK=0x04;
    
 TCCR1A=0x00;
 TCCR1B=0x04;    //div=256
 TCCR1C=0x00;
    
 TCNT1H=0x0B;
 TCNT1L=0xDC; 
 
 UCSR0A = 0x0; // USART 초기화 (251p)
UCSR0B = 0b00001000; // 송신 인에이블 TXEN = 1 (253p)
UCSR0C = 0b00000110; // 비동기[7], 데이터 8비트 모드 (253,4p)
UBRR0H = 0; // X-TAL = 16MHz 일때, BAUD = 9600
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

ad_val = (int)ADCL + ((int)ADCH << 8); // A/D값 읽기

}
AD_disp(ad_val); // A/D값 표시
delay_ms(2);





}
}


void AD_disp(int val) { 
float fval;
int ival, buf; 

fval = (float)val * 5.0 / 1023.0; // 전압값으로 변환
ival = (int)(fval * 1000.0 + 0.5); // 반올림 후 정수화
N100 = ival / 100; // 정수부 추출
buf = ival % 100; 
N10 = buf / 10; // 소수 첫째 자리 추출
N1 = buf % 10; // 소수 둘째 자리 추출
PORTG = 0b00001000; // PG3=1, 소수 둘째 자리
PORTD = ((seg_pat[N1] & 0x0F) << 4) | (PORTD & 0x0F);
PORTB = (seg_pat[N1] & 0x70 ) | (PORTB & 0x0F);
delay_ms(1);
PORTG = 0b00000100; // PG2=1, 소수 첫째 자리
PORTD = ((seg_pat[N10] & 0x0F) << 4) | (PORTD & 0x0F);
PORTB = (seg_pat[N10] & 0x70 ) | (PORTB & 0x0F);
PORTB = PORTB | 0x80; // DP on(소수점)  
delay_ms(1); 
PORTG = 0b00000010; // PG1=1, 정수부
PORTD = ((seg_pat[N100] & 0x0F) << 4) | (PORTD & 0x0F);
PORTB = (seg_pat[N100] & 0x70 ) | (PORTB & 0x0F); 

delay_ms(1);
}


interrupt [TIM1_OVF] void timer1_ovf(void)
{  SREG&=0x7F;
    tim1_ovf_bit=1;
   SREG|=0x80;
}

void Putch(char data) // 한 바이트 송신
{
while((UCSR0A & 0x20) == 0x0); //UDRE0[5] = 1 송신준비완료 될 때까지 대기
UDR0 = data; // 데이터 전송
} 