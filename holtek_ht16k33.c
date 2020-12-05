/* Nov. 17, 2020
	States for holtek ht16k33.

	Adapted from Fabio Pereira.
	HCS08 Unleashed. 2008
*/

/* Function prototype(s). */
// Inputs: address of 7-seg display, pointer to temp. data array
void ht16k33_fsm(unsigned char slav_addr, unsigned char *data);	
/**************************/

/***** Function begins ****/
/* This is for the holtek ht16k33 7-seg display. */
void ht16k33_fsm(unsigned char slav_addr, unsigned char *data)
{
	static unsigned char done = 0;					// Indicates if state machine is done.
	static unsigned char addr_indx = 0;				// Address of the com channel.
	static unsigned char digit_data = 0;			// Data for each digit of the 7-seg display.
	static unsigned char i2c_state = 0;				// State machine index.
	static unsigned char i2c_buffer[10]= 	{
														0xEE,	// Send addr. and write. 	0	
														0x35,	// Wakeup command msb		1
														0x17,	// Wakeup command lsb		2
														0x5C,	// Meas. command msb			3 	0
														0x24,	// Meas. command lsb			4	1
														0xE1,	// Send addr. read			5	2
														0xB0, // Sleep command msb			6	3
														0x98,	// Sleep command lsb			7	4
														0x00,	// read r.h. data.			8	5
														0x00 	// read r.h. crc				9	6
														};		
	/* The COM address of each digit.  COM2 is for the colen.  Not used here. */
	static unsigned char digit_addr[4]= 	{
														0x00,	// Digit 0 (com 0) 		
														0x02,	// Digit 1 (com 1)
														0x06,	// Digit 2 (com 3)
														0x08,	// Digit 3 (com 4), F degree label
														};		
	/*		
		i2c_states:
		
		0	I2C_IDLE
		1	I2C_SND_STRT_BIT
		2	I2C_SND_DEV_ADDR_WR
		3	I2C_SND_DIG_ADDR
		4	I2C_SND_STOP_BIT_AND_QUIT				// Send stop bit and quits.
		5	I2C_ACK_QRY
		6	I2C_SND_DIG_DAT
		7	I2C_SND_STOP_BIT
		8	CHK_DIG_FIN									// Check if all digits are written.
	*/

	if (strt)
	{	
		i2c_state = 1;									// go to start state
	}
	else
	{
		i2c_state = 0;									// stay at idle state.
	}		

	while(!done)
	{
		switch(i2c_state)
		{
			/***************************/
			// I2C in idle state.
			case 0:											// i2c_idl
				prev_st = 0;								// Set previous state.
				done = 1;									// exit state machine
				break;
			/***************************/
			// Send a start condition.
			case 1:											// i2c_start
				IICC = 0xb0;								// Send the start bit.
				i2c_state = 2;								// send dev. addr with wr bit.
				break;
			/***************************/
			// Send a device address and write bit.
			case 2:											// 
				while(!IICS_TCF);							// Wait until transmission is done.  Wait for any transfer to complete.
				IICD = slav_addr;							// Send the addr. field with WR bit set (R/W = WR).
				prev_st = 2;
				i2c_state = 5; 							// I2C_ACK_QRY;			// next state
				Delay(5);									// delay 5 ms.
				break;
			/***************************/
			// Query for ACK response from slave.
			case 5: 											// I2C_ACK_QRY;
				if (IICS_RXAK)								/*	If NAK from slave. */
				{	
					i2c_state = 4;							//I2C_snd_stop_bit and quits;
				}
				else 											// If ACK.
				{
					if (prev_st == 2)						// If previous command is send device address.
					{
						i2c_state = 3;						// Go to send digit address.
					}	
					else if (prev_st == 3)				// If previous command is send digit address.
					{
						i2c_state = 6;						// Go to send digit data.
					}	
				}
				break;
			/***************************/
			// Send digit address.
			case 3:											// 
				while(!IICS_TCF);							// Wait until transmission is done.
				IICD = digit_addr[addr_indx];			// Send the digital address (com address).
				prev_st = 3;
				i2c_state = 5; 							// go to ack query
				Delay(5);									// delay 5 ms.			
				break;
			/***************************/
			// Send a stop bit and quits.
			case 4:											// 
				IICC_MST = 0;								// Send a stop (go to slave mode)
				done = 1;									// 
				break;
			/**************************/
			// Send digital data.
			case 6:											// 
				while(!IICS_TCF);							// Wait until transmission is done.
				IICD = cntrl_reg_label;					// Send the digit data
				prev_st = 6;								// 
				i2c_state = 7; 							// stop bit;			// next state
				Delay(5);									// delay 5 ms.			
				break;
			/***************************/
			// Send a stop and go to slave mode.
			case 7:											// 
				IICC_MST = 0;								// Send a stop (go to slave mode)
				i2c_state = 8;								// 
				break;
			/**************************/
			// Decide if done with state machine.
			case 8:											// 
				if (addr_indx == 3){
					done = 1;								// done with digits
				}
				else {
					addr_indx += 1;
					i2c_state = 1;							// go to start bit state
				}
				break;
			/**************************/
		}														// switch
	}															// while
