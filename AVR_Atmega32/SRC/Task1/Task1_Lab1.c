 /***********************************/
 /*	Author 	  : Nour Abd-elaziz     */
 /*	Swc		  : DIO   		        */
 /*	Layer	  : MCAL                */
 /*	Version   : 1.1                 */
 /*	Date	  : December 1 , 2023   */
 /*	Last Edit : December 12 , 2023  */
 /***********************************/
 
 #define F_CPU 8000000
 #include <util/delay.h> 
 #include  "../../LIB/STD_types.h"
 #include  "../../LIB/BIT_math.h"

 #include  "../../MCAL/MDIO/AVR_REGs.h"

 #include  "../../MCAL/MDIO/MDIO_config.h"
 #include  "../../MCAL/MDIO/MDIO_interface.h"
 
int main(void)
{
	MDIO_SetPinDirection(MDIO_enumPortA,MDIO_enumPin0,MDIO_enumOutput_LOW);
	MDIO_SetPinDirection(MDIO_enumPortA,MDIO_enumPin1,MDIO_enumOutput_LOW);
	MDIO_SetPinDirection(MDIO_enumPortA,MDIO_enumPin2,MDIO_enumOutput_LOW);
	while(1)
	{
		

		_delay_ms(500);

		MDIO_SetPinValue(MDIO_enumPortA,MDIO_enumPin0,MDIO_enumOutput_HIGH);
		MDIO_SetPinValue(MDIO_enumPortA,MDIO_enumPin1,MDIO_enumOutput_HIGH);
		_delay_ms(500);
		MDIO_SetPinValue(MDIO_enumPortA,MDIO_enumPin1,MDIO_enumOutput_LOW);
		MDIO_SetPinValue(MDIO_enumPortA,MDIO_enumPin0,MDIO_enumOutput_LOW);
		MDIO_SetPinValue(MDIO_enumPortA,MDIO_enumPin2,MDIO_enumOutput_HIGH);
		_delay_ms(500);
		MDIO_SetPinValue(MDIO_enumPortA,MDIO_enumPin2,MDIO_enumOutput_LOW);
	}
	
}
