/*
 * Lcd_Modes.c
 *
 *  Created on: Jun 23, 2018
 *      Author: Maha
 */
#include "Lcd_Modes.h"
#include "LCD.h"
#include "DIO.h"
#include "Arabic.h"
#include <avr/delay.h>

void LCD_Mode_Init()
{
	LCD_Init();

}


void LCD_Mode(u8 Number)
{
	u8* data="Maha Ezzat";
	u8* data1="Mah";
	u8* data2="Ezz";
	s8 count,count2=0,count3=0;
	u8 Arabic_name[8]={al,ai,ah,' ',au,aN,aj,'\0'};

	switch (Number)
	{

/*******************************************************************************************/
	/*LCD Mod10(Arabic)*/
	case 10:

		LCD_WrtireString(data);
		LCD_GoTo(5,1);
		LCD_WrtireString_Arabic(Arabic_name);

		break;
/*******************************************************************************************/
	/*LCD Mod9*/
	case 9:
		while(1)
		{
			if(count2<10)
			{
				for(count=0;count<=9-count2;count++)
				{
					for(count3=0;count3<count;count3++)
						LCD_WriteData(' ');
					LCD_WriteData(*(data+(9-count2)));

					for(count3=0;count3<9-count2-count;count3++)
						LCD_WriteData(' ');
					for(count3=10-count2;count3<10;count3++)
						LCD_WriteData(*(data+count3));

					_delay_ms(1000);
					LCD_CLear();
				}
			}
			else
			{
				if(count2%2)
				{
					for(count=0;count<10;count++)
						LCD_WriteData(*(data+count));
				}
			}
				count2++;
				if(count2>15)
					count2=0;
				_delay_ms(1000);
				LCD_CLear();
		}
			break;
/*******************************************************************************************/
	/*LCD Mod8*/
	case 8:
		while(1)
		{
			for(count=0;count<count2;count++)
				LCD_WriteData(' ');
			for(count=0;count<3;count++)
				LCD_WriteData(*(data1+count));

			LCD_WriteCommand(0xc0);
			for(count=13-count2;count>0;count--)
				LCD_WriteData(' ');
			for(count=0;count<3;count++)
				LCD_WriteData(*(data2+count));

			count2++;
			if(count2>13)
				count2=0;
			_delay_ms(1000);
			LCD_CLear();
	}
		break;
/*******************************************************************************************/
	/*LCD Mod7*/
	case 7:
		while(1)
		{
			if(count2%2)
				LCD_WriteCommand(0xc0);
			for(count=2*count2;count>0;count--)
				LCD_WriteData(' ');
			for(count=0;count<4;count++)
				LCD_WriteData(*(data+count));
			count2++;
			if(count2>5)
				count2=0;
			_delay_ms(1000);
			LCD_CLear();
		}
		break;
/*******************************************************************************************/
	/*LCD Mod6*/
	case 6:
		while(1)
		{
			if(count2<16)
			{
				for(count=0;count<count2;count++)
					LCD_WriteData(' ');
				for(count=0;count<10;count++)
					LCD_WriteData(*(data+count));
				if (count2>6)
				{
					LCD_WriteCommand(0xc0);
					for(count=0;count<22-count2;count++)
						LCD_WriteData(' ');

					for(count=16-count2;count<10;count++)
						LCD_WriteData(*(data+count));
				}
			}

			else if(count2<22)
				{
					LCD_WriteCommand(0xc0);
					for(count=0;count<22-count2;count++)
						LCD_WriteData(' ');

					for(count=0;count<10;count++)
						LCD_WriteData(*(data+count));
				}
			else
			{
				for(count=0;count<=count2-22;count++)
					LCD_WriteData(*(data+count));

				LCD_WriteCommand(0xc0);
				for(count=count2-22;count<10;count++)
					LCD_WriteData(*(data+count));
			}

			count2++;
			if(count2>30)
				count2=0;
			_delay_ms(1000);
			LCD_CLear();
		}
		break;

/*******************************************************************************************/
	/*LCD Mod5*/
	case 5:
		while(1)
		{
			if(count2<16)
			{
				for(count=0;count<count2;count++)
					LCD_WriteData(' ');


				for(count=0;count<10;count++)
					LCD_WriteData(*(data+count));

				if (count2>6)
				{
					LCD_WriteCommand(0xc0);
					for(count=16-count2;count<10;count++)
						LCD_WriteData(*(data+count));
				}
			}

			else if(count2<22)
			{
				LCD_WriteCommand(0xc0);
				for(count=0;count<count2-16;count++)
					LCD_WriteData(' ');

				for(count=0;count<10;count++)
					LCD_WriteData(*(data+count));
			}
			else
			{
				for(count=31-count2;count<10;count++)
					LCD_WriteData(*(data+count));

				LCD_WriteCommand(0xc0);
				for(count=0;count<count2-16;count++)
					LCD_WriteData(' ');

				for(count=0;count<10;count++)
					LCD_WriteData(*(data+count));
			}
			count2++;
			if(count2>30)
				count2=0;
			_delay_ms(1000);
			LCD_CLear();
		}
		break;
/*******************************************************************************************/
	case 4:
		while(1)
		{
			if(count2<16)
			{
				for(count=0;count<count2;count++)
					LCD_WriteData(' ');

				for(count=0;count<10;count++)
					LCD_WriteData(*(data+count));
			}
			_delay_ms(1000);
			LCD_CLear();
			count2++;
			if(count2>16)
				count2=0;
		}
/*******************************************************************************************/
	}
}
