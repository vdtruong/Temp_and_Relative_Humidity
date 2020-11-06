/* Nov. 5, 2020
	States for tca9548a.

	Adapted from Fabio Pereira.
	HCS08 Unleashed. 2008
*/

#include "i2c_sens_states.h"
#include "define.h"


/* Function prototype(s). */
//enum ei2c_states i2c_fsm(char new_state);
void tca9548a_fsm(unsigned char cntrl_reg);	// Change which i2c channel to use.
/**************************/

/***** Function begins ****/
/* This is for the shtc3 sensor. */
void tca9548a_fsm(unsigned char cntrl_reg)
{
	static unsigned char cntrl_reg_label = 0x00;

	if (cntrl_reg == 0){
		cntrl_reg_label = 0x01;}
	else if (cntrl_reg == 1){
		cntrl_reg_label = 0x02;}
	else if (cntrl_reg == 2){
		cntrl_reg_label = 0x04;}
	else if (cntrl_reg == 3){
		cntrl_reg_label = 0x08;}
	else if (cntrl_reg == 4){
		cntrl_reg_label = 0x10;}
	else if (cntrl_reg == 5){
		cntrl_reg_label = 0x20;}
	else if (cntrl_reg == 6){
		cntrl_reg_label = 0x40;}
	else if (cntrl_reg == 7){
		cntrl_reg_label = 0x80;}

	static unsigned char i2c_buffer[10]= 	{
														0xE0,	// Send addr. write. 	0	
														0x35,	// Wakeup command msb	1
														0x17,	// Wakeup command lsb	2
														0x5C,	// Meas. command msb		3 		0
														0x24,	// Meas. command lsb		4		1
														0xE1,	// Send addr. read		5		2
														0xB0, // Sleep command msb		6		3
														0x98,	// Sleep command lsb		7		4
														0x00,	// read r.h. data.		8		5
														0x00 	// read r.h. crc			9		6
														};		
	static unsigned char data[6] = 			{
			  											0x00,	// rh msb 
			  											0x00,	// rh lsb
														0x00, // rh crc
														0x00,	// t msb
														0x00, // t lsb
														0x00	// t crc
														};		
	/*		
		i2c_states:
		
		0	I2C_IDLE
		1	I2C_SND_STRT_BIT
		2	I2C_SND_DEV_ADDR_WR
		3	Not used.
		4	Not used.
		5	I2C_ACK_QRY
		6	I2C_SND_WKUP_CMD_MSB
		7	I2C_SND_WKUP_CMD_LSB
		8	I2C_SND_STOP_BIT
		9	I2C_WAIT_FOR_WKUP
		10	I2C_SND_MEAS_CMD_MSB
		11	I2C_SND_MEAS_CMD_LSB
		12	I2C_SND_DEV_ADDR_RD
		13	I2C_WAIT_MEAS
		14	Not used.
		15	I2C_RD_DATA
		16	I2C_SND_ACK
		17	I2C_SND_NACK
		18	I2C_SND_SLEEP_CMD_MSB
		19	I2C_SND_SLEEP_CMD_LSB
	*/

	if (strt)
	{
		i2c_state = 1;									// go to start state
	}
	else
	{
		i2c_state = 0;									// stay at idle state.
	}	

	switch(i2c_state)
	{
		/***************************/
		// I2C in idle state.
		case 0:											// i2c_idl
			prev_st = 0;								// Set previous state.
			break;
		/***************************/
		// Send a start condition.
		case 1:											// i2c_start
			IICC = 0xb0;								// Send the start bit.
			if (prev_st == 0 || prev_st == 9 || prev_st == 16)
				{ i2c_state = 2;} 					// send dev. addr with wr bit.
			else if (prev_st == 11)
				{ i2c_state = 12;}					// send dev. addr with rd bit.
			break;
		/***************************/
		// Send a device address and write bit before wake command.
		case 2:											// i2c_start
			while(!IICS_TCF);							// Wait until transmission is done.  Wait for any transfer to complete.
			IICD = *(i2c_buffer + 0);				// Send the addr. field with WR bit set (R/W = WR).
			i2c_state = 5; 							// I2C_ACK_QRY;			// next state
			break;
		/***************************/
		// Send a device address and write bit before meas. command.
		case 3:											// i2c_start
			while(!IICS_TCF);							// Wait until transmission is done.
			IICD = *(i2c_buffer + 0);				// Send the addr. field with WR bit set (R/W = WR).
			//Delay(20);									// Delay 20 ms.
			prev_st = 3;
			i2c_state = 5; 							// I2C_ACK_QRY;			// next state
			break;
		/***************************/
		// Query for ACK response from slave.
		case 5: 											// I2C_ACK_QRY;
			if (IICS_RXAK)								/*	If NAK from slave. */
			{
				i2c_state = 0;							//I2C_IDLE;
			}
			else 											// If ACK.
			{
				if (prev_st == 0)						// If previous command is write before wakeup msb command.
				{
					i2c_state = 6;						// Go to wakeup cmd msb.
				}	
				else if (prev_st == 6)
				{
					i2c_state = 7;						// Go to wakeup cmd lsb
				}
				else if (prev_st == 7 || prev_st == 11 || prev_st == 19)
				{
					i2c_state = 8;						// Send stop bit state.
				}
				else if (prev_st == 9)
				{
					i2c_state = 10;					// send meas. command msb
				}
				else if (prev_st == 10)
				{
					i2c_state = 11;					// send meas. command lsb
				}
				else if (prev_st == 12)
				{
					i2c_state = 13;					// wait for read to start 
				}
				else if (prev_st == 16)
				{
					i2c_state = 18;					// send sleep command msb
				}
				else if (prev_st == 18)
				{
					i2c_state = 19;					// send sleep command lsb
				}
			}
			break;
		/***************************/
		// Send wakeup msb command.
		case 6:											// 
			while(!IICS_TCF);							// Wait until transmission is done.
			IICD = *(i2c_buffer + 1);				// Send the wakeup msb command.
			//Delay(20);									// Delay 20 ms.
			//snd_cmd = 1;								// Indicates after ACK, send a command.
			prev_st = 6;
			i2c_state = 5; 							// I2C_ACK_QRY;			// next state
			break;
		/***************************/
		// Send wakeup lsb command.
		case 7:											// 
			while(!IICS_TCF);							// Wait until transmission is done.
			IICD = *(i2c_buffer + 2);				// Send the wakeup msb command.
			prev_st = 7;
			i2c_state = 5; 							// I2C_ACK_QRY;			// next state
			break;
		/***************************/
		// Send a stop and go to slave mode.
		case 8:											// 
			IICC_MST = 0;								// Send a stop (go to slave mode)
			if (prev_st == 7)
				{	i2c_state = 9;}					// Wait for device to wake up.
			else if (prev_st == 11 || prev_st == 16)
				{
					i2c_state = 1;						// send start bit 
				}
			else
				{
					i2c_state = 0						// idle
					rd_byte_cntr = 0					// reset
				}
			break;
		/**************************/
		// Wait for device to wake up.
		case 9:											// 
			Delay(2);									// Delay 2 ms.
			prev_st = 9;
			i2c_state = 1; 							// Start bit state.
			break;
		/***************************/
		// Send the meas. msb command.
		case 10:											// 
			while(!IICS_TCF);							// Wait until transmission is done.
			IICD = *(i2c_buffer + 3);				// Send the meas. msb command.
			prev_st = 10;
			i2c_state = 5; 							// I2C_ACK_QRY;			// next state
			break;
		/***************************/
		// Send the meas. lsb command.
		case 11:											// 
			while(!IICS_TCF);							// Wait until transmission is done.
			IICD = *(i2c_buffer + 4);				// Send the meas. lsb command.
			prev_st = 11;
			i2c_state = 5; 							// I2C_ACK_QRY;			// next state
			break;
		/***************************/
		// Send device addr. rd command.
		case 12:											// 
			while(!IICS_TCF);							// Wait until transmission is done.
			IICD = *(i2c_buffer + 5);				// Send the device address and W/R bit sets to read.
			prev_st = 12;
			i2c_state = 5; 							// I2C_ACK_QRY;			// next state
			break;
		/***************************/
		// Wait for device to finish meas.
		case 13:											// 
			Delay(13);									// Delay 13 ms.
			prev_st = 13;
			i2c_state = 15; 							// Start to read data.
			break;
		/***************************/
		// Send the read command packet.
		case 4:											// I2C_SND_RD_CMD;
			while(!IICS_TCF);							// Wait until transmission is done.
			IICD = cmd_byte;							// Send the read command.
			Delay(20); 									// Delay for 20 ms.
			snd_cmd = 0;								// Do not send a read command next.
			rpt_strt = 1;								// Send a repeated start next.
			i2c_state = 3;								// I2C_ACK_QRY;// Next state, query for ACK.
			break;
		/***************************/
		// Do a dummy read to change direction and cause a delay.
		case 14:											// I2C_DUMMY_READ:
			while(!IICS_TCF);							// Wait until transmission is done.
			IICC_TX = 0;								// Change to read mode.
			*(i2c_buffer + 3) = IICD;				// Do a dummy read.
			Delay(20);									// Wait 20 ms.
			i2c_state = 6;								// I2C_RD_BYTE;	// Dummy read, does not require an ACK send.
			break;
		/***************************/
		// Read one byte of data from sensor.
		case 15:											// I2C_RD_BYTE:
			while(!IICS_TCF);							// Wait until ready.
			/* When transmission is done, ready to do some thing. */
			*(data + rd_byte_cntr) = IICD;		// Read one byte of data from sensor.
			rd_byte_cntr =+ 1;						// Increment counter.
			Delay(20);									// Wait 20 ms.
			if (rd_byte_cntr >5)
			{	
				i2c_state = 1;							// Send Start bit.			
			}
			else
				i2c_state = 16;						// Send ACK.
			prev_st = 15;
		/***************************/
		// Send ACK after byte read.
		case 16:											// I2C_SND_ACK:
			while(!IICS_TCF);							// Wait until transmission is done.
			IICC_TXAK = 0;								// Send ACK.
			Delay(10);									// Wait 10 ms.
			if (rd_byte_cntr < 6)					// If has not read 6 bytes yet.
			{
				i2c_state = 15;
			}
			else
				i2c_state = 8;							// Send stop bit;
			break;
			prev_st = 16;
		/***************************/
		// Send NAK after CRC byte read.
		case 17:											// I2C_SND_NAK:
			IICC_TXAK = 1;								// Send NAK.
			Delay(10);									// Wait 10 ms.
			i2c_state = 9;								// I2C_STOP;
			break;
		/***************************/
		// Send the sleep command msb.
		case 18:											// 
			while(!IICS_TCF);							// Wait until transmission is done.
			IICD = *(i2c_buffer + 6);				// Send the sleep msb command.
			prev_st = 18;
			i2c_state = 5; 							// I2C_ACK_QRY;			// next state
			break;
		/***************************/
		// Send the sleep lsb command.
		case 19:											// 
			while(!IICS_TCF);							// Wait until transmission is done.
			IICD = *(i2c_buffer + 7);				// Send the meas. lsb command.
			prev_st = 19;
			i2c_state = 5; 							// I2C_ACK_QRY;			// next state
			break;
		/***************************/
	}
	return (data);
}
