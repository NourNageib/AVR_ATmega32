/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : Seven Segment		*/
/*  Layer	  : HAL  				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 19, 2023	*/
/*	Last Edit :	N/A					*/
/************************************/

#include "../../LIB/BIT_math.h"
#include "../../LIB/STD_types.h"

#include "../../MCAL/MDIO/MDIO_config.h"
#include "../../MCAL/MDIO/MDIO_interface.h"
#include "../../MCAL/MDIO/MDIO_Private.h"

#include "SEVSEG_config.h"
#include "SEVSEG_interface.h"
#include "SEVSEG_private.h"



/****************Externs for Arrays from configuration file **************/

extern SEVSEG_Sruct_confg  SEVSEG_Config_Array[NUM_SEVSEGs][NUM_SEVSEGPINs];
extern  SEVSEG_MODE_opts SEVSEG_MODE_cnfg[NUM_SEVSEGs];
extern const char SEVSEG_Num[10];
extern MDIO_enumConfig_t ZERO  [NUM_SEVSEGPINs];
extern MDIO_enumConfig_t ONE   [NUM_SEVSEGPINs];
extern MDIO_enumConfig_t TWO   [NUM_SEVSEGPINs];
extern MDIO_enumConfig_t THREE [NUM_SEVSEGPINs];
extern MDIO_enumConfig_t FOUR  [NUM_SEVSEGPINs];
extern MDIO_enumConfig_t FIVE  [NUM_SEVSEGPINs];
extern MDIO_enumConfig_t SIX   [NUM_SEVSEGPINs];
extern MDIO_enumConfig_t SEVEN [NUM_SEVSEGPINs];
extern MDIO_enumConfig_t EIGHT [NUM_SEVSEGPINs];
extern MDIO_enumConfig_t NINE  [NUM_SEVSEGPINs];
/****************************************************************************/


HAL_enumSEVSEGERRORStatus HAL_SEVSEG_Init(void)
{
   /*
      * Define local array for switches to pass to port function to set registers
   */


	MDIO_HW_Config_t loc_SEVSEG_Array[SIZE_Cnfg_PORT_Array];
	/*
	  *declaring errors for each port and switches
	*/
	HAL_enumSEVSEGERRORStatus loc_SEVSEG_state;
	MDIO_enumError_t loc_Port_state;
	/*Total Number of pins to be configured  */

	uinit8_t MPORT_counter=0;

	for(uinit8_t SEVSEG_counter =0;SEVSEG_counter<NUM_SEVSEGs;SEVSEG_counter++)
	{
		for(uinit8_t SEVSEGPINs_counter = 0 ; SEVSEGPINs_counter<NUM_SEVSEGPINs ; SEVSEGPINs_counter++ ,MPORT_counter++)
		{
					/*
						*Copying required data from array of 7SEG configuration to
						*array of configurations sent to the port function
						*in port driver
					*/

					loc_SEVSEG_Array[MPORT_counter].MPORT_HW_Config         = SEVSEG_Config_Array[SEVSEG_counter][SEVSEGPINs_counter].SEVSEG_PORT;
					loc_SEVSEG_Array[MPORT_counter].MPIN_HW_Config          = SEVSEG_Config_Array[SEVSEG_counter][SEVSEGPINs_counter].SEVSEG_PIN;
					loc_SEVSEG_Array[MPORT_counter].MPORT_Config_State      = SEVSEG_Config_Array[SEVSEG_counter][SEVSEGPINs_counter].SEVSEG_STATE;
		}

	}
	/*
	  * receive the return of port function if the registers
	*/
	loc_Port_state = MDIO_SetConfig( loc_SEVSEG_Array , SIZE_Cnfg_PORT_Array);

	/*
	   *condition to ensure that port configured correctly first then return switch condition correctly
	*/
	if( loc_Port_state == MDIO_enumOk )
	{
		loc_SEVSEG_state = SEVSEG_enumOK;
	}
	else if(loc_Port_state == MDIO_enumWrongConfig)
	{
		loc_SEVSEG_state = SEVSEG_enumConfigError;
	}

	return loc_SEVSEG_state;

}

HAL_enumSEVSEGERRORStatus HAL_SEVSEG_PORT_INIT(void)
{
	MDIO_SetPortDirection(SEVSEG_1_PORT,SEVSEG_1_STATE);
	MDIO_SetPortDirection(SEVSEG_2_PORT,SEVSEG_2_STATE);
	MDIO_SetPortValue(SEVSEG_1_PORT,SEVSEG_1_STATE);
	MDIO_SetPortValue(SEVSEG_2_PORT,SEVSEG_2_STATE);
	return SEVSEG_enumWrongNum;

}

HAL_enumSEVSEGERRORStatus HAL_SEVSEG_PORT_DISPLAY_NUM(uinit8_t NUM_of_SEVSEGs,uinit8_t Copy_InputNumberDisplay)
{
		HAL_enumSEVSEGERRORStatus state =SEVSEG_enumWrongNum;

				switch(NUM_of_SEVSEGs)
				{
					case 1 :
					{
							if((Copy_InputNumberDisplay <=9) && (Copy_InputNumberDisplay >=0))

							{
								MDIO_AssignPortValue(SEVSEG_1_PORT,SEVSEG_Num[Copy_InputNumberDisplay]);
								state =SEVSEG_enumNumDisplayOK;
							}
							else
							{
								state =SEVSEG_enumWrongNum;
							}

					}break;
					case 2 :
					{
						//MDIO_SetPinDirection(MDIO_enumPortB,MDIO_enumPin2,MDIO_enumOutput_HIGH);
						MDIO_AssignPortValue(SEVSEG_1_PORT,SEVSEG_Num[Copy_InputNumberDisplay/10]);
						MDIO_AssignPortValue(SEVSEG_2_PORT,SEVSEG_Num[Copy_InputNumberDisplay%10]);
						state =SEVSEG_enumNumDisplayOK;
					}break;

				default :
				{
					state =SEVSEG_enumNumDisplayError;
				}
		}

		return state;

}

HAL_enumSEVSEGERRORStatus HAL_SINGLE_SEVSEG_Display (uinit8_t SEVSEG_ID_Copy , uinit8_t Copy_InputNumberDisplay)
{
	HAL_enumSEVSEGERRORStatus state = SEVSEG_enumWrongNum;

	if((Copy_InputNumberDisplay <=9) && (Copy_InputNumberDisplay >=0))

	{
					switch(SEVSEG_MODE_cnfg[SEVSEG_ID_Copy])
					{
						case SEVSEG_COMMON_CATHODE_EN :
						{
							switch (Copy_InputNumberDisplay)
							{
							case ZERO_0 :
								{
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,ZERO[SEVSEG_A_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,ZERO[SEVSEG_B_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,ZERO[SEVSEG_C_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,ZERO[SEVSEG_D_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,ZERO[SEVSEG_E_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,ZERO[SEVSEG_F_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,ZERO[SEVSEG_G_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,ZERO[SEVSEG_DP_]);
										state =SEVSEG_enumNumDisplayOK;
								}break;
								case ONE_1 :
								{
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,ONE[SEVSEG_A_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,ONE[SEVSEG_B_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,ONE[SEVSEG_C_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,ONE[SEVSEG_D_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,ONE[SEVSEG_E_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,ONE[SEVSEG_F_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,ONE[SEVSEG_G_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,ONE[SEVSEG_DP_]);
										state =SEVSEG_enumNumDisplayOK;
								}break;
								case TWO_2 :
								{
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,TWO[SEVSEG_A_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,TWO[SEVSEG_B_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,TWO[SEVSEG_C_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,TWO[SEVSEG_D_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,TWO[SEVSEG_E_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,TWO[SEVSEG_F_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,TWO[SEVSEG_G_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,TWO[SEVSEG_DP_]);
										state =SEVSEG_enumNumDisplayOK;
								}break;
								case THREE_3 :
									{
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,THREE[SEVSEG_A_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,THREE[SEVSEG_B_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,THREE[SEVSEG_C_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,THREE[SEVSEG_D_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,THREE[SEVSEG_E_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,THREE[SEVSEG_F_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,THREE[SEVSEG_G_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,THREE[SEVSEG_DP_]);
									    state =SEVSEG_enumNumDisplayOK;
									}break;
									case FOUR_4 :
									{
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,FOUR[SEVSEG_A_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,FOUR[SEVSEG_B_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,FOUR[SEVSEG_C_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,FOUR[SEVSEG_D_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,FOUR[SEVSEG_E_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,FOUR[SEVSEG_F_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,FOUR[SEVSEG_G_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,FOUR[SEVSEG_DP_]);
									    state =SEVSEG_enumNumDisplayOK;
									}break;
									case FIVE_5 :
									{
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,FIVE[SEVSEG_A_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,FIVE[SEVSEG_B_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,FIVE[SEVSEG_C_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,FIVE[SEVSEG_D_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,FIVE[SEVSEG_E_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,FIVE[SEVSEG_F_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,FIVE[SEVSEG_G_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,FIVE[SEVSEG_DP_]);
									    state =SEVSEG_enumNumDisplayOK;
									}break;
									case SIX_6 :
									{
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,SIX[SEVSEG_A_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,SIX[SEVSEG_B_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,SIX[SEVSEG_C_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,SIX[SEVSEG_D_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,SIX[SEVSEG_E_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,SIX[SEVSEG_F_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,SIX[SEVSEG_G_]);
										MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,SIX[SEVSEG_DP_]);
									    state =SEVSEG_enumNumDisplayOK;
									 }break;
										case SEVEN_7 :
										{
											MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,SEVEN[SEVSEG_A_]);
											MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,SEVEN[SEVSEG_B_]);
											MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,SEVEN[SEVSEG_C_]);
											MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,SEVEN[SEVSEG_D_]);
											MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,SEVEN[SEVSEG_E_]);
											MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,SEVEN[SEVSEG_F_]);
											MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,SEVEN[SEVSEG_G_]);
											MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,SEVEN[SEVSEG_DP_]);
									        state =SEVSEG_enumNumDisplayOK;
										}break;
											case EIGHT_8 :
											{
												MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,EIGHT[SEVSEG_A_]);
												MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,EIGHT[SEVSEG_B_]);
												MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,EIGHT[SEVSEG_C_]);
												MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,EIGHT[SEVSEG_D_]);
												MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,EIGHT[SEVSEG_E_]);
												MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,EIGHT[SEVSEG_F_]);
												MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,EIGHT[SEVSEG_G_]);
												MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,EIGHT[SEVSEG_DP_]);
											    state =SEVSEG_enumNumDisplayOK;
											}break;
												case NINE_9 :
												{
													MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,NINE[SEVSEG_A_]);
													MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,NINE[SEVSEG_B_]);
													MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,NINE[SEVSEG_C_]);
													MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,NINE[SEVSEG_D_]);
													MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,NINE[SEVSEG_E_]);
													MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,NINE[SEVSEG_F_]);
													MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,NINE[SEVSEG_G_]);
													MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,NINE[SEVSEG_DP_]);
											       state =SEVSEG_enumNumDisplayOK;
												}break;
											default :
											{
												state =SEVSEG_enumNumDisplayError;
											}break;
									}

						}break;

					case SEVSEG_COMMON_ANODE_EN :
					{
						switch (Copy_InputNumberDisplay)
						{
							case ONE_1 :
							{
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN , ~ONE[SEVSEG_A_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN , ~ONE[SEVSEG_B_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN , ~ONE[SEVSEG_C_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN , ~ONE[SEVSEG_D_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN , ~ONE[SEVSEG_E_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN , ~ONE[SEVSEG_F_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN , ~ONE[SEVSEG_G_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN ,~ONE[SEVSEG_DP_]);
								state =SEVSEG_enumNumDisplayOK;
							}break;
							case TWO_2 :
							{
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,~TWO[SEVSEG_A_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,~TWO[SEVSEG_B_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,~TWO[SEVSEG_C_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,~TWO[SEVSEG_D_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,~TWO[SEVSEG_E_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,~TWO[SEVSEG_F_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,~TWO[SEVSEG_G_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,~TWO[SEVSEG_DP_]);
							    state =SEVSEG_enumNumDisplayOK;
							}break;
							case THREE_3 :
							{
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,~THREE[SEVSEG_A_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,~THREE[SEVSEG_B_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,~THREE[SEVSEG_C_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,~THREE[SEVSEG_D_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,~THREE[SEVSEG_E_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,~THREE[SEVSEG_F_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,~THREE[SEVSEG_G_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,~THREE[SEVSEG_DP_]);
								state =SEVSEG_enumNumDisplayOK;
							}break;
							case FOUR_4 :
							{
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,~FOUR[SEVSEG_A_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,~FOUR[SEVSEG_B_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,~FOUR[SEVSEG_C_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,~FOUR[SEVSEG_D_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,~FOUR[SEVSEG_E_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,~FOUR[SEVSEG_F_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,~FOUR[SEVSEG_G_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,~FOUR[SEVSEG_DP_]);
							    state =SEVSEG_enumNumDisplayOK;
							}break;
							case FIVE_5 :
							{
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,~FIVE[SEVSEG_A_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,~FIVE[SEVSEG_B_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,~FIVE[SEVSEG_C_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,~FIVE[SEVSEG_D_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,~FIVE[SEVSEG_E_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,~FIVE[SEVSEG_F_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,~FIVE[SEVSEG_G_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,~FIVE[SEVSEG_DP_]);
							    state =SEVSEG_enumNumDisplayOK;
							}break;
							case SIX_6:
							{
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,~SIX[SEVSEG_A_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,~SIX[SEVSEG_B_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,~SIX[SEVSEG_C_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,~SIX[SEVSEG_D_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,~SIX[SEVSEG_E_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,~SIX[SEVSEG_F_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,~SIX[SEVSEG_G_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,~SIX[SEVSEG_DP_]);
							   state =SEVSEG_enumNumDisplayOK;
							}break;
							case SEVEN_7:
							{
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,~SEVEN[SEVSEG_A_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,~SEVEN[SEVSEG_B_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,~SEVEN[SEVSEG_C_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,~SEVEN[SEVSEG_D_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,~SEVEN[SEVSEG_E_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,~SEVEN[SEVSEG_F_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,~SEVEN[SEVSEG_G_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,~SEVEN[SEVSEG_DP_]);
							    state =SEVSEG_enumNumDisplayOK;
							}break;
							case EIGHT_8 :
							{
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,~EIGHT[SEVSEG_A_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,~EIGHT[SEVSEG_B_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,~EIGHT[SEVSEG_C_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,~EIGHT[SEVSEG_D_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,~EIGHT[SEVSEG_E_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,~EIGHT[SEVSEG_F_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,~EIGHT[SEVSEG_G_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,~EIGHT[SEVSEG_DP_]);
							   state =SEVSEG_enumNumDisplayOK;
							}break;
							case NINE_9:
							{
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_A_].SEVSEG_PIN,~NINE[SEVSEG_A_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_B_].SEVSEG_PIN,~NINE[SEVSEG_B_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_C_].SEVSEG_PIN,~NINE[SEVSEG_C_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_D_].SEVSEG_PIN,~NINE[SEVSEG_D_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_E_].SEVSEG_PIN,~NINE[SEVSEG_E_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_F_].SEVSEG_PIN,~NINE[SEVSEG_F_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_G_].SEVSEG_PIN,~NINE[SEVSEG_G_]);
								MDIO_SetPinValue (SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PORT,SEVSEG_Config_Array[SEVSEG_ID_Copy][SEVSEG_DP_].SEVSEG_PIN,~NINE[SEVSEG_DP_]);
							    state =SEVSEG_enumNumDisplayOK;
							}break;
							default :
							{
								state  =SEVSEG_enumNumDisplayError;
							}break;
						}

					}break;

						default :
						{
							state =SEVSEG_enumNumDisplayError;
						}break;
					}


	}
	else
	{
		state =SEVSEG_enumWrongNum;
	}
	return state;

}
HAL_enumSEVSEGERRORStatus HAL_DOUBLE_SEVSEG_Display(uinit8_t Copy_InputNumberDisplay)
{
	HAL_enumSEVSEGERRORStatus state=SEVSEG_enumNumDisplayError;


    if ((Copy_InputNumberDisplay >99) || (Copy_InputNumberDisplay<0))
        
		{
			/*warning int "This function will display tens and uints of input number only!"*/
	        Copy_InputNumberDisplay = Copy_InputNumberDisplay%100;
		}
    

	uinit8_t Num_uint=Copy_InputNumberDisplay%10;
	uinit8_t Num_Tens=Copy_InputNumberDisplay/10;
	HAL_SINGLE_SEVSEG_Display(SEVSEG_1_,Num_uint);
	HAL_SINGLE_SEVSEG_Display(SEVSEG_2_,Num_Tens);
	state=SEVSEG_enumNumDisplayOK;

	return  state;
}
HAL_enumSEVSEGERRORStatus HAL_SEVSEG_STARTCount(uinit8_t CopyNUM_of_SEVSEGs,uinit8_t Start_Num,uinit8_t Stop_Num)
{

	if(CopyNUM_of_SEVSEGs == 1)
	{
		if(Start_Num >Stop_Num)
			{
					for(int i=Start_Num;i>=Stop_Num;i--)
					{

						HAL_SINGLE_SEVSEG_Display(SEVSEG_1_,i);
						_delay_ms(700);
					}
			}
		else
		{
			for(int i=Start_Num;i<=Stop_Num;i++)
				{
					HAL_SINGLE_SEVSEG_Display(SEVSEG_1_,i);
					_delay_ms(700);
				}
		}

	}
	else if(CopyNUM_of_SEVSEGs == 2)
	{
		if(Start_Num >Stop_Num)
			{
					for(int i=Start_Num;i>=Stop_Num;i--)
					{
						HAL_DOUBLE_SEVSEG_Display(i);
						_delay_ms(700);
					}
			}
		else
		{
			for(int i=Start_Num;i<=Stop_Num;i++)
				{
				      HAL_DOUBLE_SEVSEG_Display(i);
				      _delay_ms(700);
				}
		}
	}
	return  SEVSEG_enumWrongNum;

}
/*HAL_enumSEVSEGERRORStatus HAL_SEVSEG_STOP   (void)
{

	return  SEVSEG_enumWrongNum;
}*/


