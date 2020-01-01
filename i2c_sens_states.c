/* Nov. 29, 2019i
	States for sensor i2c states.

	Adapted from Fabio Pereira.
*/

#include "i2c_sens_states.h"
#include "define.h"

/* Function prototype(s). */
enum ei2c_states i2c_fsm(char new_state)
/**************************/

/***** Function begins ****/
enum ei2c_states i2c_fsm(char new_state)
{
	static enum ei2c_states i2c_state;
	static char current_command;
	static uint i;
	static uint rd_temp = 1;		/* read temp = 1, else read r.h. */
	static uint snd_cmd = 1;		// 1 is for sending a command after ACK.
	static uinit rpt_strt = 0;		// Send a repeated start command.
	static uint snd_ack_cntr = 0;	// Send ack counter.
	static uint rd_byte_cntr =0;	// Byte read counter.
	static char i2c_buffer[4]= {
											0x80,	// Send addr. write. 0	rd_byte_cntr
											0xE3,	// Read temp. cmd.	1
											0xE5,	// Read r.h. cmd.		2
											0x00	// Read dummy data.	3 		0
											0x00,	// read temp. data.	4		1
											0x00,	// read temp. data.	5		2
											0x00, // read temp. crc		6		3
											0x00,	// read r.h. data.	7		4
											0x00,	// read r.h. data.	8		5
											0x00 	// read r.h. crc		9		6
										};		

	if (new_state == I2C_SENS_RD)
	{
		current_command = RD;	// current command is read
		i2c_state = I2C_STRT_RD;// go to start state
	}
	if (new_state == I2C_SENS_WR)
	{
		current_command = WR;	// current command is write
		i2c_state = I2C_STRT_WR;// go to start state
	}

	// If the TCF flag is not set, do not process the state machine
	// and return now with the current state.
	if (!IICS_TCF) return (i2c_state);
	IICS_TCF = 1;	// clear TCF flag
	switch(i2c_state)
	{
		/***************************/
		// I2C in idle state.
		case I2C_IDLE:
			break;
		/***************************/
		// Send a start :condition.
		case I2C_START:
			IICC = bIICEN | bIICIE | bMST | bTX;// Send the start bit.
			IICD = *(i2c_buffer + 0);				// Send the addr. field with WR bit set (R/W = WR).
			delay(20);									// Delay 20 ms.
			while(!IICS_TCF);							// Wait until transmission is done.
			snd_cmd = 1;								// Indicates after ACK, send a command.
			i2c_state = I2C_ACK_QRY;				// next state
			break;
		/***************************/
		// Send a repeated start condition.
		case I2C_REPEATED_START:
			IICC_RSTA = 1;						// Send repeated start.
			IICD = *(i2c_buffer + 0)|RD;	// Send the addr. field plus the read bit (R/W = RD).
			delay(20);							// Delay 20 ms.
			while(!IICS_TCF);					// Wait until transmission is done.
			snd_cmd = 0;						// Indicates the next send is not a command.
			rpt_strt = 0;						// Reset.
			i2c_state = I2C_ACK_QRY;		// next state
			break;
		/***************************/
		// Send the slave address to write to it.
		//case I2C_SND_SLV_ADDR_WR;
		//	IICD = i2c_buffer[1]|WR;	// Send the slave address.  Could use pointer with buffer array.
		//	i2c_state = I2C_ACK_QRY;	// Next state, look for ACK from slave.
		//	break;
		/***************************/
		// Send the slave address to read from it.
		//case I2C_SND_SLV_ADDR_RD;
		//	IICD = i2c_buffer[1]|RD;	// Send the slave address.  Could use pointer with buffer array.
		//	i2c_state = I2C_ACK_QRY;	// Next state, look for ACK from slave.
		//	break;
		/***************************/
		// Query for ACK response from slave.
		case I2C_ACK_QRY;
			if (IICS_RXAK)	/*	If NAK from slave. */
			{
				i2c_state = I2C_IDLE;
			}
			else 				
			{
				if (snd_cmd)					// Send a read command.
				{
					if (rd_temp)				// If read temperature data.
					{	
						cmd_byte = *(i2c_buffer + 1);
					}
					else							// Else, read relative humility data.
					{
						cmd_byte = *(i2c_buffer + 2);	
					}
					i2c_state = I2C_SND_RD_CMD;
				}
				else if (rpt_strt)
				{
					i2c_state = I2C_REPEATED_START;
				}
				else
				{
					i2c_state = I2C_DUMMY_READ;// Change directon to read.
				}
			}
			break;
		/***************************/
		// Send the read command packet.
		case I2C_SND_RD_CMD;
			IICD = cmd_byte;			// Send the read command.
			delay(20); 					// Delay for 20 ms.
			while(!IICS_TCF);			// Wait until transmission is done.
			snd_cmd = 0;				// Do not send a read command next.
			rpt_strt = 1;				// Send a repeated start next.
			i2c_state = I2C_ACK_QRY;// Next state, query for ACK.
			break;
		/***************************/
		// Do a dummy read to change direction and cause a delay.
		case I2C_DUMMY_READ:
			IICC_TX = 0;					// Change to read mode.
			*(i2c_buffer + 3) = IICD;	// Do a dummy read.
			delay(20);						// Wait 20 ms.
			while(!IICS_TCF);				// Wait until transmission is done.
			i2c_state = I2C_RD_BYTE;	// Dummy read, does not require an ACK send.
			break;
		/***************************/
		// Read one byte of data from sensor.
		case I2C_RD_BYTE:
			rd_byte_cntr =+ 1;								// Increment counter.
			*(i2c_buffer + rd_byte_cntr + 3) = IICD;	// Read one byte of data from sensor.
			delay(20);											// Wait 20 ms.
			while(!IICS_TCF);									// Wait until transmission is done.
			if(rd_byte_cntr == 3 | rd_byte_cntr == 6) // Send NAK for these two counts.
			{				
				i2c_state = I2C_SND_NAK;					// Send NACK.
			}
			else 
			{
				i2c_state = I2C_SND_ACK;					// Send ACK.
			}
			break;
		/***************************/
		// Send ACK after byte read.
		case I2C_SND_ACK:
			IICC_TXAK = 0;				// Send ACK.
			delay(10);					// Wait 10 ms.
			i2c_state = I2C_RD_BYTE;
			break;
		/***************************/
		// Send NAK after CRC byte read.
		case I2C_SND_NAK:
			IICC_TXAK = 1;		// Send NAK.
			delay(10);			// Wait 10 ms.
			i2c_state = I2C_STOP;
			break;
		/***************************/
		// Send a stop and go to slave mode.
		case I2C_STOP:
			IICC_MST = 0;				// Send a stop (go to slave mode)
			command_ready = 1;		// Set the command ready flag.
			rd_byte_cntr = 0;			// Reset.
			snd_ack_cntr = 0;			// Reset.
			rd_byte_cntr =0;			// Reset.	
			snd_cmd = 1;				// Reset.
			i2c_state = I2C_IDLE;	// Next state.
			break;
		/**************************/
		// Wait before making measurement.
		case I2C_RD_WAIT:
			delay(20);					// Wait 20 ms before taking measurement.
			i2c_state = I2C_RD_BYTE;// Go to read one byte of data.
			break;
		/***************************/
	}
	return (i2c_state);
}
