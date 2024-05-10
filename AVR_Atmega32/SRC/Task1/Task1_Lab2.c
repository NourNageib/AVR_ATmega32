 /***********************************/
 /*	Author 	  : Nour Abd-elaziz     */
 /*	Swc		  : DIO   		        */
 /*	Layer	  : MCAL                */
 /*	Version   : 1.1                 */
 /*	Date	  : December 1 , 2023   */
 /*	Last Edit : December 12 , 2023  */
 /***********************************/
 /*
 //#define F_CPU 8000000UL
 #include <util/delay.h>
 #include  "../../LIB/STD_types.h"
 #include  "../../LIB/BIT_math.h"

 #include  "../../MCAL/MDIO/AVR_REGs.h"

 #include  "../../MCAL/MDIO/MDIO_config.h"
 #include  "../../MCAL/MDIO/MDIO_interface.h"

 #include "../../HAL/LED/LED_config.h"
 #include "../../HAL/LED/LED_interface.h"

 
 int main(void)
 {
	 HLED_SetLEDDirection(MDIO_enumPortA,MDIO_enumPin0);
	 HLED_SetLEDDirection(MDIO_enumPortA,MDIO_enumPin1);
	 HLED_SetLEDDirection(MDIO_enumPortA,MDIO_enumPin2);
	 while(1)
	 {
		 

		 _delay_ms(500);

		 HLED_SetSingleLED_ON(MDIO_enumPortA,MDIO_enumPin0);
		 HLED_SetSingleLED_ON(MDIO_enumPortA,MDIO_enumPin1);
		 _delay_ms(500);
		 HLED_SetSingleLED_OFF(MDIO_enumPortA,MDIO_enumPin1);
		 HLED_SetSingleLED_OFF(MDIO_enumPortA,MDIO_enumPin0);
		 HLED_SetSingleLED_ON(MDIO_enumPortA,MDIO_enumPin2);
		 _delay_ms(500);
		 HLED_SetSingleLED_OFF(MDIO_enumPortA,MDIO_enumPin2);
	 }
	 
 }
*/