/**************************************************************************/
/* SSK_P_1_11017_2.c                                                      */
/*                                                                        */
/* Created: 2023-11-17 ���� 10:58:27                                       */
/* Author: user                                                           */
/**************************************************************************/

#include <mega128.h>
#include <delay.h>



void Putch(char); // �۽�
void main(void)
{ 
char string1[] = "No I can't forget this evening,\r";
char string2[] = "Or your face as you were leaving.\r";
char string3[] = "But I guess that's just the way The story goes.\r";
char string4[] = "You always smile but in your eyes.\r";
char string5[] = "Your sorrow shows Yes it shows. \r";
char string6[] = "No I can't forget tomorrow \r";
char string7[] = "When I think of all my sorrow \r";
char string8[] = "When I had you there \r";
char string9[] = "But then I let you go And now it's only fair. \r";
char string10[] = "That I should let you know What you should know\r";

char *pStr; // ���ڿ� ������
delay_ms(2000); // PC���� �޽��� Ȯ�� ����
UCSR0A = 0x0; // USART �ʱ�ȭ (251p)
UCSR0B = 0b00001000; // �۽� �ο��̺� TXEN = 1 (253p)
UCSR0C = 0b00000110; // �񵿱�[7], ������ 8��Ʈ ��� (253,4p)
UBRR0H = 0; // X-TAL = 16MHz �϶�, BAUD = 9600
UBRR0L = 103; // (257p) 
pStr = string1; 
while(*pStr != 0) Putch(*pStr++); // ���ڿ� ����
Putch(0x0D);
pStr = string2; 
while(*pStr != 0) Putch(*pStr++); // ���ڿ� ����
pStr = string3; 
while(*pStr != 0) Putch(*pStr++); // ���ڿ� ����
pStr = string4; 
while(*pStr != 0) Putch(*pStr++); // ���ڿ� ����
pStr = string5; 
while(*pStr != 0) Putch(*pStr++); // ���ڿ� ����
pStr = string6; 
while(*pStr != 0) Putch(*pStr++); // ���ڿ� ����
pStr = string7; 
while(*pStr != 0) Putch(*pStr++); // ���ڿ� ����
pStr = string8; 
while(*pStr != 0) Putch(*pStr++); // ���ڿ� ����
pStr = string9; 
while(*pStr != 0) Putch(*pStr++); // ���ڿ� ����
pStr = string10; 
while(*pStr != 0) Putch(*pStr++); // ���ڿ� ����
while(1); 
}
void Putch(char data) // �� ����Ʈ �۽�
{
while((UCSR0A & 0x20) == 0x0); //UDRE0[5] = 1 �۽��غ�Ϸ� �� ������ ���
UDR0 = data; // ������ ����
} 