/*
 * HLCD_private.h
 *
 *  Created on: Jan 9, 2024
 *      Author: Nour
 */


#ifndef HLCD_PRIVATE_H_
#define HLCD_PRIVATE_H_


/******Enum for LCD ERROR types*********/

typedef enum
{
	HAL_LCDenumOk,
	HAL_LCDenumERROR,
	HAL_LCDwrongInput,
	HAL_LCDwrongConfig,
	HAL_LCDConfigOK

}LCD_enuErrorStatus;
/**************************************/


#define  _8_BIT_MODE 0
#define  _4_BIT_MODE 1

#define LCD_PINs_NUM 10

/*********Struct For individual LCD pin Config*****/

typedef struct
{
	MDIO_enumPorts_t  LCD_PORT;
	MDIO_enumPins_t   LCD_PIN ;
	MDIO_enumConfig_t LCD_STATE ;

}LCD_Control_Pins_cnfg;
/*************************************************/
extern LCD_Control_Pins_cnfg LCD_PinsConfig[LCD_PINs_NUM];

/****PORTS FOR LCD Config******/
#define LCD_PORTA MDIO_enumPortA
#define LCD_PORTB MDIO_enumPortB
#define LCD_PORTC MDIO_enumPortC
#define LCD_PORTD MDIO_enumPortD

#define EN 0
#define RS 1
#define D0 2
#define D1 3
#define D2 4
#define D3 5
#define D4 6
#define D5 7
#define D6 8
#define D7 9

#endif
