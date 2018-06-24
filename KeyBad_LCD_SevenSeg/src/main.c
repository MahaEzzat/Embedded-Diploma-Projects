/*
 * main.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#include "avr/delay.h"
#include "KeyBad.h"
#include "Seven_Segment.h"
#include "LCD.h"

#define KeyBad_First_Click 1
#define KeyBad_Last_Click 2

/*Selected Mode*/
#define MODE KeyBad_First_Click



int main()
{
	KeyBad_Init();
	SS_Init();
	LCD_Init();

	while(1)
	{

/*******************************************************************************************/
/*KeyBoard(1st Pressed)*/
		#if MODE==KeyBad_First_Click
			u8 key,pressed=0;
			pressed=KeyBad_Pressed(&key,KeyBad_First_Click);
			if(pressed)
			{
				LCD_WriteData(key);
				SS_Write(key-=48,0);
			}
			else
			{
				LCD_WriteData('0');
				SS_Write(0,0);
			}
			_delay_ms(1000);
			LCD_CLear();

		#endif
/*******************************************************************************************/
/*KeyBoard(Last Pressed)*/
		#if MODE==KeyBad_Last_Click
			u8 key,pressed=0;
			pressed=KeyBad_LastPressed(&key);
			if(pressed)
				LCD_WriteData(key);
			_delay_ms(1000);
			LCD_CLear();
			#endif
/*******************************************************************************************/
		}

}
