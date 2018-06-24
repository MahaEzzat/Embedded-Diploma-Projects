/*
 * DIO.h
 *
 *  Created on: Jun 8, 2018
 *      Author: Shrouk
 */

#ifndef DIO_H_
#define DIO_H_

#include "DIO_Private.h"
#include "STD_Types.h"

void DIO_voidInit(); /* Init. All i/o pins as input pins */
u8 DIO_u8GetVal(u8 u8PORT, u8 u8PIN);
void DIO_voidWriteVal(u8 u8Port, u8 u8Pin, u8 u8Val);
void DIO_voidSetDir(u8 u8Port, u8 u8Pin, u8 u8Dir);


#endif /* DIO_H_ */
