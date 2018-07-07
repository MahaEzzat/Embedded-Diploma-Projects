/*
 * Buzzer.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */
#include "Buzzer.h"
#include "DIO.h"
#include "avr/delay.h"
#include "Utils.h"

void Buzzer_Init()
{
	DIO_voidSetDir(PortD,Pin7,Output); /* Set pin 7D as an output pin (buzzer)*/
	DIO_voidWriteVal(PortD,Pin7,Zero_Volt); /* Set pin 7D to 0V */
}
void Buzzer(u8 u8State)
{
	DIO_voidWriteVal(PortD,Pin7,u8State);
}

void Buzzer_Toggle()
{
	Toggle_Bit(PORTD,Pin7);
}

void Buzzer_Mode(u8 u8Freq1, u8 u8Freq2)
{
		int count;
		for(count=0; count<u8Freq1; count++)
		{
			Buzzer(ON);
			_delay_ms(1);
			Buzzer(OFF);
			_delay_ms(10);
		}
		_delay_ms(1000);
		for(count=0; count<u8Freq2; count++)
		{
			Buzzer(ON);
			_delay_ms(10);
			Buzzer(OFF);
			_delay_ms(1);
		}
		_delay_ms(100);

}
