#include"STD_Types.h"
#include"Utils.h"
#include "GPIO_PIC16F887A_Local.h"
#include"GPIO_PIC16F877A.h"
void GPIO_INIT()
{
    
}
void GPIO_SetPORT_Dir(uint8 Port,uint8 Dir)
{
    switch(Port)
    {
        case 0:
            if(Dir ==INPUT_PORT)
            {
                SETPORT(TRISA);
            }
            if(Dir == OUTPUT_PORT)
            {
                CLRPORT(TRISA);
            }
        break;
        case 1:
            if(Dir ==INPUT_PORT)
            {
                SET_LOW_NIPPLE(TRISB);
                SET_HIGH_NIPPLE(TRISB);
            }
            if(Dir == OUTPUT_PORT)
            {
                CLR_LOW_NIPPLE(TRISB);
                CLR_HIGH_NIPPLE(TRISB);
            }
        break;
        case 2:
            if(Dir ==INPUT_PORT)
            {
                SET_LOW_NIPPLE(TRISC);
                SET_HIGH_NIPPLE(TRISC);
            }
            if(Dir == OUTPUT_PORT)
            {
                CLR_LOW_NIPPLE(TRISC);
                CLR_HIGH_NIPPLE(TRISC);
            }
        break;
        case 3:
            if(Dir ==INPUT_PORT)
            {
                SET_LOW_NIPPLE(TRISD);
                SET_HIGH_NIPPLE(TRISD);
            }
            if(Dir == OUTPUT_PORT)
            {
                CLR_LOW_NIPPLE(TRISD);
                CLR_HIGH_NIPPLE(TRISD);
            }
        break;
        case 4:
            if(Dir ==INPUT_PORTE)
            {
                SETBIT(TRISE,0);
                SETBIT(TRISE,1);
                SETBIT(TRISE,2);
            }
            if(Dir == OUTPUT_PORT)
            {
                CLRBIT(TRISE,0);
                CLRBIT(TRISE,1);
                CLRBIT(TRISE,2);
            }
        break;
    }
}
void GPIO_WritePortValue(uint8 Port,uint8 value)
{
    switch(Port)
    {
        case 0:
            PORTA=value;
		break;
        case 1:
            PORTB=value;
		break;
        case 2:
            PORTC=value;
		break;
        case 3:
            PORTD=value;
		break;
        case 4:
            PORTE=value;
        break;
    }
}
uint8 GPIO_ReadPortValue(uint8 U8PortNum)
{
	uint8 U8Portval;
    switch(U8PortNum)
    {
        case GPIO_PortA:
          U8Portval=PORTA;
          break;
        case GPIO_PortB:
            U8Portval=PORTB;
          break;
          case GPIO_PortC:
            U8Portval=PORTC;
          break;
          case GPIO_PortD:
            U8Portval=PORTD;
            case GPIO_PortE:
            U8Portval=PORTE;
          break;
    }
return U8Portval;
}
void GPIO_SetPIN_Dir(uint8 pinnum,uint8 Dir)
{
    switch(Dir)
    {
        case OUTPUT_PIN:
            /**/
            if(pinnum>=PINA0&&pinnum<PINB0){
                CLRBIT(TRISA,pinnum%8);}
            if (pinnum>=PINB0&&pinnum<PINC0){
                CLRBIT(TRISB,pinnum%8);}
            if (pinnum>=PINC0&&pinnum<PIND0){
                CLRBIT(TRISC,pinnum%8);}
            if (pinnum>=PIND0&&pinnum<PINE0){
                CLRBIT(TRISD,pinnum%8);}
            if (pinnum>=PINE0&&pinnum<=PINE2){
                CLRBIT(TRISE,pinnum%8);}
            break;
        case INPUT_PIN:
            if(pinnum>=PINA0&&pinnum<PINB0){
                SETBIT(TRISA,pinnum%8);}
            if (pinnum>=PINB0&&pinnum<PINC0){
                SETBIT(TRISB,pinnum%8);}
            if (pinnum>=PINC0&&pinnum<PIND0){
                SETBIT(TRISC,pinnum%8);}
            if (pinnum>=PIND0&&pinnum<PINE0){
                SETBIT(TRISD,pinnum%8);}
            if (pinnum>=PINE0&&pinnum<=PINE2){
                SETBIT(TRISE,(pinnum%8));}
            break;
    }
}
void GPIO_WritePinValue(uint8 Pin_Num,uint8 Value)
{

    if((Pin_Num>=PINA0)&&(Pin_Num<PINB0))
	{
		/*PORTA*/
		ASSIGNBIT(PORTA, (Pin_Num)%8, Value);
        
        
	}
	if((Pin_Num>=PINB0)&&(Pin_Num<PINC0))
	{
		/*PORTB*/
		ASSIGNBIT(PORTB, (Pin_Num%8), Value);
	}
	if((Pin_Num>=PINC0)&&(Pin_Num<PIND0))
	{
		/*PORTC*/
		ASSIGNBIT(PORTC,(Pin_Num%8), Value);
	}
	if((Pin_Num>=PIND0)&&(Pin_Num<PINE0))
	{
		/*PORTD*/
		ASSIGNBIT(PORTD,(Pin_Num%8), Value);
	}
  if((Pin_Num>=PINE0)&&(Pin_Num<=PINE2))
	{
		/*PORTD*/
		ASSIGNBIT(PORTE, (Pin_Num%8), Value);
	}
}
uint8 GPIO_ReadPinValue(uint8 Pin_Num)
{
    if((Pin_Num>=PINA0)&&(Pin_Num<PINB0))
	{
		/*PINA*/
		return (GETBIT(PORTA,Pin_Num%8));
	}
	if((Pin_Num>=PINB0)&&(Pin_Num<PINC0))
	{
		/*PINB*/
		return (GETBIT(PORTB, (Pin_Num%8)));
	}
	if((Pin_Num>=PINC0)&&(Pin_Num<PIND0))
	{
		/*PINC*/
		return (GETBIT(PORTC, (Pin_Num%8)));
	}
	if((Pin_Num>=PIND0)&&(Pin_Num<PINE0))
	{
		/*PIND*/
		return (GETBIT(PORTD, (Pin_Num%8)));
	}
    if((Pin_Num>=PINE0)&&(Pin_Num<=PINE2))
	{
		/*PIND*/
		return (GETBIT(PORTE,(Pin_Num%8)));
	}
    
}
