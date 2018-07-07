/*
 * main.c
 *
 *  Created on: Jun 30, 2018
 *      Author: Maha
 */

#include "UART.h"
#include "Seven_Segment.h"
#include "Buzzer.h"
#include "avr/delay.h"

int main()
{
	u8 Tran=6;
	UART_voidInit();
	SS_Init();

	while(1)
	{
		UART_voidTxData(Tran);
		SS_Write(Tran,0);
	}

}

