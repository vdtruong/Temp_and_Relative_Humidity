/* 10/31/09	Structures headers. 
 * 12/20/20 Added for pibs project. */

typedef struct Coord 
{
	uint16 xCoordArry[SETCOEFFSIZE];
	uint16 yCoordArry[SETCOEFFSIZE];
} lcdCoord;
typedef struct plotXHYH
{
	uint8 cmnd;
	uint8 xmsb; /* x most sig. byte */
	uint8 xlsb; /* x least sig. byte */
	uint8 ymsb;
	uint8 ylsb;
} plotXhyh;
typedef struct cmndXHYH
{
	uint8 cmnd; /* use cmnd needed */
	uint8 xmsb; /* x most sig. byte */
	uint8 xlsb; /* x least sig. byte */
	uint8 ymsb;
	uint8 ylsb;
} cmndXhyh;
typedef struct shtc3_OUTPUT {
	static unsigned char data[6] = {
		0x00,									// rh msb 
		0x00,									// rh lsb
		0x00, 								// rh crc
		0x00,									// t msb
		0x00, 								// t lsb
		0x00};								// t crc
	static unsigned char done = 0;	// Indicates state machine is done.
} shtc3_output;
