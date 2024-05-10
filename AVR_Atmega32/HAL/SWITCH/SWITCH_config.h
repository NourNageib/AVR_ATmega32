/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : SWITCH 		       */
/*	Layer	  : HAL                */
/*	Version   : 1.1                */
/*	Date	  : December 1 , 2023  */
/*	Last Edit : N/A                */
/***********************************/


#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_



/*Set Num of LEDs in system*/
#define SWITCH_DEFAULT_NUM  3
#define NUM_SWITCHs SWITCH_DEFAULT_NUM


/*Examples of SWITCHs used in system */
#define START_SWITCH 0
#define STOP_SWITCH  1
#define RESET_SWITCH 2
/*****************************************/
/*                                      **/
/*                                      **/
/*HAL_L                                ***/
/*****************************************/



typedef enum
{
	HAL_SWITCHenumInput_PU,
	HAL_SWITCHenumInput_HI

}HAL_enumSWITCHState;

/*SWITCH CONFIGURATION STRUCT FOR EACH SWITCH ALL IN ONE ARRAY */
typedef struct
{
	
	MDIO_enumPorts_t    HAL_SWITCH_PORT;
	MDIO_enumPins_t     HAL_SWITCH_PIN;
	MDIO_enumConfig_t   HAL_SWITCH_STATE;
	
}SWITCH_struct_config;

typedef enum
{
	HAL_SWITCHenumNORMALPRESS,
	HAL_SWITCHenumLONGPRESS,
	HAL_SWITCHenumSORTPRESS

}HAL_enumSWITCHmode;
typedef enum
{
	HAL_SWITCHenumOk,
	HAL_SWITCHenumERROR
	
}HAL_SWITCHenumStatus;



extern SWITCH_struct_config SWITCH_Global_Array[NUM_SWITCHs];



#endif /* SWITCH_CONFIG_H_ */