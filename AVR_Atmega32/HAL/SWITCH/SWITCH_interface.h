/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : SWITCH 		       */
/*	Layer	  : HAL                */
/*	Version   : 1.1                */
/*	Date	  : December 1 , 2023  */
/*	Last Edit : N/A                */
/***********************************/


#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_



HAL_SWITCHenumStatus HAL_SWITCH_INIT(void);
uinit8_t HAL_SWITCH_GETState(SWITCH_struct_config Copy_configstruct_switch);

#endif /* SWITCH_INTERFACE_H_ */