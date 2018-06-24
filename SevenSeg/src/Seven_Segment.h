/*
 * Seven_Segment.h
 *
 *  Created on: Jun 23, 2018
 *      Author: Maha
 */

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_
#include "DIO.h"

void SS_Init();
void SS_Mode(u8 Number);
void SS_Write(u8 u8Number, u8 u8channel);

#endif /* SEVEN_SEGMENT_H_ */
