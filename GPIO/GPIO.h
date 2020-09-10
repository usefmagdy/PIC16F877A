/* 
 * File:   GPIO_PIC16F877A.h
 * Author: Yousif
 *
 * Created on July 15, 2020, 10:26 PM
 */

#ifndef GPIO_PIC16F877A_H
#define	GPIO_PIC16F877A_H


#include"STD_Types.h"
void GPIO_INIT();
void GPIO_SetPORT_Dir(uint8 Port,uint8 Dir);
void GPIO_WritePortValue(uint8 Port,uint8 value);
uint8 GPIO_ReadPortValue(uint8 U8PortNum);
void GPIO_SetPIN_Dir(uint8 pinnum,uint8 Dir);
void GPIO_WritePinValue(uint8 Pin_Num,uint8 Value);
uint8 GPIO_ReadPinValue(uint8 Pin_Num);


#define PINA0 0
#define PINA1 1
#define PINA2 2
#define PINA3 3
#define PINA4 4
#define PINA5 5

#define PINB0 8
#define PINB1 9
#define PINB2 10
#define PINB3 11
#define PINB4 12
#define PINB5 13
#define PINB6 14
#define PINB7 15

#define PINC0 16
#define PINC1 17
#define PINC2 18
#define PINC3 19
#define PINC4 20
#define PINC5 21
#define PINC6 22
#define PINC7 23

#define PIND0 24
#define PIND1 25
#define PIND2 26
#define PIND3 27
#define PIND4 28
#define PIND5 29
#define PIND6 30
#define PIND7 31

#define PINE0 32
#define PINE1 33
#define PINE2 34

#define INPUT_PORT 0xff
#define INPUT_PORTE 0x07
#define INPUT_PORTA 0x3f
#define INPUT_PIN 1

#define OUTPUT_PORT 0x00
#define OUTPUT_PIN 0

#define High 1
#define Low 0
#define High_Port 0xff
#define Low_Port 0x00

#define GPIO_PortA 0
#define GPIO_PortB 1
#define GPIO_PortC 2
#define GPIO_PortD 3
#define GPIO_PortE 4

#endif	/* GPIO_PIC16F877A_H */

