/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : Keypad 		       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : December 30 , 2023 */
/*	Last Edit : N/A                */
/***********************************/
#ifndef HKPD_CONFIG_H_
#define HKPD_CONFIG_H_

#define HKPD_ROW_NUM 4
#define HKPD_COL_NUM 4


/*WILL ONLY DEFINED ONCE WHEN KEYPAD IS ON */
#ifdef KEYPAD_ON
const uinit8_t Keypad_Keys[HKPD_ROW_NUM][HKPD_COL_NUM] =
{
  { '7', '8', '9', '/'},
  { '4', '5', '6', '*'},
  { '1', '2', '3', '-'},
  { 'O', '0', '=', '+'}
};
#endif


#endif /* HKPD_CONFIG_H_ */
