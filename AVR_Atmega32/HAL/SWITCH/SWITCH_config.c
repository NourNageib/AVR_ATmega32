/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : SWITCH 		       */
/*	Layer	  : HAL                */
/*	Version   : 1.1                */
/*	Date	  : December 1 , 2023  */
/*	Last Edit : N/A                */
/***********************************/

#include "../../MCAL/MDIO/MDIO_config.h"
#include "../../MCAL/MDIO/MDIO_config.h"

#include "SWITCH_config.h"






/*User must enter the configuration of Switch here */

/*********************/
/*  PORTS options:   */
/*				     */
/* MDIO_enumPortA,  */
/* MDIO_enumPortB,  */
/* MDIO_enumPortC,  */
/* MDIO_enumPortD   */
/*                   */
/*********************/
/*******************/
/*  PINS options:  */
/*				   */
/* MDIO_enumPin0, */
/* MDIO_enumPin1, */
/* MDIO_enumPin2, */
/* MDIO_enumPin3, */
/* MDIO_enumPin4, */
/* MDIO_enumPin5, */
/* MDIO_enumPin6, */
/* MDIO_enumPin7  */
/*                 */
/*******************/
/****************************/
/*     STATE options        */
/*				            */
/*  MDIO_enumInputInternalPU, */
/*  MDIO_enumInputExternalPD  */
/****************************/
/*User must enter the configuration of SWITCHs here */

SWITCH_struct_config SWITCH_Global_Array[NUM_SWITCHs] =
{
	
	[START_SWITCH]={
		
		MDIO_enumPortC,/*.HAL_SWITCH_PORT*/
		MDIO_enumPin0, /*.HAL_SWITCH_PIN */
		MDIO_enumInputInternalPU,/*.HAL_SWITCH_STATE*/
		
		
	},
	[STOP_SWITCH]={
		
		MDIO_enumPortC,/*.HAL_SWITCH_PORT*/
		MDIO_enumPin1,/*.HAL_SWITCH_PIN */
		MDIO_enumInputInternalPU,/*.HAL_SWITCH_STATE*/
		
	},
	[RESET_SWITCH]={
		
		MDIO_enumPortC,/*.HAL_SWITCH_PORT*/
		MDIO_enumPin2,/*.HAL_SWITCH_PIN */
		MDIO_enumInputInternalPU,/*.HAL_SWITCH_STATE*/
		
		
	},
	
};
