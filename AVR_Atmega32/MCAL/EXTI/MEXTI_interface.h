/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : EXTI   		       */
/*	Layer	  : MCAL               */
/*	Version   : 1.0                */
/*	Date	  : December 25 , 2023 */
/*	Last Edit : N/A				   */
/***********************************/


#ifndef MEXTI_INERFACE_H_
#define MEXTI_INERFACE_H_

/**********FOR PRE-COMPILATION CONFIGURATION ************/
/* User should send one of these opts */
/*   to enable/Disable -> PIE (GICR)  */

#define MEXTI_INT1  7
#define MEXTI_INT0  6
#define MEXTI_INT2  5
#define MEXTI_IBIT  7

/*INT Trigger mode */
#define MEXTI_FALLING_EDGE      0
#define MEXTI_RAISING_EDGE      1
#define MEXTI_LOW_LEVEL         2
#define MEXTI_HIGH_LEVEL        3
#define MEXTI_ON_LOGICAL_CHANGE 4



/********************************************************MEXTI Functions ***********************************************************/

/*
  *Function  : MGIE_enumEnableGIE ->Take void return status to enable Global Interrupt Enable by set 1 to I-BIT in SFIOR REG
 */

MEXTI_enumErrorStatus MEXTI_enumEnableGIE(void);
/*
  *Function  : MGIE_enumDisableGIE -> Take void return status to disable Global Interrupt Enable by clear I-BIT in SFIOR REG
 */
MEXTI_enumErrorStatus MEXTI_enumDisableGIE(void);
/*
  * Function : Function Take INT Number and Trigger mode
*/
MEXTI_enumErrorStatus MEXTI_enumInit(uinit8_t Copy_uinit8INTno , uinit8_t Copy_uinit8MODE);
/*
  *Function  : MEXTI_enumPeripheralINTEnable ->Take INT need to be enabled from avalible opts and set PIE in control register -> GICR
 */
MEXTI_enumErrorStatus MEXTI_enumPeripheralINTEnable (uinit8_t Copy_uinit8INTno);
/*
  *Function  : MEXTI_enumPeripheralINTDisable ->Take INT need to be disabled from avalible opts and clear PIE in control register -> GICR
 */
MEXTI_enumErrorStatus MEXTI_enumPeripheralINTDisable(uinit8_t Copy_uinit8INTno);
/*
  *Function  : SetCallBack_INT ->Take INT number and user function to call for execution once this ext int triggered
 */
MEXTI_enumErrorStatus SetCallBack_INT(void (*USER_INTEvent_fun)(void),uinit8_t Copy_uinit8INTno);


#endif /* MEXTI_INERFACE_H_ */
