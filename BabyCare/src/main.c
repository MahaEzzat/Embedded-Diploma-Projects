/*
 * main.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#include "LCD.h"
#include "Seven_Segment.h"
#include "ADC.h"
#include "LED.h"
#include "Buzzer.h"
#include "DIO.h"
#include "avr/delay.h"


int main()
{
	u32 Data_Reading;
	u32 Data_Voltage;
	u8 count,count2, Reading[4], Voltage[4];
	u8 Temp;
	ADC_voidInit();
	LCD_Init();
	SS_Init();
	Buzzer_Init();
	LED_Init(0);

	while(1)
	{
		Data_Reading = ADC_u32GetVal(0);
		Data_Voltage=(Data_Reading*5*100)/1023;
		Temp=Data_Voltage/10; /*from 0 to 50*/

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

		for(count2=0;count2<50;count2++)
		{
				SS_Write(Voltage[0],1);
				_delay_ms(10);
				SS_Write(Voltage[1],0);
				_delay_ms(10);
		}

	if(Temp>=27 && Temp<=31)
	{
		Buzzer(OFF);
		LED(0,ON);
		for(count=0;count<4;count++)
			LCD_WriteData(Reading[count]);
	}
	else if (Temp>31 && Temp<=35)
		{
		Buzzer(OFF);
		LED(0,ON);
		_delay_ms(1000);
		LED(0,OFF);
		for(count=0;count<4;count++)
			LCD_WriteData(Reading[count]);
		}
		else if (Temp>35)
		{
			Buzzer(ON);
			LCD_WrtireString("DANGER!");
		}
		else
		{
			for(count=0;count<4;count++)
				LCD_WriteData(Reading[count]);
				LED(0,OFF);
				Buzzer(OFF);
		}

	_delay_ms(1000);
	LCD_CLear();
	}
}
