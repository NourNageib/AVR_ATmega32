/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : LCD  		       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : December 30 , 2023 */
/*	Last Edit : N/A                */
/***********************************/ 


#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_

/*******************************************************************************************/
/****************************************LCD APIs*******************************************/
/*******************************************************************************************/
/*
    *Function Description : This function configure each pin of the LCD  (PORT , PIN , STATE)
 */
LCD_enuErrorStatus HAL_LCD_Init                   (void);
/*
    *Function Description : This function for LCD Initialization
 */
LCD_enuErrorStatus LCD_init                       (void);
/*
    *Function Description : "LCD_enuWriteData" Take data you want to send to LCD through LCD PORT
    *Function ->Handles BOTH (4-BITMODE and 8-BITMODE)
 */
LCD_enuErrorStatus LCD_enuWriteData               (uinit8_t Copy_u8Data);
/*
    *Function Description : This function Take command and sent as an instruction to the LCD MC
 */
LCD_enuErrorStatus LCD_enuWriteCommand            (uinit8_t Copy_u8Command);
/*
    *Function Description : "LCD_enuGotoDDRAM_XY" set cursor at required location on LCD
    *                         LCD Lines X -> [1,2]......LCD cells Y -> [1:16]
 */
LCD_enuErrorStatus LCD_enuGotoDDRAM_XY            (uinit8_t Copy_u8X, uinit8_t Copy_u8Y);
LCD_enuErrorStatus LCD_enumClearCell              (uinit8_t Copy_u8X, uinit8_t Copy_u8Y,uinit8_t Copy_numofcells);
/*
    *Function Description : "LCD_enumPrintStringwithLocation" Take string you want to print and its required location on LCD Screen
    *                                                         LCD Lines X -> [1,2]......LCD cells Y -> [1:16]
    *
 */
LCD_enuErrorStatus LCD_enumPrintStringwithLocation (uinit8_t Copy_u8X, uinit8_t Copy_u8Y,char* Copy_pString);
/*
    *Function Description : "LCD_enuWriteNumber" take integer number and convert it into string to be displayed on LCD
 */
LCD_enuErrorStatus LCD_enuWriteNumber (int32__t Copy_u8Number);
/*
    *Function Description : "LCD_enuWriteString" function takes string (array of character /ptr to char)
    *						and print the inpuut string on LCD
    *						used as
    *					   1- LCD_enuWriteString(" DISPLAY ON LCD ");
    *					   2- char  mystr[]="DISPLAY ON LCD";  LCD_enuWriteString(mystr);
    *					   3- char* mystr=" DISPLAY ON LCD";  LCD_enuWriteString(mystr);
 */
LCD_enuErrorStatus LCD_enuWriteString             (char* Copy_pchPattern);
/*
    *Function Description : This function take character to display on LCD
 */
LCD_enuErrorStatus LCD_enuWriteCharacter(uinit8_t Copy_u8Character);
/*
    *Function Description : This function configure each pin of the LCD  (PORT , PIN , STATE)
 */
LCD_enuErrorStatus LCD_enuDisplaySpecialPattern   (uinit8_t* Copy_pu8Pattern, uinit8_t Copy_u8CGRAMBlockNumber, uinit8_t Copy_u8X, uinit8_t Copy_u8Y);

/*
    *Function Description : LCD_enumWriteHEX function take decimal value and convert to HEXDECIMAL
 */
LCD_enuErrorStatus LCD_enumWriteHEX   (int32__t Copy_u8DecimalNumber);

#endif /* HLCD_INTERFACE_H_ */
