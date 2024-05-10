/*
 * main.c
 *
 *  Created on: Dec 11, 2023
 *      Author: Nour
 */

#define F_CPU 8000000UL

#include <stdio.h>
#include <util/delay.h>

#include "STD_types.h"
#include  "AVR_REGs.h"
#include "BIT_math.h"
#include  "MDIO_config.h"
#include "MDIO_interface.h"


int main(void)
{
	//MDIO_DDRA =0XFF;
	MDIO_SetPortDirection(MDIO_enumPortA,MDIO_enumOutput_LOW);

	uinit8_t counter;
	while(1)
	{
		counter =0;
			//MDIO_PORTA=0x00;
			MDIO_SetPortValue(MDIO_enumPortA,MDIO_enumOutput_LOW);
			uinit8_t Value;
			MDIO_GetPortValue(MDIO_enumPortA,&Value);
			while(Value<255)
			{
				_delay_ms(500);
				MDIO_AssignPortValue(MDIO_enumPortA,counter);
				counter++;
			}

	}



	return 0;
}
