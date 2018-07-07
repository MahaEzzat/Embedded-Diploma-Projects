/*
 * Timer.c
 *
 *  Created on: Jun 29, 2018
 *      Author: Maha
 */


#include "Timer.h"

void TIMERINT_voidInit(u8 u8Type)
{
	switch (u8Type)
	{
	case NORMAL:
		/*Pre-Scaler (/8) */
		Clr_Bit(TCCR0,Pin0);
		Set_Bit(TCCR0,Pin1);
		Clr_Bit(TCCR0,Pin2);

		/*Enable Timer INT*/
		Set_Bit(TIMSK,Pin0);

		/*Normal Mode*/
		Clr_Bit(TCCR0,Pin6);
		Clr_Bit(TCCR0,Pin3);
	break;

	case CTC:
		/*Pre-Scaler (/8) */
		Clr_Bit(TCCR0,Pin0);
		Set_Bit(TCCR0,Pin1);
		Clr_Bit(TCCR0,Pin2);

		/*Enable Timer INT*/
		Set_Bit(TIMSK,Pin1);

		/*Normal Mode*/
		Clr_Bit(TCCR0,Pin6);
		Set_Bit(TCCR0,Pin3);

		/*Assign Compare value*/
		OCR0=128;
	break;

	case PW_PASE:
		/*Pre-Scaler (/8) */
		Clr_Bit(TCCR0,Pin0);
		Set_Bit(TCCR0,Pin1);
		Clr_Bit(TCCR0,Pin2);

		/*Enable Timer INT*/
		Set_Bit(TIMSK,Pin1);

		/*Normal Mode*/
		Clr_Bit(TCCR0,Pin6);
		Set_Bit(TCCR0,Pin3);

		/*Assign Compare value*/
		OCR0=128;
	break;



	case FAST_PW:
		/*Pre-Scaler (/8) */
		Clr_Bit(TCCR0,Pin0);
		Set_Bit(TCCR0,Pin1);
		Clr_Bit(TCCR0,Pin2);

		/*FAST PW Mode*/
		Set_Bit(TCCR0,Pin6);
		Set_Bit(TCCR0,Pin3);
		DIO_voidSetDir(PortB,Pin3,Output);


		/*oc0 Mode*/
		Set_Bit(TCCR0,Pin4);
		Set_Bit(TCCR0,Pin5);

		/*Assign Compare value*/
		OCR0=60;
	}
}
