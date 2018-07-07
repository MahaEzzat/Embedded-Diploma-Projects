/*
 * SPI.c
 *
 *  Created on: Jun 30, 2018
 *      Author: Maha
 */

#include "SPI.h"
#include "Utils.h"

void SPI_voidInit(u8 u8MASTER_SLAVE)
{
	/*Pre-scaler /4 */
	Clr_Bit(SPCR,Pin0);
	Clr_Bit(SPCR,Pin1);

	/*Clock Polarity*/
	Clr_Bit(SPCR,Pin2);
	Clr_Bit(SPCR,Pin3);

	switch(u8MASTER_SLAVE)
	{
	case MASTER:
		/*DIO Master*/
		DIO_voidSetDir(PortB,Pin4,Output); /*ss*/
		DIO_voidWriteVal(PortB,Pin4,Zero_Volt); /*select the slave ship*/
		DIO_voidSetDir(PortB,Pin5,Output); /*MOSI*/
		DIO_voidSetDir(PortB,Pin6,Input);  /*MISO*/
		DIO_voidSetDir(PortB,Pin7,Output); /*SCK*/
		/*Master Mode*/
		Assign_Bit(SPCR,Pin4,MASTER);
		break;

	case SLAVE:
		/*DIO Slave*/
		DIO_voidSetDir(PortB,Pin4,Input); /*ss*/
		DIO_voidSetDir(PortB,Pin5,Input); /*MOSI*/
		DIO_voidSetDir(PortB,Pin6,Output);  /*MISO*/
		DIO_voidSetDir(PortB,Pin7,Input); /*SCK*/
		/*Slave Mode*/
		Assign_Bit(SPCR,Pin4,SLAVE);
		break;
	}

	/*Enable SPI*/
	Set_Bit(SPCR,Pin6);

	/*Disable INT*/
	Global_Interrupt_Disable();

}
u8 SPI_u8Data(u8 u8Data)
{
	SPDR=u8Data;
	while(Flag!=1){}
	return SPDR;
}

