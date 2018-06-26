/*
 * main.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#include "DAC.h"


int main()
{
	DAC_voidInit();
	while(1)
	{
		DAC_voidOutput(RAMP);
	}
}
