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
#include "BIT_math.h"

#include <util/delay.h>
#include "MDIO_config.h"
#include "MDIO_interface.h"
#include "MDIO_private.h"

#include "HLCD_private.h"
#include "HLCD_config.h"
#include "HLCD_interface.h"

/*
 APP1:
 HAL_LCD_Init();
 LCD_init();
 LCD_enumPrintStringwithLocation(1,1,"Char :");
 LCD_enumPrintStringwithLocation(2,1,"ASCII :");
 sint8_t mychar='A';[0:25]
 while(1)
 {
 	 LCD_enumPrintStringwithLocation(1,7,mychar);
 	 LCD_enuGotoDDRAM_XY(2,7);
 	 LCD_enuWriteNumber(mychar);
 	 mychar++;
 	 _delay_ms(500);
 }

*/




int main(void)
{
	 HAL_LCD_Init();
	 LCD_init();
	 LCD_enuWriteNumber(-776);
	 _delay_ms(7000);
	 LCD_enuWriteCommand(0x01);
	 _delay_ms(7000);
	 LCD_enuWriteNumber(0);
	 _delay_ms(7000);
	 LCD_enuWriteCommand(0x01);
	 LCD_enuWriteNumber(15845);
	 _delay_ms(7000);


              /* LCD_enuWriteCommand(0x01);
        LCD_enumPrintStringwithLocation(1,1,"Char  :");
        	 LCD_enumPrintStringwithLocation(2,1,"ASCII :");
        	 sint8_t mychar='A';*/
    /*	  */
	// LCD_enuWriteNumber(123);
	 //
/*
	 */

	while(1)
	{
		  _delay_ms(7000);
		        LCD_enuWriteCommand(0x01);
		        LCD_enuGotoDDRAM_XY(1,1);
		        LCD_enuWriteString(" Stop Watch ");
		        LCD_enuGotoDDRAM_XY(2,1);
		        LCD_enuWriteString("  00:00:00 ");
		        _delay_ms(7000);
		/*
		     LCD_enuGotoDDRAM_XY(1,9);
		     LCD_enuWriteCharacter(mychar);
		 	 LCD_enuGotoDDRAM_XY(2,9);
		 	 LCD_enuWriteNumber(mychar);
		 	 mychar++;
		 	 _delay_ms(500);
		 	 */

	}



  return 0;
}
