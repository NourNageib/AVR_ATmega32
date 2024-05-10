/*
 * main.c
 *
 *  Created on: Jan 5, 2024
 *      Author: Nour
 */


#define F_CPU 8000000UL
#include <stdio.h>
#include "STD_types.h"
#include "AVR_REGs.h"
#include <avr/delay.h>
#include "BIT_math.h"

#include "MDIO_config.h"
#include "MDIO_interface.h"
#include "MDIO_private.h"

#include "HLCD_private.h"
#include "HLCD_config.h"
#include "HLCD_interface.h"

#include "HKPD_config.h"
#include "HKPD_private.h"
#include "HKPD_interface.h"



int main(void)
{


	HAL_LCD_Init();
	LCD_init();
	KPD_Init();



	while(1)
	{

		uinit8_t val = KPDGetValueinReturn();
		if(val != DEFAULT_KEY)
		{
			LCD_enuWriteCharacter(val);
					_delay_ms(900);
		}

	}



  return 0;
}
