/*
 * Relay.h
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#ifndef RELAY_H_
#define RELAY_H_
#define ON 1
#define OFF 0
#include "DIO.h"

void Relay_Init();
void Relay(u8 u8State);


#endif /* RELAY_H_ */
