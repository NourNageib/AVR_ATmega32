/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : Keypad 		       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : December 30 , 2023 */
/*	Last Edit : N/A                */
/***********************************/

#ifndef HKPD_INTERFACE_H_
#define HKPD_INTERFACE_H_




KPD_enuErrorStatus KPD_Init(void);
KPD_enuErrorStatus KPD_GetKeyValue(uinit8_t* Get_Puinit8_tPintValue);
uinit8_t           KPDGetValueinReturn(void);



#endif /* HKPD_INTERFACE_H_ */
