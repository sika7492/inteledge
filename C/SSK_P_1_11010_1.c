#include <mega128.h>
#include <delay.h>
const unsigned char seg_pat[10]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
void seg(unsigned char N);
unsigned char num = 0;
void main(void)
{ 
unsigned char oldkey, key, num = 0;
DDRB = 0xF0; // ��Ʈ B ���� 4��Ʈ ��� ����
DDRD = 0xF0; // ��Ʈ D ���� 4��Ʈ ��� ����
DDRG = 0x0F; DDRE = 0x00; // ��Ʈ G ���� 4��Ʈ ��� ����, ��Ʈ E �Է¼���
PORTG = 0b00001000; // �� ���� 7-Segment DIG4 ON(PG3=1)
PORTB = 0x0; // E, F, G, DP off
PORTD = 0x0; // A, B, C, D off
oldkey = PINE & 0b11110000; // SW1~4 ���¸� ����
while(1){
PORTG = 0b00001000; 
seg(num%10);
delay_ms(5);
if (num>10)
{PORTG = 0b00000100; 
seg(num/10);
delay_ms(5);}
key = PINE & 0b11110000; // SW1~4 ���¸� ����
if(oldkey == 0xF0 && key == 0xE0){ // ���� ���� OFF, �� ���� ON ? 
num = (num + 1)% 100; // num�� 1���� (9 ������ 0)
}
if(oldkey == 0xF0 && key == 0xD0){ // ���� ���� OFF, �� ���� ON ? 
num = (num - 1) % 100; // num�� 1���� (9 ������ 0)
} 
if(oldkey == 0xF0 && key == 0xB0){ // ���� ���� OFF, �� ���� ON ? 
num = (num + 2) % 100; // num�� 1���� (9 ������ 0)
} 
if(oldkey == 0xF0 && key == 0x70){ // ���� ���� OFF, �� ���� ON ? 
num = (num - 2) % 100; // num�� 1���� (9 ������ 0)
} 
oldkey = key; // ���� ���� <- ������ 

}
}

void seg(unsigned char N){
PORTD = ((seg_pat[N] & 0x0F) << 4) | (PORTD & 0x0F); // A, B, C, D ǥ��
PORTB = (seg_pat[N] & 0x70 ) | (PORTB & 0x0F); // E, F, G ǥ��
}

void  KEY(char N){
n=0;

key = PINE & 0b11110000; // SW1~4 ���¸� ����
if(oldkey == 0xF0 && key == 0xE0){ // ���� ���� OFF, �� ���� ON ? 
num = (num + 1)% 100; // num�� 1���� (9 ������ 0)
}
if(oldkey == 0xF0 && key == 0xD0){ // ���� ���� OFF, �� ���� ON ? 
num = (num - 1) % 100; // num�� 1���� (9 ������ 0)
} 
if(oldkey == 0xF0 && key == 0xB0){ // ���� ���� OFF, �� ���� ON ? 
num = (num + 2) % 100; // num�� 1���� (9 ������ 0)
} 
if(oldkey == 0xF0 && key == 0x70){ // ���� ���� OFF, �� ���� ON ? 
num = (num - 2) % 100; // num�� 1���� (9 ������ 0)
} 

}