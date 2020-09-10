/* 
 * File:   ADC_PIC16F877A.h
 * Author: Yousif
 *
 * Created on July 16, 2020, 2:51 AM
 */

#ifndef ADC_PIC16F877A_H
#define	ADC_PIC16F877A_H
#include "Utils.h"
#include "STD_Types.h"
void ADC_init(uint8 CLK);
uint8 ADC_Read(uint8 channel);



#define CLK_DIV_2   2
#define CLK_DIV_4   4
#define CLK_DIV_8   8
#define CLK_DIV_16  16
#define CLK_DIV_32  32
#define CLK_DIV_64  64


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ADC_PIC16F877A_H */

