/* 
 * File:   I2C_PIC16F877A.h
 * Author: Yousif
 *
 * Created on July 17, 2020, 10:27 PM
 */

#ifndef I2C_PIC16F877A_H
#define	I2C_PIC16F877A_H
#include"STD_Types.h"
void I2C_Master_Init(const uint32 baud);
void I2C_Master_Wait(void);
void I2C_Master_Start(void);
void I2C_Master_Repeat_Start(void);
void I2C_Master_Stop(void);
uint8 I2C_Master_Write(uint8 Data);
uint8 I2C_Master_Read(void);
void I2C_NACK(void);
void I2C_ACK(void);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* I2C_PIC16F877A_H */

