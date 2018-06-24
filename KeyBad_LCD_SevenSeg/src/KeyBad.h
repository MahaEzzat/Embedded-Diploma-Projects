/*
 * KeyBoard.h
 *
 *  Created on: Jun 22, 2018
 *      Author: Maha
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_
#include "STD_Types.h"

void KeyBad_Init();
u8 KeyBad_Pressed(u8* key,u8 order);
u8 KeyBad_LastPressed(u8* key);

#endif /* KEYBOARD_H_ */
