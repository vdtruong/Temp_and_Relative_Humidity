/* Version 1 
   12-15-20		Try to adapt the original project to the pibs project. 
					However, the pibs project will only use the two pairs
					of sci and iic modules.
					This device will capture 8 temperature sensors and 
					display their values on 8 7-seg displays.
*/

#include "initFunctions.c"
#include "i2c_sens_states.c"
#include "holtek_ht16k33.c"
#include "misc.c"
#include "tca9548a.c"
#include "structures.h"


void main(void) { 
  
	static unsigned char cntrl_reg = 0;	/* Set the counter for the tca9548a. */
	static unsigned tca_done = 0;
	static shtc3_output sens_outputs;
	static unsigned char slv_addr[8] = [0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee];	/* slave address with write bit */
	static unsigned char slv_addr_cntr = 0;																/* There are eight displays. */
	
  	initDevice();
  	delay(10);	/* ms */

  	for(;;) {
  		/* Switch tca to each temp. sensor. */
		// tca_done = tca9548a_fsm(cntrl_reg);
		while(!tca9548a_fsm(cntrl_reg));		/* Wait until the switch is done. */
		/* Capture temperature data. */
		while(!sens_outputs.done){				
			sens_outputs = i2c_fsm_shtc3(1);	/* Capture temp. sensor data. */
		}
		/* Display data to 7-seg display. */
		/* Wait until display is done. */
		while(!ht16k33_fsm(*(slv_addr + slv_addr_cntr), sens_outputs.data))
		slv_addr_cntr += 1;						/* Move to next display. */
		if(slv_addr_cntr == 8)
			slv_addr_cntr = 0;					/* Reset to first display. */
   	//sciComm();    /* comm. with labview */
  
  } 	/* loop forever */
  		/* please make sure that you never leave main */
}


