/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : Keypad 		       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : December 30 , 2023 */
/*	Last Edit : N/A                */
/***********************************/

#include "STD_types.h"
#include "BIT_math.h"

#include "MDIO_private.h"
#include "MDIO_config.h"
#include "MDIO_interface.h"


#include "HKPD_config.h"
#include "HKPD_private.h"
#include "HKPD_interface.h"



/*******User configure KPD PINs individually ***/
KPD_Control_Pins_cnfg KPD_PinsConfig[HKPD_COL_NUM][HKPD_ROW_NUM] =
{
			  {
				      {
						 .KPD_PORT  = MDIO_enumPortC,
						 .KPD_PIN   = MDIO_enumPin0,
						 .KPD_STATE = MDIO_enumInputInternalPU

				      },

	    	          {
						 .KPD_PORT  = MDIO_enumPortC,
						 .KPD_PIN   = MDIO_enumPin1,
						 .KPD_STATE = MDIO_enumInputInternalPU

				        },

			            {
					     .KPD_PORT  = MDIO_enumPortC,
						 .KPD_PIN   = MDIO_enumPin2,
						 .KPD_STATE = MDIO_enumInputInternalPU

					    },
			            {
						 .KPD_PORT  = MDIO_enumPortC,
						 .KPD_PIN   = MDIO_enumPin3,
						 .KPD_STATE = MDIO_enumInputInternalPU

			  			   }
			  },

			  {
			           {
			    		 .KPD_PORT  = MDIO_enumPortC,
						 .KPD_PIN   = MDIO_enumPin4,
						 .KPD_STATE = MDIO_enumOutput_HIGH

					   },

			           {
					     .KPD_PORT  = MDIO_enumPortC,
						 .KPD_PIN   = MDIO_enumPin5,
						 .KPD_STATE = MDIO_enumOutput_HIGH

					    },

			           {
			    		  .KPD_PORT  = MDIO_enumPortC,
						  .KPD_PIN   = MDIO_enumPin6,
						  .KPD_STATE = MDIO_enumOutput_HIGH
					   },

					   {  .KPD_PORT  = MDIO_enumPortC,
					      .KPD_PIN   = MDIO_enumPin7,
                          .KPD_STATE = MDIO_enumOutput_HIGH
					   }
			  }
};

