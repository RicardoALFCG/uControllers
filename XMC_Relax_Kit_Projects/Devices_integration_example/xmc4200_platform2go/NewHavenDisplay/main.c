#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)


void delay (unsigned int count);
uint32_t s_tick = 0;
uint8_t s_trigger = 0;


int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status == DAVE_STATUS_FAILURE)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /* Set background colour */
  //GUI_SetBkColor(GUI_BLUE);
  /* Clear screen */
  GUI_Clear();

  /* Display text */
  GUI_SetFont(&GUI_Font20B_1);
  GUI_SetColor(GUI_WHITE);
  GUI_DispStringHCenterAt("10s TIMER", 80, 30);


  while(1U)
  {
	  if(s_trigger){
		  /* Display text */
		  GUI_SetColor(GUI_WHITE);
		  GUI_DispDecAt(s_tick, 80, 60, 1);
	  }
  }
}

void tick(){
	s_tick = s_tick + 1;

	if(s_tick == 10){
		s_tick = 0;
	}
	s_trigger = 1;

}
/**
 * @brief Delay function:This routine is used for creating delay
 * @param[in] count (value = n sec X 12 X 1000000)
 * @return None
 */
void delay (volatile unsigned int count)
{
	while (count != 0)
	{
		count--;
	}
}
