/*
 * SSK_P_1_1107_2.c
 *
 * Created: 2023-11-07 오후 1:20:17
 * NAME: SONG_SI_KEYEONG
 */

#include <mega128a.h>
#include <delay.h>
           


#define CLK_HIGH PORTD|=0x01 //  PD.0=1
#define CLK_LOW PORTD&=0xFE  //  PD.0=0
#define DAT_HIGH PORTD|=0x02 //   PD.1=1
#define DAT_LOW PORTD|=0xFD //  PD.1=0

#define SCL_OUT DDRD|=0x01 // 
#define SDA_IN DDRD|=0xFD  //
#define SDA_OUT DDRD|=0x02 //

typedef unsigned char U8;


U8 DEV_ADD_W=0xA0  ;   // data address(256~511)= 0xA2 data address(512~1023)= 0xA4 
U8 IIC_ADD=0;  // 임의값
//U8 IIC_ADD_ARRAY[10]={0,0x01,0x02,0x03,0x05,0x06,0x07,0x0A,0x0B,0x0D};
U8 IIC_DAT=0;  // 임의값
//U8 IIC_DAT_ARRAY[10]={0,0x01,0x02,0x03,0x05,0x06,0x07,0x0A,0x0B,0x0D};
//U8 DEV_ADD_R=0xA1; // data address(256~511)= 0xA3 data address(512~1023)= 0xA5

//U8 old_sw,new_sw;



void IIC_START(void);
void IIC_STOP(void);
void ACK_write(void);
//void ACK_no(void);

void Process_8data(U8 value);
//void Process_8data_READ(U8 value);



void main(void)
{   //U8 n,m;
    DDRC=0xFF;
    PORTC=0xFF;
    DDRE=DDRE&0x0F;
    
    SCL_OUT;
    SDA_OUT;
    
    //old_sw=0;
    //new_sw=0;
    
    
while(1)
   {
	//new_sw=PINE&0xF0;
	//if ((old_sw==0xF0)&(new_sw==0xE0)){   //Q1
	
		IIC_START();
		Process_8data(DEV_ADD_W);
		ACK_write();
		Process_8data(IIC_ADD);
		ACK_write();
		Process_8data(IIC_DAT);
		ACK_write();
		IIC_STOP();
    delay_ms(100);    
	}										//end of if (4_sw)
/*	
	if ((old_sw==0xF0)&(new_sw==0xD0)){ //Q2
		for(n=0;n<10;n++){
			
		IIC_START();
		Process_8data(DEV_ADD_W);
		ACK_write();
		Process_8data(IIC_ADD_ARRAY[n]);
		ACK_write();
		Process_8data(IIC_DAT_ARRAY[n]);
		ACK_write();
			for(m=n;m<10;m++){
				if ((IIC_ADD_ARRAY[n]+0x01)==IIC_ADD_ARRAY[n+1]){
					n++;
					Process_8data(IIC_DAT_ARRAY[n]);
					ACK_write();
				}				//end of if
			}				//end of for
		IIC_STOP();
		}					//end of for 
	}				//end of if (5_sw)
*/	
/*	if ((old_sw==0xF0)&(new_sw==0xB0)){ //Q3 
		IIC_START();
			Process_8data(DEV_ADD_W);
		ACK_write();
			Process_8data(IIC_ADD);
		ACK_write();
			Process_8data(DEV_ADD_R);
		ACK_write();	
		    Process_8data_READ(IIC_ADD);
			ACK_no(); 
        IIC_STOP();
	
	
	
	
	}// end of if(6_sw)
*/
//old_sw=new_sw;
	
	

    //}// end of while 
}//end of main
                                     
    


void IIC_START(void){
    
    DAT_HIGH;
     
    CLK_HIGH;  
    DAT_LOW;  
    delay_us(6);
    CLK_LOW;  
    delay_us(6);

}//end of IIC_START

void IIC_STOP(void){
    
    DAT_LOW;  
    CLK_HIGH; 
    DAT_HIGH;
    delay_us(6); 
    CLK_LOW;
    delay_us(6);

}//end of IIC_STOP



void Process_8data(U8 value){
    U8 i_8bit;
    U8 value_buffer;
    
    value_buffer=value;
            for(i_8bit=0;i_8bit<8;i_8bit++)
            {    
                if((value_buffer&0x80)==0x80)
                    DAT_HIGH;  // 76543210 순으로 데이터값을 읽어온다
                else DAT_LOW; 
                
                                   
                        CLK_HIGH;
                        delay_us(6);
                        CLK_LOW;
                        delay_us(6);
                        value_buffer<<=1;    
            } //end of for

} //end of Process_8data


/*void Process_8data_READ(U8 value){    
U8 i_8bit;
U8 value_buffer;  
    SDA_IN;
   
    
    &value_buffer=*value;
            for(i_8bit=0;i_8bit<8;i_8bit++)
            {    
                if((value_buffer&0x80)==0x80)
                    DAT_HIGH;  
                else
                    DAT_LOW;
                        
                        CLK_HIGH;
                        delay_us(1);
                        CLK_LOW;
                        value_buffer<<=1;    
            } //end of for
    SDA_OUT;



}//end of Process_8data_READ
*/



void ACK_write(void){
    U8 i;
    
    
    SDA_IN;
    CLK_HIGH;
    for(i=0;i<50;i++)
    {
     if((PIND&0x02)==0x00){
        PORTC=0xFE;
        i=10;
        }//end if
    else PORTC=0xAA;

    }//end of for
     delay_us(6);
     CLK_LOW;
     delay_us(6);
     SDA_OUT;

}//end of ACK_write


/*void ACK_no(void){
U8 i;
    
    SDA_OUT;
    CLK_HIGH;
    for(i=0;i<50;i++)
    {
     if((PORTD&0x02)==0x02){
        PORTC=0xFE;
        i=10;
        }
    else PORTC=0xAA;
    }
     delay_us(1);    
     CLK_LOW;
     SDA_OUT;
}
*/

