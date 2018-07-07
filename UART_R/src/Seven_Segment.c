/*
 * Seven_Segment.c
 *
 *  Created on: Jun 23, 2018
 *      Author: Maha
 */

#include "Seven_Segment.h"
#include "DIO.h"
#include "Utils.h"
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
