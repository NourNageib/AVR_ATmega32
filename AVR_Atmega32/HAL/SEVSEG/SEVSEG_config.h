/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : Seven Segment		*/
/*  Layer	  : HAL  				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 19, 2023	*/
/*	Last Edit :	N/A					*/
/************************************/

#ifndef SEVSEG_CONFIG_H_
#define SEVSEG_CONFIG_H_

/*************************NUM od 7SEF **********************/
/*Configure number of seven segments based on application .*/
/***********************************************************/
#define NUM_SEVSEGs                       2
#define NUM_SEVSEGPINs                    8
#define SIZE_Cnfg_PORT_Array NUM_SEVSEGs * NUM_SEVSEGPINs
/***********************************************************/




/****************Errors Enum***************************/

typedef enum
{
	SEVSEG_enumOK,
	SEVSEG_enumConfigError,
	SEVSEG_enumNumDisplayError,
	SEVSEG_enumNumDisplayOK,
	SEVSEG_enumWrongNum

}HAL_enumSEVSEGERRORStatus;

/************SEVSEG Configurations ****************/


typedef struct
{
	MDIO_enumPorts_t  SEVSEG_PORT;
	MDIO_enumPins_t   SEVSEG_PIN ;
	MDIO_enumConfig_t SEVSEG_STATE ;

}SEVSEG_Sruct_confg;





/*****************7SEF MODE *****************/
/*
  * User must choose from following options:
  *------------------------------------------
  *1-SEVSEG_COMMON_CATHODE_EN
  *2-SEVSEG_COMMON_CATHODE_DA
  *3-SEVSEG_COMMON_ANODE_EN
  *4-SEVSEG_COMMON_ANODE_DA
*/
typedef enum
{
	SEVSEG_COMMON_CATHODE_EN,
	SEVSEG_COMMON_CATHODE_DA,
	SEVSEG_COMMON_ANODE_EN,
	SEVSEG_COMMON_ANODE_DA

}SEVSEG_MODE_opts;

/****************************************************************************************************/
/*                                         Struct for 7SEG config					   			    */
/*--------------------------------------------------------------------------------------------------*/
/*	 ** PORTS OPTIONS : **	    */                 /*     ** PINS OPTIONS : **	   *//*             */
/*   -----------------------                           -------------------------                    */
/*	   MDIO_enumPortA,	    */                          /* MDIO_enumPin0, *//*                      */
/*	   MDIO_enumPortB,	    */						    /* MDIO_enumPin1, *//*                      */
/*	   MDIO_enumPortC,  	*/                          /* MDIO_enumPin2, *//*					    */
/*	   MDIO_enumPortD	   	*/                          /* MDIO_enumPin3, *//*                      */
/*****************************/                         /* MDIO_enumPin4, *//*                      */
/*  HINT :TO CONFIG EACH PIN OF 7SEG                    /* MDIO_enumPin5, *//*                      */
/*        CONNECTED TO WHICH PIN     */                 /* MDIO_enumPin6, *//*                      */
/*                                                      /* MDIO_enumPin7  *//*                      */
/****************************************************************************************************/
/**********************CASE OF CONNECT SEVSEG PORT **********************/
/*Configure number of seven segments based on application .*/
/***********************************************************/
#define SEVSEG_1_PORT  MDIO_enumPortB
#define SEVSEG_2_PORT  MDIO_enumPortD
#define SEVSEG_1_STATE MDIO_enumOutput_LOW
#define SEVSEG_2_STATE MDIO_enumOutput_LOW
/*****************************************************************/
#define SEVSEG_A_        0
#define SEVSEG_B_        1
#define SEVSEG_C_        2
#define SEVSEG_D_        3
#define SEVSEG_E_        4
#define SEVSEG_F_        5
#define SEVSEG_G_        6
#define SEVSEG_DP_       7
//#define SEVSEG_MODE_     8


#define SEVSEG_A_PIN        MDIO_enumPin0
#define SEVSEG_B_PIN        MDIO_enumPin1
#define SEVSEG_C_PIN        MDIO_enumPin2
#define SEVSEG_D_PIN        MDIO_enumPin3
#define SEVSEG_E_PIN        MDIO_enumPin4
#define SEVSEG_F_PIN        MDIO_enumPin5
#define SEVSEG_G_PIN        MDIO_enumPin6
#define SEVSEG_DP_PIN       MDIO_enumPin7
//#define SEVSEG_MODE_PIN     MDIO_enumPin0

#define SEVSEG_A_PORT       MDIO_enumPortA
#define SEVSEG_B_PORT       MDIO_enumPortA
#define SEVSEG_C_PORT       MDIO_enumPortA
#define SEVSEG_D_PORT       MDIO_enumPortA
#define SEVSEG_E_PORT       MDIO_enumPortA
#define SEVSEG_F_PORT       MDIO_enumPortA
#define SEVSEG_G_PORT       MDIO_enumPortA
#define SEVSEG_DP_PORT      MDIO_enumPortA
//#define SEVSEG_MODE_PORT    MDIO_enumPortB


/*************************************************************/
/*                   PIN MODE OPTIONS                        */
/*************************************************************/
/*                  1-MDIO_enumOutput_LOW,                   */
/*                  2-MDIO_enumOutput_HIGH                   */
/*************************************************************/

#define SEVSEG_A_OUTPUT_CONFIG     MDIO_enumOutput_LOW
#define SEVSEG_B_OUTPUT_CONFIG     MDIO_enumOutput_LOW
#define SEVSEG_C_OUTPUT_CONFIG     MDIO_enumOutput_LOW
#define SEVSEG_D_OUTPUT_CONFIG     MDIO_enumOutput_LOW
#define SEVSEG_E_OUTPUT_CONFIG     MDIO_enumOutput_LOW
#define SEVSEG_F_OUTPUT_CONFIG     MDIO_enumOutput_LOW
#define SEVSEG_G_OUTPUT_CONFIG     MDIO_enumOutput_LOW
#define SEVSEG_DP_OUTPUT_CONFIG    MDIO_enumOutput_LOW




#define ZERO_0  0
#define ONE_1   1
#define TWO_2   2
#define THREE_3 3
#define FOUR_4  4
#define FIVE_5  5
#define SIX_6   6
#define SEVEN_7 7
#define EIGHT_8 8
#define NINE_9  9



#endif /* SEVSEG_CONFIG_H_ */
