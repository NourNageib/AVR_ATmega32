/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : Keypad   	       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : December 30 , 2023 */
/*	Last Edit : N/A                */
/***********************************/

#define KEYPAD_ON 0
#include "STD_types.h"
#include "BIT_math.h"

#include "MDIO_private.h"
#include "MDIO_config.h"
#include "MDIO_interface.h"

#include "HKPD_config.h"
#include "HKPD_private.h"
#include "HKPD_interface.h"



#define SIZE_Cnfg_PORT_Array  HKPD_COL_NUM*HKPD_ROW_NUM

KPD_enuErrorStatus KPD_Init(void)
{

   /*
      * Define local array for KPD to pass to port function to set registers
   */


	MDIO_HW_Config_t loc_KPD_Array[SIZE_Cnfg_PORT_Array];
	/*
	  *declaring errors for  port and KPD
	*/
	KPD_enuErrorStatus loc_KPD_state;
	MDIO_enumError_t loc_Port_state;
	/*Total Number of pins to be configured  */

	uinit8_t MPORT_counter=0;

	for(uinit8_t KPD_counter =0;KPD_counter<HKPD_ROW_NUM;KPD_counter++)
	{
		for(uinit8_t KPDPINs_counter = 0 ; KPDPINs_counter<HKPD_COL_NUM ; KPDPINs_counter++ ,MPORT_counter++)
		{
					/*
						*Copying required data from array of KPD configuration to
						*array of configurations sent to the port function
						*in port driver
					*/

					loc_KPD_Array[MPORT_counter].MPORT_HW_Config         = KPD_PinsConfig[KPD_counter][KPDPINs_counter].KPD_PORT;
					loc_KPD_Array[MPORT_counter].MPIN_HW_Config          = KPD_PinsConfig[KPD_counter][KPDPINs_counter].KPD_PIN;
					loc_KPD_Array[MPORT_counter].MPORT_Config_State      = KPD_PinsConfig[KPD_counter][KPDPINs_counter].KPD_STATE;
		}

	}
	/*
	  * receive the return of port function if the registers
	*/
	loc_Port_state = MDIO_SetConfig( loc_KPD_Array , SIZE_Cnfg_PORT_Array);

	/*
	   *condition to ensure that port configured correctly first then return SEVSEG condition correctly
	*/
	if( loc_Port_state == MDIO_enumOk )
	{
		loc_KPD_state = HAL_KPDenumOk;
	}
	else if(loc_Port_state == MDIO_enumWrongConfig)
	{
		loc_KPD_state = HAL_KPDenumERROR;
	}

	return loc_KPD_state;
}
KPD_enuErrorStatus KPD_GetKeyValue(uinit8_t* Get_Puinit8_tPintValue)
{
	KPD_enuErrorStatus loc_KPD_state;

    *Get_Puinit8_tPintValue = DEFAULT_KEY;


	for(uinit8_t KPD_iterator_row =0;KPD_iterator_row<HKPD_ROW_NUM;KPD_iterator_row++)
		{
		    /*Default values on pins is HIGH therefore I need one of the 4 is LOW once a key from this line is pressed it will read low on this pin (HINT : Pins input is pullup default read HIGH)*/
			MDIO_SetPinValue(KPD_PinsConfig[OUTPUT_KPD_PINS][KPD_iterator_row].KPD_PORT,KPD_PinsConfig[OUTPUT_KPD_PINS][KPD_iterator_row].KPD_PIN,MDIO_enumOutput_LOW);
			for(uinit8_t KPD_iterator_col = 0 ; KPD_iterator_col<HKPD_COL_NUM ; KPD_iterator_col++)
			{
					if(MDIO_GetPinValueReturn(KPD_PinsConfig[INPUT_KPD_PINS][KPD_iterator_col].KPD_PORT,KPD_PinsConfig[INPUT_KPD_PINS][KPD_iterator_col].KPD_PIN) == LOW_VALUE)
					{
						*Get_Puinit8_tPintValue = Keypad_Keys[KPD_iterator_row][KPD_iterator_col];
						/*Busy wait to wait till value updated */
						while(MDIO_GetPinValueReturn(KPD_PinsConfig[INPUT_KPD_PINS][KPD_iterator_col].KPD_PORT,KPD_PinsConfig[INPUT_KPD_PINS][KPD_iterator_col].KPD_PIN) == LOW_VALUE);
					}
			}
			/*Then after check each col value if any pin pressed will return HIGH on pin and set low again on next pin*/
			MDIO_SetPinValue(KPD_PinsConfig[OUTPUT_KPD_PINS][KPD_iterator_row].KPD_PORT,KPD_PinsConfig[OUTPUT_KPD_PINS][KPD_iterator_row].KPD_PIN,MDIO_enumOutput_HIGH);

		}


	if(*Get_Puinit8_tPintValue == -1)
	{
		loc_KPD_state =HAL_KPDenumERROR;
	}
	else
	{
		loc_KPD_state =HAL_KPDenumOk;
	}

	return loc_KPD_state;
}
uinit8_t KPDGetValueinReturn(void)
{
	KPD_enuErrorStatus loc_KPD_state;

	    uinit8_t Get_Puinit8_tPintValue = DEFAULT_KEY;


		for(uinit8_t KPD_iterator_row =0;KPD_iterator_row<HKPD_ROW_NUM;KPD_iterator_row++)
			{
			    /*Default values on pins is HIGH therefore I need one of the 4 is LOW once a key from this line is pressed it will read low on this pin (HINT : Pins input is pullup default read HIGH)*/
				MDIO_SetPinValue(KPD_PinsConfig[OUTPUT_KPD_PINS][KPD_iterator_row].KPD_PORT,KPD_PinsConfig[OUTPUT_KPD_PINS][KPD_iterator_row].KPD_PIN,MDIO_enumOutput_LOW);
				for(uinit8_t KPD_iterator_col = 0 ; KPD_iterator_col<HKPD_COL_NUM ; KPD_iterator_col++)
				{
						if(MDIO_GetPinValueReturn(KPD_PinsConfig[INPUT_KPD_PINS][KPD_iterator_col].KPD_PORT,KPD_PinsConfig[INPUT_KPD_PINS][KPD_iterator_col].KPD_PIN) == LOW_VALUE)
						{
							Get_Puinit8_tPintValue = Keypad_Keys[KPD_iterator_row][KPD_iterator_col];
							/*Busy wait to wait till value updated */
							while(MDIO_GetPinValueReturn(KPD_PinsConfig[INPUT_KPD_PINS][KPD_iterator_col].KPD_PORT,KPD_PinsConfig[INPUT_KPD_PINS][KPD_iterator_col].KPD_PIN) == LOW_VALUE);
						}
				}
				/*Then after check each col value if any pin pressed will return HIGH on pin and set low again on next pin*/
				MDIO_SetPinValue(KPD_PinsConfig[OUTPUT_KPD_PINS][KPD_iterator_row].KPD_PORT,KPD_PinsConfig[OUTPUT_KPD_PINS][KPD_iterator_row].KPD_PIN,MDIO_enumOutput_HIGH);

			}




		return Get_Puinit8_tPintValue;
}
