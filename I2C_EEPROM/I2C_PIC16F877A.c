#include <pic16f877a.h>

#include"I2C_PIC16F877A.h"
#include"STD_Types.h"
#include"Utils.h"
#include "I2C_PIC16F877A_Local.h"
#define _XTAL_FREQ 16000000

void I2C_Master_Init(const uint32 baud)
{
    CLRPORT(SSPCON1);
    SSPCON1|=(1<<SSPM3)|(1<<SSPEN);/*enable serial port mode and master mode*/
    CLRPORT(SSPCON2);
    SSPADD = (_XTAL_FREQ/(4*baud))-1;/*I2C Bits per Second*/
    CLRPORT(SSPSTAT);  // (High Speed Mode, Disable SMBus)
    SETBIT(TRISC,3);//as input for SCL
    SETBIT(TRISC,4);//as input for SDA
}
void I2C_Master_Wait(void)
{
    while(GETBIT(SSPSTAT,S) ||   SSPCON2&0x1f);
    /*wait untill start bit flag is 1   */

}
void I2C_Master_Start(void)
{
    I2C_Master_Wait();
    SETBIT(SSPCON2,SEN);
}
void I2C_Master_Repeat_Start(void)
{
    I2C_Master_Wait();
    SETBIT(SSPCON2,RSEN);
}
void I2C_Master_Stop(void)
{
    I2C_Master_Wait();
    SETBIT(SSPCON2,PEN);
}
uint8 I2C_Master_Write(uint8 Data)
{
    I2C_Master_Wait();
    SSPBUF=Data;
    while(!GETBIT(PIE1,SSPIF));//wait to complete
    CLRBIT(PIE1,SSPIF);
    I2C_Master_Wait();
    return (GETBIT(SSPCON2,ACKSTAT));
}
uint8 I2C_Master_Read(void)
{
    I2C_Master_Wait();
    SETBIT(SSPCON2,RCEN);
    while(!GETBIT(PIE1,SSPIF));//wait to complete
    CLRBIT(PIE1,SSPIF);
    I2C_Master_Wait();
    return SSPBUF;
}
void I2C_ACK(void)
{
    CLRBIT(SSPCON2,ACKDT); // the data is found
    I2C_Master_Wait();
    SETBIT(SSPCON2,ACKEN);
}
void I2C_NACK(void)
{
    SETBIT(SSPCON2,ACKDT); // the data is found
    I2C_Master_Wait();
    SETBIT(SSPCON2,ACKEN);
}