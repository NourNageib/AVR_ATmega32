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
 #include "LED_interface.h"


extern LED_struct_config LEDs_Global_Array[NUM_LEDs];

HAL_LEDenumStatus HAL_LED_INIT(void)
{
	MDIO_HW_Config_t  loc_leds_Array[NUM_LEDs];
	HAL_LEDenumStatus loc_led_state=HAL_LEDenumOk;
	MDIO_enumError_t  loc_Port_state;
	
	for(uinit8_t i =0;i<NUM_LEDs;i++)
	{
		/*Copying required data from array of leds configuration to
		*array of configurations sent to the port function 
		*in port driver
		*/
		
		loc_leds_Array[i].MPORT_HW_Config       = LEDs_Global_Array[i].HAL_LED_PORT;
		loc_leds_Array[i].MPIN_HW_Config        = LEDs_Global_Array[i].HAL_LED_PIN;
		loc_leds_Array[i].MPORT_Config_State    = LEDs_Global_Array[i].HAL_LED_ACTIVE_STATE;
	
	}
	loc_Port_state = MDIO_SetConfig(loc_leds_Array,NUM_LEDs);
	if( loc_Port_state == MDIO_enumOk )
	{
		loc_led_state = HAL_LEDenumOk;
	}
	else if(loc_Port_state == MDIO_enumWrongConfig)
	{
		loc_led_state = HAL_LEDenumERROR;
	}
	
	return loc_led_state;
}

HAL_LEDenumStatus HLED_SetLEDDirection(MDIO_enumPorts_t Copy_uinit8PortNum ,MDIO_enumPins_t Copy_uinit8PinNum)
{
	MDIO_enumError_t DIO_loc_State  = MDIO_SetPinDirection(Copy_uinit8PortNum,Copy_uinit8PinNum, MDIO_enumOutput_LOW);
	HAL_LEDenumStatus HAL_Loc_state = HAL_LEDenumERROR;
	if(DIO_loc_State == MDIO_enumWrongConfig )
	{
		HAL_Loc_state=HAL_LEDenumERROR;
	}
	else if(DIO_loc_State == MDIO_enumOk)
	{
		HAL_Loc_state=HAL_LEDenumOk;
	}

	return HAL_Loc_state;
}


HAL_LEDenumStatus HLED_SetSingleLED_ON(MDIO_enumPorts_t Copy_uinit8PortNum ,MDIO_enumPins_t Copy_uinit8PinNum)
{
	MDIO_enumError_t DIO_loc_State = MDIO_SetPinValue(Copy_uinit8PortNum,Copy_uinit8PinNum,MDIO_enumOutput_HIGH);
	HAL_LEDenumStatus HAL_Loc_state = HAL_LEDenumERROR;
	if(DIO_loc_State == MDIO_enumWrongConfig )
	{
		HAL_Loc_state=HAL_LEDenumERROR;
	}
	else if(DIO_loc_State == MDIO_enumOk)
	{
		HAL_Loc_state=HAL_LEDenumOk;
	}

	return HAL_Loc_state;

}
HAL_LEDenumStatus HLED_SetSingleLED_OFF(MDIO_enumPorts_t Copy_uinit8PortNum ,MDIO_enumPins_t Copy_uinit8PinNum)
{
	MDIO_enumError_t DIO_loc_State= MDIO_SetPinValue(Copy_uinit8PortNum,Copy_uinit8PinNum,MDIO_enumOutput_LOW);

		HAL_LEDenumStatus HAL_Loc_state = HAL_LEDenumERROR;
		if(DIO_loc_State == MDIO_enumWrongConfig )
		{
			HAL_Loc_state=HAL_LEDenumERROR;
		}
		else if(DIO_loc_State == MDIO_enumOk)
		{
			HAL_Loc_state=HAL_LEDenumOk;
		}

		return HAL_Loc_state;
}
