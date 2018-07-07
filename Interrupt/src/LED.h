/*
 * LED.h
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#ifndef LED_H_
#define LED_H_
#define ON 1
#define OFF 0
#include "DIO.h"

void LED_Init(u8 u8LedNumber);
void LED(u8 u8LedNumber, u8 u8State);
void ToggleLED(u8 u8LedNumber);

#endif /* LED_H_ */
