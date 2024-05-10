/************************************/
/*	Author	  :	Nour Abd EL-Aziz 	*/
/*	SWC		  : Seven Segment		*/
/*  Layer	  : HAL  				*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 19, 2023	*/
/*	Last Edit :	N/A					*/
/************************************/
#ifndef SEVSEG_INTERFACE_H_
#define SEVSEG_INTERFACE_H_

/**********************************************************************************************************************/
/******************************************************SEVSEG CONFIG FUNCTIONS*******************************************/
/**********************************************************************************************************************/
/**
	* Function Description :       HAL_SEVSEG_Init take Config all pins and ports from SEVSEG_CONFIG array in config.c file
*/
HAL_enumSEVSEGERRORStatus HAL_SEVSEG_Init(void);
/**
	* Function Description :       HAL_SEVSEG_PORT_INIT Config when sevsseg is connected on whole PORT PIN A of SEVSEG corresponding to pin0 of PORT
*/
HAL_enumSEVSEGERRORStatus HAL_SEVSEG_PORT_INIT(void);
/**
	* Function Description :       HAL_SEVSEG_PORT_DISPLAY_NUM display the input number if SEVSEG configured by HAL_SEVSEG_PORT_INIT
    *this function handle number display up to 99
*/
HAL_enumSEVSEGERRORStatus HAL_SEVSEG_PORT_DISPLAY_NUM(uinit8_t NUM_of_SEVSEGs,uinit8_t Copy_InputNumberDisplay);
/**
	* Function Description :       HAL_SINGLE_SEVSEG_Display display the input number if SEVSEG configured by HAL_SEVSEG_Init
    *this function handle number display up to 9
    *give the ID of which segment to display on this number
*/
HAL_enumSEVSEGERRORStatus HAL_SINGLE_SEVSEG_Display(uinit8_t SEVSEG_ID,uinit8_t Copy_InputNumberDisplay);
/**
	* Function Description :       HAL_DOUBLE_SEVSEG_Display display the input number if SEVSEG configured by HAL_SEVSEG_Init
    *this function handle number display up to 99
    *give number to display ->ONLY HANDLE 2SEVSEGs
*/
HAL_enumSEVSEGERRORStatus HAL_DOUBLE_SEVSEG_Display(uinit8_t Copy_InputNumberDisplay);
/**
	* Function Description :       HAL_SEVSEG_STARTCount count from the input start number to stop if SEVSEG configured by HAL_SEVSEG_Init
    *this function handle count up and count down
    *give number to display ->ONLY HANDLE 2SEVSEGs
*/
HAL_enumSEVSEGERRORStatus HAL_SEVSEG_STARTCount(uinit8_t CopyNUM_of_SEVSEGs,uinit8_t Start_Num,uinit8_t Stop_Num);
//HAL_enumSEVSEGERRORStatus HAL_SEVSEG_STOP   (void);

#endif /* SEVSEG_INTERFACE_H_ */
