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
	u8 Rec=0;
	UART_voidInit();
	SS_Init();
	Buzzer_Init();

	while(1)
	{
		Rec=UART_u8RxData();
		if(Rec==6)
			{
				Buzzer_Toggle();
				_delay_ms(1000);
			}
		SS_Write(Rec,0);
	}

}

