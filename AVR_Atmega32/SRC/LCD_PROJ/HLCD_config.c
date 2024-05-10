/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : LCD  		       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : December 30 , 2023 */
/*	Last Edit : N/A                */
/***********************************/
#include "BIT_math.h"
#include "STD_types.h"

#include "MDIO_config.h"
#include "MDIO_config.h"

#include "HLCD_config.h"
#include "HLCD_private.h"
/***************************************/
/*****User configure PINs connection****/
/*  For EN->Enable                     */
/*      RS->Register Select            */
/*      R/W->Read/                     */
/*       (mostly connected to          */
/*       GND only use LCD to write)    */
/***************************************/
/* EN
/* R/W ->GND
/* RS
/* D0
 * D1
 * D2
 * D3
 * D4
 * D5
 * D6
 * D7
 */

/*******User configure LCD PINs individually ***/
LCD_Control_Pins_cnfg LCD_PinsConfig[LCD_PINs_NUM] =
{
		[EN] = { .LCD_PORT  = MDIO_enumPortB,
			     .LCD_PIN   = MDIO_enumPin0,
			     .LCD_STATE = MDIO_enumOutput_LOW

			   },

	   [RS] = {  .LCD_PORT  = MDIO_enumPortB,
			     .LCD_PIN   = MDIO_enumPin1,
			     .LCD_STATE = MDIO_enumOutput_LOW

			   },

	   [D0] = {  .LCD_PORT  = MDIO_enumPortA,
		     	 .LCD_PIN   = MDIO_enumPin0,
				 .LCD_STATE = MDIO_enumOutput_LOW

			  },
       [D1] = { .LCD_PORT  = MDIO_enumPortA,
		    	.LCD_PIN   = MDIO_enumPin1,
			    .LCD_STATE = MDIO_enumOutput_LOW

			   },
	   [D2] = { .LCD_PORT  = MDIO_enumPortA,
			    .LCD_PIN   = MDIO_enumPin2,
		    	.LCD_STATE = MDIO_enumOutput_LOW

				},
	   [D3] = { .LCD_PORT  = MDIO_enumPortA,
				.LCD_PIN   = MDIO_enumPin3,
				.LCD_STATE = MDIO_enumOutput_LOW

				},
	   [D4] = { .LCD_PORT  = MDIO_enumPortA,
				.LCD_PIN   = MDIO_enumPin4,
				.LCD_STATE = MDIO_enumOutput_LOW

				},
	   [D5] = { .LCD_PORT  = MDIO_enumPortA,
				.LCD_PIN   = MDIO_enumPin5,
				.LCD_STATE = MDIO_enumOutput_LOW

				},
	   [D6] = { .LCD_PORT  = MDIO_enumPortA,
				.LCD_PIN   = MDIO_enumPin6,
				.LCD_STATE = MDIO_enumOutput_LOW

				},
		[D7] = { .LCD_PORT  = MDIO_enumPortA,
				 .LCD_PIN   = MDIO_enumPin7,
				 .LCD_STATE = MDIO_enumOutput_LOW

				}

};
/****************************************************/
