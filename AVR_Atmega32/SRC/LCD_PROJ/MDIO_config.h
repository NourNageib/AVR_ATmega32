/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : DIO   		       */
/*	Layer	  : MCAL               */
/*	Version   : 1.1                 */
/*	Date	  : December 1 , 2023  */
/*	Last Edit : December 12 , 2023 */
/***********************************/


#ifndef MDIO_CONFIG_H_
#define MDIO_CONFIG_H_

typedef enum
{
	MDIO_enumPortA,
	MDIO_enumPortB,
	MDIO_enumPortC,
	MDIO_enumPortD

}MDIO_enumPorts_t;

typedef enum
{
	MDIO_enumOk,
	MDIO_enumNullPointer,
	MDIO_enumWrongPort,
	MDIO_enumWrongPin,
	MDIO_enumWrongConfig,
	MDIO_enumERRORValue,
	MDIO_enumErrorOpre
	
}MDIO_enumError_t;


typedef enum
{
	MDIO_enumLogicLow,
	MDIO_enumLogicHigh
}MDIO_enumLogicState_t;

typedef enum
{
	MDIO_enumPin0,
	MDIO_enumPin1,
	MDIO_enumPin2,
	MDIO_enumPin3,
	MDIO_enumPin4,
	MDIO_enumPin5,
	MDIO_enumPin6,
	MDIO_enumPin7
}MDIO_enumPins_t;




/*Define pins  value*/
#define MDIO_PIN_HIGH    1
#define MDIO_PIN_LOW     0


/********************************************/
/*   Options to set all pins at a time
 *   Replace "MDIO_OUTPUT_LOW" with your
 *   option in "MDIO_PIN_DEF_DDR"         */
/********************************************/

typedef enum
{

	MDIO_enumOutput_LOW,
	MDIO_enumOutput_HIGH,
	MDIO_enumInputInternalPU,
	MDIO_enumInputExternalPD

}MDIO_enumConfig_t;


/***********************************************************/
/*Set default DDR for PINS MDIO_OUTPUT_LOW */
//#define MDIO_PIN_DEF_DDR    MDIO_OUTPUT_LOW

/***********************************************************/

/*Port config for each hardware connection (LED,SWITCH....etc)*/
typedef struct
{
	MDIO_enumPorts_t   MPORT_HW_Config;
	MDIO_enumPins_t    MPIN_HW_Config;
	MDIO_enumConfig_t  MPORT_Config_State;

}MDIO_HW_Config_t;


#endif /* MDIO_CONFIG_H_ */
