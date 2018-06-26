/*
 * ADC.h
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#ifndef ADC_H_
#define ADC_H_
#include "DIO.h"
#include"Utils.h"

#define ADMUX *((volatile u8*)(0x27))
#define ADCSRA *((volatile u8*)(0x26))
#define ADCH *((volatile u8*)(0x25))
#define ADCL *((volatile u8*)(0x24))
#define flag Get_Bit(ADCSRA,4)
#define POLLING 0
#define INTER 1

void ADC_voidInit();
void ADC_voidStartConversion(u8 u8Channel);
u16 ADC_u16GetVal();



#endif /* ADC_H_ */
