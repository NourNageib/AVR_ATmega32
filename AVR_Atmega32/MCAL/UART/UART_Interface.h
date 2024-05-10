/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : UART   		       */
/*	Layer	  : MCAL               */
/*	Version   : 1.1                */
/*	Date	  : May 9  , 2023      */
/*	Last Edit : N/A                */
/***********************************/


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


typedef enum
{
	UART_INIT_OK,
	UART_OK,
	UART_NOK,
	UART_INIT_NOK,
	UART_TX_SENT,
	UART_TX_NOTSENT,
	UART_RX_RECEIVED,
	UART_RX_NOTRECEIVED
	
}UART_enumError_t;

UART_enumError_t UART_Init(void);
UART_enumError_t UART_SendData(uint8_t DataByte);
UART_enumError_t UART_ReceiveData(uint8_t * DataByte);
uint8_t UART_ReceiveDataPeriodically(uint8_t * DataByte);
uint16__t UART_SW_Frame_Design(uint16__t  DataByte,uint8_t Parity,uint8_t Num_StopBits);
void UART_TX_SetCallback( void (*ARG_pvoidfUserFunction)(void));
void UART_Data_Register_Empty_Interrupt_DIS(void);
void UART_Data_Register_Empty_Interrupt_EN(void);
void UART_Complete_Interrupt_DIS(void);
void UART_Complete_Interrupt_EN(void);
void UART_Receive_Complete_Interrupt_DIS(void);
void UART_Receive_Complete_Interrupt_EN(void);
void UART_SendData_NOBLOCK(uint8_t Byte);
uint8_t UART_ReceiveData_NOBLOCK(void);
#endif