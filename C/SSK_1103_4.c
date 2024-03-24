/*
 * SSK_1103_4.c
 *
 * Created: 2023-11-03 ¿ÀÈÄ 3:10:27
 * Author: user
 */

#include <mega128a.h>


unsigned char led[8]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};

void main(void)
{
    unsigned char old_sw,new_sw,i;
   i=0;
   old_sw=0;
   new_sw=0;

    DDRC=0xFF;
    DDRE= DDRE&0x0F;
    PORTC=0xFF;
  
    while (1){
        new_sw=PINE&0x10;
        
        if((old_sw !=0) && (new_sw ==0)){
            i=(i+1)%8;
            PORTC=led[i];}   //end of if
            else if ((old_sw ==0) && (new_sw !=0)){
            i=(i+2)%8;
            PORTC=led[i];
         }//end of else if 
        
      
     old_sw=new_sw;       
} //end of whule 
}  //end of main 
