/* Routines for KBI interrupt. */

void KBI_configuration(void) {
 
   KBI2SC = 0x06; /* KBI interrupt request enabled. Detects edges only */
   KBI2PE = 0xa0; /* PTC7, ptc4 enabled as Keyboard interrupts */
   KBI2ES = 0x00; /* Pins detects falling edge */
}
interrupt void KBI_ISR(void) {

   KBI2SC_KBACK = 1; /* Clear the KBI interrupt flag */
  
   /* First entering the analog or pwm percentage mode. */
   firstEnter = 1;
  
   /*  if showAna is 1 before
      now make it 0. */  
   if(showAna){
      showAna = 0;   /* reset */
   } 
   else{
      showAna = 1;   /* set */
   }
}
