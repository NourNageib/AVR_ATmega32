/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : SWITCH				*/
/*  Layer	  : HAL  				*/
/*	Version	  :	1.1		  			*/
/*	Date	  :	December 8, 2023	*/
/*	Last Edit :	December 16, 2023	*/
/************************************/


#include "../../LIB/STD_types.h"
#include "../../LIB/BIT_math.h"

#include "../../MCAL/MDIO/MDIO_private.h"
#include "../../MCAL/MDIO/MDIO_config.h"
#include "../../MCAL/MDIO/MDIO_interface.h"



#include "SWITCH_config.h"
#include "SWITCH_interface.h"

/*
  * Extern array used to configure my switches 
*/
extern SWITCH_struct_config SWITCH_Global_Array[NUM_SWITCHs];

HAL_SWITCHenumStatus HAL_SWITCH_INIT()
{
	
   /*
      * Define local array for switches to pass to port function to set registers 
   */
	MDIO_HW_Config_t loc_switches_Array[NUM_SWITCHs];
	/*
	  *declaring errors for each port and switches 
	*/
	HAL_SWITCHenumStatus loc_switches_state=HAL_SWITCHenumOk;
	MDIO_enumError_t loc_Port_state;
	
	for(uinit8_t i =0;i<NUM_SWITCHs;i++)
	{
		/*
			*Copying required data from array of switches configuration to
			*array of configurations sent to the port function 
			*in port driver
		*/
		
		loc_switches_Array[i].MPORT_HW_Config      = SWITCH_Global_Array[i].HAL_SWITCH_PORT;
		loc_switches_Array[i].MPIN_HW_Config       = SWITCH_Global_Array[i].HAL_SWITCH_PIN;
		loc_switches_Array[i].MPORT_Config_State   = SWITCH_Global_Array[i].HAL_SWITCH_STATE;
	
	}
	/*
	  * receive the return of port function if the registers 
	*/
	loc_Port_state = MDIO_SetConfig(&loc_switches_Array,NUM_SWITCHs);
	
	/*
	   *condition to ensure that port configured correctly first then return switch condition correctly 
	*/
	if( loc_Port_state == MDIO_enumOk )
	{
		loc_switches_state = HAL_SWITCHenumOk;
	}
	else if(loc_Port_state == MDIO_enumWrongConfig)
	{
		loc_switches_state = HAL_SWITCHenumERROR;
	}
	
	return loc_switches_state;

}
uinit8_t HAL_SWITCH_GETState(SWITCH_struct_config Copy_configstruct_switch)
{
	 uinit8_t loc_val ;
	 MDIO_GetPinValue(Copy_configstruct_switch.HAL_SWITCH_PORT,Copy_configstruct_switch.HAL_SWITCH_PIN,&loc_val);
	 return loc_val;
	
}
