/*
 * main.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#include "Interrupt.h"
#include "avr/delay.h"
#include "LED.h"

void __vector_1(void) __attribute__((signal,naked));


void __vector_1(void)
{
	LED_Init(0);
	LED(0,ON);
	_delay_ms(1000);
	LED(0,OFF);
}

int main()
{
	Global_Interrupt_Enable();
	ExtINT_voidInit(INT0);
	DIO_voidSetDir(PortA,Pin7,Output);
	DIO_voidWriteVal(PortA,Pin7,Zero_Volt);

	while(1)
	{
		DIO_voidWriteVal(PortA,Pin7,Five_Volt);
		_delay_ms(1000);
		DIO_voidWriteVal(PortA,Pin7,Zero_Volt);
		_delay_ms(1000);

	}
}
