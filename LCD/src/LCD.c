/*
 * LCD.c
 *
 *  Created on: Jun 9, 2018
 *      Author: Maha
 */
#include "LCD.h"
#include "Utils.h"
#include "DIO.h"
#include <avr/delay.h>

static u8 charact_prev[8]={28,28,28,28,28,28,28,28};
static u8 charact_number=0;
static u8 current_charact=0;
static u8 English_Char=0;

void LCD_WriteCommand(u8 com)
{

	DIO_voidWriteVal(PortD,Pin0,Zero_Volt); /*RS=0*/

	Assign_Nibble_High(PORTC,(Get_Nibble_High(com)));
	DIO_voidWriteVal(PortD,Pin1,Five_Volt); /*E=1*/
	_delay_ms(2);
	DIO_voidWriteVal(PortD,Pin1,Zero_Volt); /*E=0*/

	Assign_Nibble_High(PORTC,(Get_Nibble_Low(com)));
	DIO_voidWriteVal(PortD,Pin1,Five_Volt); /*E=1*/
	_delay_ms(2);
	DIO_voidWriteVal(PortD,Pin1,Zero_Volt); /*E=0*/

}

void LCD_Init(void)
{
	DIO_voidSetDir(PortD,Pin0,Output); /*RS(DDRD,0) output*/
	DIO_voidSetDir(PortD,Pin1,Output); /*E(DDRD,1) output*/
	/*LCD Data Bus as output */
	DIO_voidSetDir(PortC,Pin4,Output);
	DIO_voidSetDir(PortC,Pin5,Output);
	DIO_voidSetDir(PortC,Pin6,Output);
	DIO_voidSetDir(PortC,Pin7,Output);

	_delay_ms(50);
	LCD_WriteCommand(0x02);

	/*LCD_WriteCommand(0x20); for 1 line*/
	LCD_WriteCommand(0x28); /*for 2 lines*/
	_delay_ms(10);
	LCD_WriteCommand(0x0c);
	_delay_ms(10);
	LCD_CLear();
	LCD_Set_Entry_Mode(1);

}

void LCD_WriteData(u8 com)
{

	Set_Bit(PORTD,0); /*RS*/

	Assign_Nibble_High(PORTC,(Get_Nibble_High(com)));
	DIO_voidWriteVal(PortD,Pin1,Five_Volt); /*E=1*/
	_delay_ms(20);
	DIO_voidWriteVal(PortD,Pin1,Zero_Volt); /*E=0*/

	Assign_Nibble_High(PORTC,(Get_Nibble_Low(com)));
	DIO_voidWriteVal(PortD,Pin1,Five_Volt); /*E=1*/
	_delay_ms(20);
	DIO_voidWriteVal(PortD,Pin1,Zero_Volt); /*E=0*/
	English_Char++;

}

void LCD_CLear()
{
	LCD_WriteCommand(0x01);
	_delay_ms(20);
	charact_number=0;
}

void LCD_GoTo(u8 x, u8 y)
{
	if(y)
		English_Char=4*16+x;
	else
		English_Char=x;

	LCD_Set_DD_Add(English_Char);

}


u8 LCD_WrtireString(u8* str)
{
	u8 count=0;
	u8 size=0;

	while( (!((*(str+count))=='\0')) && size<=16)
	{
		count++;
		size++;
	}

	if(size<=16)
	{
		for(count=0;count<size;count++)
			LCD_WriteData(*(str+count));
		return 1;
	}
	else
		return 0;

}


void LCD_Set_CG_Add(u8 add)
{
	LCD_WriteCommand(add);
	_delay_ms(10);

}

void LCD_Shift()
{
	LCD_WriteCommand(0x1c);
	_delay_ms(10);
}
void LCD_Set_Entry_Mode(u8 I_D)
{
	if(I_D)
		LCD_WriteCommand(0x06);
	else
		LCD_WriteCommand(0x07);
	_delay_ms(10);
}

void LCD_Set_DD_Add(u8 add)
{
	LCD_WriteCommand(add);
	_delay_ms(10);
}


void LCD_Arabic_Dict(u8 charact)
{
	LCD_Set_CG_Add(0x40+8*charact_number);
	switch (charact)
	{
	int count;
	case 1:
		/* alf */
	    for(count=0;count<5;count++)
	    	LCD_WriteData(0x04);
	    LCD_WriteData(0x07);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 2:
		/* ba2 */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0xff);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x01);
	    break;

	case 3:
		/* ta2 */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0xf5);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0xff);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 4:
		/* tha2 */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x08);
	    LCD_WriteData(0xf5);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0xff);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 5:
		/* gem */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x0c);
	    LCD_WriteData(0xf2);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0xff);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x01);
	    break;

	case 6:
		/* 7a2 */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x0c);
	    LCD_WriteData(0xf2);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0xff);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 7:
		/* kha2 */
	    LCD_WriteData(0x04);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x0c);
	    LCD_WriteData(0xf2);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0xff);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 8:
		/* dal */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x0f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 9:
		/* zal */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x0f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 10:
		/* ra2 */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x03);
	    LCD_WriteData(0x02);
	    LCD_WriteData(0x04);
	    break;

	case 11:
		/* zan */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x02);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x03);
	    LCD_WriteData(0x02);
	    LCD_WriteData(0x04);
	    break;

	case 12:
		/* seen */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x15);
	    LCD_WriteData(0x15);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 13:
		/* sheen */
	    LCD_WriteData(0x04);
	    LCD_WriteData(0x0a);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x15);
	    LCD_WriteData(0x15);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 14:
		/* saad */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x06);
	    LCD_WriteData(0x09);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 15:
		/* daad */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x04);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x06);
	    LCD_WriteData(0x09);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 16:
		/* taah */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x08);
	    LCD_WriteData(0x08);
	    LCD_WriteData(0x0e);
	    LCD_WriteData(0x09);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 17:
	    /* zaah */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x0a);
	    LCD_WriteData(0x08);
	    LCD_WriteData(0x0e);
	    LCD_WriteData(0x09);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 18:
		/* 3een */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x07);
	    LCD_WriteData(0x08);
	    LCD_WriteData(0x08);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 19:
		/* 3'een */
	    LCD_WriteData(0x04);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x07);
	    LCD_WriteData(0x08);
	    LCD_WriteData(0x08);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 20:
		/* faa2 */
	    LCD_WriteData(0x02);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x03);
	    LCD_WriteData(0x03);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 21:
		/* k'aaf */
	    LCD_WriteData(0x03);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x03);
	    LCD_WriteData(0x03);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 22:
		/* kaaf */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x0f);
	    LCD_WriteData(0x04);
	    LCD_WriteData(0x02);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 23:
		/* laam */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 24:
		/* meem */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x03);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x03);
	    LCD_WriteData(0x00);
	    break;

	case 25:
		/* noon */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x05);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    break;

	case 26:
		/* heeh */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x06);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x06);
	    LCD_WriteData(0x00);
	    break;

	case 27:
		/* waaw */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x03);
	    LCD_WriteData(0x03);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x02);
	    break;

	case 28:
		/* yaah */
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x01);
	    LCD_WriteData(0x1f);
	    LCD_WriteData(0x00);
	    LCD_WriteData(0x0a);
	}
	English_Char-=8;
	LCD_Set_DD_Add(0x80+charact_number+English_Char);

}
void LCD_WriteArabicData(u8 data)
{
	if(!(IS_WRITTEN(data)))
	{
		LCD_Arabic_Dict(data);
		LCD_WriteData(charact_number);
	    charact_number++;
	    if(charact_number>7)
	    	charact_number=0;
	}
	else
		LCD_WriteData(current_charact);
	English_Char--;

}

u8 IS_WRITTEN(u8 data)
{
	int count;
	for(count=0;count<8;count++)
		if(charact_prev[count]==data)
		{
			current_charact=count;
			return 1;
		}
	charact_prev[charact_number]=data;

	return 0;
}

u8 LCD_WrtireString_Arabic(u8* str)
{
	if(English_Char>6*16+7)
		English_Char=0;

	int count=0;
	u8 size=0;

	while( (!((*(str+count))=='\0')) && size<=16)
	{
		count++;
		size++;
	}

		if(size<=16)
		{
			for(count=size-1;count>=0;count--)
			{
				if((*(str+count))<=28)
					LCD_WriteArabicData(*(str+count));
				else
					LCD_WriteData(*(str+count));
			}
			return 1;
		}
		else
			return 0;
}
