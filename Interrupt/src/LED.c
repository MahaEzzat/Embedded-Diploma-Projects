/*
 * LED.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#include "LED.h"
#include "DIO.h"
#include "Utils.h"
#include "avr/delay.h"

void LED_Init(u8 u8LedNumber)
{
	if(u8LedNumber)
	{
		DIO_voidSetDir(PortA,Pin5,Output); /* Set pin 5A as an output pin */
		DIO_voidWriteVal(PortA,Pin5,Zero_Volt); /* Set pin 5A to 0V */
	}
	else
	{
		DIO_voidSetDir(PortA,Pin4,Output); /* Set pin 4A as an output pin */
		DIO_voidWriteVal(PortA,Pin4,Zero_Volt); /* Set pin 4A to 0V */
	}
}
void LED(u8 u8LedNumber, u8 u8State)
{
	if(u8LedNumber)
		DIO_voidWriteVal(PortA,Pin5,u8State); /* Set pin 5A to StateV */

	else
		DIO_voidWriteVal(PortA,Pin4,u8State); /* Set pin 4A to StateV */
}
void ToggleLED(u8 u8LedNumber)
{
	if(u8LedNumber)
	{
		LED(1,ON);
		_delay_ms(1000);
		LED(1,OFF);
		_delay_ms(1000);
	}
	else
	{
		LED(0,ON);
		_delay_ms(1000);
		LED(0,OFF);
		_delay_ms(1000);
	}

}
