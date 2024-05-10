/*
 * main.c
 *
 *  Created on: Jan 5, 2024
 *      Author: Nour
 */


//#define F_CPU 8000000UL
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

#include "UART_Interface.h"
#include "UART_Service.h"

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
	 LCD_enuWriteCommand(CLEAR_LCD_SCREEN);
	 _delay_ms(7000);
	 LCD_enuWriteNumber(0);
	 _delay_ms(7000);
	 LCD_enuWriteCommand(CLEAR_LCD_SCREEN);
	 LCD_enuWriteNumber(15845);
	 _delay_ms(7000);
	 LCD_enumPrintStringwithLocation(1,3,"UART TEST");
     UART_Init();

              /* LCD_enuWriteCommand(0x01);
        LCD_enumPrintStringwithLocation(1,1,"Char  :");
        	 LCD_enumPrintStringwithLocation(2,1,"ASCII :");
        	 sint8_t mychar='A';*/
    /*	  */
	// LCD_enuWriteNumber(123);
	 //
/*
	 */
	/*Before busy wait you wil corupt data will only send 
	  First Byte */
	LCD_enuWriteCommand(CLEAR_LCD_SCREEN);
	// LCD_enuGotoDDRAM_XY(2,4);
	// UART_SendData('N');
	// UART_SendData('o');
	// UART_SendData('u');
	// UART_SendData('r');
	// _delay_ms(2000);
	// LCD_enuWriteCommand(CLEAR_LCD_SCREEN);
	UART_SendStringSynchrounous("Nour");
	UART_SendStringSynchrounous("& Aliah");
    uint8_t X,DataByte,DataBuffer[20];
	LCD_enuGotoDDRAM_XY(2,4);
	while(1)
	{
		LCD_enuWriteCommand(CLEAR_LCD_SCREEN);
		UART_ReceiveString(DataBuffer);
		LCD_enuGotoDDRAM_XY(1,0);
		LCD_enuWriteString(DataBuffer);
		//    if(UART_ReceiveDataPeriodically( &DataByte))
		//    {
		// 	LCD_enuWriteCommand(CLEAR_LCD_SCREEN);
		// 	LCD_enuGotoDDRAM_XY(1,8);
		// 	LCD_enuWriteData(DataByte);
		//    }
		//   _delay_ms(7000);
		//         LCD_enuWriteCommand(0x01);
		//         LCD_enuGotoDDRAM_XY(1,0);
		// 		LCD_enuWriteCharacter(X);
				X++;
				if (X==10)
				{
					X=0;
				}
			/*Print on LCD 0->9*/
			UART_SendData('0'+X);
				
		       
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
