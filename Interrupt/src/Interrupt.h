/*
 * Interrupt.h
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "DIO.h"
#include "Utils.h"

#define INT0 0
#define INT1 1
#define INT2 2
#define ADC 3

#define SREG *((volatile u8*)(0x5f))
#define GICR *((volatile u8*)(0x5b))
#define MCUCR *((volatile u8*)(0x55))
#define MCUCSR *((volatile u8*)(0x54))
#define Global_Interrupt_Enable() Set_Bit(SREG,Pin7)
#define Global_Interrupt_Disable() Clr_Bit(SREG,Pin7)

void ExtINT_voidInit(u8 u8Number);



#endif /* INTERRUPT_H_ */
