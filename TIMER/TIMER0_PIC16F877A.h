/* 
 * File:   TIMER0_PIC16F877A.h
 * Author: Yousif
 *
 * Created on July 17, 2020, 12:45 AM
 */

#ifndef TIMER0_PIC16F877A_H
#define	TIMER0_PIC16F877A_H
#include"TIMER0_PIC16F877A_Local.h"
#include"STD_Types.h"
void TIMER0_Init(uint8 prescalar);
void TIMER0_INIT_Interrupt(void);
void __interrupt() timer0_isr();






#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* TIMER0_PIC16F877A_H */

