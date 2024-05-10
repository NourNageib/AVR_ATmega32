/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : UART   		       */
/*	Layer	  : Service            */
/*	Version   : 1.0                */
/*	Date	  : December 24 , 2022 */
/*	Last Edit : N/A                */
/***********************************/
#include "STD_types.h"
#include "UART_Interface.h"
#include "UART_Service.h"
#include "HLCD_interface.h"

uint8_t * Tx_str;
uint8_t * Rx_str;

/*No error checking is needed */
typedef unsigned long uint32_t;
void UART_SendStringSynchrounous(uint8_t* StrByte)
{
    uint8_t counter;
    for(counter=0;StrByte[counter];counter++)
    {
        UART_SendData(StrByte[counter]);
    }
    UART_SendData('&');
}
            /*Empty Buffer you want to fill*/
UART_enumError_t UART_ReceiveString(uint8_t* StrByteBuffer)
{
    uint8_t Counter = 0,Data;
    UART_ReceiveData(&Data);
    StrByteBuffer[Counter]= Data;
    for(;StrByteBuffer[Counter] != '&';)
    {
        Counter++;
        UART_ReceiveData(&Data);
        StrByteBuffer[Counter]= Data;
    }
    /*To remove the & sign from the Buffer*/
    StrByteBuffer[Counter] = '\0';

}
  Endian_t Check_Endian(void)
  {
    uint32_t Number = 1;
    uint8_t *NumPointer = &Number;
    if(*NumPointer == 1 )
    {
        return Little_Endian;
    }
    else
    {
        return Big_Endian;
    }

  }
  void Uart_Send_Endian(void)
  {
    uint32_t Number = 1;
    uint8_t *NumPointer = &Number;
    if(*NumPointer == 1 )
    {
        UART_SendString("Little Endian");
    }
    else
    {
        UART_SendString("Big Endian");
    }

  }
  uint32_t Convert_Endian(uint32_t Number)
  {
    return (Number<<24) |  (Number>>24) |  ((Number<<8) & (0x00ff0000)) |  ((Number>>8) & (0x0000ff00));
  }
   uint32_t Convert_Endian2(uint32_t Number)
  {
     uint8_t * PNum =& Number;
     uint8_t Temp = PNum[0];
     PNum[0] = PNum[3];
     PNum[3] = Temp;
     Temp    = PNum[1];
     PNum[1] = PNum[2];
     PNum[2] = Temp;
     return Number;
  }

UART_enumError_t UART_SendStringCheckSum(uint8_t* Str)
{

    uint8_t STRlength;
    int16__t CheckSum;
    for(STRlength =0 ;Str[STRlength];STRlength++);
    UART_SendData(STRlength);
    for(STRlength =0 ;Str[STRlength];STRlength++)
    {
        UART_SendData(STRlength);
        CheckSum+=Str[STRlength];

    }
    UART_SendData(CheckSum);


}
UART_enumError_t UART_ReceiveStringCheckSum(uint8_t* Str)
{
    uint8_t STRlength,counter;
    uint16__t Checksum;
      UART_ReceiveString(Str);
      //Str[counter] = 0; -> not needed ec string received puts nul at the end after receive strbbufer
     STRlength = Str[0];
     for(counter=0;Str[counter];counter++)
     {
        Checksum+= Str[counter];
     }
      /*    CODE TEST  USING LCD */
      LCD_enuWriteNumber(Checksum);
      LCD_enuWriteCharacter('--');
      LCD_enuWriteNumber(counter);
      LCD_enuWriteCharacter('--');
      LCD_enuWriteNumber(STRlength);
     if((counter==STRlength) && (Checksum == (Str[STRlength]| (Str[STRlength-1]<<8))))
     {
        return UART_OK;
     }
     else
     {
        return UART_NOK;
     }

}

void TX_FUNCTION_handler(void)
{
	//what to handle once send data async?
    //each time int happen a byte is sent from string means 
    // the previous byte is sent from UDE REG
	static uint8_t counter=1;
    if(Tx_str[counter] != '\0')
    {
       UART_SendData_NOBLOCK(Tx_str);
      counter++; 
    }
    else
    {
        counter =1;
    }
	

}
void RX_FUNCTION_handler(void)
{
    //you can add a check when to stop 
    //example number of bytes to be sent
    //or a char for checking
    static uint8_t i;
    Rx_str[i]=UART_ReceiveData_NOBLOCK();
    i++;
}
UART_enumError_t UART_SendStringAsynchrounous(uint8_t* Str)
{
    Tx_str =Str;
    
    UART_TX_SetCallback(TX_FUNCTION_handler);
    //first byte is sent to set the flag for int trigger
    UART_SendData_NOBLOCK(Str[0]);
    UART_Complete_Interrupt_EN();

}
/*Function to receive data asynch by giving an empty buffer*/
UART_enumError_t   UART_ReceiveStringAsynchrounous(uint8_t* Str)
{
    //GIVE THE HANDLER THE EMPTY BUFFER ADDRESS TO START FILL IN HANDLER 
    //FOR EACH INT TRIGGER
    Rx_str =Str;
    UART_Receive_Complete_Interrupt_EN();
    UART_TX_SetCallback( RX_FUNCTION_handler);
    //
   
}
/*
  function for user to get the buffer of data
  the buffer is of releated data application request once its full
  thus app read only when buffer is full
  after checksum of received data set flag 1 
  Now user can read the buffer 
  */
UART_enumError_t UART_Buffer_Getter(uint8_t* StrByte)
{

}
 //i can have two uffers in case user didnot read the first buffer