/*
 * Relay.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#include "Relay.h"

void Relay_Init()
{
	DIO_voidSetDir(PortA,Pin2,Output); /* Set pin 2A as an output pin (relay)*/
}
void Relay(u8 u8State)
{
	DIO_voidWriteVal(PortA,Pin2,u8State);
}
