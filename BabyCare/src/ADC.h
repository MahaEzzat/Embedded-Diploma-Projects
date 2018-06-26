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

void ADC_voidInit();
u16 ADC_u32GetVal(u8 u8Channel);


#endif /* ADC_H_ */
