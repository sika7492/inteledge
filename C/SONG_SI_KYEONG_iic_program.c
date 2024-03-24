/***************************************************************/
/* SONG_SI_KYEONG_iic_program.c                                */
/* NAME: SONG_SI_KEYEONG                                       */
/* Created: 2023-11-08 오후 1:20:17                             */
/*                                                             */
/***************************************************************/


#include <mega128a.h>
#include <delay.h>

#define CLK_HIGH    PORTD |= 0x01   // PD.0=1      
#define CLK_LOW     PORTD &= 0xFE   // PD.0=0
#define DAT_HIGH    PORTD |= 0x02   // PD.1=1
#define DAT_LOW     PORTD &= 0xFD   // PD.1=0
    
#define SCL_OUT     DDRD |= 0x01    // PD.0=1
#define SDA_IN      DDRD &= 0xFD    // PD.1=0
#define SDA_OUT     DDRD |= 0x02    // PD.1=1
//#define N   10

typedef unsigned char U8;

/***************************************************************/

U8 N=10;
U8 DEV_ADD_W=0xA0;                                                          // data address(256~511)= 0xA2 data address(512~1023)= 0xA4
U8 DEV_ADD_R=0xA1;                                                          // data address(256~511)= 0xA3 data address(512~1023)= 0xA5 
U8 IIC_ADD=0xAA;                                                            // 어드레스 지정
U8 IIC_DAT=0x55;                                                            // 데이터값 �
//U8 IIC_ADD_ARRAY[10]={0,0x01,0x02,0x03,0x05,0x06,0x07,0x0A,0x0B,0x0D};    // 주소 배열
U8 IIC_DAT_ARRAY[N]={0,0xFF,0,0xFF,0,0xFF,0,0xFF,0,0xFF};                 // 데이터값 배열



U8 old_sw,new_sw;
U8 READ_DATA=0;

void IIC_START(void);
void IIC_STOP(void);

void Process_8data(U8 value);
void Process_8data_read(void);

void ACK_write(void);
void no_ACK(void);
void ACK_read(void);


void byte_write(void);
void Page_write(void);
void byte_read(void);
void Page_read(void);


/***************************************************************/
void main(void)           
{   
    DDRC=0xFF;  
    PORTC=0xAA;
    DDRE=DDRE&0x0F;
    
    SCL_OUT;                     
    SDA_OUT;                            
    
    
    while(1){ 
    
    new_sw=PINE&0xF0;
    
    if((old_sw==0xF0)&(new_sw==0xE0))byte_write();    
    if((old_sw==0xF0)&(new_sw==0xD0))Page_write();      
    if((old_sw==0xF0)&(new_sw==0xB0))byte_read();
    if((old_sw==0xF0)&(new_sw==0x70))Page_read();
    
    
    old_sw=new_sw;
    delay_us(200);
       
    }//end of while    
}//end of main
    


/***************************************************************/
void IIC_START(void)
{
    DAT_HIGH;
    delay_us(6);
    CLK_HIGH; 
    delay_us(6);
    DAT_LOW;
    delay_us(6);
    CLK_LOW;
    delay_us(6);
    
}//end of IIC_START

void IIC_STOP(void)
{
    DAT_LOW;
    delay_us(6);
    CLK_HIGH;
    delay_us(6);
    DAT_HIGH;
    delay_us(6);
    CLK_LOW;
    delay_us(6);
    
}//end of IIC_STOP

/***************************************************************/
void Process_8data(U8 value)
{
    U8 i_8bit;
    U8 value_buffer;
    
    value_buffer=value; 
    
    for(i_8bit=0;i_8bit<7;i_8bit++){
        if((value_buffer&0x80)==0x80)
            DAT_HIGH;
        else
            DAT_LOW;
            
        delay_us(6);
        CLK_HIGH;
        delay_us(6);
        CLK_LOW;
        delay_us(6);  
        value_buffer<<=1; 
    
    }//end of for 
    
    if((value_buffer&0x80)==0x80)
            DAT_HIGH;
        else
            DAT_LOW;
            
        delay_us(6);
        CLK_HIGH;
        delay_us(6);
        CLK_LOW;
        delay_us(6); 
        
        if(value_buffer==0x80) DAT_LOW;           // data high 이면 ACK값이 clk이 high일때 입력받으므로  
        delay_us(6);                              // clk low 일때 데이터가 변경되는 파형모양을 위해 clk high 되기전 data 인위적으로로 low 해줌  
             
} //end of Process_8data



void Process_8data_read(void)
{
    U8 i, TEMP_READ_DATA = 0;
    SDA_IN;

    for (i = 0; i < 8; i++)
    {
        CLK_LOW;
        delay_us(6);
        CLK_HIGH;                  // slave에서 이구간에서 data를 주기 떄문에 우리는 low에서 데이터값을 입력받는다.
        delay_us(12);
        CLK_LOW;
        TEMP_READ_DATA = (PIND & 0x02 == 0x00) ? 0x00 : 0x80;
        TEMP_READ_DATA >>= i;
        READ_DATA |= TEMP_READ_DATA; 
        delay_us(6);
        
    } // end of for   
    
} //end of Process_8data_read

/***************************************************************/


void ACK_write(void){               // ACK 함수 slave ->  master      
    U8 i;
    SDA_IN;
    CLK_HIGH;  
    
    for(i=10;i>0;i--){                       
        if((PIND & 0x02) == 0x00){
        i=1;
        PORTC=0xF1;
        }//end of if
        
        else PORTC=0xFE;//
          
    }//end of for
    
        delay_us(6);
        CLK_LOW;
        delay_us(6);
        SDA_OUT;

} //end of ACK_write

void ACK_read(void){     // ACK 함수  master -> slave

    SDA_OUT;              // 데이터 출력
    DAT_LOW;              // master 데이터를 주어야하기떄문에 직접 데이터를 low로 한다
    CLK_HIGH;  
    delay_us(12);
    CLK_LOW; 
    delay_us(6);   

}//end of ACK_read

void no_ACK(void){

    SDA_OUT;        // 데이터 출력
    DAT_HIGH;       // master 데이터를 주어야하기떄문에 직접 데이터를 high로 한다.
    CLK_HIGH;  
    delay_us(12);
    CLK_LOW; 
    delay_us(6); 

}//end of no_ACk






/***************************************************************/

void byte_write(void)
{       
    IIC_START();
        Process_8data(DEV_ADD_W);
    ACK_write();
        Process_8data(IIC_ADD);
    ACK_write();
        Process_8data(IIC_DAT);
    ACK_write();
        IIC_STOP();
        
}//end of byte_write

void Page_write(void){


    IIC_START();
        Process_8data(DEV_ADD_W);
    ACK_write();
        Process_8data(IIC_ADD);
    ACK_write();
        for(N=0;N<10;N++){                   
            Process_8data(IIC_DAT_ARRAY[N]);
            ACK_write();
        } //end of  for 
    
    IIC_STOP();
        
}

/*void Page_write(void)
{   U8 n,m;
    
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
                }//end of if             
            }//end of  for               
        IIC_STOP();
        } //end of  for 
}            
*///end of byte_array_write

void byte_read(void)
{   
    IIC_START();
        Process_8data(DEV_ADD_W);
    ACK_write();
        Process_8data(IIC_ADD);
    ACK_write();
    IIC_START();
        Process_8data(DEV_ADD_R);
    ACK_write();
        Process_8data_read();
    no_ACK();
    IIC_STOP();
    
}// end of byte_read

void Page_read(void)
{   U8 n;

    IIC_START();
        Process_8data(DEV_ADD_W);
    ACK_write();
        Process_8data(IIC_ADD);
    ACK_write();
    IIC_START();
        Process_8data(DEV_ADD_R);
    ACK_write();
        for(n=0;n<10;n++){
            Process_8data_read();
            if(n<9)ACK_read();
        }//end of for
    no_ACK();
    IIC_STOP();
    
}// end of byte_array_read


