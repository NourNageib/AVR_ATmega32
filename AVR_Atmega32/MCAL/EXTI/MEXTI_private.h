/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : EXTI   		       */
/*	Layer	  : MCAL               */
/*	Version   : 1.0                */
/*	Date	  : December 25 , 2023 */
/*	Last Edit : N/A				   */
/***********************************/

#ifndef MEXTI_INTERFACE_H_
#define MEXTI_INTERFACE_H_

/**************MEXI REGISTERS***************/

#define GICR	(*((volatile uinit8_t*)0x5B))
#define MCUCSR 	(*((volatile uinit8_t*)0x54))
#define MCUCR 	(*((volatile uinit8_t*)0x55))
#define GIFR	(*((volatile uinit8_t*)0x5A))
#define SREG	(*((volatile uinit8_t*)0x5F))

/*************INT0 MODES **********************/
#define MEXTI_INT0_LL 0X00
#define MEXTI_INT0_LC 0X01
#define MEXTI_INT0_FE 0X02
#define MEXTI_INT0_RE 0X03
/*********************************************/
/*************INT1 MODES **********************/
#define MEXTI_INT1_LL 0X00
#define MEXTI_INT1_LC 0X04
#define MEXTI_INT1_FE 0X08
#define MEXTI_INT1_RE 0X0C
/*********************************************/
/*************INT2 MODES **********************/
#define MEXTI_INT2_FE 0X00
#define MEXTI_INT2_RE 0X40
/*****************************************/
/*         MCUCR CLEAR VALUE          */
#define MEXTI_INT0_MASK 0XFC /*0b11111100 MCUCR */
#define MEXTI_INT1_MASK 0XF3 /*0b11110011 MCUCR */
#define MEXTI_INT2_MASK 0XBF /*0b10111111 MCUCSR */
#define NULL 0

#endif /* MEXTI_INTERFACE_H_ */
