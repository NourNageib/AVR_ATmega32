/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : DIO   		       */
/*	Layer	  : MCAL               */
/*	Version   : 1.1                */
/*	Date	  : December 1 , 2023  */
/*	Last Edit : December 12 , 2023 */
/***********************************/

#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_


/**********************************************************************************************************************/
/******************************************************DIO CONFIG FUNCTIONS*******************************************/
/**********************************************************************************************************************/
/**
	* Funtcion Description :       MDIO_SetPortDirection take port num and config to set DDR reg                                                           
*/
MDIO_enumError_t MDIO_SetPortDirection (MDIO_enumPorts_t Copy_uinit8PortNum ,MDIO_enumConfig_t Copy_uinitPortConfig);
/**
	* Funtcion Description :       MDIO_SetPortValue take port num and State (HIGH VS LOW) to set PORT reg                                                           
*/
MDIO_enumError_t MDIO_SetPortValue     (MDIO_enumPorts_t Copy_uinit8PortNum ,MDIO_enumConfig_t Copy_uinit8LogicState);
/**
	* Function Description :       MDIO_GetPortValue take port num and address of variable to return port value in it BY READING PIN REG                                                         
*/
MDIO_enumError_t MDIO_GetPortValue     (MDIO_enumPorts_t Copy_uinit8PortNum ,uinit8_t* Get_Puinit8_tPortValue);
/*
	*Function Description :       MDIO_AssignPortValue Take port num and ssign the value required on the whole port at atime
*/
MDIO_enumError_t MDIO_AssignPortValue  (MDIO_enumPorts_t Copy_uinit8PortNum,uinit8_t uinit8_tPortValue);
/*
    *Funcion to write low nibble of the port at a time Take port required and value to be assigned
 */
MDIO_enumError_t MDIO_AssignValueLowNibble (MDIO_enumPorts_t Copy_uinit8PortNum, uinit8_t uinit8_tLowNibblePortValue );

/*ASSIGN HIGH <<4*/

/**********************************************************************************************************************/
/******************************************************PIN CONFIG FUNCTIONS********************************************/
/**********************************************************************************************************************/
/**
	*Funtcion Description :       MDIO_SetPinDirection take port num, pin num and config to set DDR reg                                                           
*/
MDIO_enumError_t MDIO_SetPinDirection  (MDIO_enumPorts_t Copy_uinit8PortNum ,MDIO_enumPins_t Copy_uinit8PinNum,MDIO_enumConfig_t Copy_uinitPortConfig);
/**
	*Funtcion Description :       MDIO_SetPinValue take port num, pin num and config to set PORT reg                                                           
*/
MDIO_enumError_t MDIO_SetPinValue      (MDIO_enumPorts_t Copy_uinit8PortNum ,MDIO_enumPins_t Copy_uinit8PinNum,MDIO_enumConfig_t Copy_uinit8LogicState);
/**
	* Funtcion Description :       MDIO_GetPortValue take port num,PIN num and address of variable to return port value in it BY READING PIN REG                                                            
*/
MDIO_enumError_t MDIO_GetPinValue      (MDIO_enumPorts_t Copy_uinit8PortNum,MDIO_enumPins_t Copy_uinit8PinNum,uinit8_t* Get_Puinit8_tPinValue);
/*
	* Function Description : MDIO_SetConfig :receive array from HW layer contain the HW configuration of this array and begin setting the configuration required
	**LENGTH ->indicates the number of HW parts 
*/
MDIO_enumError_t MDIO_SetConfig(MDIO_HW_Config_t* Add_Port_Config, uinit8_t LENGTH);

/**
	*Funtcion Description :       MDIO_GetPinValueReturn take port num, pin num and return directly pin reading in case of
	* any errors will return -1
*/
uinit8_t MDIO_GetPinValueReturn      (MDIO_enumPorts_t Copy_uinit8PortNum,MDIO_enumPins_t Copy_uinit8PinNum);
#endif
