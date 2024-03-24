#include <mega128.h>
#include <delay.h>
const unsigned char seg_pat[10]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
void seg(unsigned char N);
unsigned char num = 0;
void main(void)
{ 
unsigned char oldkey, key, num = 0;
DDRB = 0xF0; // 포트 B 상위 4비트 출력 설정
DDRD = 0xF0; // 포트 D 상위 4비트 출력 설정
DDRG = 0x0F; DDRE = 0x00; // 포트 G 하위 4비트 출력 설정, 포트 E 입력설정
PORTG = 0b00001000; // 맨 우측 7-Segment DIG4 ON(PG3=1)
PORTB = 0x0; // E, F, G, DP off
PORTD = 0x0; // A, B, C, D off
oldkey = PINE & 0b11110000; // SW1~4 상태만 추출
while(1){
PORTG = 0b00001000; 
seg(num%10);
delay_ms(5);
if (num>10)
{PORTG = 0b00000100; 
seg(num/10);
delay_ms(5);}
key = PINE & 0b11110000; // SW1~4 상태만 추출
if(oldkey == 0xF0 && key == 0xE0){ // 먼저 상태 OFF, 현 상태 ON ? 
num = (num + 1)% 100; // num값 1증가 (9 다음은 0)
}
if(oldkey == 0xF0 && key == 0xD0){ // 먼저 상태 OFF, 현 상태 ON ? 
num = (num - 1) % 100; // num값 1증가 (9 다음은 0)
} 
if(oldkey == 0xF0 && key == 0xB0){ // 먼저 상태 OFF, 현 상태 ON ? 
num = (num + 2) % 100; // num값 1증가 (9 다음은 0)
} 
if(oldkey == 0xF0 && key == 0x70){ // 먼저 상태 OFF, 현 상태 ON ? 
num = (num - 2) % 100; // num값 1증가 (9 다음은 0)
} 
oldkey = key; // 먼저 상태 <- 현상태 

}
}

void seg(unsigned char N){
PORTD = ((seg_pat[N] & 0x0F) << 4) | (PORTD & 0x0F); // A, B, C, D 표시
PORTB = (seg_pat[N] & 0x70 ) | (PORTB & 0x0F); // E, F, G 표시
}

void  KEY(char N){
n=0;

key = PINE & 0b11110000; // SW1~4 상태만 추출
if(oldkey == 0xF0 && key == 0xE0){ // 먼저 상태 OFF, 현 상태 ON ? 
num = (num + 1)% 100; // num값 1증가 (9 다음은 0)
}
if(oldkey == 0xF0 && key == 0xD0){ // 먼저 상태 OFF, 현 상태 ON ? 
num = (num - 1) % 100; // num값 1증가 (9 다음은 0)
} 
if(oldkey == 0xF0 && key == 0xB0){ // 먼저 상태 OFF, 현 상태 ON ? 
num = (num + 2) % 100; // num값 1증가 (9 다음은 0)
} 
if(oldkey == 0xF0 && key == 0x70){ // 먼저 상태 OFF, 현 상태 ON ? 
num = (num - 2) % 100; // num값 1증가 (9 다음은 0)
} 

}