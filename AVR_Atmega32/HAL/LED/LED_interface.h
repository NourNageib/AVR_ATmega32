/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : LED  		       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : December 12 , 2023 */
/*	Last Edit : N/A                */
/***********************************/


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_



/*
 *
 * *Description : HAL_LED_INIT function use array of led struct to configure each led as a a group
 *
 */
HAL_LEDenumStatus HAL_LED_INIT(void);
/*
 *
 * *Description : HLED_SetSingleLEDDirection function use  led struct to configure each led alone
 *
 */
HAL_LEDenumStatus HLED_SetLEDDirection(MDIO_enumPorts_t Copy_uinit8PortNum ,MDIO_enumPins_t Copy_uinit8PinNum);
/*
 *
 * *Description : HLED_SetSingleLEDDirection function use  led struct to set  led ON
 *
 */
HAL_LEDenumStatus HLED_SetSingleLED_ON(MDIO_enumPorts_t Copy_uinit8PortNum ,MDIO_enumPins_t Copy_uinit8PinNum);
/*
 *
 * *Description : HLED_SetSingleLEDDirection function use  led struct to set  led OFF
 *
 */
HAL_LEDenumStatus HLED_SetSingleLED_OFF(MDIO_enumPorts_t Copy_uinit8PortNum ,MDIO_enumPins_t Copy_uinit8PinNum);


#endif /* LED_INTERFACE_H_ */