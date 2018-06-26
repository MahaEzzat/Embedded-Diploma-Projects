/*
 * main.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#include "LCD.h"
#include "ADC.h"
#include "DIO.h"
#include "Seven_Segment.h"
#include "avr/delay.h"


int main()
{
	u32 Data_Reading;
	u32 Data_Voltage;
	u8 count,count2, Reading[4], Voltage[4];
	ADC_voidInit();
	LCD_Init();
	SS_Init();

	while(1)
	{
		Data_Reading = ADC_u32GetVal(0);
		Data_Voltage=(Data_Reading*5*100)/1023;

		for(count=4;count>0;count--)
		{
			Reading[count-1]=Data_Reading%10 + 48;
			Data_Reading/=10;
		}

		for(count=3;count>0;count--)
		{
			Voltage[count-1]=Data_Voltage%10;
			Data_Voltage/=10;
		}

		for(count=0;count<4;count++)
			LCD_WriteData(Reading[count]);

		for(count2=0;count2<50;count2++)
		{
				SS_Write(Voltage[0],1);
				_delay_ms(10);
				SS_Write(Voltage[1],0);
				_delay_ms(10);
		}
		_delay_ms(10);
		LCD_CLear();
	}
}
