/*
 * DIO.c
 *
 *  Created on: Jun 17, 2018
 *      Author: Maha
 */

#include "DIO.h"
#include "Utils.h"

void DIO_voidInit()
{
	Clr_Nibble_High(DDRA);
	Clr_Nibble_Low(DDRA);
	Clr_Nibble_High(DDRB);
	Clr_Nibble_Low(DDRB);
	Clr_Nibble_High(DDRC);
	Clr_Nibble_Low(DDRC);
	Clr_Nibble_High(DDRD);
	Clr_Nibble_Low(DDRD);
}

u8 DIO_u8GetVal(u8 u8Port, u8 u8Pin)
{
	u8 Local_u8Return;
	switch (u8Port)
	{
	case 0:
		Local_u8Return=Get_Bit(PINA,u8Pin);
		break;
	case 1:
		Local_u8Return=Get_Bit(PINB,u8Pin);
		break;
	case 2:
		Local_u8Return=Get_Bit(PINC,u8Pin);
		break;
	case 3:
		Local_u8Return=Get_Bit(PIND,u8Pin);
	}
	return Local_u8Return;
}

void DIO_voidWriteVal(u8 u8Port, u8 u8Pin, u8 u8Val)
{
	switch (u8Port)
		{
		case 0:
			Assign_Bit(PORTA,u8Pin,u8Val);
			break;
		case 1:
			Assign_Bit(PORTB,u8Pin,u8Val);
			break;
		case 2:
			Assign_Bit(PORTC,u8Pin,u8Val);
			break;
		case 3:
			Assign_Bit(PORTD,u8Pin,u8Val);
		}

}

void DIO_voidSetDir(u8 u8Port, u8 u8Pin, u8 u8Dir)
{
	switch (u8Port)
		{
		case 0:
			Assign_Bit(DDRA,u8Pin,u8Dir);
			break;
		case 1:
			Assign_Bit(DDRB,u8Pin,u8Dir);
			break;
		case 2:
			Assign_Bit(DDRC,u8Pin,u8Dir);
			break;
		case 3:
			Assign_Bit(DDRD,u8Pin,u8Dir);
		}

}

