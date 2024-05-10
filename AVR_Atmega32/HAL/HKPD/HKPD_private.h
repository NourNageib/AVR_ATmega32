/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : Keypad 		       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : December 30 , 2023 */
/*	Last Edit : N/A                */
/***********************************/
#ifndef HKPD_PRIVATE_H_
#define HKPD_PRIVATE_H_

/*********Struct For individual KPD pin Config*****/

typedef struct
{
	MDIO_enumPorts_t  KPD_PORT;
	MDIO_enumPins_t   KPD_PIN ;
	MDIO_enumConfig_t KPD_STATE ;

}KPD_Control_Pins_cnfg;
/***********************************************/

/************Enum for KPD ERROR types***********/

typedef enum
{
	HAL_KPDenumOk,
	HAL_KPDenumERROR,
	HAL_KPDwrongInput,
	HAL_KPDwrongConfig,
	HAL_KPDConfigOK

}KPD_enuErrorStatus;
/**********************************************/

/*************************************************/
extern KPD_Control_Pins_cnfg KPD_PinsConfig[HKPD_COL_NUM][HKPD_ROW_NUM];
extern const uinit8_t Keypad_Keys[HKPD_ROW_NUM][HKPD_COL_NUM];

/****PORTS FOR KPD Config******/
#define KPD_PORTA MDIO_enumPortA
#define KPD_PORTB MDIO_enumPortB
#define KPD_PORTC MDIO_enumPortC
#define KPD_PORTD MDIO_enumPortD



/*Default Value in case no one key is pressed in keypad */
#define DEFAULT_KEY 'X'

/**/
#define INPUT_KPD_PINS  0
#define OUTPUT_KPD_PINS 1

/**/
#define LOW_VALUE 0

#endif /* HKPD_PRIVATE_H_ */
