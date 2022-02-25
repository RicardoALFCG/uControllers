/*
* main.c
 *
 *  Created on: 2022 Feb 21 23:37:11
 *  Author: RGoncalves
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)


CAN_NODE_STATUS_t mo_tranmit_status;
CAN_NODE_STATUS_t status;
XMC_CAN_MO_t *MO_Ptr;
const CAN_NODE_t *HandlePtr1 = &CAN_NODE_0;
MO_Ptr = HandlePtr1->lmobj_ptr[0]->mo_ptr;

uint8_t tick;



/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

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

  tick = 1;

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}


void tick_interrupt(){

	if(tick == 0){
		tick = 1;
	}
	else{
		tick = 0;
	}

	uint8_t can_data_arr[8] = {tick,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
	update_m0_data(can_data_arr);
	transmit_can_message_m0();
}

void receive_can_message_m0(){
	 // Application code
	status = CAN_NODE_MO_GetStatus(HandlePtr1->lmobj_ptr[0]);
	//Check receive pending status
	if ( status & XMC_CAN_MO_STATUS_RX_PENDING)
	{
	// Clear the flag
	XMC_CAN_MO_ResetStatus(MO_Ptr,XMC_CAN_MO_RESET_STATUS_RX_PENDING);
	// Read the received Message object
	receive_status = CAN_NODE_MO_Receive(HandlePtr1->lmobj_ptr[0]);
	if (receive_status == CAN_NODE_STATUS_SUCCESS)
	{
	// message object receive success.
	}
	else
	{
	// message object failed to receive.
	}

}

void transmit_can_message_m0(){
	mo_tranmit_status = CAN_NODE_MO_Transmit(HandlePtr1->lmobj_ptr[0]);
	if (mo_tranmit_status == CAN_NODE_STATUS_SUCCESS)
	{
	  //message object transmission success.
	  // read the TXOK status bit
	  status = CAN_NODE_MO_GetStatus(HandlePtr1->lmobj_ptr[0]);

	  if (status &  XMC_CAN_MO_STATUS_TX_PENDING)
	  {
		//Clear the transmit OK flag
		XMC_CAN_MO_ResetStatus(MO_Ptr,XMC_CAN_MO_RESET_STATUS_TX_PENDING);
	  }
	}
	else
	{
	  // message object failed to transmit.
	}
}

void update_m0_data(uint8_t *can_data_arr){
	 //  update data for the MO to transmit
	status = (CAN_NODE_STATUS_t)CAN_NODE_MO_UpdateData(HandlePtr1->lmobj_ptr[0],array_data);

	if (status == CAN_NODE_STATUS_SUCCESS)
	{
	  // message object data updated.

	  // transmit the data
	  CAN_NODE_MO_Transmit(HandlePtr1->lmobj_ptr[0]);
	}
	else
	{
	  // message object failed to update.
	}
}