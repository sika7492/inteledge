/*
 * SSK_1103_1.c
 *
 * Created: 2023-11-03 ���� 12:36:54
 * 
 * NAME: SONG_SI_KYEONG
 * 
 */

#include <mega128a.h>

void main(void)
{ DDRC = 0xFF; // ��ƮC ��� ����
PORTC = 0xFE; // ��Ʈ C 0x55(�Ǵ� 0101 0101) ���
while(1); 
}