/* 9/21/10 SPI routines. */

void SPI_configuration (void) {
   /* Select the highest baud rate prescaler divisor 
      and the highest baud rate divisor */
   SPI1BR = 0x75;
   /* SPI Interrupt enable, system enable and slave mode selected */
   SPI1C1 = 0xC2; 
   SPI1C2 = 0x10;/* Different pins for data input and data output */
}

interrupt void Vspi1_ISR(void) {

   /*byte temp, buffer;*/

   /*while (PTDD_PTDD0);*/
   SPI1S;   /* Clear register flag */
   /* Read data register to clear receive flag.
     It's a two steps clearing process. */
   *(canMssg + canIndx) = SPI1D;
  
   if(canIndx == CANLENGTH-1){
    
      canIndx = 0; /* reset the index. */
   } 
   else{
      canIndx++;
   }
}