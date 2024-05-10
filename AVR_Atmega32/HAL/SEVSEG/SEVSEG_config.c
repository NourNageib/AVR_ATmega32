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
#include "../../MCAL/MDIO/MDIO_config.h"

#include "SEVSEG_config.h"
#include "SEVSEG_interface.h"
#include "SEVSEG_private.h"


/*
	*ARRAY SET SEG CONFIG AUTOMATOCALLY ONLY ADD IF MORE TAHN 1 SEG is USED *
	*2D ARRAY 1ST D->( ID of the Segment) || 2ndD -> (Configuration of each pin of the segement ) -> struct of (_7_SEG_Config_t type
	*To configure each pin ( HAL_7SEG_PORT )
	                       ( HAL_7SEG_PIN  )
						   ( _7SEG_CONFIG  )
*/

/***********************************************************/
/*             Configuration Array of 7SEGMENT             */
/***********************************************************/

SEVSEG_Sruct_confg  SEVSEG_Config_Array[NUM_SEVSEGs][NUM_SEVSEGPINs] =
{

		[SEVSEG_1_]=
			   {     /*PIN A of 7SEG  CONFIG */
				   {
						   .SEVSEG_PORT  = MDIO_enumPortA,
						   .SEVSEG_PIN   = MDIO_enumPin0,
						   .SEVSEG_STATE = MDIO_enumOutput_LOW
				   },
				   /*PIN B of 7SEG  CONFIG */
				   {
						   .SEVSEG_PORT  = MDIO_enumPortA,
						   .SEVSEG_PIN   = MDIO_enumPin1,
						   .SEVSEG_STATE = MDIO_enumOutput_LOW
				   },
				   /*PIN C of 7SEG  CONFIG */
				   {
						   .SEVSEG_PORT  =  MDIO_enumPortA,
						   .SEVSEG_PIN   =  MDIO_enumPin2,
						   .SEVSEG_STATE =  MDIO_enumOutput_LOW
				   },
				   /*PIN D of 7SEG  CONFIG */
				   {
						   .SEVSEG_PORT  = MDIO_enumPortA,
						   .SEVSEG_PIN   =  MDIO_enumPin3,
						   .SEVSEG_STATE =  MDIO_enumOutput_LOW
				   },
				   /*PIN E of 7SEG  CONFIG */
				   {
						   .SEVSEG_PORT  =  MDIO_enumPortA,
						   .SEVSEG_PIN   =  MDIO_enumPin4,
						   .SEVSEG_STATE =  MDIO_enumOutput_LOW
				   },
				   /*PIN F of 7SEG  CONFIG */
				   {
						   .SEVSEG_PORT  = MDIO_enumPortA,
						   .SEVSEG_PIN   = MDIO_enumPin5,
						   .SEVSEG_STATE = MDIO_enumOutput_LOW
				   },
				   /*PIN G of 7SEG  CONFIG */
				   {
						   .SEVSEG_PORT  = MDIO_enumPortA,
						   .SEVSEG_PIN   = MDIO_enumPin6,
						   .SEVSEG_STATE = MDIO_enumOutput_LOW
				   },
				   /*DOT of 7SEG  CONFIG */
				   {
						   .SEVSEG_PORT  = MDIO_enumPortA,
						   .SEVSEG_PIN   = MDIO_enumPin7,
						   .SEVSEG_STATE = MDIO_enumOutput_LOW
				   }
			   },

	[SEVSEG_2_]=
	   {     /*PIN A of 7SEG  CONFIG */
		{
			 .SEVSEG_PORT  = MDIO_enumPortC,
			 .SEVSEG_PIN   = MDIO_enumPin0,
			 .SEVSEG_STATE = MDIO_enumOutput_LOW
		},
		 /*PIN B of 7SEG  CONFIG */
		{
				.SEVSEG_PORT  = MDIO_enumPortC,
				.SEVSEG_PIN   = MDIO_enumPin1,
				.SEVSEG_STATE =  MDIO_enumOutput_LOW
		},
		/*PIN C of 7SEG  CONFIG */
		{
				.SEVSEG_PORT  = MDIO_enumPortC,
				.SEVSEG_PIN   = MDIO_enumPin2,
				.SEVSEG_STATE = MDIO_enumOutput_LOW
		},
	    /*PIN D of 7SEG  CONFIG */
		{
				.SEVSEG_PORT  = MDIO_enumPortC,
				.SEVSEG_PIN   = MDIO_enumPin3,
				.SEVSEG_STATE = MDIO_enumOutput_LOW
		},
	    /*PIN E of 7SEG  CONFIG */
		{
				.SEVSEG_PORT  = MDIO_enumPortC,
				.SEVSEG_PIN   = MDIO_enumPin4,
				.SEVSEG_STATE = MDIO_enumOutput_LOW
		},
	   /*PIN F of 7SEG  CONFIG */
		{
				.SEVSEG_PORT  = MDIO_enumPortC,
				.SEVSEG_PIN   = MDIO_enumPin5,
				.SEVSEG_STATE =  MDIO_enumOutput_LOW
		},
	   /*PIN G of 7SEG  CONFIG */
	    {
	    		.SEVSEG_PORT  = MDIO_enumPortC,
				.SEVSEG_PIN   = MDIO_enumPin6,
				.SEVSEG_STATE =  MDIO_enumOutput_LOW
		},
	   /*DOT of 7SEG  CONFIG */
		{
				.SEVSEG_PORT  = MDIO_enumPortC,
				.SEVSEG_PIN   = MDIO_enumPin7,
				.SEVSEG_STATE =  MDIO_enumOutput_LOW
    	}
	   }

	};

SEVSEG_MODE_opts SEVSEG_MODE_cnfg[NUM_SEVSEGs] =
{
	  SEVSEG_COMMON_CATHODE_EN ,
	  SEVSEG_COMMON_CATHODE_EN

};

/**************************************************/
/**************************************************/
/*              **************                    */
/*            ********A********                   */
/*          *   *************  *                  */
/*         ***                ***                 */
/*	       ***                ***                 */
/*		   ***                ***                 */
/*		   *F*				  *B*                 */
/*         ***				  ***                 */
/*         ***				  ***                 */
/*	       ***				  ***                 */
/*	        *  **************  *                  */
/*           ********G********                    */
/*          *   *************  *                  */
/*         ***                ***                 */
/*         ***                ***                 */
/*         ***                ***                 */
/*         *E*				  *C*                 */
/*         ***				  ***                 */
/*         ***				  ***                 */
/*         ***				  ***                 */
/*          *  **************  *         **       */
/*            ********D********		   **DP**     */
/*             *************             **       */
 /**************************************************/
 /**************************************************/
 /***********************************************************/
 /*        Configuration Array of 7SEGMENT  Mode            */
 /***********************************************************/

MDIO_enumConfig_t ZERO [NUM_SEVSEGPINs]={
									MDIO_enumOutput_HIGH, /*A*/
									MDIO_enumOutput_HIGH, /*B*/
									MDIO_enumOutput_HIGH, /*C*/
									MDIO_enumOutput_HIGH, /*D*/
									MDIO_enumOutput_HIGH, /*E*/
									MDIO_enumOutput_HIGH, /*F*/
									MDIO_enumOutput_LOW,  /*G*/
									MDIO_enumOutput_LOW  /*DP*/
									//MDIO_enumOutput_LOW,  /*MODE*/

							  };
MDIO_enumConfig_t ONE[NUM_SEVSEGPINs]={
									MDIO_enumOutput_LOW, /*A*/
									MDIO_enumOutput_HIGH,/*B*/
									MDIO_enumOutput_HIGH,/*C*/
									MDIO_enumOutput_LOW, /*D*/
									MDIO_enumOutput_LOW, /*E*/
									MDIO_enumOutput_LOW, /*F*/
									MDIO_enumOutput_LOW, /*G*/
									MDIO_enumOutput_LOW /*DP*/
									//MDIO_enumOutput_LOW /*MODE*/
							};
MDIO_enumConfig_t TWO[NUM_SEVSEGPINs]={
									MDIO_enumOutput_HIGH, /*A*/
									MDIO_enumOutput_HIGH, /*B*/
									MDIO_enumOutput_LOW,  /*C*/
									MDIO_enumOutput_HIGH, /*D*/
									MDIO_enumOutput_HIGH, /*E*/
									MDIO_enumOutput_LOW,  /*F*/
									MDIO_enumOutput_HIGH, /*G*/
									MDIO_enumOutput_LOW  /*DP*/
									//MDIO_enumOutput_LOW,  /*MODE*/
							};

MDIO_enumConfig_t THREE[NUM_SEVSEGPINs]={
									MDIO_enumOutput_HIGH, /*A*/
									MDIO_enumOutput_HIGH, /*B*/
									MDIO_enumOutput_HIGH, /*C*/
									MDIO_enumOutput_HIGH, /*D*/
									MDIO_enumOutput_LOW,  /*E*/
									MDIO_enumOutput_LOW,  /*F*/
									MDIO_enumOutput_HIGH, /*G*/
									MDIO_enumOutput_LOW  /*DP*/
									//MDIO_enumOutput_LOW,  /*MODE*/
							};
MDIO_enumConfig_t FOUR [NUM_SEVSEGPINs]={
									MDIO_enumOutput_LOW,  /*A*/
									MDIO_enumOutput_HIGH, /*B*/
									MDIO_enumOutput_HIGH, /*C*/
									MDIO_enumOutput_LOW,  /*D*/
									MDIO_enumOutput_LOW,  /*E*/
									MDIO_enumOutput_HIGH, /*F*/
									MDIO_enumOutput_HIGH, /*G*/
									MDIO_enumOutput_LOW  /*DP*/
									//MDIO_enumOutput_LOW,  /*MODE*/
							};
MDIO_enumConfig_t FIVE [NUM_SEVSEGPINs]={
									MDIO_enumOutput_HIGH, /*A*/
									MDIO_enumOutput_LOW,  /*B*/
									MDIO_enumOutput_HIGH, /*C*/
									MDIO_enumOutput_HIGH, /*D*/
									MDIO_enumOutput_LOW,  /*E*/
									MDIO_enumOutput_HIGH, /*F*/
									MDIO_enumOutput_HIGH, /*G*/
									MDIO_enumOutput_LOW   /*DP*/
									//MDIO_enumOutput_LOW,  /*MODE*/
							};
MDIO_enumConfig_t SIX [NUM_SEVSEGPINs]={
									MDIO_enumOutput_HIGH, /*A*/
									MDIO_enumOutput_LOW,  /*B*/
									MDIO_enumOutput_HIGH, /*C*/
									MDIO_enumOutput_HIGH, /*D*/
									MDIO_enumOutput_HIGH, /*E*/
									MDIO_enumOutput_HIGH, /*F*/
									MDIO_enumOutput_HIGH, /*G*/
									MDIO_enumOutput_LOW   /*DP*/
									//MDIO_enumOutput_LOW,  /*MODE*/
							};

MDIO_enumConfig_t SEVEN [NUM_SEVSEGPINs]={
									MDIO_enumOutput_HIGH, /*A*/
									MDIO_enumOutput_HIGH, /*B*/
									MDIO_enumOutput_HIGH, /*C*/
									MDIO_enumOutput_LOW,  /*D*/
									MDIO_enumOutput_LOW,  /*E*/
									MDIO_enumOutput_LOW,  /*F*/
									MDIO_enumOutput_LOW,  /*G*/
									MDIO_enumOutput_LOW  /*DP*/
									//MDIO_enumOutput_LOW,  /*MODE*/
							};

MDIO_enumConfig_t EIGHT [NUM_SEVSEGPINs]={
									MDIO_enumOutput_HIGH, /*A*/
									MDIO_enumOutput_HIGH, /*B*/
									MDIO_enumOutput_HIGH, /*C*/
									MDIO_enumOutput_HIGH, /*D*/
									MDIO_enumOutput_HIGH, /*E*/
									MDIO_enumOutput_HIGH, /*F*/
									MDIO_enumOutput_HIGH, /*G*/
									MDIO_enumOutput_LOW  /*DP*/
									//MDIO_enumOutput_LOW,  /*MODE*/
							};

MDIO_enumConfig_t NINE  [NUM_SEVSEGPINs]={
									MDIO_enumOutput_HIGH, /*A*/
									MDIO_enumOutput_HIGH, /*B*/
									MDIO_enumOutput_HIGH, /*C*/
									MDIO_enumOutput_HIGH, /*D*/
									MDIO_enumOutput_LOW,  /*E*/
									MDIO_enumOutput_HIGH, /*F*/
									MDIO_enumOutput_HIGH, /*G*/
									MDIO_enumOutput_LOW  /*DP*/
									//MDIO_enumOutput_LOW,  /*MODE*/
							};

const char SEVSEG_Num[10]= {0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};


