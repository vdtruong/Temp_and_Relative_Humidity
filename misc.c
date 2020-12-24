/* Misc. routines */
//////////////////////////////////////////////////////////////
// delay
// -----------------------------------------------------------
// Delay of multiples of 1ms
//////////////////////////////////////////////////////////////
#include "mc9s08qe128.h"

void delay(unsigned char del)
{
  	// Selcts fBUS as timer clock source and starts the timer
  	/* TPM divisor is 1. */
  	TPM1SC = 0x08;
  	while(del){
    	if(TPM1SC&0x80) 
    	{
      	del--;
      	// Clears TOF flag
      	TPM1SC &= ~0x80;
    	}
	}
  	// Stops the timer  
 	TPM1SC = 0x00;
}
