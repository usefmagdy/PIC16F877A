#include"TIMER0_PIC16F877A.h"
#include"STD_Types.h"
#include"Utils.h"

void TIMER0_Init(uint8 prescalar)
{
    CLRBIT(OPTION_REG,PSA);
    switch(prescalar)
    {
        case 2:
            CLRBIT(OPTION_REG, PS0);
            CLRBIT(OPTION_REG, PS1);
            CLRBIT(OPTION_REG, PS2);
            break;
        case 4:
            SETBIT(OPTION_REG, PS0);
            CLRBIT(OPTION_REG, PS1);
            CLRBIT(OPTION_REG, PS2);
            break;
        case 8:
            CLRBIT(OPTION_REG, PS0);
            SETBIT(OPTION_REG, PS1);
            CLRBIT(OPTION_REG, PS2);
            break;
        case 16:
            SETBIT(OPTION_REG, PS0);
            SETBIT(OPTION_REG, PS1);
            CLRBIT(OPTION_REG, PS2);
            break;
        case 32:
            CLRBIT(OPTION_REG, PS0);
            CLRBIT(OPTION_REG, PS1);
            SETBIT(OPTION_REG, PS2);
            break;
        case 64:
            SETBIT(OPTION_REG, PS0);
            CLRBIT(OPTION_REG, PS1);
            SETBIT(OPTION_REG, PS2);
            break;
        case 128:
            CLRBIT(OPTION_REG, PS0);
            SETBIT(OPTION_REG, PS1);
            SETBIT(OPTION_REG, PS2);
            break;
        case 256:
            SETBIT(OPTION_REG, PS0);
            SETBIT(OPTION_REG, PS1);
            SETBIT(OPTION_REG, PS2);
            break;
    }    
    CLRBIT(OPTION_REG,T0CS);
    CLRBIT(OPTION_REG,T0SE);
}
//tick=prescalar*4/Fosc
//Delay = ((256-REG_val(TIM0))*(Prescal*4))/Fosc
void TIMER0_INIT_Interrupt(void)
{
    SETBIT(INTCON,GIE);   //GLOBAL Interrupt
    SETBIT(INTCON,PEIE); //interrupt peripherial
    SETBIT(INTCON,TMR0IE);//interrupt enable of timer0
}
void __interrupt() timer0_isr()
{
    uint8 count=0;
    TMR0=0;//for exmaple
    count++;
    if (TMR0IF)
    {
        CLRBIT(INTCON,TMR0IF);
    }
    /* if (count==Delay)
     * {count=0;
     * }
     */
}
