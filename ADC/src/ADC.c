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

u16 ADC_u16GetVal(u8 u8Channel)
{
	/*define channel*/
	Assign_Bit(ADMUX,Pin0,Get_Bit(u8Channel,Pin0));
	Assign_Bit(ADMUX,Pin1,Get_Bit(u8Channel,Pin1));
	Assign_Bit(ADMUX,Pin2,Get_Bit(u8Channel,Pin2));
	Assign_Bit(ADMUX,Pin3,Get_Bit(u8Channel,Pin3));
	Assign_Bit(ADMUX,Pin4,Get_Bit(u8Channel,Pin4));

	/*Start Conversion*/
	Set_Bit(ADCSRA,Pin6);

	while(flag !=1 ){}
	Set_Bit(ADCSRA,Pin4);
	return ADCH;
}
