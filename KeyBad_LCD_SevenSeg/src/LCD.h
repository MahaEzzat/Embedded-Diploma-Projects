/*
 * LCD.h
 *
 *  Created on: Jun 9, 2018
 *      Author: Maha
 */

#ifndef LCD_H_
#define LCD_H_
#include "STD_Types.h"


void LCD_Init(void);
void LCD_WriteData(u8 data);
void LCD_WriteCommand(u8 command);
void LCD_CLear();
void LCD_GoTo(u8 x,u8 y);
u8 LCD_WrtireString(u8* str);

/* Arabic dictionary */
void LCD_Set_CG_Add(u8 add);
void LCD_Set_Entry_Mode(u8 I_D);
void LCD_LCD_Shift();
void LCD_Set_DD_Add(u8 add);
void LCD_Arabic_Dict(u8 charact);
void LCD_Arab_Dict1();
void LCD_Arab_Dict2();
void LCD_Arab_Dict3();
void LCD_Arab_Dict4();
void LCD_WriteArabicData(u8 data);
u8 IS_WRITTEN(u8 data);
u8 LCD_WrtireString_Arabic(u8* str);
#endif /* LCD_H_ */
