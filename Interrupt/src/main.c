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
#include "Timer.h"
#include "Seven_Segment.h"
#include "Buzzer.h"


#define INT INT0
#define Channel 0

u32 counter=0;

void __vector_1(void) __attribute__((signal,__INTR_ATTRS));  /*INT0*/
void __vector_2(void) __attribute__((signal,__INTR_ATTRS));  /*INT1*/
void __vector_9(void) __attribute__((signal,__INTR_ATTRS));  /*Timer0 OVF*/
void __vector_14(void) __attribute__((signal,__INTR_ATTRS)); /*ADC*/
void __vector_18(void) __attribute__((signal,__INTR_ATTRS)); /*INT2*/
void __vector_19(void) __attribute__((signal,__INTR_ATTRS)); /*Timer0 Comp*/

void __vector_1(void)
{
	ToggleLED(0);
}

void __vector_2(void)
{
	ToggleLED(1);
}

void __vector_9(void)
{
	counter++;
	if(counter==488)
	{	counter=0;
		ToggleLED(0);
	}
}

void __vector_14(void)
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

void __vector_18(void)
{
	Buzzer_Toggle();
}

void __vector_19(void)
{
	counter++;
	if(counter==625)
	{	counter=0;
		ToggleLED(0);
	}
}

int main()
{
#if INT==NORMAL
	LED_Init(0);
	TIMERINT_voidInit(NORMAL);
	Global_Interrupt_Enable();
	while(1){}

#endif

#if INT==FAST_PW
	LED_Init(0);
	TIMERINT_voidInit(FAST_PW);
	while(1)
	{
		OCR0+=20;
	}

#endif

#if INT==CTC
	LED_Init(0);
	TIMERINT_voidInit(CTC);
	while(1){}

#endif

#if INT==INT0 || INT==INT1 || INT==INT2

	Buzzer_Init();
	LED_Init(0);
	LED_Init(1);
	ExtINT_voidInit(INT);
	Global_Interrupt_Enable();
	DIO_voidSetDir(PortD,Pin6,Output);
	DIO_voidWriteVal(PortD,Pin6,Zero_Volt);

	while(1)
	{
		_delay_ms(100);
		DIO_voidWriteVal(PortD,Pin6,Five_Volt);
		_delay_ms(100);
		DIO_voidWriteVal(PortD,Pin6,Zero_Volt);
	}

#endif

#if INT==ADC

	ADC_voidInit();
	LCD_Init();
	SS_Init();
	ExtINT_voidInit(INT);
	Global_Interrupt_Enable();

	while(1)
	{
		ADC_voidStartConversion(Channel);
		LCD_WriteData('M');
	}

#endif
}
