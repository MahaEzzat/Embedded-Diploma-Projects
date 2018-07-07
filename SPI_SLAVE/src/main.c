/*
 * main.c
 *
 *  Created on: Jun 30, 2018
 *      Author: Maha
 */

#include "SPI.h"
#include "avr/delay.h"
#include "LCD.h"

#define MODE SLAVE

int main()
{
	u8 Rec=0,Trans=6;
	LCD_Init();
	SPI_voidInit(MODE);

	while(1)
	{
		Rec=SPI_u8Data(Trans);
		LCD_CLear();
		LCD_WriteData(Rec+48);
		_delay_ms(1000);
	}

}

