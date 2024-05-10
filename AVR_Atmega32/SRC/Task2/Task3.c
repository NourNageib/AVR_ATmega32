/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	Task      : Task3        		*/
/*  Layer	  : APP  				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 19, 2023	*/
/*	Last Edit :	N/A					*/
/************************************/
#define F_CPU 8000000UL

#include <stdio.h>
#include <util/delay.h>

#include "../../LIB/STD_types.h"
#include  "../../MCAL/MDIO/AVR_REGs.h"
#include "../../LIB/BIT_math.h"
#include  "../../MCAL/MDIO/MDIO_config.h"
#include "../../MCAL/MDIO/MDIO_interface.h"

#include "../../HAL/LED/LED_config.h"
#include "../../HAL/LED/LED_interface.h"

#include "../../HAL/SWITCH/SWITCH_config.h"
#include "../../HAL/SWITCH/SWITCH_interface.h"

int main(void)
{

	MDIO_SetPortDirection(MDIO_enumPortA,MDIO_enumOutput_LOW);/*LED */
	HAL_SWITCH_INIT();


	while(1)
	{
		if(!HAL_SWITCH_GETState(SWITCH_Global_Array[0]))
		{
			HLED_SetSingleLED_ON(MDIO_enumPortA,MDIO_enumPin0);
			_delay_ms(500);
			HLED_SetSingleLED_OFF(MDIO_enumPortA,MDIO_enumPin0);
		}


	}



	return 0;
}
