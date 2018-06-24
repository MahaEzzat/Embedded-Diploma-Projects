/*
 * Seven_Segment.c
 *
 *  Created on: Jun 23, 2018
 *      Author: Maha
 */

#include "Seven_Segment.h"
#include "DIO.h"
#include "Utils.h"
#include "Buzzer.h"
#include "LED.h"
#include <avr/delay.h>

void SS_Init()
{
	DIO_voidSetDir(PortB,Pin0,Output);
	DIO_voidSetDir(PortB,Pin1,Output);
	DIO_voidSetDir(PortB,Pin4,Output);
	DIO_voidSetDir(PortB,Pin5,Output);
	DIO_voidSetDir(PortB,Pin6,Output);
	DIO_voidSetDir(PortB,Pin7,Output);
}

void SS_Write(u8 u8Number, u8 u8channel)
{
	if(u8channel) /*1 for SS number 4(Most Sig)*/
	{
		DIO_voidWriteVal(PortB,Pin4,Zero_Volt);
		DIO_voidWriteVal(PortB,Pin5,Five_Volt);
	}
	else /*0 for SS number 5(Lest Sig)*/
	{
		DIO_voidWriteVal(PortB,Pin4,Five_Volt);
		DIO_voidWriteVal(PortB,Pin5,Zero_Volt);
	}

	DIO_voidWriteVal(PortB,Pin0,Get_Bit(u8Number,0)); /*A*/
	DIO_voidWriteVal(PortB,Pin1,Get_Bit(u8Number,1)); /*B*/
	DIO_voidWriteVal(PortB,Pin6,Get_Bit(u8Number,2)); /*C*/
	DIO_voidWriteVal(PortB,Pin7,Get_Bit(u8Number,3)); /*D*/

}

void SS_Mode(u8 u8Number)
{
	u8 number,number1,number2,number3;
/* Mode 1 (count-down)*/
 switch(u8Number)
 {
 case 1:
	 	LED(0,ON);
	 	LED(1,OFF);
	 	Buzzer(OFF);

		for(number=60; number>0; number--)
		{
			number1=number/10;
			number2=number%10;

			for(number3=0;number3<100;number3++)
			{
				/*Set Number 1 on 1st 7-segment*/
				SS_Write(number2, 0);

				_delay_ms(10);

				/*Set Number 2 on 2nd 7-segment*/
				SS_Write(number1, 1);

				_delay_ms(10);
			}
		}


	 	LED(0,OFF);
	 	LED(1,OFF);
	 	Buzzer(ON);

		for(number=10; number>0; number--)
		{
			number1=number/10;
			number2=number%10;
			for(number3=0;number3<100;number3++)
			{
				/*Set Number 1 on 1st 7-segment*/
				SS_Write(number2, 0);

				_delay_ms(10);

				/*Set Number 2 on 2nd 7-segment*/
				SS_Write(number1, 1);

				_delay_ms(10);
			}
		}

	 	LED(0,OFF);
	 	LED(1,ON);
	 	Buzzer(OFF);

		for(number=60; number>0; number--)
			{
			number1=number/10;
			number2=number%10;
			for(number3=0;number3<100;number3++)
				{
				/*Set Number 1 on 1st 7-segment*/
				SS_Write(number2, 0);

				_delay_ms(10);

				/*Set Number 2 on 2nd 7-segment*/
				SS_Write(number1, 1);

				_delay_ms(10);
				}
			}
		break;

 	 }
 }
