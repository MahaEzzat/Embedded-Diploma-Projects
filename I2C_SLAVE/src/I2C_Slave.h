/*
 * I2C_Slave.h
 *
 *  Created on: Jul 6, 2018
 *      Author: Maha
 */

#ifndef I2C_SLAVE_H_
#define I2C_SLAVE_H_

#include "Utils.h"
#include "DIO.h"

#define SREG *((volatile u8*)(0x5f))
#define TWAR *((volatile u8*)(0x22))
#define TWBR *((volatile u8*)(0x20))
#define TWCR *((volatile u8*)(0x56))
#define TWDR *((volatile u8*)(0x23))
#define TWSR *((volatile u8*)(0x21))

#define ClearFlag() Set_Bit(TWCR,Pin7)
#define Flag Get_Bit(TWCR,Pin7)
#define Global_Interrupt_Disable() Clr_Bit(SREG,Pin7)

#define WRITE 1
#define READ 0

void I2C_SlaveAdd(u8 u8Add);
u8 I2C_u8SlaveRead();


#endif /* I2C_SLAVE_H_ */
