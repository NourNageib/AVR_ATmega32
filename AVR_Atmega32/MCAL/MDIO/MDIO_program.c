/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : DIO   		       */
/*	Layer	  : MCAL               */
/*	Version   : 1.1                */
/*	Date	  : December 1 , 2023  */
/*	Last Edit : December 12 , 2023 */
/***********************************/

#include  "STD_types.h"
#include  "BIT_math.h"

#include  "AVR_REGs.h"

#include  "MDIO_config.h"
#include  "MDIO_interface.h"




MDIO_enumError_t MDIO_SetPortDirection (MDIO_enumPorts_t Copy_uinit8PortNum ,MDIO_enumConfig_t Copy_uinitPortConfig)
{
	MDIO_enumError_t State;
	/*check on port num didnot exceed the max*/
	if((Copy_uinit8PortNum>4)|| (Copy_uinit8PortNum<0))
	{
		State = MDIO_enumWrongPort;
		
	}
	else
	{
		if((Copy_uinitPortConfig == MDIO_enumOutput_HIGH) || (Copy_uinitPortConfig == MDIO_enumOutput_LOW))
		{
			switch (Copy_uinit8PortNum)
			{
				case MDIO_enumPortA : SET_REG(MDIO_DDRA);break;
				case MDIO_enumPortB : SET_REG(MDIO_DDRB);break;
				case MDIO_enumPortC : SET_REG(MDIO_DDRC);break;
				case MDIO_enumPortD : SET_REG(MDIO_DDRD);break;
				default:/*error*/break;
			}
			State=MDIO_enumOk;
		}
		else if((Copy_uinitPortConfig == MDIO_enumInputInternalPU) ||(Copy_uinitPortConfig == MDIO_enumInputExternalPD))
		{
			switch(Copy_uinitPortConfig)
						{
							case  MDIO_enumInputInternalPU :
							{
								switch (Copy_uinit8PortNum)
								{
									case MDIO_enumPortA : SET_REG(MDIO_PORTA);CLR_REG(MDIO_DDRA);break;
									case MDIO_enumPortB : SET_REG(MDIO_PORTB);CLR_REG(MDIO_DDRA);break;
									case MDIO_enumPortC : SET_REG(MDIO_PORTC);CLR_REG(MDIO_DDRA);break;
									case MDIO_enumPortD : SET_REG(MDIO_PORTD);CLR_REG(MDIO_DDRA);break;

			                     	default:/*error*/break;
			                      }
			                    State=MDIO_enumOk;
							}break;
							case  MDIO_enumInputExternalPD :
							{
								switch (Copy_uinit8PortNum)
								{
									case MDIO_enumPortA : CLR_REG(MDIO_DDRA);break;
									case MDIO_enumPortB : CLR_REG(MDIO_DDRA);break;
									case MDIO_enumPortC : CLR_REG(MDIO_DDRA);break;
									case MDIO_enumPortD : CLR_REG(MDIO_DDRA);break;

									default:/*error*/break;
								  }
								State=MDIO_enumOk;
							}break;
							default:/*error*/break;
		            }
	          }
	}
	State =MDIO_enumWrongConfig;
	return State;
	
}
MDIO_enumError_t MDIO_SetPortValue     (MDIO_enumPorts_t Copy_uinit8PortNum ,MDIO_enumConfig_t Copy_uinit8LogicState)
{
	MDIO_enumError_t State;
	if((Copy_uinit8PortNum>4) || (Copy_uinit8PortNum<0))
	{
		State =MDIO_enumWrongPort;
		
	}
	else
	{
		if(Copy_uinit8LogicState==MDIO_enumOutput_HIGH)
		{
			switch (Copy_uinit8PortNum)
			{
				case MDIO_enumPortA : SET_REG(MDIO_PORTA);break;
				case MDIO_enumPortB : SET_REG(MDIO_PORTB);break;
				case MDIO_enumPortC : SET_REG(MDIO_PORTC);break;
				case MDIO_enumPortD : SET_REG(MDIO_PORTD);break;
			}
			State=MDIO_enumOk;
		}
		else if(Copy_uinit8LogicState==MDIO_enumOutput_LOW)
		{
			switch (Copy_uinit8PortNum)
			{
				case MDIO_enumPortA : CLR_REG(MDIO_PORTA);break;
				case MDIO_enumPortB : CLR_REG(MDIO_PORTB);break;
				case MDIO_enumPortC : CLR_REG(MDIO_PORTC);break;
				case MDIO_enumPortD : CLR_REG(MDIO_PORTD);break;
			}
			State=MDIO_enumOk;
		}
		else if(Copy_uinit8LogicState==MDIO_enumInputInternalPU)
		{
			switch (Copy_uinit8PortNum)
			{
				case MDIO_enumPortA : SET_REG(MDIO_PORTA);break;
				case MDIO_enumPortB : SET_REG(MDIO_PORTB);break;
				case MDIO_enumPortC : SET_REG(MDIO_PORTC);break;
				case MDIO_enumPortD : SET_REG(MDIO_PORTD);break;
			}
			State=MDIO_enumOk;
		}
		else if(Copy_uinit8LogicState == MDIO_enumInputExternalPD)
		{
			switch (Copy_uinit8PortNum)
			{
				case MDIO_enumPortA : CLR_REG(MDIO_PORTA);break;
				case MDIO_enumPortB : CLR_REG(MDIO_PORTB);break;
				case MDIO_enumPortC : CLR_REG(MDIO_PORTC);break;
				case MDIO_enumPortD : CLR_REG(MDIO_PORTD);break;
			}
			State=MDIO_enumOk;
		}
	}
	State = MDIO_enumWrongConfig;
	return State;
	
	
}
MDIO_enumError_t MDIO_GetPortValue     (MDIO_enumPorts_t Copy_uinit8PortNum ,uinit8_t* Get_Puinit8_tPortValue)
{
	MDIO_enumError_t State;
	if((Copy_uinit8PortNum>4) || (Copy_uinit8PortNum<0))
	{
		State = MDIO_enumWrongPort;
		
	}
	else
	{
		switch (Copy_uinit8PortNum)
		{
			case MDIO_enumPortA    : *Get_Puinit8_tPortValue = MDIO_PINA ; break;
			case MDIO_enumPortB    : *Get_Puinit8_tPortValue = MDIO_PINB ; break;
			case MDIO_enumPortC    : *Get_Puinit8_tPortValue = MDIO_PINC ; break;
			case MDIO_enumPortD    : *Get_Puinit8_tPortValue = MDIO_PIND ; break;
			default :
			{
				State =MDIO_enumERRORValue;
			}
		}
		State=MDIO_enumOk;
	}

	return State;
	

}

/*PIN CONFIG FUNCTIONS*/
MDIO_enumError_t MDIO_SetPinDirection  (MDIO_enumPorts_t Copy_uinit8PortNum ,MDIO_enumPins_t Copy_uinit8PinNum,MDIO_enumConfig_t Copy_uinitPortConfig)
{
	
	MDIO_enumError_t State;
	/*check on port and pin num didnot exceed the max*/
	if(((Copy_uinit8PortNum>4) || (Copy_uinit8PortNum<0)) && ((Copy_uinit8PinNum<0) || (Copy_uinit8PinNum>8)))
	{
		State =MDIO_enumWrongConfig;
		
	}
	else
	{
		if((Copy_uinitPortConfig==MDIO_enumOutput_HIGH) ||(Copy_uinitPortConfig==MDIO_enumOutput_LOW))
		{
			switch (Copy_uinit8PortNum)
			{
				case MDIO_enumPortA : SET_BIT(MDIO_DDRA,Copy_uinit8PinNum);break;
				case MDIO_enumPortB : SET_BIT(MDIO_DDRB,Copy_uinit8PinNum);break;
				case MDIO_enumPortC : SET_BIT(MDIO_DDRC,Copy_uinit8PinNum);break;
				case MDIO_enumPortD : SET_BIT(MDIO_DDRD,Copy_uinit8PinNum);break;
				default :
				{
					State =MDIO_enumWrongConfig;
				}
			}
			State=MDIO_enumOk;
		}
		else if((Copy_uinitPortConfig==MDIO_enumInputInternalPU) ||(Copy_uinitPortConfig==MDIO_enumInputExternalPD))
		{
			switch(Copy_uinitPortConfig)
			{
				case  MDIO_enumInputInternalPU :
				{
					switch (Copy_uinit8PortNum)
					{
						case MDIO_enumPortA : SET_BIT(MDIO_PORTA,Copy_uinit8PinNum);CLR_BIT(MDIO_DDRA,Copy_uinit8PinNum);break;
						case MDIO_enumPortB : SET_BIT(MDIO_PORTB,Copy_uinit8PinNum);CLR_BIT(MDIO_DDRB,Copy_uinit8PinNum);break;
						case MDIO_enumPortC : SET_BIT(MDIO_PORTC,Copy_uinit8PinNum);CLR_BIT(MDIO_DDRC,Copy_uinit8PinNum);break;
						case MDIO_enumPortD : SET_BIT(MDIO_PORTD,Copy_uinit8PinNum);CLR_BIT(MDIO_DDRD,Copy_uinit8PinNum);break;
						default :
						{
							State =MDIO_enumWrongConfig;
						}
					}
					State=MDIO_enumOk;
				}break;
				case  MDIO_enumInputExternalPD :
				{
					switch (Copy_uinit8PortNum)
						{
							case MDIO_enumPortA : CLR_BIT(MDIO_DDRA,Copy_uinit8PinNum);break;
							case MDIO_enumPortB : CLR_BIT(MDIO_DDRB,Copy_uinit8PinNum);break;
							case MDIO_enumPortC : CLR_BIT(MDIO_DDRC,Copy_uinit8PinNum);break;
							case MDIO_enumPortD : CLR_BIT(MDIO_DDRD,Copy_uinit8PinNum);break;
							default :
							{
								State =MDIO_enumWrongConfig;
							}
						}
						State=MDIO_enumOk;
				}break;
			}

		}
		else
		{

			State =MDIO_enumWrongConfig;
		}
	}

	return State;
	
}
MDIO_enumError_t MDIO_SetPinValue      (MDIO_enumPorts_t Copy_uinit8PortNum ,MDIO_enumPins_t Copy_uinit8PinNum,MDIO_enumConfig_t Copy_uinit8LogicState)
{
	MDIO_enumError_t State;
	/*check on port and pin num didnot exceed the max*/
	if(((Copy_uinit8PortNum>4) || (Copy_uinit8PortNum<0)) && ((Copy_uinit8PinNum<0) || (Copy_uinit8PinNum>8)))
	{
		State =MDIO_enumWrongConfig;
		
	}
	else
	{
		if(Copy_uinit8LogicState==MDIO_enumOutput_HIGH)
		{
			switch (Copy_uinit8PortNum)
			{
				case MDIO_enumPortA : SET_BIT(MDIO_PORTA,Copy_uinit8PinNum);break;
				case MDIO_enumPortB : SET_BIT(MDIO_PORTB,Copy_uinit8PinNum);break;
				case MDIO_enumPortC : SET_BIT(MDIO_PORTC,Copy_uinit8PinNum);break;
				case MDIO_enumPortD : SET_BIT(MDIO_PORTD,Copy_uinit8PinNum);break;
				default :
				{
					State =MDIO_enumWrongConfig;
				}
			}
			State=MDIO_enumOk;
		}
		else if(Copy_uinit8LogicState==MDIO_enumOutput_LOW)
		{
			switch (Copy_uinit8PortNum)
			{
				case MDIO_enumPortA : CLR_BIT(MDIO_PORTA,Copy_uinit8PinNum);break;
				case MDIO_enumPortB : CLR_BIT(MDIO_PORTB,Copy_uinit8PinNum);break;
				case MDIO_enumPortC : CLR_BIT(MDIO_PORTC,Copy_uinit8PinNum);break;
				case MDIO_enumPortD : CLR_BIT(MDIO_PORTD,Copy_uinit8PinNum);break;
				default :
				{
					State =MDIO_enumWrongConfig;
				}
			}
			State=MDIO_enumOk;
		}
		else if(Copy_uinit8LogicState==MDIO_enumInputInternalPU)
		{
			switch (Copy_uinit8PortNum)
			{
				case MDIO_enumPortA : SET_BIT(MDIO_PORTA,Copy_uinit8PinNum);break;
				case MDIO_enumPortB : SET_BIT(MDIO_PORTB,Copy_uinit8PinNum);break;
				case MDIO_enumPortC : SET_BIT(MDIO_PORTC,Copy_uinit8PinNum);break;
				case MDIO_enumPortD : SET_BIT(MDIO_PORTD,Copy_uinit8PinNum);break;
				default :
				{
					State =MDIO_enumWrongConfig;
				}
			}
			State=MDIO_enumOk;
		}
		else if(Copy_uinit8LogicState==MDIO_enumInputExternalPD)
		{
			switch (Copy_uinit8PortNum)
			{
				case MDIO_enumPortA : CLR_BIT(MDIO_PORTA,Copy_uinit8PinNum);break;
				case MDIO_enumPortB : CLR_BIT(MDIO_PORTB,Copy_uinit8PinNum);break;
				case MDIO_enumPortC : CLR_BIT(MDIO_PORTC,Copy_uinit8PinNum);break;
				case MDIO_enumPortD : CLR_BIT(MDIO_PORTD,Copy_uinit8PinNum);break;
				default :
				{
					State =MDIO_enumWrongConfig;
				}
			}
			State=MDIO_enumOk;
		}
		else
		{
			State =MDIO_enumWrongConfig;
		}
	}

	return State;
}

MDIO_enumError_t MDIO_GetPinValue      (MDIO_enumPorts_t Copy_uinit8PortNum,MDIO_enumPins_t Copy_uinit8PinNum,uinit8_t* Get_Puinit8_tPinValue)
{
	MDIO_enumError_t State;
	if(((Copy_uinit8PortNum>4) || (Copy_uinit8PortNum<0)) && ((Copy_uinit8PinNum<0) || (Copy_uinit8PinNum>8)))
	{
		State =MDIO_enumWrongConfig;
		
	}
	else
	{
		switch (Copy_uinit8PortNum)
		{
			case MDIO_enumPortA : *Get_Puinit8_tPinValue = READ_BIT(MDIO_PINA,Copy_uinit8PinNum) ; break;
			case MDIO_enumPortB : *Get_Puinit8_tPinValue = READ_BIT(MDIO_PINB,Copy_uinit8PinNum) ; break;
			case MDIO_enumPortC : *Get_Puinit8_tPinValue = READ_BIT(MDIO_PINC,Copy_uinit8PinNum) ; break;
			case MDIO_enumPortD : *Get_Puinit8_tPinValue = READ_BIT(MDIO_PIND,Copy_uinit8PinNum) ; break;
			default :
			{
				State =MDIO_enumERRORValue;
			}
		}
		State=MDIO_enumOk;
	}

	return State;
}
//MDIO_enumError_t MDIO_TogglePinValue();
MDIO_enumError_t MDIO_AssignPortValue(MDIO_enumPorts_t Copy_uinit8PortNum,uinit8_t uinit8_tPortValue)
{
	MDIO_enumError_t State=MDIO_enumOk;
		/*check on port num didnot exceed the max*/
		if((Copy_uinit8PortNum>4)|| (Copy_uinit8PortNum<0))
		{
			State = MDIO_enumWrongPort;

		}
		else
		{
			/*
			 * Description: assign a required value to the port at a time
			 * */
				switch (Copy_uinit8PortNum)
				{
					case MDIO_enumPortA : MDIO_PORTA=uinit8_tPortValue;break;
					case MDIO_enumPortB : MDIO_PORTB=uinit8_tPortValue;break;
					case MDIO_enumPortC : MDIO_PORTC=uinit8_tPortValue;break;
					case MDIO_enumPortD : MDIO_PORTD=uinit8_tPortValue;break;
					default :
					{
						State=MDIO_enumERRORValue;
					}
				}

			}



		return State;
}

MDIO_enumError_t MDIO_SetConfig(MDIO_HW_Config_t* Add_Port_Config, uinit8_t LENGTH)
{
	
	MDIO_enumError_t state;
	
	for(uinit8_t i=0;i<LENGTH;i++)
	{
		switch(Add_Port_Config[i].MPORT_HW_Config)
		{
			case MDIO_enumPortA:
			{
				switch(Add_Port_Config[i].MPORT_Config_State)
				{
					case MDIO_enumInputInternalPU:
					{
						CLR_BIT(MDIO_DDRA,Add_Port_Config[i].MPIN_HW_Config);
						SET_BIT(MDIO_PORTA,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					case MDIO_enumInputExternalPD :
					{
						CLR_BIT(MDIO_DDRA,Add_Port_Config[i].MPIN_HW_Config);
						CLR_BIT(MDIO_PORTA,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					case MDIO_enumOutput_LOW :
					{
						SET_BIT(MDIO_DDRA,Add_Port_Config[i].MPIN_HW_Config);
						CLR_BIT(MDIO_PORTA,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					case MDIO_enumOutput_HIGH :
					{
						SET_BIT(MDIO_DDRA,Add_Port_Config[i].MPIN_HW_Config);
						SET_BIT(MDIO_PORTA,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					default:
					{
						/*Report error*/
						state = MDIO_enumWrongConfig;
					}break;
					
					
				}
				
				
			}break;
			
			case MDIO_enumPortB:
			{
				
				switch(Add_Port_Config[i].MPORT_Config_State)
				{
					case MDIO_enumInputInternalPU:
					{
						CLR_BIT(MDIO_DDRB,Add_Port_Config[i].MPIN_HW_Config);
						SET_BIT(MDIO_PORTB,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					case MDIO_enumInputExternalPD :
					{
						CLR_BIT(MDIO_DDRB,Add_Port_Config[i].MPIN_HW_Config);
						CLR_BIT(MDIO_PORTB,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					case MDIO_enumOutput_LOW :
					{
						SET_BIT(MDIO_DDRB,Add_Port_Config[i].MPIN_HW_Config);
						CLR_BIT(MDIO_PORTB,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					case MDIO_enumOutput_HIGH :
					{
						SET_BIT(MDIO_DDRB,Add_Port_Config[i].MPIN_HW_Config);
						SET_BIT(MDIO_PORTB,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					
					default:
					{
						/*Report error*/
						state = MDIO_enumWrongConfig;
					}break;
					
					
				}
			}break;
			
			
			case MDIO_enumPortC:
			{
				
				switch(Add_Port_Config[i].MPORT_Config_State)
				{
					case MDIO_enumInputInternalPU:
					{
						CLR_BIT(MDIO_DDRC,Add_Port_Config[i].MPIN_HW_Config);
						SET_BIT(MDIO_PORTC,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
					}break;
					case MDIO_enumInputExternalPD :
					{
						CLR_BIT(MDIO_DDRC,Add_Port_Config[i].MPIN_HW_Config);
						CLR_BIT(MDIO_PORTC,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					case MDIO_enumOutput_LOW :
					{
						SET_BIT(MDIO_DDRC,Add_Port_Config[i].MPIN_HW_Config);
						CLR_BIT(MDIO_PORTC,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					case MDIO_enumOutput_HIGH :
					{
						SET_BIT(MDIO_DDRC,Add_Port_Config[i].MPIN_HW_Config);
						SET_BIT(MDIO_PORTC,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					
					default:
					{
						/*Report error*/
						state = MDIO_enumWrongConfig;
						
						
					}break;
					
					
				}
			}break;
			
			case MDIO_enumPortD:
			{
				
				switch(Add_Port_Config[i].MPORT_Config_State)
				{
					case MDIO_enumInputInternalPU:
					{
						CLR_BIT(MDIO_DDRD,Add_Port_Config[i].MPIN_HW_Config);
						SET_BIT(MDIO_PORTD,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					case MDIO_enumInputExternalPD :
					{
						CLR_BIT(MDIO_DDRD,Add_Port_Config[i].MPIN_HW_Config);
						CLR_BIT(MDIO_PORTD,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					case MDIO_enumOutput_LOW :
					{
						SET_BIT(MDIO_DDRD,Add_Port_Config[i].MPIN_HW_Config);
						CLR_BIT(MDIO_PORTD,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					case MDIO_enumOutput_HIGH :
					{
						SET_BIT(MDIO_DDRD,Add_Port_Config[i].MPIN_HW_Config);
						SET_BIT(MDIO_PORTD,Add_Port_Config[i].MPIN_HW_Config);
						state = MDIO_enumOk;
						
					}break;
					
					default:
					{
						/*Report error*/
						state = MDIO_enumWrongConfig;
						
					}break;
					
					
				}
			}break;
			
			default:
			{
				/*Report error*/
				state = MDIO_enumWrongConfig;
			}break;
			
			}/*FOR SWITCH */
			
			
			
			
			}/*FOR FOR LOOP */
			
			
			return state;
			
}



MDIO_enumError_t MDIO_AssignValueLowNibble (MDIO_enumPorts_t Copy_uinit8PortNum, uinit8_t uinit8_tLowNibblePortValue )
{
	MDIO_enumError_t state = MDIO_enumErrorOpre;
	
	/*
	  * Clear HIGH because we need only the low nibble value to be assigned to Port so we cleared any unrequited value (Value &= 0X0F)
	 */
	CLR_HIGH_NIB(uinit8_tLowNibblePortValue); 
	
	switch(Copy_uinit8PortNum)
	{
		
		case MDIO_enumPortA : CLR_LOW_NIB (MDIO_PORTA); WRITE_REG_VAL(MDIO_PORTA,uinit8_tLowNibblePortValue); state = MDIO_enumOk; break; 
		case MDIO_enumPortB : CLR_LOW_NIB (MDIO_PORTB); WRITE_REG_VAL(MDIO_PORTB,uinit8_tLowNibblePortValue); state = MDIO_enumOk; break;
		case MDIO_enumPortC : CLR_LOW_NIB (MDIO_PORTC); WRITE_REG_VAL(MDIO_PORTC,uinit8_tLowNibblePortValue); state = MDIO_enumOk; break;
		case MDIO_enumPortD : CLR_LOW_NIB (MDIO_PORTD); WRITE_REG_VAL(MDIO_PORTD,uinit8_tLowNibblePortValue); state = MDIO_enumOk; break;
		
		default :
		{
			
			state = MDIO_enumErrorOpre;
			
		}
	}
	
	return state;
	
	
}
uinit8_t MDIO_GetPinValueReturn      (MDIO_enumPorts_t Copy_uinit8PortNum,MDIO_enumPins_t Copy_uinit8PinNum)
{
	uinit8_t Get_Puinit8_tPinValue;

	if(((Copy_uinit8PortNum>4) || (Copy_uinit8PortNum<0)) && ((Copy_uinit8PinNum<0) || (Copy_uinit8PinNum>8)))
	{
		Get_Puinit8_tPinValue=-1;
	}
	else
	{
		switch (Copy_uinit8PortNum)
		{
			case MDIO_enumPortA : Get_Puinit8_tPinValue = READ_BIT(MDIO_PINA,Copy_uinit8PinNum) ; break;
			case MDIO_enumPortB : Get_Puinit8_tPinValue = READ_BIT(MDIO_PINB,Copy_uinit8PinNum) ; break;
			case MDIO_enumPortC : Get_Puinit8_tPinValue = READ_BIT(MDIO_PINC,Copy_uinit8PinNum) ; break;
			case MDIO_enumPortD : Get_Puinit8_tPinValue = READ_BIT(MDIO_PIND,Copy_uinit8PinNum) ; break;
			default :
			{
				Get_Puinit8_tPinValue=-1;
			}
		}

	}

	return Get_Puinit8_tPinValue;
}
