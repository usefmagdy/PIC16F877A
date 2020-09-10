#include"EEPROM_PIC16F877A.h"
#include"STD_Types.h"
#include"Utils.h"
#include"I2C_PIC16F877A.h"
#include "EEPROM_PIC16F877A_Local.h"

void EEPROM_Write_I2C_Byte(uint16 Address,uint8 Data)
{
    I2C_Master_Start();
    while(I2C_Master_Write(EEPROM_ADD_WRITE))//slave address
        I2C_Master_Repeat_Start();
    I2C_Master_Write(Address>>8);/*sending the high order of the address*/
    I2C_Master_Write((uint8)Address);/*sending the lower order of address*/
    I2C_Master_Write(Data);
    I2C_Master_Stop();
}
uint8 EEPROM_Read_I2C_Byte(uint16 Address)
{
    uint8 Data;
     I2C_Master_Start();
    while(I2C_Master_Write(EEPROM_ADD_WRITE))//slave address
        I2C_Master_Repeat_Start();
    I2C_Master_Write(Address>>8);/*sending the high order of the address*/
    I2C_Master_Write((uint8)Address);/*sending the lower order of address*/
    I2C_Master_Repeat_Start();
    I2C_Master_Write(EEPROM_ADD_READ);
    Data=I2C_Master_Read();
    I2C_NACK();
    I2C_Master_Stop();
    return Data;
}
