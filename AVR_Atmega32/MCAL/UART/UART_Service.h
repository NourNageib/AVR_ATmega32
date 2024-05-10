/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : UART   		       */
/*	Layer	  : Service            */
/*	Version   : 1.0                */
/*	Date	  : December 24 , 2022 */
/*	Last Edit : N/A                */
/***********************************/
#include "UART_Interface.h"
#include "STD_types.h"


#ifndef UART_SERVICE_H_
#define UART_SERVICE_H_

typedef unsigned long uint32_t;

typedef enum
{
  Little_Endian,
  Big_Endian

}Endian_t;
/*This file for services which handle by software some functionality 
  Which cannot be handled by HW because no HW avaliable support this 
  Functionalities*/


  UART_enumError_t UART_SendString(uint8_t* StrByte);
  UART_enumError_t UART_ReceiveString(uint8_t* StrByteBuffer);

  UART_enumError_t UART_SendStringCheckSum(uint8_t* StrByte);
  UART_enumError_t UART_ReceiveStringCheckSum(uint8_t* StrByte);

  UART_enumError_t UART_SendStringAsynchrounous(uint8_t* Str);
  UART_enumError_t UART_ReceiveStringAsynchrounous(uint8_t* Str);
  UART_enumError_t UART_Buffer_Getter(uint8_t* StrByte);

  
  UART_enumError_t UART_SendNumber(uint32);

  Endian_t Check_Endian(void);
  void Uart_Send_Endian(void);
  uint32_t Convert_Endian(uint32_t Number);
  uint32_t Convert_Endian2(uint32_t Number);

  void TX_FUNCTION_handler(void);
  #endif