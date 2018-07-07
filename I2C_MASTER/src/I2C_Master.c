/*
 * I2C_Master.c
 *
 *  Created on: Jul 6, 2018
 *      Author: Maha
 */
#include "I2C_Master.h"
#include "DIO.h"
#include "Utils.h"


void I2C_MasterInit()
{
	/*Choose Frequency 200KHZ*/
	TWBR=22;

	/*Set Pre-Scaler*/
	Clr_Bit(TWSR,Pin0);
	Clr_Bit(TWSR,Pin1);
}


void I2C_MasterStartSequence()
{
	/*Clear Flag*/
	ClearFlag();

	/*enable I2C*/
	Set_Bit(TWCR,Pin2);

	/*Start sequence*/
	Set_Bit(TWCR,Pin5);

	while(Flag==0);

	/*Sequence has been started*/
	while((TWSR&0xf8)!= 0x08);

}

void I2C_MasterSend(u8 u8Add, u8 u8Data)
{
	/*Write the Slave Address*/
	TWDR=u8Add+READ;

	/*Clear Flag*/
	ClearFlag();

	while(Flag==0);

	/*Slave Add has been sent and slave has been ack*/
	while((TWSR&0xf8)!= 0x18);

	/*Write Data*/
	TWDR=u8Data;

	/*Clear Flag*/
	ClearFlag();

	while(Flag==0);

	/*data has been sent*/
	while((TWSR&0xf8)!= 0x28);
}


void I2C_MasterStopSequence()
{
	/*Clear Flag*/
	ClearFlag();

	/*Stop Sequence*/
	Set_Bit(TWCR,Pin4);

}
