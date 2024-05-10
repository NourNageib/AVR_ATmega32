/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : LED  		       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : December 12 , 2023 */
/*	Last Edit : N/A                */
/***********************************/

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_


/*Set Num of LEDs in system*/
#define NUM_LEDs 3


/*Examples of LEDS used in system */
#define START_LED 0
#define STOP_LED  1
#define RESET_LED 2


typedef enum
{
	HAL_LED_ACTIVE_HIGH,
	HAL_LED_ACTIVE_LOW
	
}HAL_LEDenumActiveState;
typedef struct
{
	 
	MDIO_enumPorts_t        HAL_LED_PORT;
	MDIO_enumPins_t         HAL_LED_PIN;
	MDIO_enumConfig_t       HAL_LED_ACTIVE_STATE;
	uinit8_t                HAL_LED_ON_OFF;
	
}LED_struct_config;

typedef enum
{
	HAL_LEDenumOk,
	HAL_LEDenumERROR
	
}HAL_LEDenumStatus;

/*OPTIONS FOR LED CONFIGURATION*/

#define HAL_LED_ACTIVE_LOW     0
#define HAL_LED_ACTIVE_HIGH    1
#define HAL_LED_INIT_STATE_OFF 1
#define HAL_LED_INIT_STATE_ON  1

/*User must enter the configuration of leds here */

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






#endif /* LED_CONFIG_H_ */