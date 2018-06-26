/*
 * ADC.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#include "ADC.h"
#include "Utils.h"


void ADC_voidInit()
{
	/*Clock Devision Factor*/
	Set_Bit(ADCSRA,Pin0);
	Set_Bit(ADCSRA,Pin1);
	Set_Bit(ADCSRA,Pin2);

	/*Left Adjustment*/
	Set_Bit(ADMUX,Pin5);

	/*Ref. Voltage*/
	Set_Bit(ADMUX,Pin6);
	Clr_Bit(ADMUX,Pin7);

	/*Enable ADC*/
	Set_Bit(ADCSRA,Pin7);

}

void ADC_voidStartConversion(u8 u8Channel)
{
	/*define channel*/
	Assign_Bit(ADMUX,Pin0,Get_Bit(u8Channel,Pin0));
	Assign_Bit(ADMUX,Pin1,Get_Bit(u8Channel,Pin1));
	Assign_Bit(ADMUX,Pin2,Get_Bit(u8Channel,Pin2));
	Assign_Bit(ADMUX,Pin3,Get_Bit(u8Channel,Pin3));
	Assign_Bit(ADMUX,Pin4,Get_Bit(u8Channel,Pin4));

	/*Start Conversion*/
	Set_Bit(ADCSRA,Pin6);

}

u16 ADC_u16GetVal()
{
	u16 u16ReturnReading,u16ReadingHigh;
	u8 u8ReadingLow;

	u8ReadingLow = (Get_Bit(ADCL,Pin6)) + (2*Get_Bit(ADCL,Pin7));
	u16ReadingHigh= ADCH;
	u16ReturnReading = u8ReadingLow + (u16ReadingHigh<<2);

	return u16ReturnReading;
}
