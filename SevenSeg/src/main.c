#include "Seven_Segment.h"

int main()
{
	SS_Init();
	LED_Init(0);
	LED_Init(1);
	Buzzer_Init();

	while(1)
	{
		SS_Mode(1); /*Count Down*/
	}
}
