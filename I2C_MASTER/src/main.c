/*
 * main.c
 *
 *  Created on: Jun 30, 2018
 *      Author: Maha
 */

#include "I2C_Master.h"
#include "avr/delay.h"

int main()
{
	u8 Trans=2,Add=0x20;
	I2C_MasterInit();

	while(1)
	{
		I2C_MasterStartSequence();
		I2C_MasterSend(Add,Trans);
		I2C_MasterStopSequence();
	}

}

