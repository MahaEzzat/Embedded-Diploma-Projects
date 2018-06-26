/*
 * DAC.c
 *
 *  Created on: Jun 26, 2018
 *      Author: Maha
 */


#include "DAC.h"
#include "Utils.h"
#include "avr/delay.h"

void DAC_voidInit()
{
	DIO_voidSetDir(PortB,Pin0,Output);
	DIO_voidSetDir(PortB,Pin1,Output);
	DIO_voidSetDir(PortB,Pin2,Output);
	DIO_voidSetDir(PortB,Pin3,Output);
	DIO_voidSetDir(PortB,Pin4,Output);
	DIO_voidSetDir(PortB,Pin5,Output);
	DIO_voidSetDir(PortB,Pin6,Output);
	DIO_voidSetDir(PortB,Pin7,Output);
}

void DAC_voidOutput(u8 u8Type)
{
	int count;
	PORTB=0x00;
	_delay_ms(10);

	if(u8Type==RAMP)
	{
		for(count=1;count<256;count++)
		{
			PORTB=count;
			_delay_ms(10);
		}

		for(count=255;count>0;count--)
		{
			PORTB=count;
			_delay_ms(10);
		}
	}

}
