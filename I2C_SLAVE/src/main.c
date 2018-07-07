/*
 * main.c
 *
 *  Created on: Jun 30, 2018
 *      Author: Maha
 */

#include "I2C_Slave.h"
#include "avr/delay.h"
#include "LCD.h"

int main()
{
	u8 Rec=0,Add=0x20;
	I2C_SlaveAdd(Add);
	LCD_Init();

	while(1)
	{
		Rec=I2C_u8SlaveRead();
		LCD_WriteData(Rec);
		_delay_ms(1000);
		LCD_CLear();
	}

}

