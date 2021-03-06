/*
 * Interrupt.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */
#include "Interrupt.h"
#include "Utils.h"
#include "ADC.h"
#include <avr/delay.h>

void ExtINT_voidInit(u8 u8Number)

{
	switch (u8Number)
	{

	case INT0:
		/*Interrupt Configuration*/
		Set_Bit(MCUCR,Pin0);
		Clr_Bit(MCUCR,Pin1);

		/*Enable INT0*/
		Set_Bit(GICR,Pin6);
		break;

	case INT1:
		Set_Bit(GICR,Pin7);

		Set_Bit(MCUCR,Pin2);
		Clr_Bit(MCUCR,Pin3);
		break;

	case INT2:
		Set_Bit(GICR,Pin5);


		Set_Bit(MCUCSR,Pin6); /*Raising edge*/
		break;

	case ADC:
		Set_Bit(ADCSRA,Pin3);

		Clr_Bit(GICR,Pin7);
		Clr_Bit(GICR,Pin6);
		Clr_Bit(GICR,Pin5);
		break;
	}

}


