/*
 * SPI.h
 *
 *  Created on: Jun 30, 2018
 *      Author: Maha
 */

#ifndef SPI_H_
#define SPI_H_
#include "DIO.h"

#define SREG *((volatile u8*)(0x5f))
#define SPCR *((volatile u8*)(0x2d))
#define SPSR *((volatile u8*)(0x2e))
#define SPDR *((volatile u8*)(0x2f))

#define Flag Get_Bit(SPSR,Pin7)

#define Global_Interrupt_Enable() Set_Bit(SREG,Pin7)
#define Global_Interrupt_Disable() Clr_Bit(SREG,Pin7)

#define MASTER 1
#define SLAVE 0

void SPI_voidInit(u8 u8MASTER_SLAVE);
u8 SPI_u8Data(u8 u8Data); /*Trans_Rec function*/

#endif
/* SPI_H_ */
