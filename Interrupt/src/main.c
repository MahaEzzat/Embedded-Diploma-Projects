/*
 * main.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#include "Interrupt.h"
#include "avr/delay.h"
#include "LED.h"
#include "ADC.h"
#include "LCD.h"
#include "Seven_Segment.h"

#define INT ADC
#define Channel 0

void __vector_1(void) __attribute__((signal,naked));
void __vector_2(void) __attribute__((signal,naked));
void __vector_14(void) __attribute__((signal,naked));
void __vector_18(void) __attribute__((signal,naked));

void __vector_1(void)
{
	LED_Init(0);
	LED(0,ON);
	_delay_ms(1000);
	LED(0,OFF);
}

void __vector_2(void)
{
	LED_Init(0);
	LED(0,ON);
	_delay_ms(1000);
	LED(0,OFF);
}

void __vector_14(void)
{
	LED_Init(0);
	LED(0,ON);
	_delay_ms(1000);
	LED(0,OFF);
}

void __vector_18(void)
{
	u32 Data_Reading,Data_Voltage;
	u8 count,count2, Reading[4], Voltage[4];
	Data_Reading = ADC_u16GetVal();
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
	_delay_ms(100);
	LCD_CLear();
}

int main()
{
	ADC_voidInit();
	LCD_Init();
	SS_Init();
	Global_Interrupt_Enable();
	ExtINT_voidInit(INT);

#if INT==INT0 || INT==INT1 || INT==INT2

	DIO_voidSetDir(PortA,Pin7,Output);
	DIO_voidWriteVal(PortA,Pin7,Zero_Volt);

	while(1)
	{
		DIO_voidWriteVal(PortA,Pin7,Five_Volt);
		_delay_ms(1000);
		DIO_voidWriteVal(PortA,Pin7,Zero_Volt);
		_delay_ms(1000);
	}

#endif

#if INT==ADC

	while(1)
	{
		ADC_voidStartConversion(Channel);
		LCD_WriteData('M');
	}

#endif
}
