/* Nov. 29, 2019
	States for sensor i2c states.

	Adapted from Fabio Pereira.
*/

#include "i2c_sens_states.h"

/* Prototype function(s). */
enum ei2c_states i2c_fsm(char new_state)
{
	static enum ei2c_states i2c_state;
	static char current_command;
	static char i2c_buffer[4];	/* i2c_buffer array */
	static uint i;
	static uint rd_temp = 1;	/* read temp = 1, else read r.h. */
	static uint snd_cmd = 0		// 1 is for sending a command after ACK.

	/* Fill up the i2c_buffer array. */
	for (i=0, i<4, i++)
	{
		if (i = 0)
		{
			*(i2c_buffer + i) = 0x80;	// Sensor address and write bit.
		}
		else if (i = 1)
		{
			*(i2c_buffer + i) = 0x81;	// Sensor address and read bit.
		}

	if (new_state == I2C_SENS_RD)
	{
		current_command = RD;	// current command is read
		i2c_state = I2C_START;	// go to start state
	}
	if (new_state == I2C_SENS_WR)
	{
		current_command = WR;	// current command is write
		i2c_state = I2C_START;	// go to start state
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
		// Send a start - read condition.
		case I2C_STRT_RD:
			IICC = bIICEN | bIICIE | bMST | bTX;// Send the start bit.
			IICD = i2c_buffer[0];					// Send the addr. field.
			i2c_state = I2C_ACK_QRY;				// next state
			break;
		/***************************/
		// Send a start - write condition.
		case I2C_STRT_WR:
			IICC = bIICEN | bIICIE | bMST | bTX;// Send the start bit.
			IICD = i2c_buffer[0];					// Send the addr. field plus the write bit.
			i2c_state = I2C_ACK_QRY;				// next state
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
				if (snd_cmd)	// Send a write or read command.
				{
					if (rd_temp)
					{	// Need a flag to indicate a temp read or r.h. read.
						i2c_state = I2C_SND_RD_TEMP_CMD;	// Next state.
					}
					else
					{
						i2c_state = I2C_SND_RD_RH_CMD;	// Next state.
					}
					}
				else	// Wait for the acquisition to finish.
				{
					i2c_state = I2C_READ_WAIT;				// Wait before read.
				}
			}
			break;
		/***************************/
		// Send the read temp. command packet.
		case I2C_SND_RD_TEMP_CMD;
			IICD = i2c_buffer[1]|RD;	// Send the read temp. command.
			cmd_or_rd = 0					// 0 is for read time after ACK.
			i2c_state = I2C_ACK_QRYI;	// Next state, query for ACK.
			break;
		/***************************/
		// Read one byte of data from sensor.
		case I2C_RD_BYTE:
			IICC_TXAK = 1;				// Send NACK on the next read.
			i2c_buffer[3] = IICD;	// Read one byte of data from sensor.
			i2c_state = I2C_STOP;	// Go to i2c stop state.
			break;
		/***************************/
		// Send a stop and go to slave mode.
		case I2C_STOP:
			IICC_MST = 0;				// Send a stop (go to slave mode)
			i2c_state = I2C_IDLE;	// Next state.
			command_ready = 1;		// Set the command ready flag.
			break;
	}
	return (i2c_state);
}
