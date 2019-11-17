/* TPM routines */

#include "define.h"
#include "globals.h"

/* Prototypes */
void tpmConfig(void);
interrupt void tpm2ch1_ISR(void);
/********************************************/

/*  Use this routine for pwm input capture. */
void tpmConfig(void){
  
   /* This is the period of the square wave. */
   TPM2MOD   = HIPWMCNT;
   TPM2CNT   = 1;     /*  clear the counter */
   TPM2C1SC  = 0x48;  /*  Enable input interrupt request 
                         and input capture on falling edge. */      
   TPM2SC    = 0x0e;  /*  TPM Clock Source is the bus rate clock. 
                         This bus is divided by 32, i.e. 8 MHz/64 = 125 kHz.
                         The tpm clock is 125 kHz.  Also, the time overflow 
                         flag is not enabled and the tpm clock is turned on. */
}
/* The isr is set in the Project.prm file. */
interrupt void tpm2ch1_ISR(void) {
   /*  This isr assumes a low polarity pwm pulse width. 
       The rising and falling edges are captured with the
       input capture function.  The difference will tell
       us the pulse width.  For a high polarity wave,
       reverse the codes. 
       The way this isr works, the rising and falling values
       are on every other index.  This is why we increase 
       the capture array size by twice the original array size.
       See the debug window for the arrays. */ 
   TPM2C1SC_CH1F;     /* Clear TPWM channel flag */
   TPM2C1SC_CH1F = 0; /* Two-step flag acknowledgement */
  
   if(!riseEdge){
      *(inputCapFall+idx) = TPM2C1V; /*  Save input capture on falling edge. */
      TPM2C1SC  = 0x44;       /*  Enable input interrupt request 
                                  and switch to input capture on rising edge. */  
     
      riseEdge = 1;           /*  switch to rising edge */
   } 
   else{
      /*  Save input capture on falling edge. */
      *(inputCapRise+idx) = TPM2C1V; 
      TPM2C1SC  = 0x48;       /*  Enable input interrupt request 
                                  and switch to input capture on falling edge. */
      riseEdge = 0;           /*  switch to falling edge */
   }
  
   if(idx == 2*PWARRAY-1){
      idx = 0; /* reset index */
      updtePulsWidth = 1;
      /*  Turns off the TPM clock
          and waits for the pulse width calc.
          to be completed in main. */
      TPM2SC = 0x00;
   } 
   else{
      idx++;
   }
  
}