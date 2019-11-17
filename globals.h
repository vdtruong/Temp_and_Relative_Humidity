/* Input capture ISR globals. */
byte riseEdge = 0, idx = 0, updtePulsWidth = 0;
byte showAna = 0, firstEnter = 0;
/*  We increase the size of the array by two because
    every other element of the array in this case
    will be zero.  The rise and fall values of the
    tpm capture will be on different index, not the
    same index.  The tpm isr will catch the rise and
    fall in every other index.  The two values cannot
    occupy the same index.  */
word inputCapRise[PWARRAY*2], inputCapFall[PWARRAY*2];
/* SPI globals for CAN message. */
/* CAN message has 8 bytes. */
/* This is for the Danfoss sensor.
  	 0:   angle low byte 				   1: angle high byte
  	 2:   count          				   3: angle change low byte
  	 4:   angle change high byte        5: status
  	 6:	crc-16 low byte				   7: crc-16 high byte 
  	 This is assuming we will get all 8 bytes of data. */
byte canMssg[8], canIndx=0; 