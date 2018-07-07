/*
 * UART.h
 *
 *  Created on: Jun 30, 2018
 *      Author: Maha
 */

#ifndef UART_H_
#define UART_H_
#include "DIO.h"

#define SREG  *((volatile u8*)(0x5f))
#define UCSRA *((volatile u8*)(0x2b))
#define UCSRB *((volatile u8*)(0x2a))
#define UCSRC *((volatile u8*)(0x40))
#define UBRRH *((volatile u8*)(0x40))
#define UBRRL *((volatile u8*)(0x29))
#define UDR   *((volatile u8*)(0x2c))

#define RxFlag Get_Bit(UCSRA,Pin7)
#define TxFlag Get_Bit(UCSRA,Pin6)
#define ClrTxFlag() Set_Bit(UCSRA,Pin6)

#define Global_Interrupt_Enable() Set_Bit(SREG,Pin7)
#define Global_Interrupt_Disable() Clr_Bit(SREG,Pin7)

void UART_voidInit();
void UART_voidTxData(u8 u8Data);
u8 UART_u8RxData();

#endif /* UART_H_ */
