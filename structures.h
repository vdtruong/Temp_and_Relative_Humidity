/* 10/31/09	Structures headers. 
 * 12/20/20 Added for pibs project. */
//#include "mc9s08qe128.h"

//unsigned char done = 0;

struct Shtc3Outputs 
{
	unsigned char data[6];	// Cannot initialize inside of structure.
	unsigned char done;		// Indicates state machine is done.
};
/*
typedef struct shtc3_OUTPUT 
{
	unsigned char data[6] = {
		0x00,									// rh msb 
		0x00,									// rh lsb
		0x00, 								// rh crc
		0x00,									// t msb
		0x00, 								// t lsb
		0x00};								// t crc 
	unsigned char data[6];
	unsigned char done = 0;				// Indicates state machine is done.
} shtc3_output; 
*/
