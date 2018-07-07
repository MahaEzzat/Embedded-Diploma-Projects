/*
 * Timer.h
 *
 *  Created on: Jun 29, 2018
 *      Author: Maha
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "DIO.h"
#include "Utils.h"

#define NORMAL 5
#define CTC 6
#define FAST_PW 7
#define PW_PASE 8

#define TIMER 4
#define TCCR0 *((volatile u8*)(0x53))
#define TIMSK *((volatile u8*)(0x59))
#define SREG  *((volatile u8*)(0x5f))
#define OCR0  *((volatile u8*)(0x5c))
#define Global_Interrupt_Enable() Set_Bit(SREG,Pin7)
#define Global_Interrupt_Disable() Clr_Bit(SREG,Pin7)

void TIMERINT_voidInit(u8 u8Type);



#endif /* TIMER_H_ */
