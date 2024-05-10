/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : LED  		       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : December 12 , 2023 */
/*	Last Edit : N/A                */
/***********************************/
 #include  "../../LIB/STD_types.h"
 #include  "../../LIB/BIT_math.h"

 #include  "../../MCAL/MDIO/AVR_REGs.h"

 #include  "../../MCAL/MDIO/MDIO_config.h"
 #include  "../../MCAL/MDIO/MDIO_interface.h"
#include "LED_config.h"


LED_struct_config LEDs_Global_Array[NUM_LEDs] =
{
	
	[START_LED]={
		MDIO_enumPortA,
		MDIO_enumPin1,
		HAL_LED_ACTIVE_LOW ,
		HAL_LED_INIT_STATE_OFF,
		
	},
	[STOP_LED]={
		MDIO_enumPortA,
		MDIO_enumPin2,
		HAL_LED_ACTIVE_LOW ,
		HAL_LED_INIT_STATE_OFF,
		
	},
	[RESET_LED]={
		MDIO_enumPortA,
		MDIO_enumPin3,
		HAL_LED_ACTIVE_LOW ,
		HAL_LED_INIT_STATE_OFF,
		
	}
	
};
