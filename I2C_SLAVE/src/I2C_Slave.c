/*
 * I2C_Slave.c
 *
 *  Created on: Jul 6, 2018
 *      Author: Maha
 */


/*
 * I2C_Master.c
 *
 *  Created on: Jul 6, 2018
 *      Author: Maha
 */
#include "I2C_Slave.h"
#include "DIO.h"
#include "Utils.h"


void I2C_SlaveAdd(u8 u8Add)
{
	/*Slave Add*/
	 TWAR=u8Add;
}

u8 I2C_u8SlaveRead()
{
	/*Clear Flag*/
	ClearFlag();

	/*enable ACK*/
	Set_Bit(TWCR,Pin6);

	/*enable I2C*/
	Set_Bit(TWCR,Pin2);

	while(Flag==0);

	/*address and ack received*/
	while((TWSR&0xf8)!= 0x60);

	/*Clear FLag*/
	ClearFlag();

	while(Flag==0);

	/*data and ack received*/
	while((TWSR&0xf8)!= 0x60);

	return TWDR;

}

