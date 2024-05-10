/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : LCD  		       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : December 30 , 2023 */
/*	Last Edit : N/A                */
/***********************************/

#define F_CPU 8000000UL
#include<avr/delay.h>

 #include  "STD_types.h"
 #include  "BIT_math.h"

 #include  "AVR_REGs.h"

 #include  "MDIO_config.h"
 #include  "MDIO_interface.h"
 
#include "HLCD_private.h"
#include "HLCD_interface.h"
#include "HLCD_config.h"

/***********************************************************/
/* Description ! 16x2 Character LCD for chip LMB161A       */
/* Version     ! V01                                       */
/***********************************************************/

LCD_enuErrorStatus HAL_LCD_Init(void)
{
   /*
      * Define local array for LCD to pass to port function to set registers
   */


	MDIO_HW_Config_t loc_LCD_Array[LCD_PINs_NUM];
	/*
	  *declaring errors for each port and switches
	*/
	LCD_enuErrorStatus loc_LCD_state;
	MDIO_enumError_t loc_Port_state;
	/*Total Number of pins to be configured  */



	for(uinit8_t LCD_iteration_counter =0;LCD_iteration_counter<LCD_PINs_NUM;LCD_iteration_counter++)
	{
			/*
				*Copying required data from array of LCD configuration to
				*array of configurations sent to the port function
				*in port driver
			*/
			loc_LCD_Array[LCD_iteration_counter].MPORT_HW_Config         = LCD_PinsConfig[LCD_iteration_counter].LCD_PORT;
			loc_LCD_Array[LCD_iteration_counter].MPIN_HW_Config          = LCD_PinsConfig[LCD_iteration_counter].LCD_PIN;
			loc_LCD_Array[LCD_iteration_counter].MPORT_Config_State      = LCD_PinsConfig[LCD_iteration_counter].LCD_STATE;


	}
	/*
	  * receive the return of port function if the registers
	*/
	loc_Port_state = MDIO_SetConfig( loc_LCD_Array , LCD_PINs_NUM);

	/*
	   *condition to ensure that port configured correctly first then return LCD condition correctly
	*/
	if( loc_Port_state == MDIO_enumOk )
	{
		loc_LCD_state = HAL_LCDConfigOK;
	}
	else if(loc_Port_state == MDIO_enumWrongConfig)
	{
		loc_LCD_state = HAL_LCDwrongConfig;
	}

	return loc_LCD_state;

}

LCD_enuErrorStatus LCD_init (void)
{
	LCD_enuErrorStatus Loc_state = HAL_LCDenumERROR;
	#if LCD_MODE == _8_BIT_MODE

	     /*Wait more than 30ms after Vdd is raised Up to 4.5V*/
		_delay_ms(50);

		/***********************Function Set************************/
		/*Set character font 5X7 dots & Number of Lines 2 -> (0X38)*/
		/*    character font 5X7 dots & Number of Lines 1 -> (0X30)*/
		/***********************************************************/
	    LCD_enuWriteCommand(0X38);
	    /*Inbetween delay is handled inside LCD_enuWriteCommand function*/

	    /*********************DisplayON/OFF Control ****************/
	    /*                                                         */
	    /*                         0b000001DCB                     */
	    /*                 D->  : display ON/OFF                   */
	    /*                 C->1 : cursor display ON                */
	    /*                 C->0 : cursor display OFF               */
 	    /*                 B->1 : Cursor Blink   ON                */
	    /*                 B->0 : Cursor Blink   OFF               */
	    /***********************************************************/
	    LCD_enuWriteCommand(0X0F);

	    /******************Display Clear***************************/
	    LCD_enuWriteCommand(0X01);
        _delay_ms(2);
	    /***********************Entry Mode****************************/
	    /*                                                           */
		/*                  0b0000001I/DSH                           */
		/*  I/D ->1 :Increases "Cursor/ address shift to the right"  */
	    /*  I/D ->0 :Decreases "Cursor/ address shift to the left"   */
	    /*  SH  ->1 :Display shift to left when I/D ->1              */
	    /*************************************************************/
	    LCD_enuWriteCommand(0X06);
	    Loc_state =HAL_LCDenumOk;

	#endif
   #if LCD_MODE == _4_BIT_MODE

	     /*Wait more than 30ms after Vdd is raised Up to 4.5V*/
		_delay_ms(50);

		/***********************Function Set*************************/
		/*         Set the MODE to be 4bit mode -> 0x02   then 0x28 */
		/************************************************************/
		LCD_enuWriteCommand(0X02);
		LCD_enuWriteCommand(0X28);
		/*Inbetween delay is handled inside LCD_enuWriteCommand function*/

		/*********************DisplayON/OFF Control ****************/
		/*                                                         */
		/*                         0b000001DCB                     */
		/*                 D->  : display ON/OFF                   */
		/*                 C->1 : cursor display ON                */
		/*                 C->0 : cursor display OFF               */
		/*                 B->1 : Cursor Blink   ON                */
		/*                 B->0 : Cursor Blink   OFF               */
		/***********************************************************/
		LCD_enuWriteCommand(0X0E);

		/******************Display Clear***************************/
		LCD_enuWriteCommand(0X01);

		/***********************Entry Mode****************************/
		/*                                                           */
		/*                  0b0000001I/DSH                           */
		/*  I/D ->1 :Increases "Cursor/ address shift to the right"  */
		/*  I/D ->0 :Decreases "Cursor/ address shift to the left"   */
		/*  SH  ->1 :Display shift to left when I/D ->1              */
		/*************************************************************/
		LCD_enuWriteCommand(0X06);


	#endif

	return Loc_state;
}

LCD_enuErrorStatus LCD_enuWriteData (uinit8_t Copy_u8Data)
{
           	LCD_enuErrorStatus Loc_state = HAL_LCDwrongInput;

		#if LCD_MODE == _8_BIT_MODE

			   /*Select Instruction data for RS-> H */
				MDIO_SetPinValue(LCD_PinsConfig[RS].LCD_PORT,LCD_PinsConfig[RS].LCD_PIN,MDIO_enumOutput_HIGH);

				/*
				 * In case not connecting R/W -> PIN TO GND
				 *  MDIO_SetPinValue(LCD_PinsConfig[RW].LCD_PORT,LCD_PinsConfig[RW].LCD_PIN,MDIO_enumOutput_LOW);
				 */
				/*Assign Data to port on which LCD is connected */
				MDIO_AssignPortValue(LCD_PORT_CONFIG,Copy_u8Data);
				/*In case of configuring pins separately*/
				/*
				MDIO_SetPinValue(LCD_PinsConfig[D0].LCD_PORT,LCD_PinsConfig[D0].LCD_PIN,READ_BIT(Copy_u8Data,0));
				MDIO_SetPinValue(LCD_PinsConfig[D1].LCD_PORT,LCD_PinsConfig[D1].LCD_PIN,READ_BIT(Copy_u8Data,1));
				MDIO_SetPinValue(LCD_PinsConfig[D2].LCD_PORT,LCD_PinsConfig[D2].LCD_PIN,READ_BIT(Copy_u8Data,2));
				MDIO_SetPinValue(LCD_PinsConfig[D3].LCD_PORT,LCD_PinsConfig[D3].LCD_PIN,READ_BIT(Copy_u8Data,3));
				MDIO_SetPinValue(LCD_PinsConfig[D4].LCD_PORT,LCD_PinsConfig[D4].LCD_PIN,READ_BIT(Copy_u8Data,4));
				MDIO_SetPinValue(LCD_PinsConfig[D5].LCD_PORT,LCD_PinsConfig[D5].LCD_PIN,READ_BIT(Copy_u8Data,5));
				MDIO_SetPinValue(LCD_PinsConfig[D6].LCD_PORT,LCD_PinsConfig[D6].LCD_PIN,READ_BIT(Copy_u8Data,6));
				MDIO_SetPinValue(LCD_PinsConfig[D7].LCD_PORT,LCD_PinsConfig[D7].LCD_PIN,READ_BIT(Copy_u8Data,7));
				*/


				/*Trigger H->L to inform LCD MC to read port */
				MDIO_SetPinValue(LCD_PinsConfig[EN].LCD_PORT,LCD_PinsConfig[EN].LCD_PIN,MDIO_enumOutput_HIGH);
				_delay_ms(1);
				MDIO_SetPinValue(LCD_PinsConfig[EN].LCD_PORT,LCD_PinsConfig[EN].LCD_PIN,MDIO_enumOutput_LOW);
				_delay_ms(1);

				Loc_state = HAL_LCDenumOk;

		 #endif

		#if LCD_MODE == _4_BIT_MODE

				/*Select Instruction data for RS-> H */
				MDIO_SetPinValue(LCD_PinsConfig[RS].LCD_PORT,LCD_PinsConfig[RS].LCD_PIN,MDIO_enumOutput_HIGH);

				/*
				 * In case not connecting R/W -> PIN TO GND
				 *  MDIO_SetPinValue(LCD_PinsConfig[RW].LCD_PORT,LCD_PinsConfig[RW].LCD_PIN,MDIO_enumOutput_LOW);
				 */
				/*Assign Data to port on which LCD is connected */
				/* First high bits */
				MDIO_SetPinValue(LCD_PinsConfig[D7].LCD_PORT,LCD_PinsConfig[D7].LCD_PIN,READ_BIT(Copy_u8Data,7));
				MDIO_SetPinValue(LCD_PinsConfig[D6].LCD_PORT,LCD_PinsConfig[D6].LCD_PIN,READ_BIT(Copy_u8Data,6));
				MDIO_SetPinValue(LCD_PinsConfig[D5].LCD_PORT,LCD_PinsConfig[D5].LCD_PIN,READ_BIT(Copy_u8Data,5));
				MDIO_SetPinValue(LCD_PinsConfig[D4].LCD_PORT,LCD_PinsConfig[D4].LCD_PIN,READ_BIT(Copy_u8Data,4));
				/*Trigger H->L to inform LCD MC to read port */
				MDIO_SetPinValue(LCD_PinsConfig[EN].LCD_PORT,LCD_PinsConfig[EN].LCD_PIN,MDIO_enumOutput_HIGH);
				_delay_ms(1);
				MDIO_SetPinValue(LCD_PinsConfig[EN].LCD_PORT,LCD_PinsConfig[EN].LCD_PIN,MDIO_enumOutput_LOW);
				_delay_ms(1);
				/* First high bits */
				MDIO_SetPinValue(LCD_PinsConfig[D7].LCD_PORT,LCD_PinsConfig[D7].LCD_PIN,READ_BIT(Copy_u8Data,3));
				MDIO_SetPinValue(LCD_PinsConfig[D6].LCD_PORT,LCD_PinsConfig[D6].LCD_PIN,READ_BIT(Copy_u8Data,2));
				MDIO_SetPinValue(LCD_PinsConfig[D5].LCD_PORT,LCD_PinsConfig[D5].LCD_PIN,READ_BIT(Copy_u8Data,1));
				MDIO_SetPinValue(LCD_PinsConfig[D4].LCD_PORT,LCD_PinsConfig[D4].LCD_PIN,READ_BIT(Copy_u8Data,0));
				/*Trigger H->L to inform LCD MC to read port */
				MDIO_SetPinValue(LCD_PinsConfig[EN].LCD_PORT,LCD_PinsConfig[EN].LCD_PIN,MDIO_enumOutput_HIGH);
				_delay_ms(1);
				MDIO_SetPinValue(LCD_PinsConfig[EN].LCD_PORT,LCD_PinsConfig[EN].LCD_PIN,MDIO_enumOutput_LOW);
				_delay_ms(1);

				Loc_state = HAL_LCDenumOk;

        #endif
	 return Loc_state;

}
LCD_enuErrorStatus LCD_enuWriteCommand  (uinit8_t Copy_u8Command)
{

	        LCD_enuErrorStatus Loc_state = HAL_LCDwrongInput;

		#if LCD_MODE == _8_BIT_MODE

			   /*Select Instruction mode for RS-> L */
				MDIO_SetPinValue(LCD_PinsConfig[RS].LCD_PORT,LCD_PinsConfig[RS].LCD_PIN,MDIO_enumOutput_LOW);

				/*
				 * In case not connecting R/W -> PIN TO GND
				 *  MDIO_SetPinValue(LCD_PinsConfig[RW].LCD_PORT,LCD_PinsConfig[RW].LCD_PIN,MDIO_enumOutput_LOW);
				 */
				/*Assign Command to port on which LCD is connected */
				MDIO_AssignPortValue(LCD_PORT_CONFIG,Copy_u8Command);
				/*In case of configuring pins separately*/
				/*
				MDIO_SetPinValue(LCD_PinsConfig[D0].LCD_PORT,LCD_PinsConfig[D0].LCD_PIN,READ_BIT(Copy_u8Command,0));
				MDIO_SetPinValue(LCD_PinsConfig[D1].LCD_PORT,LCD_PinsConfig[D1].LCD_PIN,READ_BIT(Copy_u8Command,1));
				MDIO_SetPinValue(LCD_PinsConfig[D2].LCD_PORT,LCD_PinsConfig[D2].LCD_PIN,READ_BIT(Copy_u8Command,2));
				MDIO_SetPinValue(LCD_PinsConfig[D3].LCD_PORT,LCD_PinsConfig[D3].LCD_PIN,READ_BIT(Copy_u8Command,3));
				MDIO_SetPinValue(LCD_PinsConfig[D4].LCD_PORT,LCD_PinsConfig[D4].LCD_PIN,READ_BIT(Copy_u8Command,4));
				MDIO_SetPinValue(LCD_PinsConfig[D5].LCD_PORT,LCD_PinsConfig[D5].LCD_PIN,READ_BIT(Copy_u8Command,5));
				MDIO_SetPinValue(LCD_PinsConfig[D6].LCD_PORT,LCD_PinsConfig[D6].LCD_PIN,READ_BIT(Copy_u8Command,6));
				MDIO_SetPinValue(LCD_PinsConfig[D7].LCD_PORT,LCD_PinsConfig[D7].LCD_PIN,READ_BIT(Copy_u8Command,7));
				*/
				/*Trigger H->L to inform LCD MC to read port */
				MDIO_SetPinValue(LCD_PinsConfig[EN].LCD_PORT,LCD_PinsConfig[EN].LCD_PIN,MDIO_enumOutput_HIGH);
				_delay_ms(1);
				MDIO_SetPinValue(LCD_PinsConfig[EN].LCD_PORT,LCD_PinsConfig[EN].LCD_PIN,MDIO_enumOutput_LOW);
               _delay_ms(1);



				Loc_state = HAL_LCDenumOk;

			#endif


		#if LCD_MODE ==_4_BIT_MODE
				/*Select Instruction data for RS-> H */
						MDIO_SetPinValue(LCD_PinsConfig[RS].LCD_PORT,LCD_PinsConfig[RS].LCD_PIN,MDIO_enumOutput_LOW);

						/*
						 * In case not connecting R/W -> PIN TO GND
						 *  MDIO_SetPinValue(LCD_PinsConfig[RW].LCD_PORT,LCD_PinsConfig[RW].LCD_PIN,MDIO_enumOutput_LOW);
						 */
						/*Assign Data to port on which LCD is connected */
						/* First high bits */
						MDIO_SetPinValue(LCD_PinsConfig[D7].LCD_PORT,LCD_PinsConfig[D7].LCD_PIN,READ_BIT(Copy_u8Command,7));
						MDIO_SetPinValue(LCD_PinsConfig[D6].LCD_PORT,LCD_PinsConfig[D6].LCD_PIN,READ_BIT(Copy_u8Command,6));
						MDIO_SetPinValue(LCD_PinsConfig[D5].LCD_PORT,LCD_PinsConfig[D5].LCD_PIN,READ_BIT(Copy_u8Command,5));
						MDIO_SetPinValue(LCD_PinsConfig[D4].LCD_PORT,LCD_PinsConfig[D4].LCD_PIN,READ_BIT(Copy_u8Command,4));
						/*Trigger H->L to inform LCD MC to read port */
						MDIO_SetPinValue(LCD_PinsConfig[EN].LCD_PORT,LCD_PinsConfig[EN].LCD_PIN,MDIO_enumOutput_HIGH);
						_delay_ms(1);
						MDIO_SetPinValue(LCD_PinsConfig[EN].LCD_PORT,LCD_PinsConfig[EN].LCD_PIN,MDIO_enumOutput_LOW);
						_delay_ms(1);
						/* low bits */
						MDIO_SetPinValue(LCD_PinsConfig[D7].LCD_PORT,LCD_PinsConfig[D7].LCD_PIN,READ_BIT(Copy_u8Command,3));
						MDIO_SetPinValue(LCD_PinsConfig[D6].LCD_PORT,LCD_PinsConfig[D6].LCD_PIN,READ_BIT(Copy_u8Command,2));
						MDIO_SetPinValue(LCD_PinsConfig[D5].LCD_PORT,LCD_PinsConfig[D5].LCD_PIN,READ_BIT(Copy_u8Command,1));
						MDIO_SetPinValue(LCD_PinsConfig[D4].LCD_PORT,LCD_PinsConfig[D4].LCD_PIN,READ_BIT(Copy_u8Command,0));

						/*Trigger H->L to inform LCD MC to read port */
						MDIO_SetPinValue(LCD_PinsConfig[EN].LCD_PORT,LCD_PinsConfig[EN].LCD_PIN,MDIO_enumOutput_HIGH);
						_delay_ms(1);
						MDIO_SetPinValue(LCD_PinsConfig[EN].LCD_PORT,LCD_PinsConfig[EN].LCD_PIN,MDIO_enumOutput_LOW);
						_delay_ms(1);

						Loc_state = HAL_LCDenumOk;
			#endif
	        return Loc_state;
}

LCD_enuErrorStatus LCD_enuWriteCharacter(uinit8_t Copy_u8Character)
{
	LCD_enuErrorStatus Loc_state = HAL_LCDenumERROR;
	#if LCD_MODE ==_8_BIT_MODE

		LCD_enuWriteData(Copy_u8Character);

	 #endif
	return Loc_state;
}
#define NULL 0

LCD_enuErrorStatus LCD_enumPrintStringwithLocation (uinit8_t Copy_u8X, uinit8_t Copy_u8Y,char* Copy_pString)
{
	LCD_enuErrorStatus Loc_state = HAL_LCDenumERROR;
	if(Copy_pString != NULL)
	{
		Loc_state =LCD_enuGotoDDRAM_XY(Copy_u8X,Copy_u8Y);
		LCD_enuWriteString(Copy_pString);
	}

	return Loc_state;
}

LCD_enuErrorStatus LCD_enuGotoDDRAM_XY (uinit8_t Copy_u8X, uinit8_t Copy_u8Y)
{
	LCD_enuErrorStatus Loc_state = HAL_LCDenumERROR;

	/*x for line of the LCD (1 OR 2)   Y for cell (1:15)  */
	if(( Copy_u8X == 1 || Copy_u8X == 2) && (Copy_u8Y >= 1 && Copy_u8Y <=16 ))
	{
		if(Copy_u8X == 1)
		{
			LCD_enuWriteCommand(0X80|(Copy_u8Y-1));
			Loc_state = HAL_LCDenumOk;
		}
		else if (Copy_u8X == 2)
		{
			LCD_enuWriteCommand(0X80|0X40|(Copy_u8Y-1));
			Loc_state = HAL_LCDenumOk;
		}
		else
		{
			//if LCD MORE THAN 2 LINES
		}

	}
	else
	{
		Loc_state = HAL_LCDenumERROR;
	}
	return Loc_state;
}
LCD_enuErrorStatus LCD_enuWriteNumber (int32__t Copy_u8Number)
{
	LCD_enuErrorStatus Loc_state = HAL_LCDenumOk;
	uinit8_t mystr[16];
	sint8_t  Loc_Loop_iterator = 0 ;
	if(Copy_u8Number==0)
	{
		LCD_enuWriteCharacter('0');
	}
	else
	{
		if(Copy_u8Number<0)
		{
			Copy_u8Number*=(-1);
			LCD_enuWriteCharacter('-');
		}
		while(Copy_u8Number)
			{
				mystr[Loc_Loop_iterator++] = Copy_u8Number%10 + '0';
				Copy_u8Number/=10;
			}
			for(Loc_Loop_iterator-=1;Loc_Loop_iterator>=0;Loc_Loop_iterator--)
			{
				LCD_enuWriteCharacter(mystr[Loc_Loop_iterator]);

			}

	}

	return Loc_state;
}
LCD_enuErrorStatus LCD_enuWriteString   (char* Copy_pchPattern)
{
	LCD_enuErrorStatus Loc_state =HAL_LCDenumERROR;

	for(uinit8_t Loc_string_ieration=0;Copy_pchPattern[Loc_string_ieration];Loc_string_ieration++)
	{
			LCD_enuWriteCharacter(Copy_pchPattern[Loc_string_ieration]);
	}

	return Loc_state;
}
LCD_enuErrorStatus LCD_enumClearCell   (uinit8_t Copy_u8X, uinit8_t Copy_u8Y,uinit8_t Copy_numofcells)
{
	LCD_enuErrorStatus Loc_state = HAL_LCDenumOk;
	LCD_enuGotoDDRAM_XY(Copy_u8X,Copy_u8Y);
	for(uinit8_t Loc_iterator=0;Loc_iterator<=Copy_numofcells;Copy_numofcells++)
	{
		LCD_enuWriteCharacter(' ');
	}

	return Loc_state;

}
LCD_enuErrorStatus LCD_enumWriteHEX   (int32__t Copy_u8DecimalNumber)
{
	LCD_enuErrorStatus Loc_state = HAL_LCDenumOk;

	if(Copy_u8DecimalNumber == 0)
	{
		LCD_enuWriteNumber(0);
	}
	else
	{
	  Copy_u8DecimalNumber/=16;
	}
	return Loc_state;
}
LCD_enuErrorStatus LCD_enuDisplaySpecialPattern   (uinit8_t* Copy_pu8Pattern, uinit8_t Copy_u8CGRAMBlockNumber, uinit8_t Copy_u8X, uinit8_t Copy_u8Y)
{
	LCD_enuErrorStatus Loc_state =HAL_LCDenumERROR;
	return Loc_state;
}

