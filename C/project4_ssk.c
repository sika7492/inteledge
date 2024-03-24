/*
 * project4_ssk.c
 *
 * Created: 2023-11-22 ¿ÀÈÄ 2:30:05
 * Author: user
 */

#include <mega128a.h>
#include <delay.h>

typedef unsigned char U8;
typedef unsigned short U16; 
typedef unsigned int U32;

const U16 volt_set[21]={0x0000,0x001A,0x0033,0x004C,0x0066,0x0080,0x009A,0x00B3,0x00CD,0x00E6,0X00FF,0x00E6,0x00CD,0x00B3,0x009A,0x0080,0x0066,0x004C,0x0033,0x001A,0x0000};


#define CLK_HIGH    PORTD |= 0x01   // PD.0=1      
#define CLK_LOW     PORTD &= 0xFE   // PD.0=0
#define DAT_HIGH    PORTD |= 0x02   // PD.1=1
#define DAT_LOW     PORTD &= 0xFD   // PD.1=0

#define LD_HIGH     PORTD |= 0x04   // PD.2=1
#define LD_LOW      PORTD &= 0xFB   // PD.2=0


#define SCL_OUT     DDRD |= 0x01    // PD.0=1
#define SDA_IN      DDRD &= 0xFD    // PD.1=0
#define SDA_OUT     DDRD |= 0x02    // PD.1=1
#define LD_OUT      DDRD |= 0x04    // PD.2=1



U8 i,j;
U16 value_buffer;

U8 EINT4_FLAG_BIT=0;
void Process_DAC(void);

void main(void)
{    
    DDRC=0xFF;
    PORTC=0xFF;
    
    SCL_OUT;
    SDA_OUT;
    LD_OUT;
    

    EIMSK |= 0b00010000;
    EICRB |= 0b00000011; 
    SREG|= 0x80;

while (1)
    {   
        CLK_HIGH;
        LD_HIGH;         //
        if(EINT4_FLAG_BIT==1){        
               
                EINT4_FLAG_BIT=0;
                Process_DAC();
                delay_us(6);  //Tldh
                 
        }//end of EINT4_FLAG


    }//end of while
}//end of main



interrupt [EXT_INT4] void external_int4(void){ 
    
    SREG &= 0x7F; // All Interrupt disable    
    EINT4_FLAG_BIT=1;    
    SREG |= 0x80; // All Interrupt enable 
    
}//end of EXT_INT4


void Process_DAC(void)
{
    
    for(i=0;i<21;i++)   {
    value_buffer=volt_set[i];
    LD_LOW;
    CLK_LOW; 
         
        for(j=0;j<9;j++){
            if((value_buffer&0x0200)==0x0200) DAT_HIGH;  
            else DAT_LOW;
                
            value_buffer<<=1;
            delay_us(6);         
            CLK_HIGH;
            delay_us(12);            
            CLK_LOW;    
            delay_us(6);      
    
        }//end of for 
    LD_HIGH;
    }//end of for
}



