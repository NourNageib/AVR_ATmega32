/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : UART   		       */
/*	Layer	  : MCAL               */
/*	Version   : 1.1                */
/*	Date	  : May 9  , 2023      */
/*	Last Edit : N/A                */
/***********************************/
#include "AVR_REGs.h"
#include "STD_types.h"
#include "BIT_math.h"

#include "UART_Private.h"
#include "UART_Interface.h"

#include "MDIO_config.h"
#include "MDIO_interface.h"
#include "MDIO_private.h"


void (*UART_TX_CALLBACK)(void) = 0;
void (*UART_RX_CALLBACK)(void) = 0;


UART_enumError_t UART_Init(void)
{
    UART_enumError_t UART_Status = UART_INIT_NOK;
    //Frame cfg
    /*Setting the BaudRate on 5 -> 9600*/
    UBRRL=51;
    /*Enable Transmit and Recceive */
    SET_BIT(UCSRB,TXEN);
    SET_BIT(UCSRB,RXEN);
    UART_Status = UART_INIT_OK;


}


UART_enumError_t UART_SendData(uint8_t DataByte)
{
    UART_enumError_t UART_Status =UART_TX_NOTSENT;
    /*Wait if Previous data is not sent yet*/
    while(!READ_BIT(UCSRA,UDRE));
    /*Then send new data*/
    UDR=DataByte;
    UART_Status =UART_TX_SENT;

}

UART_enumError_t UART_ReceiveData(uint8_t * DataByte)
{
    UART_enumError_t UART_Status =UART_RX_NOTRECEIVED;
    /*Wait if Previous data is not sent yet*/
    while(!READ_BIT(UCSRA,RXC));
    /*Then send new data*/
    *DataByte=UDR;
    UART_Status =UART_RX_RECEIVED;

}

uint8_t UART_ReceiveData_NOBLOCK(void)
{
   return UDR;
}

void UART_SendData_NOBLOCK(uint8_t Byte)
{
    UDR=Byte;
}

void UART_Receive_Complete_Interrupt_EN(void)
{
    SET_BIT(UCSRB,RXCIE);
}

void UART_Receive_Complete_Interrupt_DIS(void)
{
    CLR_BIT(UCSRB,RXCIE);
}

void UART_Complete_Interrupt_EN(void)
{
    SET_BIT(UCSRB,TXCIE);
}

void UART_Complete_Interrupt_DIS(void)
{
    CLR_BIT(UCSRB,TXCIE);
}

void UART_Data_Register_Empty_Interrupt_EN(void)
{
    SET_BIT(UCSRB,UDRIE);
}
void UART_Data_Register_Empty_Interrupt_DIS(void)
{
    CLR_BIT(UCSRB,UDRIE);
}
uint8_t UART_ReceiveDataPeriodically(uint8_t * DataByte)
{
    /*You handle periodicity of the receiving in you application
      Flag Checkked once received it return 1 to ensure the app
      you have received data you can print or use  once received 0 means 
      ignore no data received*/
    if(READ_BIT(UCSRA,RXC));
    {
        *DataByte=UDR;
        return 1;
    }
    
    return 0;

}
void UART_TX_SetCallback( void (*ARG_pvoidfUserFunction)(void))
{
    UART_TX_CALLBACK = ARG_pvoidfUserFunction;
}
void UART_RX_SetCallback( void (*ARG_pvoidfUserFunction)(void))
{
    UART_RX_CALLBACK = ARG_pvoidfUserFunction;
}
uint16__t UART_SW_Frame_Design(uint16__t  DataByte,uint8_t Parity,uint8_t Num_StopBits)
{
    


}
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	(*UART_TX_CALLBACK)();
}
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	(*UART_RX_CALLBACK)();
}