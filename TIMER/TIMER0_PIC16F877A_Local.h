/* 
 * File:   TIMER0_PIC16F877A_Local.h
 * Author: Yousif
 *
 * Created on July 17, 2020, 12:50 AM
 */

#ifndef TIMER0_PIC16F877A_LOCAL_H
#define	TIMER0_PIC16F877A_LOCAL_H

#define TMR0        *((uint8*)(0x01))
#define OPTION_REG  *((uint8*)(0x81))
        /**            OPTION_REG bits                       **/
#define RBPU    7
#define INTEDG  6
#define T0CS    5
#define T0SE    4
#define PSA     3
#define PS2     2
#define PS1     1
#define PS0     0

#define INTCON      *((uint8*)(0x0B))
            /**         INTCON BITS FOR INTERRUPT            **/
#define GIE     7
#define PEIE    6
#define TMR0IE  5
#define INTE    4
#define RBIE    3
#define TMR0IF  2
#define INTF    1
#define RBIF    0





#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* TIMER0_PIC16F877A_LOCAL_H */

