/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : EXTI   		       */
/*	Layer	  : MCAL               */
/*	Version   : 1.0                */
/*	Date	  : December 25 , 2023 */
/*	Last Edit : N/A				   */
/***********************************/

#include "../../LIB/BIT_math.h"
#include "../../LIB/STD_types.h"

#include "../MCAL/EXTI/MEXTI_config.h"
#include "../MCAL/EXTI/MEXTI_private.h"
#include "../MCAL/EXTI/MEXTI_interface.h"

void (*MEXTI_ISR0)(void)=NULL;
void (*MEXTI_ISR1)(void)=NULL;
void (*MEXTI_ISR2)(void)=NULL;


MEXTI_enumErrorStatus MEXTI_enumEnableGIE(void)
{
	MEXTI_enumErrorStatus state = MEXTI_Enable_ERROR;
	SET_BIT(SREG , MEXTI_IBIT);
	state = MEXTI_Enable_OK ;
	return state ;
}

MEXTI_enumErrorStatus MEXTI_enumDisableGIE(void)
{
	MEXTI_enumErrorStatus state = MEXTI_Disable_ERROR;
	CLR_BIT(SREG , MEXTI_IBIT);
	state = MEXTI_Disable_OK ;
	return state ;
}

MEXTI_enumErrorStatus MEXTI_enumInit(uinit8_t Copy_uinit8INTno , uinit8_t Copy_uinit8MODE)
{
	MEXTI_enumErrorStatus state = MEXTI_ERROR_INIT;
	//SET_BIT(SREG , MEXTI_IBIT);
	switch(Copy_uinit8INTno)
	{
		case MEXTI_INT0 :
		{
			uinit8_t Loc_u8RegValueINT0 = MCUCR ;
			Loc_u8RegValueINT0 &= MEXTI_INT0_MASK ;
			switch(Copy_uinit8MODE)
			{
				case MEXTI_LOW_LEVEL :
				{
					Loc_u8RegValueINT0 |= MEXTI_INT0_LL;
					MCUCR = Loc_u8RegValueINT0;
					state = MEXTI_INIT_OK ;
				}break;
				
				case MEXTI_ON_LOGICAL_CHANGE :
				{
					Loc_u8RegValueINT0 |= MEXTI_INT0_LC;
					MCUCR = Loc_u8RegValueINT0;
					state = MEXTI_INIT_OK ;
					
				}break;
				
				case MEXTI_FALLING_EDGE :
				{
					Loc_u8RegValueINT0 |= MEXTI_INT0_FE;
					MCUCR = Loc_u8RegValueINT0;
					state = MEXTI_INIT_OK ;
					
				}break;
				
				case MEXTI_RAISING_EDGE :
				{
					Loc_u8RegValueINT0 |= MEXTI_INT0_RE ;
					MCUCR = Loc_u8RegValueINT0;
					state = MEXTI_INIT_OK;
				}break;

				default :
				{
					state = MEXTI_ERROR_INIT;
				}break;
			}
			
		} break ;
		case MEXTI_INT1 :
		{
			uinit8_t Loc_u8RegValueINT1 = MCUCR ;
			Loc_u8RegValueINT1 &= MEXTI_INT1_MASK ;
			switch(Copy_uinit8MODE)
			{
				case MEXTI_LOW_LEVEL :
				{
					Loc_u8RegValueINT1 |= MEXTI_INT1_LL;
					MCUCR = Loc_u8RegValueINT1;
					state = MEXTI_INIT_OK ;
				}break;
				
				case MEXTI_ON_LOGICAL_CHANGE :
				{
					Loc_u8RegValueINT1 |= MEXTI_INT1_LC;
					MCUCR = Loc_u8RegValueINT1;
					state = MEXTI_INIT_OK ;
					
				}break;
				
				case MEXTI_FALLING_EDGE :
				{
					Loc_u8RegValueINT1 |= MEXTI_INT1_FE;
					MCUCR = Loc_u8RegValueINT1;
					state = MEXTI_INIT_OK ;
					
				}break;
				
				case MEXTI_RAISING_EDGE :
				{
					Loc_u8RegValueINT1 |= MEXTI_INT1_RE ;
					MCUCR = Loc_u8RegValueINT1;
					state = MEXTI_INIT_OK;
				}break;
				default :
				{
					state = MEXTI_ERROR_INIT;
				} break ;
			}
			
		} break ;
		case MEXTI_INT2 :
		{
			uinit8_t Loc_u8RegValueINT2 = MCUCR ;
			MCUCSR &= MEXTI_INT2_MASK ;
			switch(Copy_uinit8MODE)
			{

				
				case MEXTI_FALLING_EDGE :
				{
					Loc_u8RegValueINT2 |= MEXTI_INT2_FE ;
					MCUCR = Loc_u8RegValueINT2;
					state = MEXTI_INIT_OK;
					
				}break;
				
				case MEXTI_RAISING_EDGE :
				{
					Loc_u8RegValueINT2 |= MEXTI_INT2_RE ;
					MCUCR = Loc_u8RegValueINT2;
					state = MEXTI_INIT_OK;
				}break;
			}
			
		} break ;
		default: 
		{
			state = MEXTI_ERROR_INIT;
			
		} break ;
		
	}
	return state ;
	
}
MEXTI_enumErrorStatus MEXTI_enumPeripheralINTEnable (uinit8_t Copy_uinit8INTno)
{ 
	/*
	  * MEXTI defined by pin number in GICR register directly 
	*/
	MEXTI_enumErrorStatus state =MEXTI_Enable_ERROR ;
	switch(Copy_uinit8INTno)
	{
		case MEXTI_INT0 : SET_BIT(GICR,MEXTI_INT0); state = MEXTI_Enable_OK; break ;
		case MEXTI_INT1 : SET_BIT(GICR,MEXTI_INT1); state = MEXTI_Enable_OK; break ;
		case MEXTI_INT2 : SET_BIT(GICR,MEXTI_INT2); state = MEXTI_Enable_OK; break ;
		
		default:
		{
			state = MEXTI_Enable_ERROR;
		}break ;
	}
	
	return state;
}

MEXTI_enumErrorStatus MEXTI_enumPeripheralINTDisable (uinit8_t Copy_uinit8INTno)
{
	MEXTI_enumErrorStatus state = MEXTI_Disable_ERROR ;
	switch(Copy_uinit8INTno)
	{
		case MEXTI_INT0 : CLR_BIT(GICR,MEXTI_INT0); state = MEXTI_Enable_OK; break ;
		case MEXTI_INT1 : CLR_BIT(GICR,MEXTI_INT1); state = MEXTI_Enable_OK; break ;
		case MEXTI_INT2 : CLR_BIT(GICR,MEXTI_INT2); state = MEXTI_Enable_OK; break ;
		
		default:
		{
			state = MEXTI_Disable_ERROR;
		} break ;
	}
	
	return state;
}




MEXTI_enumErrorStatus SetCallBack_INT(void (*USER_INTEvent_fun)(void),uinit8_t Copy_uinit8INTno)
{
	MEXTI_enumErrorStatus state = MEXTI_SETCALLBACK_ERROR ;
	
	if(USER_INTEvent_fun==NULL)
	{
		 state = MEXTI_SETCALLBACK_ERROR ;
	}
	else
	{
		switch(Copy_uinit8INTno)
		{
			case MEXTI_INT0 : MEXTI_ISR0 = USER_INTEvent_fun ; state = MEXTI_SETCALLBACK_OK ; break;
			case MEXTI_INT1 : MEXTI_ISR1 = USER_INTEvent_fun ; state = MEXTI_SETCALLBACK_OK; break;
			case MEXTI_INT2 : MEXTI_ISR2 = USER_INTEvent_fun ; state = MEXTI_SETCALLBACK_OK; break;
			
			default : state = MEXTI_SETCALLBACK_ERROR; break;
		}
		
		
	}
	
	return state;
}
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{

	(*MEXTI_ISR0)();
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	(*MEXTI_ISR1)();
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	(*MEXTI_ISR2)();
}


