/* Outputs routines for pwm and analog. */

#include "showCan.c"

/* Prototypes */
unsigned long int *percent(void);
void showAnalog(unsigned long int *percnt);
void showPwmPerc(unsigned long int *percnt);
void updateOutputs(void);
/*********************************************/
unsigned long int *percent(void){ /* returns a pointer */
 
   byte i=0;
   unsigned long int percnt = 0, *percntPtr =0;
   word pulsWdth[PWARRAY*2], pulsWdthSum = 0, avgPulsWdth = 0;
   
   /*  Find the pulse width array and pw sum. */
   /*  Notice that for inputCapRise, it is every odd index
       and for inputCapFall, it is every even index. 
       The pulsWdth array has value in every even index.
       Observe the array in the debugging window. */
   for(i=0;i<2*PWARRAY-1;i++){        
      if(*(inputCapRise+i+1) < *(inputCapFall+i)){/* if overflow */
         *(pulsWdth+i) = (HIPWMCNT - *(inputCapFall+i)) + *(inputCapRise+i+1);
      }
      else{
         *(pulsWdth+i) = *(inputCapRise+i+1) - *(inputCapFall+i);
      }
      pulsWdthSum += *(pulsWdth+i);
   }
    
   avgPulsWdth = pulsWdthSum/PWARRAY;
   percnt = ((unsigned long int)avgPulsWdth*1000)/HIPWMCNT;/* 51.7 */
   percntPtr = &percnt; /* percntPtr points to percnt, assign the addr of percnt to percntPtr */
  
   return percntPtr; /* returns a pointer */
  
}
void showAnalog(unsigned long int *percnt){  /* pointer as an input */
  
   unsigned long int analog = 0;
   word anaFirstDig = 0, anaSecDig = 0, anaThirdDig = 0;
  
   analog = *percnt*5;  /* value of percnt */
   anaFirstDig = analog/1000;
   anaSecDig = (analog - anaFirstDig*1000)/100;
   anaThirdDig = ((analog - anaFirstDig*1000)-(anaSecDig*100))/10;
        
   /* first time entering the analog mode */
   if(firstEnter){/* Just entered analog mode. */            
      /* Seems like we need to PrintString
       before any other string function. */
      PrintString("ANA = ");
      LCDWriteSegment(VOLTS,0);
      /* Put a period after digit 7. */
      LCDWriteSegment(DTx,7);
      firstEnter = 0;
   }
  
   DispLowHexVal((byte)anaFirstDig, 7);
   DispLowHexVal((byte)anaSecDig, 8);
   DispLowHexVal((byte)anaThirdDig, 9);
}
void showPwmPerc(unsigned long int *percnt){
  
   word firstDig = 0, secDig = 0, thirdDig = 0;  
                                                    /* 51.7 */
   firstDig = *percnt/100;                          /* 5 */
   secDig = (*percnt - firstDig*100)/10;            /* 1 */
   thirdDig = (*percnt - firstDig*100) - secDig*10; /* 7 */
  
   if(firstEnter){
      PrintString("DC = ");
      /* Put a period after digit 8. */
      LCDWriteSegment(DTx,8);
      firstEnter = 0;
   }
   // Writes the duty cycle on the LCD
   DispLowHexVal((byte)firstDig, 7);
   DispLowHexVal((byte)secDig, 8);
   DispLowHexVal((byte)thirdDig, 9);
}
void updateOutputs(void){
  
   if(updtePulsWidth){

      if(showAna){
         showAnalog(percent()); 
      } 
      else{ /* show pwm duty cycle */
         showPwmPerc(percent());
      }/* if(showAna) */
            
      updtePulsWidth = 0; /* Reset */
      /* Turn back on the TPM2 clock. */
      tpmConfig();
    
      //showCanStrAngl();
   } /* if(updtePulsWidth) */
}