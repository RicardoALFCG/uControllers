/*
 * main.c
 *
 *  Created on: 2022 Feb 21 23:37:11
 *  Author: RGoncalves
 *
 *
 *  Sample program which sent a byte every second on TX and have add bytes to a buffer on RX line
 */

#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include "main.h"

uint8_t transmit_byte[1] = {0};
uint8_t receive_buffer[100] = {0};
uint8_t rx_count = 0;
uint8_t seconds_flag = 0;
uint16_t milisseconds = 0;

void periodic_messages(){
	milisseconds++;
	UART_Rx();
}

int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
	  if(milisseconds > 1000){
		  UART_TX();
		  milisseconds = 0;
	  }

  }
}

void UART_Rx(){
	static uint8_t receive_buffer[100] = {0};
	static uint8_t rx_count = 0;

	// Check Transmit/receive buffer status register
	while (((UART_0.channel->TRBSR) & 0x08) == 0) {
		// Receive FIFO output register
		receive_buffer[rx_count] = (uint8_t) (UART_0.channel->OUTR);

		if(rx_count == 99){
			rx_count = 0;
		}else{
			rx_count++;
		}
	}
}

void UART_Rx_(){
	static uint8_t receive_buffer_[100] = {0};
	static uint8_t rx_count_ = 0;

	if(UART_Receive(&UART_0, receive_buffer_, 1) == UART_STATUS_SUCCESS)
   {
	 //Retransmit the received 10 bytes
		DIGITAL_IO_SetOutputHigh(&RTS);
		DIGITAL_IO_SetOutputHigh(&CTS);
	 UART_Transmit(&UART_0, receive_buffer_, 1);
   }

}

void UART_TX(){
	if(transmit_byte[0] > 250){
		transmit_byte[0]++;
	}
	else{
		transmit_byte[0] = 'a';
	}
	//DIGITAL_IO_SetOutputHigh(&RTS);
	//DIGITAL_IO_SetOutputHigh(&CTS);
	UART_Transmit(&UART_0, transmit_byte, 1);

}

void Clear_lines(){
	//DIGITAL_IO_SetOutputLow(&RTS);
	//DIGITAL_IO_SetOutputLow(&CTS);
}
