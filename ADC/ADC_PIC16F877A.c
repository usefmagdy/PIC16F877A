#include "ADC_PIC16F877A_Local.h"
#include"ADC_PIC16F877A.h"
#include"Utils.h"
#include"STD_Types.h"
#include "GPIO_PIC16F877A.h"
#include "GPIO_PIC16F887A_Local.h"
void ADC_init(uint8 CLK)
{
    /*ADC Control configuration of Reference Voltage */
    CLRBIT(ADCON1, PCFG3);
    CLRBIT(ADCON1, PCFG2);
    CLRBIT(ADCON1, PCFG1);
    CLRBIT(ADCON1, PCFG0);
    
    /*ADC Clock */
    switch(CLK)
    {
        case CLK_DIV_2:
            ADCON0 &=~((1<<ADCS0)|(1<<ADCS1));
            ADCON1 &=~(1<<ADCS2);
            break;
        case CLK_DIV_4:
            ADCON0 &=~((1<<ADCS0)|(1<<ADCS1));
            ADCON1 |=(1<<ADCS2);
            break;
        case CLK_DIV_8:
            ADCON0 &=~(1<<ADCS1);
            ADCON0 |=1<<ADCS0;
            ADCON1 &=~(1<<ADCS2);
            break;
        case CLK_DIV_16:
            ADCON0 &=~(1<<ADCS1);
            ADCON0 |=1<<ADCS0;
            ADCON1 |=(1<<ADCS2);
            break;
        case CLK_DIV_32:
            ADCON0 &=~(1<<ADCS0);
            ADCON0 |=(1<<ADCS1);
            ADCON1 &=~(1<<ADCS2);
            break;
        case CLK_DIV_64:
            ADCON0 &=~(1<<ADCS0);
            ADCON0 |=(1<<ADCS1);
            ADCON1 |=(1<<ADCS2);
            break;
            
    }
    ADCON0|=1<<ADON;/*ADC START*/
    ADCON1|=1<<ADFM;/*ADC Right Adjustment*/
    CLRPORT(ADRESH);
    CLRPORT(ADRESL);
}
uint8 ADC_Read(uint8 channel)
{
    if (channel>7)
    {
        return 0;
    }
    else
    {
        switch(channel)
        {
            case 0:
                ADCON0 &=~((1<<CHS0)|(1<<CHS1)|(1<<CHS2));
                break;
            case 1:
                ADCON0 &=~((1<<CHS1)|(1<<CHS2));
                ADCON0 |=(1<<CHS0);
                break;
            case 2:
                ADCON0 &=~((1<<CHS0)|(1<<CHS2));
                ADCON0 |=(1<<CHS1);
                break;
            case 3:
                ADCON0 &=~((1<<CHS2));
                ADCON0 |=(1<<CHS1)|(1<<CHS0);
                break;
            case 4:
                ADCON0 &=~((1<<CHS1)|(1<<CHS0));
                ADCON0 |=(1<<CHS2);
                break;
            case 5:
                ADCON0 &=~(1<<CHS1);
                ADCON0 |=(1<<CHS0)|(1<<CHS2);
                break;
            case 6:
                ADCON0 &=~(1<<CHS0);
                ADCON0 |=(1<<CHS1)|(1<<CHS2);
                break;
            case 7:
                ADCON0 |=(1<<CHS1)|(1<<CHS0)|(1<<CHS2);
                break;         
        }
       // __delay_ms(2); //Acquisition time to charge hold capacitor
        SETBIT(ADCON0,GO_Done);/*start conversation*/
        while(GETBIT(ADCON0,GO_Done));
        return((ADRESH<<8) + ADRESL);
    }
  
}
