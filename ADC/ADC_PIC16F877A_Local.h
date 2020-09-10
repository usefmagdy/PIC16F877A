/* 
 * File:   ADC_PIC16F877A_Local.h
 * Author: Yousif
 *
 * Created on July 16, 2020, 2:55 AM
 */

#ifndef ADC_PIC16F877A_LOCAL_H
#define	ADC_PIC16F877A_LOCAL_H
#define INTCON  *((uint8*)(0x0B))
#define PIR1    *((uint8*)(0x0C))
#define PIE1    *((uint8*)(0x8C))
#define ADCON0  *((uint8*)(0x1F))
            /*ADC0N0 BITS*/
#define ADON    0
#define GO_Done 2
#define CHS0    3
#define CHS1    4
#define CHS2    5
#define ADCS0   6
#define ADCS1   7
            /*             */
#define ADCON1  *((uint8*)(0x9F))
        /*ADCON1 BITS*/
#define PCFG0   0
#define PCFG1   1
#define PCFG2   2
#define PCFG3   3
#define ADCS2   6
#define ADFM    7

#define ADRESH  *((uint8*)(0x1E))
#define ADRESL  *((uint8*)(0x9E))


#endif	/* ADC_PIC16F877A_LOCAL_H */

