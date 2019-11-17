/* Display routines that use lcd.c routines */
/////////////////////////////////////////////////////////////////////////////////////////
// PrintString
// --------------------------------------------------------------------------------------
// Prints a string on the LCD
/////////////////////////////////////////////////////////////////////////////////////////
void PrintString(unsigned char *str)
{
  unsigned char i;

  LCDClear();
  for(i = 0; str[i] != 0; i++)
    LCDPutChar(str[i], i+1);
    
}

/////////////////////////////////////////////////////////////////////////////////////////
// SlideString
// --------------------------------------------------------------------------------------
// Slides strings on the LCD
/////////////////////////////////////////////////////////////////////////////////////////
void SlideString(unsigned char *str, unsigned char d)
{

  unsigned char i, j, start;

  for(i = 0; str[i] != 0; i++) 
  {
    Delay(d);
    LCDClear();
    if(i < NUM_DIGITS) 
      start = 0;
    else  
      start = i-NUM_DIGITS+1; 
    for(j = start; j <= i; j++)
      LCDPutChar(str[j], NUM_DIGITS-i+j);
  }
  
}

/////////////////////////////////////////////////////////////////////////////////////////
// DispHexVal
// --------------------------------------------------------------------------------------
// Displays potentiometer value on the LCD
/////////////////////////////////////////////////////////////////////////////////////////
void DispHexVal(unsigned char val)
{

  unsigned char ch[2];
    
  // High value
  if((val>>4) < 0x0A)
    ch[1] = '0' + (val>>4);
  else
    ch[1] = 'A' + (val>>4) - 0x0A;
  // Low value
  if((val&0x0F) < 0x0A)
    ch[0] = '0' + (val&0x0F);
  else
    ch[0] = 'A' + (val&0x0F) - 0x0A;
  
  LCDPutChar(ch[1], 8);
  LCDPutChar(ch[0], 9);
  
}
/////////////////////////////////////////////////////////////////////////////////////////
// DispLowHexVal
// --------------------------------------------------------------------------------------
// Displays the low nibble of the 8-bit value entered.
// This routine will display the equivalent single dec. digit
// using its hex counterpart.  If the digits are between 0-9,
// then dec. and hex are the same.  digLoc is where you want
// to put the digit on the display.
/////////////////////////////////////////////////////////////////////////////////////////
void DispLowHexVal(byte val, byte digLoc)
{

  byte ch;
    
  // Low value
  ch = '0' + (val&0x0F);
  
  LCDPutChar(ch, digLoc);
  
}