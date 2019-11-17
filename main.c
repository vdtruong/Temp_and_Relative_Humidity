/////////////////////////////////////////////////////////////////////////////////////////
//
// Sample for Freescale DEMO9S08LC60
//
// This program displays the values of the PWM and the corresponding analog
// on the LCD.
//
// Before to run this example, verify that all jumpers are in their default
// position. See the "Summary of Jumper and Connector Settings" chapter in
// the user's manual.
//
// --------------------------------------------------------------------------------------
//
// CodeWarrior V5.1 for HC(S)08
// Registers Files version 2.87.175
//
// --------------------------------------------------------------------------------------
//
// Copyright (c) 2006 SofTec Microsystems
// http://www.softecmicro.com/
//
/////////////////////////////////////////////////////////////////////////////////////////
/*  6-22-10 This version assumes low polarity pwm. 
    6-24-10 Increase the stack size in the Project.prm
            to accomodate the unsigned long int type. 
            Original size was 0x50, it is now 0xC0.
            If using array, make sure you have enough
            stack size to work with. 
            This version has the analog result but does
            not show it on the LCD yet. 
    6-28-10 Got analog to work on the LCD in version 6.  
            Now try to write subroutines for the main routine. 
            All routines are in separate files.
    9-21-10 Try to implement spi to read CAN message from
            Coldfire MCF52259. 
    9-23-10 Got the spi to work as a slave.  Need to edit the
            isr routine to accept the array of CAN message. */

#include <hidef.h>      /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "lcd.h"
//#include "showCan.h"
#include "misc.c"
#include "init.c"
#include "display.c"
#include "outputs.c"

// Unsecured status flash
const unsigned char flash_security  @0xFFBF = 0xFE;


/////////////////////////////////////////////////////////////////////////////////////////
// MAIN
// --------------------------------------------------------------------------------------
// Entry point
/////////////////////////////////////////////////////////////////////////////////////////
void main(void)
{ 
   init();  
   EnableInterrupts;
  
   // Prints a welcome string
   SlideString("FREESCALE PWM to Analog", 200);
   PrintString("DC = ");
   // Turns on the Freescale logo on the LCD
   LCDWriteSegment(FREESCALE,0);
   /* Put a period after digit 8. */
   LCDWriteSegment(DTx,8);
  
   /* This is for TPM2C1. */
   tpmConfig();  
  
   for(;;) 
   {    
      updateOutputs();
    
   }/* for(;;) */
}