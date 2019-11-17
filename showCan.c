/* 9/23/10 This routine shows the CAN message.  The CAN message 
   is imported using spi. */
   
#include "derivative.h"
#include "showCan.h"

/* This routine shows the Danfoss steering angle. */
void showCanStrAngl(void){
  
   word firstDig = 0, secDig = 0, thirdDig = 0, fourthDig = 0;
   word strAngl = 0; 
  
   strAngl = *(canMssg+1); /* steering angle high byte */ 
   /* can high byte shifts to beginning */
   strAngl <<= 8;
   /* or with can steering angle low byte */
   strAngl |= *(canMssg+0);    
                                                          /* 321.7 deg. */
   firstDig = strAngl/1000;                                /* 3 */
   secDig = (strAngl - firstDig*1000)/100;                 /* 2 */
   thirdDig = ((strAngl - firstDig*1000) - secDig*100)/10; /* 1 */
   fourthDig = ((strAngl - firstDig*1000) - secDig*100) - thirdDig*10; /* 7 */
  
   if(firstEnter){
      PrintString("DC = ");
      /* Put a period after digit 8. */
      LCDWriteSegment(DTx,8);
      firstEnter = 0;   /* reset */
   }
   // Writes the duty cycle on the LCD
   DispLowHexVal((byte)firstDig, 6);
   DispLowHexVal((byte)secDig, 7);
   DispLowHexVal((byte)thirdDig, 8);
   DispLowHexVal((byte)thirdDig, 9);
}