/*
 * Button.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#include "Button.h"

void Button_Init(u8 u8Number)
{

}

u8 Button_Read(u8 u8Number)
{
	u8 u8State;

	if(u8Number)
		u8State=DIO_u8GetVal(PortB,Pin3);
	else
		u8State=DIO_u8GetVal(PortB,Pin2);

	return u8State;
}
