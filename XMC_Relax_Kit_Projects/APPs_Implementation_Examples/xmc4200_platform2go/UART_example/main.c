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

uint8_t transmit_byte[1] = {0};
uint8_t receive_buffer[100] = {0};
uint8_t rx_count = 0;


void UART_Rx(){

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

void UART_Tx(){
	transmit_byte[0]++;

	UART_transmit(&UART_0, *transmit_byte, 1);

	if(transmit_byte[0] == 254){
		transmit_byte[0] = 0;
	}
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

  }
}
