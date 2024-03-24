/*
 * SSK_1103_1.c
 *
 * Created: 2023-11-03 오후 12:36:54
 * 
 * NAME: SONG_SI_KYEONG
 * 
 */

#include <mega128a.h>

void main(void)
{ DDRC = 0xFF; // 포트C 출력 설정
PORTC = 0xFE; // 포트 C 0x55(또는 0101 0101) 출력
while(1); 
}