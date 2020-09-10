/* 
 * File:   I2C_PIC16F877A_Local.h
 * Author: Yousif
 *
 * Created on July 17, 2020, 10:27 PM
 */

#ifndef I2C_PIC16F877A_LOCAL_H
#define	I2C_PIC16F877A_LOCAL_H

#define SSPSTAT     *((uint8*)(0x94))
#define SMP 7
#define CKE 6
#define D_A 5
#define P   4
#define S   3
#define R_W 2
#define UA  1
#define BF  0

#define SSPCON1     *((uint8*)(0x14))
#define WCOL    7
#define SSPOV   6
#define SSPEN   5
#define CKP     4
#define SSPM3   3
#define SSPM2   2
#define SSPM1   1
#define SSPM0   0

#define SSPCON2     *((uint8*)(0x14))
#define GCEN    7
#define ACKSTAT 6
#define ACKDT   5
#define ACKEN   4
#define RCEN    3
#define PEN     2
#define RSEN    1
#define SEN     0

#define SSPADD  *((uint8*)(0x094))
#define SSPBUF  *((uint8*)(0x013))
#define PIR1    *((uint8*)(0x0c))
#define SSPIF   7
#ifdef	__cplusplus
extern "C" {
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_PIC16F877A_LOCAL_H */

