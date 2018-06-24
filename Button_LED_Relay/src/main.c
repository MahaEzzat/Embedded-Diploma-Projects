/*
 * main.c
 *
 *  Created on: Jun 24, 2018
 *      Author: Maha
 */

#include "Button.h"
#include "LED.h"
#include "Relay.h"
#include "avr/delay.h"

int main()
{
	Button_Init(0);
	Button_Init(1);
	LED_Init(0);
	Relay_Init();

	while(1)
	{
		if(Button_Read(0)==Pressed && Button_Read(1)==NotPressed)
			{
				LED(0,ON);
				Relay(OFF);
			}
			else if (Button_Read(1)==Pressed && Button_Read(0)==NotPressed)
				{
					LED(0,OFF);
					Relay(ON);
				}
				else if(Button_Read(1)==Pressed && Button_Read(0)==Pressed)
					{
						LED(0,ON);
						Relay(ON);
						_delay_ms(1000);
					}
					else
					{
						LED(0,OFF);
						Relay(OFF);
					}
	}
}
