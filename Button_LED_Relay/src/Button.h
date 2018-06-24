/*
 * Button.h
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#include "DIO.h"
#define Pressed 1
#define NotPressed 0

void Button_Init(u8 u8Number);
u8 Button_Read(u8 u8Number);


#endif /* BUTTON_H_ */
