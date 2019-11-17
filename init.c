#include "tpm.c"
#include "KBI.c"
#include "SPI.c"

/* Initializing Routines */
/////////////////////////////////////////////////////////////////////////////////////////
// PeriphInit
// --------------------------------------------------------------------------------------
// Initializes various registers and peripherals
/////////////////////////////////////////////////////////////////////////////////////////
void PeriphInit(void)
{
  // Disables COP and Enable RESET and BKGD pin
  SOPT1 = 0x13;
  
  #if !CLOCK
    // Selects FEE mode for fBUS = 8 MHz
    // Using crystal low-range oscillator. FLL prescaler factor (P) = 64
    ICGC1 = 0x38;
    // Sets MFD multiplication factor (N) to 4 and RFD divisor (R) to 1
    ICGC2 = 0x20;
    // Waita until FLL frequency is locked
    while (!(ICGS1 & 0x08))
      ;
  #else
    // Selecta FEI mode
    // Sets trimming for fBUS = 8 MHz
    ICGTRM = NVICGTRM;
    // Using internal reference clock. FLL prescaler factor (P) = 64
    ICGC1 = 0x28;
    // Sets MFD multiplication factor (N) to 14 and RFD divisor (R) to 2
    ICGC2 = 0x51;
    // Waits until FLL frequency is locked
    while (!(ICGS1 & 0x08))
      ;
  #endif
  
  // Configures PTA[7..5] as output LEDs
  PTAD = 0x00;
  PTADD = 0xE0;
  
  // Configures PTB[7..3] as output LEDs
  PTBD = 0x00;
  PTBDD  = 0xF8;
  
  // Configures ADC peripheral (ADC clock = 1MHz)
  // Bus clock as clock source, 8-bit conversion and divisor = 8
  ADCCFG = 0x60;
  // Selects ADC channel 0 (PTA0) and continuous conversion)
  ADCSC1 = 0x20;
  
  /* TPM1 is used for the delay function. */
  //Counter overflow every 1ms
  TPM1MOD = 8000;
  // Stops timer and selects 1 as prescaler divisor
  TPM1SC = 0x00;    
  // Initializes LCD Driver Peripheral
  LCDInit();
        
}
void GPIO_Init(void) { 
  
 PTCPE = 0x80; /* Enable PTC7 pin Internal Pullups */
}
void init(void){
  
  // Initializes Peripherals
  PeriphInit();
  LCDOnOffState();
  GPIO_Init();
  KBI_configuration();
  SPI_configuration ();
}