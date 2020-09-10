/* 
 * File:   GPIO_PIC16F887A_Local.h
 * Author: Yousif
 *
 * Created on July 15, 2020, 10:28 PM
 */

#ifndef GPIO_PIC16F887A_LOCAL_H
#define	GPIO_PIC16F887A_LOCAL_H


#define PORTA *((uint8*)(0x05))
#define PORTB *((uint8*)(0x06))
#define PORTC *((uint8*)(0x07))
#define PORTD *((uint8*)(0x08))
#define PORTE *((uint8*)(0x09))

#define TRISA *((uint8*)(0x85))
#define TRISB *((uint8*)(0x86))
#define TRISC *((uint8*)(0x87))
#define TRISD *((uint8*)(0x88))
#define TRISE *((uint8*)(0x89))

#endif	/* GPIO_PIC16F887A_LOCAL_H */

