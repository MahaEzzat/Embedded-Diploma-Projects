/*
 * UART.c
 *
 *  Created on: Jun 30, 2018
 *      Author: Maha
 */
#include "UART.h"
#include "DIO.h"
#include "Utils.h"

void UART_voidInit()
{
	/*Enable Trans and Rec */
	Set_Bit(UCSRB,Pin3);
	Set_Bit(UCSRB,Pin4);

	/*Assign  UBRR To define Baud Rate*/
	UBRRL=77;
	UBRRH=0;

	/*8-bit data*/
	Clr_Bit(UCSRB,Pin2);
	UCSRC=0b10000110;

	/*Polling*/
	Global_Interrupt_Disable();
}

void UART_voidTxData(u8 u8Data)
{
	UDR=u8Data;
	while(TxFlag!=1){}

	ClrTxFlag();
}

u8 UART_u8RxData()
{
	while(RxFlag!=1){}

	return UDR;
}
