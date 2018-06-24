/*
 * KeyBoard.c
 *
 *  Created on: Jun 22, 2018
 *      Author: Maha
 */

#include "KeyBad.h"
#include "DIO.h"
#include<avr/delay.h>

void KeyBad_Init()
{
	/*R*/
	DIO_voidSetDir(PortD,Pin2,Output);
	DIO_voidSetDir(PortD,Pin3,Output);
	DIO_voidSetDir(PortD,Pin4,Output);

	/*C*/
	DIO_voidSetDir(PortD,Pin5,Input);
	DIO_voidSetDir(PortD,Pin6,Input);
	DIO_voidSetDir(PortA,Pin3,Input);
	DIO_voidWriteVal(PortD,Pin5,Five_Volt);
	DIO_voidWriteVal(PortD,Pin6,Five_Volt);
	DIO_voidWriteVal(PortA,Pin3,Five_Volt);
}

u8 KeyBad_Pressed(u8* key, u8 order)
{
	u8 u8return;
	if(order==1)
	{
		/*R1=0, R2=1, R3=1*/
		DIO_voidWriteVal(PortD,Pin2,Zero_Volt);
		DIO_voidWriteVal(PortD,Pin3,Five_Volt);
		DIO_voidWriteVal(PortD,Pin4,Five_Volt);

		u8 C1=DIO_u8GetVal(PortA,Pin3);
		u8 C2=DIO_u8GetVal(PortD,Pin6);
		u8 C3=DIO_u8GetVal(PortD,Pin5);

		if(!C1)
			*key='1';
		else if(!C2)
			*key='2';
		else if(!C3)
				*key='3';
		else
		{

		/*R1=1, R2=0, R3=1*/
		DIO_voidWriteVal(PortD,Pin2,Five_Volt);
		DIO_voidWriteVal(PortD,Pin3,Zero_Volt);
		DIO_voidWriteVal(PortD,Pin4,Five_Volt);

		C1=DIO_u8GetVal(PortA,Pin3);
		C2=DIO_u8GetVal(PortD,Pin6);
		C3=DIO_u8GetVal(PortD,Pin5);

		if(!C1)
			*key='4';
		else if(!C2)
			*key='5';
		else if(!C3)
			*key='6';
		else
		{

		/*R1=1, R2=1, R3=0*/
		DIO_voidWriteVal(PortD,Pin2,Five_Volt);
		DIO_voidWriteVal(PortD,Pin3,Five_Volt);
		DIO_voidWriteVal(PortD,Pin4,Zero_Volt);

		C1=DIO_u8GetVal(PortA,Pin3);
		C2=DIO_u8GetVal(PortD,Pin6);
		C3=DIO_u8GetVal(PortD,Pin5);

		if(!C1)
			*key='7';
		else if(!C2)
			*key='8';
		else if(!C3)
			*key='9';
			else *key=0;
		}
	}

	if(*key)
		u8return=1;
	else
		u8return=0;
	}
	else
	{
			/*R1=0, R2=1, R3=1*/
			DIO_voidWriteVal(PortD,Pin2,Zero_Volt);
			DIO_voidWriteVal(PortD,Pin3,Five_Volt);
			DIO_voidWriteVal(PortD,Pin4,Five_Volt);

			u8 C1=DIO_u8GetVal(PortA,Pin3);
			u8 C2=DIO_u8GetVal(PortD,Pin6);
			u8 C3=DIO_u8GetVal(PortD,Pin5);

			if(!C1 && !(*key=='1'))
				*key='1';
			else if(!C2 && !(*key=='2') )
				*key='2';
			else if(!C3 && !(*key=='3') )
					*key='3';
			else
			{

			/*R1=1, R2=0, R3=1*/
			DIO_voidWriteVal(PortD,Pin2,Five_Volt);
			DIO_voidWriteVal(PortD,Pin3,Zero_Volt);
			DIO_voidWriteVal(PortD,Pin4,Five_Volt);

			C1=DIO_u8GetVal(PortA,Pin3);
			C2=DIO_u8GetVal(PortD,Pin6);
			C3=DIO_u8GetVal(PortD,Pin5);

			if(!C1 && !(*key=='4') )
				*key='4';
			else if(!C2 && !(*key=='5') )
				*key='5';
			else if(!C3 && !(*key=='6') )
				*key='6';
			else
			{

			/*R1=1, R2=1, R3=0*/
			DIO_voidWriteVal(PortD,Pin2,Five_Volt);
			DIO_voidWriteVal(PortD,Pin3,Five_Volt);
			DIO_voidWriteVal(PortD,Pin4,Zero_Volt);

			C1=DIO_u8GetVal(PortA,Pin3);
			C2=DIO_u8GetVal(PortD,Pin6);
			C3=DIO_u8GetVal(PortD,Pin5);

			if(!C1 && !(*key=='7') )
				*key='7';
			else if(!C2 && !(*key=='8') )
				*key='8';
			else if(!C3 && !(*key=='9') )
				*key='9';
			}
		}

		if(*key)
			u8return=1;
		else
			u8return=0;
		}
	return u8return;
}

u8 KeyBad_LastPressed(u8* key)
{
	u8 key1,u8return;
	if(KeyBad_Pressed(key,1))
	{
		key1=*key;
		_delay_ms(1);
		if(KeyBad_Pressed(key,2))
			u8return=*key;
		else
		{
			*key=key1;
			u8return=*key;
		}
	}
	else u8return=0;

	return u8return;
}
