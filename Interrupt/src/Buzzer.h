/*
 * Buzzer.h
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#define ON 1
#define OFF 0

#include "DIO.h"

void Buzzer_Init();
void Buzzer(u8 u8State);
void Buzzer_Toggle();


#endif /* BUZZER_H_ */
