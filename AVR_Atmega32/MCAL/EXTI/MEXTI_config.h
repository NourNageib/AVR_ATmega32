/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : EXTI   		       */
/*	Layer	  : MCAL               */
/*	Version   : 1.0                */
/*	Date	  : December 25 , 2023 */
/*	Last Edit : N/A				   */
/***********************************/


#ifndef MEXTI_CONFIG_H_
#define MEXTI_CONFIG_H_

typedef enum
{
	MEXTI_Enable_OK,
	MEXTI_Enable_ERROR,
	MEXTI_Disable_OK,
	MEXTI_Disable_ERROR,
	MEXTI_WRONG_INPUT,
	MEXTI_ERROR_INIT,
	MEXTI_INIT_OK,
	MEXTI_SETCALLBACK_ERROR,
	MEXTI_SETCALLBACK_OK
	
	
}MEXTI_enumErrorStatus;



#endif /* MEXTI_CONFIG_H_ */