/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : LCD  		       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : December 30 , 2023 */
/*	Last Edit : N/A                */
/***********************************/


#ifndef HLCD_CONFIG_H_
#define HLCD_CONFIG_H_

/*********USER CHOICE******/
/*      _8_BIT_MODE       */
/*      _4_BIT_MODE       */
/**************************/

#define LCD_MODE  _8_BIT_MODE

/*********LCD PORT********/
/****COMMAND AND DATA*****/
/*************************/
/*********OPTIONS ********/
/*************************/
/* LCD_PORTA
 * LCD_PORTB
 * LCD_PORTC
 * LCD_PORTD
 */
#define LCD_PORT_CONFIG LCD_PORTA


/*
#if (LCD_MODE == _4_BIT_MODE)

	#define  _4MODE_D7_PORT MDIO_enumPortA
	#define  _4MODE_D6_PORT MDIO_enumPortA
	#define  _4MODE_D5_PORT MDIO_enumPortA
	#define  _4MODE_D4_PORT MDIO_enumPortA

	#define  _4MODE_D7_PIN MDIO_enumPin0
	#define  _4MODE_D6_PIN MDIO_enumPin1
	#define  _4MODE_D5_PIN MDIO_enumPin2
	#define  _4MODE_D4_PIN MDIO_enumPin3

#endif
*/

#endif /* HLCD_CONFIG_H_ */
