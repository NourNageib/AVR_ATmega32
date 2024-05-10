/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Task	  : Task2    	       */
/*	Layer	  : APP                */
/*	Version   : 1.0                */
/*	Date	  : December 1 , 2023  */
/*	Last Edit : N/A                */
/***********************************/

#define F_CPU 8000000UL
#include <stdio.h>
#include "STD_types.h"
#include "AVR_REGs.h"
#include <avr/delay.h>
#include "BIT_math.h"
#include "MDIO_config.h"
#include "MDIO_interface.h"
#include "MDIO_private.h"
#include "SEVSEG_config.h"
#include "SEVSEG_interface.h"

#include "MEXTI_private.h"
#include "MEXTI_config.h"
#include "MEXTI_inerface.h"
uinit8_t Value=30;
void Increament(void)
{
	Value++;
	HAL_DOUBLE_SEVSEG_Display(Value);
	_delay_ms(300);
}
void Decreament(void)
{
	Value--;
	HAL_DOUBLE_SEVSEG_Display(Value);
	_delay_ms(300);
}
void sevsegstart(void)
{

		HAL_SEVSEG_STARTCount(2,Value,0);

		_delay_ms(6000);
}




int main(void)
{

	HAL_SEVSEG_Init();

	MEXTI_enumEnableGIE();
	HAL_DOUBLE_SEVSEG_Display(00);
	while(1)
	{

		MDIO_SetPinDirection(MDIO_enumPortD,MDIO_enumPin2,MDIO_enumInputInternalPU);
		MDIO_SetPinDirection(MDIO_enumPortD,MDIO_enumPin3,MDIO_enumInputInternalPU);
		MDIO_SetPinDirection(MDIO_enumPortB,MDIO_enumPin2,MDIO_enumInputInternalPU);
		MDIO_SetPinDirection(MDIO_enumPortB,MDIO_enumPin1,MDIO_enumOutput_LOW);
		MEXTI_enumPeripheralINTEnable(MEXTI_INT2);
		MEXTI_enumInit(MEXTI_INT2,MEXTI_RAISING_EDGE);
		MEXTI_enumPeripheralINTEnable(MEXTI_INT1);
		MEXTI_enumInit(MEXTI_INT1,MEXTI_ON_LOGICAL_CHANGE);
		MEXTI_enumPeripheralINTEnable(MEXTI_INT0);
	    MEXTI_enumInit(MEXTI_INT0,MEXTI_ON_LOGICAL_CHANGE);
		SetCallBack_INT(sevsegstart,MEXTI_INT2);
		SetCallBack_INT(Increament,MEXTI_INT1);
		SetCallBack_INT(Decreament,MEXTI_INT0);
	}



  return 0;
}
