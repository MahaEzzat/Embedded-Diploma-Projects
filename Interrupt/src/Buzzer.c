/*
 * Buzzer.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */
#include "Buzzer.h"
#include "DIO.h"
#include "avr/delay.h"

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
	DIO_voidWriteVal(PortD,Pin7,ON);
	_delay_ms(1000);
	DIO_voidWriteVal(PortD,Pin7,OFF);
	_delay_ms(1000);

}
