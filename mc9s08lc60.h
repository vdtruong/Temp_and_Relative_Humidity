/* Based on CPU DB MC9S08LC60_80, version 2.87.175 (RegistersPrg V2.03) */
/*
** ###################################################################
**     Filename  : MC9S08LC60.h
**     Processor : MC9S08LC60PU
**     FileFormat: V2.03
**     DataSheet : MC9S08LC60 Rev. 0.08 1/10/2006
**     Compiler  : CodeWarrior compiler
**     Date/Time : 13.02.2006, 16:09
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     (c) Copyright UNIS, spol. s r.o. 1997-2006
**     UNIS, spol. s r.o.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
**
**     File-Format-Revisions:
**      - 14.11.2005, V2.00 :
**               - Deprecated symbols added for backward compatibility (section at the end of this file)
**      - 15.11.2005, V2.01 :
**               - Fixed invalid instruction in macro __RESET_WATCHDOG for HCS12 family.
**      - 17.12.2005, V2.02 :
**               - Arrays (symbols xx_ARR) are defined as pointer to volatile, see issue #2778
**      - 16.01.2006, V2.03 :
**               - Fixed declaration of non volatile registers. Now it does not require (but allows) their initialization, see issue #2920.
**               - "volatile" modifier removed from declaration of non volatile registers (that contain modifier "const")
**
**     CPU Registers Revisions:
**      - none
** ###################################################################
*/

#ifndef _MC9S08LC60_H
#define _MC9S08LC60_H

/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

#ifndef __RESET_WATCHDOG_MACRO
#define __RESET_WATCHDOG_MACRO
/* Watchdog reset macro */
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() {asm sta SRS;}  /* Just write a byte to feed the dog */
#endif
#endif /* __RESET_WATCHDOG_MACRO */

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */

/**************** interrupt vector table ****************/
#define Vlcd                    0x0000FFD2
#define Vrti                    0x0000FFD4
#define Viic                    0x0000FFD6
#define Vacmp                   0x0000FFD8
#define Vadc                    0x0000FFDA
#define Vkeyboard2              0x0000FFDC
#define Vkeyboard1              0x0000FFDE
#define Vscitx                  0x0000FFE0
#define Vscirx                  0x0000FFE2
#define Vscierr                 0x0000FFE4
#define Vspi2                   0x0000FFE6
#define Vspi1                   0x0000FFE8
#define Vtpm2ovf                0x0000FFEA
#define Vtpm2ch1                0x0000FFEC
#define Vtpm2ch0                0x0000FFEE
#define Vtpm1ovf                0x0000FFF0
#define Vtpm1ch1                0x0000FFF2
#define Vtpm1ch0                0x0000FFF4
#define Vicg                    0x0000FFF6
#define Vlvd                    0x0000FFF8
#define Virq                    0x0000FFFA
#define Vswi                    0x0000FFFC
#define Vreset                  0x0000FFFE

/**************** registers I/O map ****************/

/*** PTAD - Port A Data Register; 0x00000000 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1;                                       /* Port A Data Register Bit 0 */
    byte PTAD1       :1;                                       /* Port A Data Register Bit 1 */
    byte PTAD2       :1;                                       /* Port A Data Register Bit 2 */
    byte PTAD3       :1;                                       /* Port A Data Register Bit 3 */
    byte PTAD4       :1;                                       /* Port A Data Register Bit 4 */
    byte PTAD5       :1;                                       /* Port A Data Register Bit 5 */
    byte PTAD6       :1;                                       /* Port A Data Register Bit 6 */
    byte PTAD7       :1;                                       /* Port A Data Register Bit 7 */
  } Bits;
} PTADSTR;
extern volatile PTADSTR _PTAD @0x00000000;
#define PTAD                            _PTAD.Byte
#define PTAD_PTAD0                      _PTAD.Bits.PTAD0
#define PTAD_PTAD1                      _PTAD.Bits.PTAD1
#define PTAD_PTAD2                      _PTAD.Bits.PTAD2
#define PTAD_PTAD3                      _PTAD.Bits.PTAD3
#define PTAD_PTAD4                      _PTAD.Bits.PTAD4
#define PTAD_PTAD5                      _PTAD.Bits.PTAD5
#define PTAD_PTAD6                      _PTAD.Bits.PTAD6
#define PTAD_PTAD7                      _PTAD.Bits.PTAD7

#define PTAD_PTAD0_MASK                 1
#define PTAD_PTAD1_MASK                 2
#define PTAD_PTAD2_MASK                 4
#define PTAD_PTAD3_MASK                 8
#define PTAD_PTAD4_MASK                 16
#define PTAD_PTAD5_MASK                 32
#define PTAD_PTAD6_MASK                 64
#define PTAD_PTAD7_MASK                 128


/*** PTADD - Data Direction Register A; 0x00000001 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADD0      :1;                                       /* Data Direction for Port A Bit 0 */
    byte PTADD1      :1;                                       /* Data Direction for Port A Bit 1 */
    byte PTADD2      :1;                                       /* Data Direction for Port A Bit 2 */
    byte PTADD3      :1;                                       /* Data Direction for Port A Bit 3 */
    byte PTADD4      :1;                                       /* Data Direction for Port A Bit 4 */
    byte PTADD5      :1;                                       /* Data Direction for Port A Bit 5 */
    byte PTADD6      :1;                                       /* Data Direction for Port A Bit 6 */
    byte PTADD7      :1;                                       /* Data Direction for Port A Bit 7 */
  } Bits;
} PTADDSTR;
extern volatile PTADDSTR _PTADD @0x00000001;
#define PTADD                           _PTADD.Byte
#define PTADD_PTADD0                    _PTADD.Bits.PTADD0
#define PTADD_PTADD1                    _PTADD.Bits.PTADD1
#define PTADD_PTADD2                    _PTADD.Bits.PTADD2
#define PTADD_PTADD3                    _PTADD.Bits.PTADD3
#define PTADD_PTADD4                    _PTADD.Bits.PTADD4
#define PTADD_PTADD5                    _PTADD.Bits.PTADD5
#define PTADD_PTADD6                    _PTADD.Bits.PTADD6
#define PTADD_PTADD7                    _PTADD.Bits.PTADD7

#define PTADD_PTADD0_MASK               1
#define PTADD_PTADD1_MASK               2
#define PTADD_PTADD2_MASK               4
#define PTADD_PTADD3_MASK               8
#define PTADD_PTADD4_MASK               16
#define PTADD_PTADD5_MASK               32
#define PTADD_PTADD6_MASK               64
#define PTADD_PTADD7_MASK               128


/*** PTBD - Port B Data Register; 0x00000002 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBD0       :1;                                       /* Port B Data Register Bit 0 */
    byte PTBD1       :1;                                       /* Port B Data Register Bit 1 */
    byte PTBD2       :1;                                       /* Port B Data Register Bit 2 */
    byte PTBD3       :1;                                       /* Port B Data Register Bit 3 */
    byte PTBD4       :1;                                       /* Port B Data Register Bit 4 */
    byte PTBD5       :1;                                       /* Port B Data Register Bit 5 */
    byte PTBD6       :1;                                       /* Port B Data Register Bit 6 */
    byte PTBD7       :1;                                       /* Port B Data Register Bit 7 */
  } Bits;
} PTBDSTR;
extern volatile PTBDSTR _PTBD @0x00000002;
#define PTBD                            _PTBD.Byte
#define PTBD_PTBD0                      _PTBD.Bits.PTBD0
#define PTBD_PTBD1                      _PTBD.Bits.PTBD1
#define PTBD_PTBD2                      _PTBD.Bits.PTBD2
#define PTBD_PTBD3                      _PTBD.Bits.PTBD3
#define PTBD_PTBD4                      _PTBD.Bits.PTBD4
#define PTBD_PTBD5                      _PTBD.Bits.PTBD5
#define PTBD_PTBD6                      _PTBD.Bits.PTBD6
#define PTBD_PTBD7                      _PTBD.Bits.PTBD7

#define PTBD_PTBD0_MASK                 1
#define PTBD_PTBD1_MASK                 2
#define PTBD_PTBD2_MASK                 4
#define PTBD_PTBD3_MASK                 8
#define PTBD_PTBD4_MASK                 16
#define PTBD_PTBD5_MASK                 32
#define PTBD_PTBD6_MASK                 64
#define PTBD_PTBD7_MASK                 128


/*** PTBDD - Data Direction Register B; 0x00000003 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDD0      :1;                                       /* Data Direction for Port B Bit 0 */
    byte PTBDD1      :1;                                       /* Data Direction for Port B Bit 1 */
    byte PTBDD2      :1;                                       /* Data Direction for Port B Bit 2 */
    byte PTBDD3      :1;                                       /* Data Direction for Port B Bit 3 */
    byte PTBDD4      :1;                                       /* Data Direction for Port B Bit 4 */
    byte PTBDD5      :1;                                       /* Data Direction for Port B Bit 5 */
    byte PTBDD6      :1;                                       /* Data Direction for Port B Bit 6 */
    byte PTBDD7      :1;                                       /* Data Direction for Port B Bit 7 */
  } Bits;
} PTBDDSTR;
extern volatile PTBDDSTR _PTBDD @0x00000003;
#define PTBDD                           _PTBDD.Byte
#define PTBDD_PTBDD0                    _PTBDD.Bits.PTBDD0
#define PTBDD_PTBDD1                    _PTBDD.Bits.PTBDD1
#define PTBDD_PTBDD2                    _PTBDD.Bits.PTBDD2
#define PTBDD_PTBDD3                    _PTBDD.Bits.PTBDD3
#define PTBDD_PTBDD4                    _PTBDD.Bits.PTBDD4
#define PTBDD_PTBDD5                    _PTBDD.Bits.PTBDD5
#define PTBDD_PTBDD6                    _PTBDD.Bits.PTBDD6
#define PTBDD_PTBDD7                    _PTBDD.Bits.PTBDD7

#define PTBDD_PTBDD0_MASK               1
#define PTBDD_PTBDD1_MASK               2
#define PTBDD_PTBDD2_MASK               4
#define PTBDD_PTBDD3_MASK               8
#define PTBDD_PTBDD4_MASK               16
#define PTBDD_PTBDD5_MASK               32
#define PTBDD_PTBDD6_MASK               64
#define PTBDD_PTBDD7_MASK               128


/*** PTCD - Port C Data Register; 0x00000004 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCD0       :1;                                       /* Port C Data Register Bit 0 */
    byte PTCD1       :1;                                       /* Port C Data Register Bit 1 */
    byte PTCD2       :1;                                       /* Port C Data Register Bit 2 */
    byte PTCD3       :1;                                       /* Port C Data Register Bit 3 */
    byte PTCD4       :1;                                       /* Port C Data Register Bit 4 */
    byte PTCD5       :1;                                       /* Port C Data Register Bit 5 */
    byte PTCD6       :1;                                       /* Port C Data Register Bit 6 */
    byte PTCD7       :1;                                       /* Port C Data Register Bit 7 */
  } Bits;
} PTCDSTR;
extern volatile PTCDSTR _PTCD @0x00000004;
#define PTCD                            _PTCD.Byte
#define PTCD_PTCD0                      _PTCD.Bits.PTCD0
#define PTCD_PTCD1                      _PTCD.Bits.PTCD1
#define PTCD_PTCD2                      _PTCD.Bits.PTCD2
#define PTCD_PTCD3                      _PTCD.Bits.PTCD3
#define PTCD_PTCD4                      _PTCD.Bits.PTCD4
#define PTCD_PTCD5                      _PTCD.Bits.PTCD5
#define PTCD_PTCD6                      _PTCD.Bits.PTCD6
#define PTCD_PTCD7                      _PTCD.Bits.PTCD7

#define PTCD_PTCD0_MASK                 1
#define PTCD_PTCD1_MASK                 2
#define PTCD_PTCD2_MASK                 4
#define PTCD_PTCD3_MASK                 8
#define PTCD_PTCD4_MASK                 16
#define PTCD_PTCD5_MASK                 32
#define PTCD_PTCD6_MASK                 64
#define PTCD_PTCD7_MASK                 128


/*** PTCDD - Data Direction Register C; 0x00000005 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDD0      :1;                                       /* Data Direction for Port C Bit 0 */
    byte PTCDD1      :1;                                       /* Data Direction for Port C Bit 1 */
    byte PTCDD2      :1;                                       /* Data Direction for Port C Bit 2 */
    byte PTCDD3      :1;                                       /* Data Direction for Port C Bit 3 */
    byte PTCDD4      :1;                                       /* Data Direction for Port C Bit 4 */
    byte PTCDD5      :1;                                       /* Data Direction for Port C Bit 5 */
    byte PTCDD6      :1;                                       /* Data Direction for Port C Bit 6 */
    byte PTCDD7      :1;                                       /* Data Direction for Port C Bit 7 */
  } Bits;
} PTCDDSTR;
extern volatile PTCDDSTR _PTCDD @0x00000005;
#define PTCDD                           _PTCDD.Byte
#define PTCDD_PTCDD0                    _PTCDD.Bits.PTCDD0
#define PTCDD_PTCDD1                    _PTCDD.Bits.PTCDD1
#define PTCDD_PTCDD2                    _PTCDD.Bits.PTCDD2
#define PTCDD_PTCDD3                    _PTCDD.Bits.PTCDD3
#define PTCDD_PTCDD4                    _PTCDD.Bits.PTCDD4
#define PTCDD_PTCDD5                    _PTCDD.Bits.PTCDD5
#define PTCDD_PTCDD6                    _PTCDD.Bits.PTCDD6
#define PTCDD_PTCDD7                    _PTCDD.Bits.PTCDD7

#define PTCDD_PTCDD0_MASK               1
#define PTCDD_PTCDD1_MASK               2
#define PTCDD_PTCDD2_MASK               4
#define PTCDD_PTCDD3_MASK               8
#define PTCDD_PTCDD4_MASK               16
#define PTCDD_PTCDD5_MASK               32
#define PTCDD_PTCDD6_MASK               64
#define PTCDD_PTCDD7_MASK               128


/*** IRQSC - Interrupt Request Status and Control Register; 0x00000006 ***/
typedef union {
  byte Byte;
  struct {
    byte IRQMOD      :1;                                       /* IRQ Detection Mode */
    byte IRQIE       :1;                                       /* IRQ Interrupt Enable */
    byte IRQACK      :1;                                       /* IRQ Acknowledge */
    byte IRQF        :1;                                       /* IRQ Flag */
    byte IRQPE       :1;                                       /* IRQ Pin Enable */
    byte IRQEDG      :1;                                       /* Interrupt Request (IRQ) Edge Select */
    byte IRQPDD      :1;                                       /* Interrupt Request (IRQ) Pull Device Disable */
    byte             :1; 
  } Bits;
} IRQSCSTR;
extern volatile IRQSCSTR _IRQSC @0x00000006;
#define IRQSC                           _IRQSC.Byte
#define IRQSC_IRQMOD                    _IRQSC.Bits.IRQMOD
#define IRQSC_IRQIE                     _IRQSC.Bits.IRQIE
#define IRQSC_IRQACK                    _IRQSC.Bits.IRQACK
#define IRQSC_IRQF                      _IRQSC.Bits.IRQF
#define IRQSC_IRQPE                     _IRQSC.Bits.IRQPE
#define IRQSC_IRQEDG                    _IRQSC.Bits.IRQEDG
#define IRQSC_IRQPDD                    _IRQSC.Bits.IRQPDD

#define IRQSC_IRQMOD_MASK               1
#define IRQSC_IRQIE_MASK                2
#define IRQSC_IRQACK_MASK               4
#define IRQSC_IRQF_MASK                 8
#define IRQSC_IRQPE_MASK                16
#define IRQSC_IRQEDG_MASK               32
#define IRQSC_IRQPDD_MASK               64


/*** KBI1SC - KBI1 Status and Control; 0x00000008 ***/
typedef union {
  byte Byte;
  struct {
    byte KBIMOD      :1;                                       /* Keyboard Detection Mode */
    byte KBIE        :1;                                       /* Keyboard Interrupt Enable */
    byte KBACK       :1;                                       /* Keyboard Interrupt Acknowledge */
    byte KBF         :1;                                       /* Keyboard Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBI1SCSTR;
extern volatile KBI1SCSTR _KBI1SC @0x00000008;
#define KBI1SC                          _KBI1SC.Byte
#define KBI1SC_KBIMOD                   _KBI1SC.Bits.KBIMOD
#define KBI1SC_KBIE                     _KBI1SC.Bits.KBIE
#define KBI1SC_KBACK                    _KBI1SC.Bits.KBACK
#define KBI1SC_KBF                      _KBI1SC.Bits.KBF

#define KBI1SC_KBIMOD_MASK              1
#define KBI1SC_KBIE_MASK                2
#define KBI1SC_KBACK_MASK               4
#define KBI1SC_KBF_MASK                 8


/*** KBI1PE - KBI1 Pin Enable Register; 0x00000009 ***/
typedef union {
  byte Byte;
  struct {
    byte KBIPE0      :1;                                       /* Keyboard Pin Enable for Port A Bit 0 */
    byte KBIPE1      :1;                                       /* Keyboard Pin Enable for Port A Bit 1 */
    byte KBIPE2      :1;                                       /* Keyboard Pin Enable for Port A Bit 2 */
    byte KBIPE3      :1;                                       /* Keyboard Pin Enable for Port A Bit 3 */
    byte KBIPE4      :1;                                       /* Keyboard Pin Enable for Port A Bit 4 */
    byte KBIPE5      :1;                                       /* Keyboard Pin Enable for Port A Bit 5 */
    byte KBIPE6      :1;                                       /* Keyboard Pin Enable for Port A Bit 6 */
    byte KBIPE7      :1;                                       /* Keyboard Pin Enable for Port A Bit 7 */
  } Bits;
} KBI1PESTR;
extern volatile KBI1PESTR _KBI1PE @0x00000009;
#define KBI1PE                          _KBI1PE.Byte
#define KBI1PE_KBIPE0                   _KBI1PE.Bits.KBIPE0
#define KBI1PE_KBIPE1                   _KBI1PE.Bits.KBIPE1
#define KBI1PE_KBIPE2                   _KBI1PE.Bits.KBIPE2
#define KBI1PE_KBIPE3                   _KBI1PE.Bits.KBIPE3
#define KBI1PE_KBIPE4                   _KBI1PE.Bits.KBIPE4
#define KBI1PE_KBIPE5                   _KBI1PE.Bits.KBIPE5
#define KBI1PE_KBIPE6                   _KBI1PE.Bits.KBIPE6
#define KBI1PE_KBIPE7                   _KBI1PE.Bits.KBIPE7

#define KBI1PE_KBIPE0_MASK              1
#define KBI1PE_KBIPE1_MASK              2
#define KBI1PE_KBIPE2_MASK              4
#define KBI1PE_KBIPE3_MASK              8
#define KBI1PE_KBIPE4_MASK              16
#define KBI1PE_KBIPE5_MASK              32
#define KBI1PE_KBIPE6_MASK              64
#define KBI1PE_KBIPE7_MASK              128


/*** KBI1ES - KBI1 Edge Select Register; 0x0000000A ***/
typedef union {
  byte Byte;
  struct {
    byte KBEDG0      :1;                                       /* Keyboard Edge Select Bit 0 */
    byte KBEDG1      :1;                                       /* Keyboard Edge Select Bit 1 */
    byte KBEDG2      :1;                                       /* Keyboard Edge Select Bit 2 */
    byte KBEDG3      :1;                                       /* Keyboard Edge Select Bit 3 */
    byte KBEDG4      :1;                                       /* Keyboard Edge Select Bit 4 */
    byte KBEDG5      :1;                                       /* Keyboard Edge Select Bit 5 */
    byte KBEDG6      :1;                                       /* Keyboard Edge Select Bit 6 */
    byte KBEDG7      :1;                                       /* Keyboard Edge Select Bit 7 */
  } Bits;
} KBI1ESSTR;
extern volatile KBI1ESSTR _KBI1ES @0x0000000A;
#define KBI1ES                          _KBI1ES.Byte
#define KBI1ES_KBEDG0                   _KBI1ES.Bits.KBEDG0
#define KBI1ES_KBEDG1                   _KBI1ES.Bits.KBEDG1
#define KBI1ES_KBEDG2                   _KBI1ES.Bits.KBEDG2
#define KBI1ES_KBEDG3                   _KBI1ES.Bits.KBEDG3
#define KBI1ES_KBEDG4                   _KBI1ES.Bits.KBEDG4
#define KBI1ES_KBEDG5                   _KBI1ES.Bits.KBEDG5
#define KBI1ES_KBEDG6                   _KBI1ES.Bits.KBEDG6
#define KBI1ES_KBEDG7                   _KBI1ES.Bits.KBEDG7

#define KBI1ES_KBEDG0_MASK              1
#define KBI1ES_KBEDG1_MASK              2
#define KBI1ES_KBEDG2_MASK              4
#define KBI1ES_KBEDG3_MASK              8
#define KBI1ES_KBEDG4_MASK              16
#define KBI1ES_KBEDG5_MASK              32
#define KBI1ES_KBEDG6_MASK              64
#define KBI1ES_KBEDG7_MASK              128


/*** KBI2SC - KBI2 Status and Control; 0x0000000C ***/
typedef union {
  byte Byte;
  struct {
    byte KBIMOD      :1;                                       /* Keyboard Detection Mode */
    byte KBIE        :1;                                       /* Keyboard Interrupt Enable */
    byte KBACK       :1;                                       /* Keyboard Interrupt Acknowledge */
    byte KBF         :1;                                       /* Keyboard Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBI2SCSTR;
extern volatile KBI2SCSTR _KBI2SC @0x0000000C;
#define KBI2SC                          _KBI2SC.Byte
#define KBI2SC_KBIMOD                   _KBI2SC.Bits.KBIMOD
#define KBI2SC_KBIE                     _KBI2SC.Bits.KBIE
#define KBI2SC_KBACK                    _KBI2SC.Bits.KBACK
#define KBI2SC_KBF                      _KBI2SC.Bits.KBF

#define KBI2SC_KBIMOD_MASK              1
#define KBI2SC_KBIE_MASK                2
#define KBI2SC_KBACK_MASK               4
#define KBI2SC_KBF_MASK                 8


/*** KBI2PE - KBI2 Pin Enable Register; 0x0000000D ***/
typedef union {
  byte Byte;
  struct {
    byte KBIPE0      :1;                                       /* Keyboard Pin Enable for Port A Bit 0 */
    byte KBIPE1      :1;                                       /* Keyboard Pin Enable for Port A Bit 1 */
    byte KBIPE2      :1;                                       /* Keyboard Pin Enable for Port A Bit 2 */
    byte KBIPE3      :1;                                       /* Keyboard Pin Enable for Port A Bit 3 */
    byte KBIPE4      :1;                                       /* Keyboard Pin Enable for Port A Bit 4 */
    byte KBIPE5      :1;                                       /* Keyboard Pin Enable for Port A Bit 5 */
    byte KBIPE6      :1;                                       /* Keyboard Pin Enable for Port A Bit 6 */
    byte KBIPE7      :1;                                       /* Keyboard Pin Enable for Port A Bit 7 */
  } Bits;
} KBI2PESTR;
extern volatile KBI2PESTR _KBI2PE @0x0000000D;
#define KBI2PE                          _KBI2PE.Byte
#define KBI2PE_KBIPE0                   _KBI2PE.Bits.KBIPE0
#define KBI2PE_KBIPE1                   _KBI2PE.Bits.KBIPE1
#define KBI2PE_KBIPE2                   _KBI2PE.Bits.KBIPE2
#define KBI2PE_KBIPE3                   _KBI2PE.Bits.KBIPE3
#define KBI2PE_KBIPE4                   _KBI2PE.Bits.KBIPE4
#define KBI2PE_KBIPE5                   _KBI2PE.Bits.KBIPE5
#define KBI2PE_KBIPE6                   _KBI2PE.Bits.KBIPE6
#define KBI2PE_KBIPE7                   _KBI2PE.Bits.KBIPE7

#define KBI2PE_KBIPE0_MASK              1
#define KBI2PE_KBIPE1_MASK              2
#define KBI2PE_KBIPE2_MASK              4
#define KBI2PE_KBIPE3_MASK              8
#define KBI2PE_KBIPE4_MASK              16
#define KBI2PE_KBIPE5_MASK              32
#define KBI2PE_KBIPE6_MASK              64
#define KBI2PE_KBIPE7_MASK              128


/*** KBI2ES - KBI2 Edge Select Register; 0x0000000E ***/
typedef union {
  byte Byte;
  struct {
    byte KBEDG0      :1;                                       /* Keyboard Edge Select Bit 0 */
    byte KBEDG1      :1;                                       /* Keyboard Edge Select Bit 1 */
    byte KBEDG2      :1;                                       /* Keyboard Edge Select Bit 2 */
    byte KBEDG3      :1;                                       /* Keyboard Edge Select Bit 3 */
    byte KBEDG4      :1;                                       /* Keyboard Edge Select Bit 4 */
    byte KBEDG5      :1;                                       /* Keyboard Edge Select Bit 5 */
    byte KBEDG6      :1;                                       /* Keyboard Edge Select Bit 6 */
    byte KBEDG7      :1;                                       /* Keyboard Edge Select Bit 7 */
  } Bits;
} KBI2ESSTR;
extern volatile KBI2ESSTR _KBI2ES @0x0000000E;
#define KBI2ES                          _KBI2ES.Byte
#define KBI2ES_KBEDG0                   _KBI2ES.Bits.KBEDG0
#define KBI2ES_KBEDG1                   _KBI2ES.Bits.KBEDG1
#define KBI2ES_KBEDG2                   _KBI2ES.Bits.KBEDG2
#define KBI2ES_KBEDG3                   _KBI2ES.Bits.KBEDG3
#define KBI2ES_KBEDG4                   _KBI2ES.Bits.KBEDG4
#define KBI2ES_KBEDG5                   _KBI2ES.Bits.KBEDG5
#define KBI2ES_KBEDG6                   _KBI2ES.Bits.KBEDG6
#define KBI2ES_KBEDG7                   _KBI2ES.Bits.KBEDG7

#define KBI2ES_KBEDG0_MASK              1
#define KBI2ES_KBEDG1_MASK              2
#define KBI2ES_KBEDG2_MASK              4
#define KBI2ES_KBEDG3_MASK              8
#define KBI2ES_KBEDG4_MASK              16
#define KBI2ES_KBEDG5_MASK              32
#define KBI2ES_KBEDG6_MASK              64
#define KBI2ES_KBEDG7_MASK              128


/*** ACMPSC - Analog Comparator Status and Control Register; 0x0000000F ***/
typedef union {
  byte Byte;
  struct {
    byte ACMOD0      :1;                                       /* Analog Comparator Mode Bit 0 */
    byte ACMOD1      :1;                                       /* Analog Comparator Mode Bit 1 */
    byte             :1; 
    byte ACO         :1;                                       /* Analog Comparator Output */
    byte ACIE        :1;                                       /* Analog Comparator Interrupt Enable */
    byte ACF         :1;                                       /* Analog Comparator Flag */
    byte ACBGS       :1;                                       /* Analog Comparator Bandgap Select */
    byte ACME        :1;                                       /* Analog Comparator Module Enable */
  } Bits;
  struct {
    byte grpACMOD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ACMPSCSTR;
extern volatile ACMPSCSTR _ACMPSC @0x0000000F;
#define ACMPSC                          _ACMPSC.Byte
#define ACMPSC_ACMOD0                   _ACMPSC.Bits.ACMOD0
#define ACMPSC_ACMOD1                   _ACMPSC.Bits.ACMOD1
#define ACMPSC_ACO                      _ACMPSC.Bits.ACO
#define ACMPSC_ACIE                     _ACMPSC.Bits.ACIE
#define ACMPSC_ACF                      _ACMPSC.Bits.ACF
#define ACMPSC_ACBGS                    _ACMPSC.Bits.ACBGS
#define ACMPSC_ACME                     _ACMPSC.Bits.ACME
#define ACMPSC_ACMOD                    _ACMPSC.MergedBits.grpACMOD

#define ACMPSC_ACMOD0_MASK              1
#define ACMPSC_ACMOD1_MASK              2
#define ACMPSC_ACO_MASK                 8
#define ACMPSC_ACIE_MASK                16
#define ACMPSC_ACF_MASK                 32
#define ACMPSC_ACBGS_MASK               64
#define ACMPSC_ACME_MASK                128
#define ACMPSC_ACMOD_MASK               3
#define ACMPSC_ACMOD_BITNUM             0


/*** ADCSC1 - Status and Control Register; 0x00000010 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCH0       :1;                                       /* Input Channel Select Bit 0 */
    byte ADCH1       :1;                                       /* Input Channel Select Bit 1 */
    byte ADCH2       :1;                                       /* Input Channel Select Bit 2 */
    byte ADCH3       :1;                                       /* Input Channel Select Bit 3 */
    byte ADCH4       :1;                                       /* Input Channel Select Bit 4 */
    byte ADCO        :1;                                       /* Continuous Conversion Enable */
    byte AIEN        :1;                                       /* Interrupt Enable */
    byte COCO        :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCH :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC1STR;
extern volatile ADCSC1STR _ADCSC1 @0x00000010;
#define ADCSC1                          _ADCSC1.Byte
#define ADCSC1_ADCH0                    _ADCSC1.Bits.ADCH0
#define ADCSC1_ADCH1                    _ADCSC1.Bits.ADCH1
#define ADCSC1_ADCH2                    _ADCSC1.Bits.ADCH2
#define ADCSC1_ADCH3                    _ADCSC1.Bits.ADCH3
#define ADCSC1_ADCH4                    _ADCSC1.Bits.ADCH4
#define ADCSC1_ADCO                     _ADCSC1.Bits.ADCO
#define ADCSC1_AIEN                     _ADCSC1.Bits.AIEN
#define ADCSC1_COCO                     _ADCSC1.Bits.COCO
#define ADCSC1_ADCH                     _ADCSC1.MergedBits.grpADCH

#define ADCSC1_ADCH0_MASK               1
#define ADCSC1_ADCH1_MASK               2
#define ADCSC1_ADCH2_MASK               4
#define ADCSC1_ADCH3_MASK               8
#define ADCSC1_ADCH4_MASK               16
#define ADCSC1_ADCO_MASK                32
#define ADCSC1_AIEN_MASK                64
#define ADCSC1_COCO_MASK                128
#define ADCSC1_ADCH_MASK                31
#define ADCSC1_ADCH_BITNUM              0


/*** ADCSC2 - Status and Control Register 2; 0x00000011 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ACFGT       :1;                                       /* Compare Function Greater Than Enable */
    byte ACFE        :1;                                       /* Compare Function Enable */
    byte ADTRG       :1;                                       /* Conversion Trigger Select */
    byte ADACT       :1;                                       /* Conversion Active */
  } Bits;
} ADCSC2STR;
extern volatile ADCSC2STR _ADCSC2 @0x00000011;
#define ADCSC2                          _ADCSC2.Byte
#define ADCSC2_ACFGT                    _ADCSC2.Bits.ACFGT
#define ADCSC2_ACFE                     _ADCSC2.Bits.ACFE
#define ADCSC2_ADTRG                    _ADCSC2.Bits.ADTRG
#define ADCSC2_ADACT                    _ADCSC2.Bits.ADACT

#define ADCSC2_ACFGT_MASK               16
#define ADCSC2_ACFE_MASK                32
#define ADCSC2_ADTRG_MASK               64
#define ADCSC2_ADACT_MASK               128


/*** ADCR - ADC Result Data Right Justified; 0x00000012 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRH - ADC Result Data Right Justified High; 0x00000012 ***/
    union {
      byte Byte;
      struct {
        byte ADR8        :1;                                       /* ADC Result Data Bit 8 */
        byte ADR9        :1;                                       /* ADC Result Data Bit 9 */
        byte ADR10       :1;                                       /* ADC Result Data Bit 10 */
        byte ADR11       :1;                                       /* ADC Result Data Bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpADR_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCRHSTR;
    #define ADCRH                       _ADCR.Overlap_STR.ADCRHSTR.Byte
    #define ADCRH_ADR8                  _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR8
    #define ADCRH_ADR9                  _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR9
    #define ADCRH_ADR10                 _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR10
    #define ADCRH_ADR11                 _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR11
    
    #define ADCRH_ADR_8                 _ADCR.Overlap_STR.ADCRHSTR.MergedBits.grpADR_8
    #define ADCRH_ADR                   ADCRH_ADR_8
    
    #define ADCRH_ADR8_MASK             1
    #define ADCRH_ADR9_MASK             2
    #define ADCRH_ADR10_MASK            4
    #define ADCRH_ADR11_MASK            8
    #define ADCRH_ADR_8_MASK            15
    #define ADCRH_ADR_8_BITNUM          0


    /*** ADCRL - ADC Result Data Right Justified Low; 0x00000013 ***/
    union {
      byte Byte;
      struct {
        byte ADR0        :1;                                       /* ADC Result Data Bit 0 */
        byte ADR1        :1;                                       /* ADC Result Data Bit 1 */
        byte ADR2        :1;                                       /* ADC Result Data Bit 2 */
        byte ADR3        :1;                                       /* ADC Result Data Bit 3 */
        byte ADR4        :1;                                       /* ADC Result Data Bit 4 */
        byte ADR5        :1;                                       /* ADC Result Data Bit 5 */
        byte ADR6        :1;                                       /* ADC Result Data Bit 6 */
        byte ADR7        :1;                                       /* ADC Result Data Bit 7 */
      } Bits;
    } ADCRLSTR;
    #define ADCRL                       _ADCR.Overlap_STR.ADCRLSTR.Byte
    #define ADCRL_ADR0                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR0
    #define ADCRL_ADR1                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR1
    #define ADCRL_ADR2                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR2
    #define ADCRL_ADR3                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR3
    #define ADCRL_ADR4                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR4
    #define ADCRL_ADR5                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR5
    #define ADCRL_ADR6                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR6
    #define ADCRL_ADR7                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR7
    
    
    #define ADCRL_ADR0_MASK             1
    #define ADCRL_ADR1_MASK             2
    #define ADCRL_ADR2_MASK             4
    #define ADCRL_ADR3_MASK             8
    #define ADCRL_ADR4_MASK             16
    #define ADCRL_ADR5_MASK             32
    #define ADCRL_ADR6_MASK             64
    #define ADCRL_ADR7_MASK             128

  } Overlap_STR;

} ADCRSTR;
extern volatile ADCRSTR _ADCR @0x00000012;
#define ADCR                            _ADCR.Word



/*** ADCCV - Compare Value Register; 0x00000014 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCCVH - Compare Value Register High; 0x00000014 ***/
    union {
      byte Byte;
      struct {
        byte ADCV8       :1;                                       /* Compare Function Value 8 */
        byte ADCV9       :1;                                       /* Compare Function Value 9 */
        byte ADCV10      :1;                                       /* Compare Function Value 10 */
        byte ADCV11      :1;                                       /* Compare Function Value 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpADCV_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCCVHSTR;
    #define ADCCVH                      _ADCCV.Overlap_STR.ADCCVHSTR.Byte
    #define ADCCVH_ADCV8                _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV8
    #define ADCCVH_ADCV9                _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV9
    #define ADCCVH_ADCV10               _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV10
    #define ADCCVH_ADCV11               _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV11
    
    #define ADCCVH_ADCV_8               _ADCCV.Overlap_STR.ADCCVHSTR.MergedBits.grpADCV_8
    #define ADCCVH_ADCV                 ADCCVH_ADCV_8
    
    #define ADCCVH_ADCV8_MASK           1
    #define ADCCVH_ADCV9_MASK           2
    #define ADCCVH_ADCV10_MASK          4
    #define ADCCVH_ADCV11_MASK          8
    #define ADCCVH_ADCV_8_MASK          15
    #define ADCCVH_ADCV_8_BITNUM        0


    /*** ADCCVL - Compare Value Register Low; 0x00000015 ***/
    union {
      byte Byte;
      struct {
        byte ADCV0       :1;                                       /* Compare Function Value 0 */
        byte ADCV1       :1;                                       /* Compare Function Value 1 */
        byte ADCV2       :1;                                       /* Compare Function Value 2 */
        byte ADCV3       :1;                                       /* Compare Function Value 3 */
        byte ADCV4       :1;                                       /* Compare Function Value 4 */
        byte ADCV5       :1;                                       /* Compare Function Value 5 */
        byte ADCV6       :1;                                       /* Compare Function Value 6 */
        byte ADCV7       :1;                                       /* Compare Function Value 7 */
      } Bits;
    } ADCCVLSTR;
    #define ADCCVL                      _ADCCV.Overlap_STR.ADCCVLSTR.Byte
    #define ADCCVL_ADCV0                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV0
    #define ADCCVL_ADCV1                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV1
    #define ADCCVL_ADCV2                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV2
    #define ADCCVL_ADCV3                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV3
    #define ADCCVL_ADCV4                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV4
    #define ADCCVL_ADCV5                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV5
    #define ADCCVL_ADCV6                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV6
    #define ADCCVL_ADCV7                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV7
    
    
    #define ADCCVL_ADCV0_MASK           1
    #define ADCCVL_ADCV1_MASK           2
    #define ADCCVL_ADCV2_MASK           4
    #define ADCCVL_ADCV3_MASK           8
    #define ADCCVL_ADCV4_MASK           16
    #define ADCCVL_ADCV5_MASK           32
    #define ADCCVL_ADCV6_MASK           64
    #define ADCCVL_ADCV7_MASK           128

  } Overlap_STR;

} ADCCVSTR;
extern volatile ADCCVSTR _ADCCV @0x00000014;
#define ADCCV                           _ADCCV.Word



/*** ADCCFG - Configuration Register; 0x00000016 ***/
typedef union {
  byte Byte;
  struct {
    byte ADICLK0     :1;                                       /* Input Clock Select Bit 0 */
    byte ADICLK1     :1;                                       /* Input Clock Select Bit 1 */
    byte MODE0       :1;                                       /* Conversion Mode Selection Bit 0 */
    byte MODE1       :1;                                       /* Conversion Mode Selection Bit 1 */
    byte ADLSMP      :1;                                       /* Long Sample Time Configuration */
    byte ADIV0       :1;                                       /* Clock Divide Select Bit 0 */
    byte ADIV1       :1;                                       /* Clock Divide Select Bit 1 */
    byte ADLPC       :1;                                       /* Low Power Configuration */
  } Bits;
  struct {
    byte grpADICLK :2;
    byte grpMODE :2;
    byte         :1;
    byte grpADIV :2;
    byte         :1;
  } MergedBits;
} ADCCFGSTR;
extern volatile ADCCFGSTR _ADCCFG @0x00000016;
#define ADCCFG                          _ADCCFG.Byte
#define ADCCFG_ADICLK0                  _ADCCFG.Bits.ADICLK0
#define ADCCFG_ADICLK1                  _ADCCFG.Bits.ADICLK1
#define ADCCFG_MODE0                    _ADCCFG.Bits.MODE0
#define ADCCFG_MODE1                    _ADCCFG.Bits.MODE1
#define ADCCFG_ADLSMP                   _ADCCFG.Bits.ADLSMP
#define ADCCFG_ADIV0                    _ADCCFG.Bits.ADIV0
#define ADCCFG_ADIV1                    _ADCCFG.Bits.ADIV1
#define ADCCFG_ADLPC                    _ADCCFG.Bits.ADLPC
#define ADCCFG_ADICLK                   _ADCCFG.MergedBits.grpADICLK
#define ADCCFG_MODE                     _ADCCFG.MergedBits.grpMODE
#define ADCCFG_ADIV                     _ADCCFG.MergedBits.grpADIV

#define ADCCFG_ADICLK0_MASK             1
#define ADCCFG_ADICLK1_MASK             2
#define ADCCFG_MODE0_MASK               4
#define ADCCFG_MODE1_MASK               8
#define ADCCFG_ADLSMP_MASK              16
#define ADCCFG_ADIV0_MASK               32
#define ADCCFG_ADIV1_MASK               64
#define ADCCFG_ADLPC_MASK               128
#define ADCCFG_ADICLK_MASK              3
#define ADCCFG_ADICLK_BITNUM            0
#define ADCCFG_MODE_MASK                12
#define ADCCFG_MODE_BITNUM              2
#define ADCCFG_ADIV_MASK                96
#define ADCCFG_ADIV_BITNUM              5


/*** APCTL1 - ADC Pin Control 1 Register; 0x00000017 ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC0       :1;                                       /* ADC Pin Control 0 */
    byte ADPC1       :1;                                       /* ADC Pin Control 1 */
    byte ADPC2       :1;                                       /* ADC Pin Control 2 */
    byte ADPC3       :1;                                       /* ADC Pin Control 3 */
    byte ADPC4       :1;                                       /* ADC Pin Control 4 */
    byte ADPC5       :1;                                       /* ADC Pin Control 5 */
    byte ADPC6       :1;                                       /* ADC Pin Control 6 */
    byte ADPC7       :1;                                       /* ADC Pin Control 7 */
  } Bits;
} APCTL1STR;
extern volatile APCTL1STR _APCTL1 @0x00000017;
#define APCTL1                          _APCTL1.Byte
#define APCTL1_ADPC0                    _APCTL1.Bits.ADPC0
#define APCTL1_ADPC1                    _APCTL1.Bits.ADPC1
#define APCTL1_ADPC2                    _APCTL1.Bits.ADPC2
#define APCTL1_ADPC3                    _APCTL1.Bits.ADPC3
#define APCTL1_ADPC4                    _APCTL1.Bits.ADPC4
#define APCTL1_ADPC5                    _APCTL1.Bits.ADPC5
#define APCTL1_ADPC6                    _APCTL1.Bits.ADPC6
#define APCTL1_ADPC7                    _APCTL1.Bits.ADPC7

#define APCTL1_ADPC0_MASK               1
#define APCTL1_ADPC1_MASK               2
#define APCTL1_ADPC2_MASK               4
#define APCTL1_ADPC3_MASK               8
#define APCTL1_ADPC4_MASK               16
#define APCTL1_ADPC5_MASK               32
#define APCTL1_ADPC6_MASK               64
#define APCTL1_ADPC7_MASK               128


/*** IICA - IIC Address Register; 0x00000018 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte ADDR0       :1;                                       /* IIC Address Bit 0 */
    byte ADDR1       :1;                                       /* IIC Address Bit 1 */
    byte ADDR2       :1;                                       /* IIC Address Bit 2 */
    byte ADDR3       :1;                                       /* IIC Address Bit 3 */
    byte ADDR4       :1;                                       /* IIC Address Bit 4 */
    byte ADDR5       :1;                                       /* IIC Address Bit 5 */
    byte ADDR6       :1;                                       /* IIC Address Bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpADDR :7;
  } MergedBits;
} IICASTR;
extern volatile IICASTR _IICA @0x00000018;
#define IICA                            _IICA.Byte
#define IICA_ADDR0                      _IICA.Bits.ADDR0
#define IICA_ADDR1                      _IICA.Bits.ADDR1
#define IICA_ADDR2                      _IICA.Bits.ADDR2
#define IICA_ADDR3                      _IICA.Bits.ADDR3
#define IICA_ADDR4                      _IICA.Bits.ADDR4
#define IICA_ADDR5                      _IICA.Bits.ADDR5
#define IICA_ADDR6                      _IICA.Bits.ADDR6
#define IICA_ADDR                       _IICA.MergedBits.grpADDR

#define IICA_ADDR0_MASK                 2
#define IICA_ADDR1_MASK                 4
#define IICA_ADDR2_MASK                 8
#define IICA_ADDR3_MASK                 16
#define IICA_ADDR4_MASK                 32
#define IICA_ADDR5_MASK                 64
#define IICA_ADDR6_MASK                 128
#define IICA_ADDR_MASK                  254
#define IICA_ADDR_BITNUM                1


/*** IICF - IIC Frequency Divider Register; 0x00000019 ***/
typedef union {
  byte Byte;
  struct {
    byte ICR0        :1;                                       /* IIC Clock Rate Bit 0 */
    byte ICR1        :1;                                       /* IIC Clock Rate Bit 1 */
    byte ICR2        :1;                                       /* IIC Clock Rate Bit 2 */
    byte ICR3        :1;                                       /* IIC Clock Rate Bit 3 */
    byte ICR4        :1;                                       /* IIC Clock Rate Bit 4 */
    byte ICR5        :1;                                       /* IIC Clock Rate Bit 5 */
    byte MULT0       :1;                                       /* Multiplier Factor Bit 0 */
    byte MULT1       :1;                                       /* Multiplier Factor Bit 1 */
  } Bits;
  struct {
    byte grpICR  :6;
    byte grpMULT :2;
  } MergedBits;
} IICFSTR;
extern volatile IICFSTR _IICF @0x00000019;
#define IICF                            _IICF.Byte
#define IICF_ICR0                       _IICF.Bits.ICR0
#define IICF_ICR1                       _IICF.Bits.ICR1
#define IICF_ICR2                       _IICF.Bits.ICR2
#define IICF_ICR3                       _IICF.Bits.ICR3
#define IICF_ICR4                       _IICF.Bits.ICR4
#define IICF_ICR5                       _IICF.Bits.ICR5
#define IICF_MULT0                      _IICF.Bits.MULT0
#define IICF_MULT1                      _IICF.Bits.MULT1
#define IICF_ICR                        _IICF.MergedBits.grpICR
#define IICF_MULT                       _IICF.MergedBits.grpMULT

#define IICF_ICR0_MASK                  1
#define IICF_ICR1_MASK                  2
#define IICF_ICR2_MASK                  4
#define IICF_ICR3_MASK                  8
#define IICF_ICR4_MASK                  16
#define IICF_ICR5_MASK                  32
#define IICF_MULT0_MASK                 64
#define IICF_MULT1_MASK                 128
#define IICF_ICR_MASK                   63
#define IICF_ICR_BITNUM                 0
#define IICF_MULT_MASK                  192
#define IICF_MULT_BITNUM                6


/*** IICC - IIC Control Register; 0x0000001A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte RSTA        :1;                                       /* Repeat START Bit */
    byte TXAK        :1;                                       /* Transmit Acknowledge Enable Bit */
    byte TX          :1;                                       /* Transmit Mode Select Bit */
    byte MST         :1;                                       /* Master Mode Select Bit */
    byte IICIE       :1;                                       /* IIC Interrupt Enable Bit */
    byte IICEN       :1;                                       /* IIC Enable Bit */
  } Bits;
} IICCSTR;
extern volatile IICCSTR _IICC @0x0000001A;
#define IICC                            _IICC.Byte
#define IICC_RSTA                       _IICC.Bits.RSTA
#define IICC_TXAK                       _IICC.Bits.TXAK
#define IICC_TX                         _IICC.Bits.TX
#define IICC_MST                        _IICC.Bits.MST
#define IICC_IICIE                      _IICC.Bits.IICIE
#define IICC_IICEN                      _IICC.Bits.IICEN

#define IICC_RSTA_MASK                  4
#define IICC_TXAK_MASK                  8
#define IICC_TX_MASK                    16
#define IICC_MST_MASK                   32
#define IICC_IICIE_MASK                 64
#define IICC_IICEN_MASK                 128


/*** IICS - IIC Status Register; 0x0000001B ***/
typedef union {
  byte Byte;
  struct {
    byte RXAK        :1;                                       /* Receive Acknowledge */
    byte IICIF       :1;                                       /* IIC Interrupt Flag */
    byte SRW         :1;                                       /* Slave Read/Write */
    byte             :1; 
    byte ARBL        :1;                                       /* Arbitration Lost */
    byte BUSY        :1;                                       /* Bus Busy bit */
    byte IAAS        :1;                                       /* Addressed as a Slave Bit */
    byte TCF         :1;                                       /* Transfer Complete Flag */
  } Bits;
} IICSSTR;
extern volatile IICSSTR _IICS @0x0000001B;
#define IICS                            _IICS.Byte
#define IICS_RXAK                       _IICS.Bits.RXAK
#define IICS_IICIF                      _IICS.Bits.IICIF
#define IICS_SRW                        _IICS.Bits.SRW
#define IICS_ARBL                       _IICS.Bits.ARBL
#define IICS_BUSY                       _IICS.Bits.BUSY
#define IICS_IAAS                       _IICS.Bits.IAAS
#define IICS_TCF                        _IICS.Bits.TCF

#define IICS_RXAK_MASK                  1
#define IICS_IICIF_MASK                 2
#define IICS_SRW_MASK                   4
#define IICS_ARBL_MASK                  16
#define IICS_BUSY_MASK                  32
#define IICS_IAAS_MASK                  64
#define IICS_TCF_MASK                   128


/*** IICD - IIC Data I/O Register; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte DATA0       :1;                                       /* IIC Data Bit 0 */
    byte DATA1       :1;                                       /* IIC Data Bit 1 */
    byte DATA2       :1;                                       /* IIC Data Bit 2 */
    byte DATA3       :1;                                       /* IIC Data Bit 3 */
    byte DATA4       :1;                                       /* IIC Data Bit 4 */
    byte DATA5       :1;                                       /* IIC Data Bit 5 */
    byte DATA6       :1;                                       /* IIC Data Bit 6 */
    byte DATA7       :1;                                       /* IIC Data Bit 7 */
  } Bits;
} IICDSTR;
extern volatile IICDSTR _IICD @0x0000001C;
#define IICD                            _IICD.Byte
#define IICD_DATA0                      _IICD.Bits.DATA0
#define IICD_DATA1                      _IICD.Bits.DATA1
#define IICD_DATA2                      _IICD.Bits.DATA2
#define IICD_DATA3                      _IICD.Bits.DATA3
#define IICD_DATA4                      _IICD.Bits.DATA4
#define IICD_DATA5                      _IICD.Bits.DATA5
#define IICD_DATA6                      _IICD.Bits.DATA6
#define IICD_DATA7                      _IICD.Bits.DATA7

#define IICD_DATA0_MASK                 1
#define IICD_DATA1_MASK                 2
#define IICD_DATA2_MASK                 4
#define IICD_DATA3_MASK                 8
#define IICD_DATA4_MASK                 16
#define IICD_DATA5_MASK                 32
#define IICD_DATA6_MASK                 64
#define IICD_DATA7_MASK                 128


/*** SCIBD - SCI Baud Rate Register; 0x00000020 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCIBDH - SCI Baud Rate Register High; 0x00000020 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
        byte SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
        byte SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
        byte SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
        byte SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCIBDHSTR;
    #define SCIBDH                      _SCIBD.Overlap_STR.SCIBDHSTR.Byte
    #define SCIBDH_SBR8                 _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR8
    #define SCIBDH_SBR9                 _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR9
    #define SCIBDH_SBR10                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR10
    #define SCIBDH_SBR11                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR11
    #define SCIBDH_SBR12                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR12
    
    #define SCIBDH_SBR_8                _SCIBD.Overlap_STR.SCIBDHSTR.MergedBits.grpSBR_8
    #define SCIBDH_SBR                  SCIBDH_SBR_8
    
    #define SCIBDH_SBR8_MASK            1
    #define SCIBDH_SBR9_MASK            2
    #define SCIBDH_SBR10_MASK           4
    #define SCIBDH_SBR11_MASK           8
    #define SCIBDH_SBR12_MASK           16
    #define SCIBDH_SBR_8_MASK           31
    #define SCIBDH_SBR_8_BITNUM         0


    /*** SCIBDL - SCI Baud Rate Register Low; 0x00000021 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
      } Bits;
    } SCIBDLSTR;
    #define SCIBDL                      _SCIBD.Overlap_STR.SCIBDLSTR.Byte
    #define SCIBDL_SBR0                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR0
    #define SCIBDL_SBR1                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR1
    #define SCIBDL_SBR2                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR2
    #define SCIBDL_SBR3                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR3
    #define SCIBDL_SBR4                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR4
    #define SCIBDL_SBR5                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR5
    #define SCIBDL_SBR6                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR6
    #define SCIBDL_SBR7                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR7
    
    
    #define SCIBDL_SBR0_MASK            1
    #define SCIBDL_SBR1_MASK            2
    #define SCIBDL_SBR2_MASK            4
    #define SCIBDL_SBR3_MASK            8
    #define SCIBDL_SBR4_MASK            16
    #define SCIBDL_SBR5_MASK            32
    #define SCIBDL_SBR6_MASK            64
    #define SCIBDL_SBR7_MASK            128

  } Overlap_STR;

} SCIBDSTR;
extern volatile SCIBDSTR _SCIBD @0x00000020;
#define SCIBD                           _SCIBD.Word



/*** SCIC1 - SCI Control Register 1; 0x00000022 ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte WAKE        :1;                                       /* Receiver Wakeup Method Select */
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte SCISWAI     :1;                                       /* SCI Stops in Wait Mode */
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} SCIC1STR;
extern volatile SCIC1STR _SCIC1 @0x00000022;
#define SCIC1                           _SCIC1.Byte
#define SCIC1_PT                        _SCIC1.Bits.PT
#define SCIC1_PE                        _SCIC1.Bits.PE
#define SCIC1_ILT                       _SCIC1.Bits.ILT
#define SCIC1_WAKE                      _SCIC1.Bits.WAKE
#define SCIC1_M                         _SCIC1.Bits.M
#define SCIC1_RSRC                      _SCIC1.Bits.RSRC
#define SCIC1_SCISWAI                   _SCIC1.Bits.SCISWAI
#define SCIC1_LOOPS                     _SCIC1.Bits.LOOPS

#define SCIC1_PT_MASK                   1
#define SCIC1_PE_MASK                   2
#define SCIC1_ILT_MASK                  4
#define SCIC1_WAKE_MASK                 8
#define SCIC1_M_MASK                    16
#define SCIC1_RSRC_MASK                 32
#define SCIC1_SCISWAI_MASK              64
#define SCIC1_LOOPS_MASK                128


/*** SCIC2 - SCI Control Register 2; 0x00000023 ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable (for IDLE) */
    byte RIE         :1;                                       /* Receiver Interrupt Enable (for RDRF) */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable (for TC) */
    byte TIE         :1;                                       /* Transmit Interrupt Enable (for TDRE) */
  } Bits;
} SCIC2STR;
extern volatile SCIC2STR _SCIC2 @0x00000023;
#define SCIC2                           _SCIC2.Byte
#define SCIC2_SBK                       _SCIC2.Bits.SBK
#define SCIC2_RWU                       _SCIC2.Bits.RWU
#define SCIC2_RE                        _SCIC2.Bits.RE
#define SCIC2_TE                        _SCIC2.Bits.TE
#define SCIC2_ILIE                      _SCIC2.Bits.ILIE
#define SCIC2_RIE                       _SCIC2.Bits.RIE
#define SCIC2_TCIE                      _SCIC2.Bits.TCIE
#define SCIC2_TIE                       _SCIC2.Bits.TIE

#define SCIC2_SBK_MASK                  1
#define SCIC2_RWU_MASK                  2
#define SCIC2_RE_MASK                   4
#define SCIC2_TE_MASK                   8
#define SCIC2_ILIE_MASK                 16
#define SCIC2_RIE_MASK                  32
#define SCIC2_TCIE_MASK                 64
#define SCIC2_TIE_MASK                  128


/*** SCIS1 - SCI Status Register 1; 0x00000024 ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Receiver Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmission Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCIS1STR;
extern volatile SCIS1STR _SCIS1 @0x00000024;
#define SCIS1                           _SCIS1.Byte
#define SCIS1_PF                        _SCIS1.Bits.PF
#define SCIS1_FE                        _SCIS1.Bits.FE
#define SCIS1_NF                        _SCIS1.Bits.NF
#define SCIS1_OR                        _SCIS1.Bits.OR
#define SCIS1_IDLE                      _SCIS1.Bits.IDLE
#define SCIS1_RDRF                      _SCIS1.Bits.RDRF
#define SCIS1_TC                        _SCIS1.Bits.TC
#define SCIS1_TDRE                      _SCIS1.Bits.TDRE

#define SCIS1_PF_MASK                   1
#define SCIS1_FE_MASK                   2
#define SCIS1_NF_MASK                   4
#define SCIS1_OR_MASK                   8
#define SCIS1_IDLE_MASK                 16
#define SCIS1_RDRF_MASK                 32
#define SCIS1_TC_MASK                   64
#define SCIS1_TDRE_MASK                 128


/*** SCIS2 - SCI Status Register 2; 0x00000025 ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte             :1; 
    byte BRK13       :1;                                       /* Break Character Length */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SCIS2STR;
extern volatile SCIS2STR _SCIS2 @0x00000025;
#define SCIS2                           _SCIS2.Byte
#define SCIS2_RAF                       _SCIS2.Bits.RAF
#define SCIS2_BRK13                     _SCIS2.Bits.BRK13

#define SCIS2_RAF_MASK                  1
#define SCIS2_BRK13_MASK                4


/*** SCIC3 - SCI Control Register 3; 0x00000026 ***/
typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       /* Parity Error Interrupt Enable */
    byte FEIE        :1;                                       /* Framing Error Interrupt Enable */
    byte NEIE        :1;                                       /* Noise Error Interrupt Enable */
    byte ORIE        :1;                                       /* Overrun Interrupt Enable */
    byte TXINV       :1;                                       /* Transmit Data Inversion */
    byte TXDIR       :1;                                       /* TxD Pin Direction in Single-Wire Mode */
    byte T8          :1;                                       /* Ninth Data Bit for Transmitter */
    byte R8          :1;                                       /* Ninth Data Bit for Receiver */
  } Bits;
} SCIC3STR;
extern volatile SCIC3STR _SCIC3 @0x00000026;
#define SCIC3                           _SCIC3.Byte
#define SCIC3_PEIE                      _SCIC3.Bits.PEIE
#define SCIC3_FEIE                      _SCIC3.Bits.FEIE
#define SCIC3_NEIE                      _SCIC3.Bits.NEIE
#define SCIC3_ORIE                      _SCIC3.Bits.ORIE
#define SCIC3_TXINV                     _SCIC3.Bits.TXINV
#define SCIC3_TXDIR                     _SCIC3.Bits.TXDIR
#define SCIC3_T8                        _SCIC3.Bits.T8
#define SCIC3_R8                        _SCIC3.Bits.R8

#define SCIC3_PEIE_MASK                 1
#define SCIC3_FEIE_MASK                 2
#define SCIC3_NEIE_MASK                 4
#define SCIC3_ORIE_MASK                 8
#define SCIC3_TXINV_MASK                16
#define SCIC3_TXDIR_MASK                32
#define SCIC3_T8_MASK                   64
#define SCIC3_R8_MASK                   128


/*** SCID - SCI Data Register; 0x00000027 ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Receive/Transmit Data Bit 0 */
    byte R1_T1       :1;                                       /* Receive/Transmit Data Bit 1 */
    byte R2_T2       :1;                                       /* Receive/Transmit Data Bit 2 */
    byte R3_T3       :1;                                       /* Receive/Transmit Data Bit 3 */
    byte R4_T4       :1;                                       /* Receive/Transmit Data Bit 4 */
    byte R5_T5       :1;                                       /* Receive/Transmit Data Bit 5 */
    byte R6_T6       :1;                                       /* Receive/Transmit Data Bit 6 */
    byte R7_T7       :1;                                       /* Receive/Transmit Data Bit 7 */
  } Bits;
} SCIDSTR;
extern volatile SCIDSTR _SCID @0x00000027;
#define SCID                            _SCID.Byte
#define SCID_R0_T0                      _SCID.Bits.R0_T0
#define SCID_R1_T1                      _SCID.Bits.R1_T1
#define SCID_R2_T2                      _SCID.Bits.R2_T2
#define SCID_R3_T3                      _SCID.Bits.R3_T3
#define SCID_R4_T4                      _SCID.Bits.R4_T4
#define SCID_R5_T5                      _SCID.Bits.R5_T5
#define SCID_R6_T6                      _SCID.Bits.R6_T6
#define SCID_R7_T7                      _SCID.Bits.R7_T7

#define SCID_R0_T0_MASK                 1
#define SCID_R1_T1_MASK                 2
#define SCID_R2_T2_MASK                 4
#define SCID_R3_T3_MASK                 8
#define SCID_R4_T4_MASK                 16
#define SCID_R5_T5_MASK                 32
#define SCID_R6_T6_MASK                 64
#define SCID_R7_T7_MASK                 128


/*** SPI1C1 - SPI1 Control Register 1; 0x00000028 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB First (shifter direction) */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* Clock Phase */
    byte CPOL        :1;                                       /* Clock Polarity */
    byte MSTR        :1;                                       /* Master/Slave Mode Select */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable */
    byte SPIE        :1;                                       /* SPI Interrupt Enable */
  } Bits;
} SPI1C1STR;
extern volatile SPI1C1STR _SPI1C1 @0x00000028;
#define SPI1C1                          _SPI1C1.Byte
#define SPI1C1_LSBFE                    _SPI1C1.Bits.LSBFE
#define SPI1C1_SSOE                     _SPI1C1.Bits.SSOE
#define SPI1C1_CPHA                     _SPI1C1.Bits.CPHA
#define SPI1C1_CPOL                     _SPI1C1.Bits.CPOL
#define SPI1C1_MSTR                     _SPI1C1.Bits.MSTR
#define SPI1C1_SPTIE                    _SPI1C1.Bits.SPTIE
#define SPI1C1_SPE                      _SPI1C1.Bits.SPE
#define SPI1C1_SPIE                     _SPI1C1.Bits.SPIE

#define SPI1C1_LSBFE_MASK               1
#define SPI1C1_SSOE_MASK                2
#define SPI1C1_CPHA_MASK                4
#define SPI1C1_CPOL_MASK                8
#define SPI1C1_MSTR_MASK                16
#define SPI1C1_SPTIE_MASK               32
#define SPI1C1_SPE_MASK                 64
#define SPI1C1_SPIE_MASK                128


/*** SPI1C2 - SPI1 Control Register 2; 0x00000029 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SPI1C2STR;
extern volatile SPI1C2STR _SPI1C2 @0x00000029;
#define SPI1C2                          _SPI1C2.Byte
#define SPI1C2_SPC0                     _SPI1C2.Bits.SPC0
#define SPI1C2_SPISWAI                  _SPI1C2.Bits.SPISWAI
#define SPI1C2_BIDIROE                  _SPI1C2.Bits.BIDIROE
#define SPI1C2_MODFEN                   _SPI1C2.Bits.MODFEN

#define SPI1C2_SPC0_MASK                1
#define SPI1C2_SPISWAI_MASK             2
#define SPI1C2_BIDIROE_MASK             8
#define SPI1C2_MODFEN_MASK              16


/*** SPI1BR - SPI1 Baud Rate Register; 0x0000002A ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Divisor Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Divisor Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Divisor Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 1 */
    byte SPPR2       :1;                                       /* SP1 Baud Rate Prescale Divisor Bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPI1BRSTR;
extern volatile SPI1BRSTR _SPI1BR @0x0000002A;
#define SPI1BR                          _SPI1BR.Byte
#define SPI1BR_SPR0                     _SPI1BR.Bits.SPR0
#define SPI1BR_SPR1                     _SPI1BR.Bits.SPR1
#define SPI1BR_SPR2                     _SPI1BR.Bits.SPR2
#define SPI1BR_SPPR0                    _SPI1BR.Bits.SPPR0
#define SPI1BR_SPPR1                    _SPI1BR.Bits.SPPR1
#define SPI1BR_SPPR2                    _SPI1BR.Bits.SPPR2
#define SPI1BR_SPR                      _SPI1BR.MergedBits.grpSPR
#define SPI1BR_SPPR                     _SPI1BR.MergedBits.grpSPPR

#define SPI1BR_SPR0_MASK                1
#define SPI1BR_SPR1_MASK                2
#define SPI1BR_SPR2_MASK                4
#define SPI1BR_SPPR0_MASK               16
#define SPI1BR_SPPR1_MASK               32
#define SPI1BR_SPPR2_MASK               64
#define SPI1BR_SPR_MASK                 7
#define SPI1BR_SPR_BITNUM               0
#define SPI1BR_SPPR_MASK                112
#define SPI1BR_SPPR_BITNUM              4


/*** SPI1S - SPI1 Status Register; 0x0000002B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte             :1; 
    byte SPRF        :1;                                       /* SP1 Read Buffer Full Flag */
  } Bits;
} SPI1SSTR;
extern volatile SPI1SSTR _SPI1S @0x0000002B;
#define SPI1S                           _SPI1S.Byte
#define SPI1S_MODF                      _SPI1S.Bits.MODF
#define SPI1S_SPTEF                     _SPI1S.Bits.SPTEF
#define SPI1S_SPRF                      _SPI1S.Bits.SPRF

#define SPI1S_MODF_MASK                 16
#define SPI1S_SPTEF_MASK                32
#define SPI1S_SPRF_MASK                 128


/*** SPI1D - SPI1 Data Register; 0x0000002D ***/
typedef union {
  byte Byte;
} SPI1DSTR;
extern volatile SPI1DSTR _SPI1D @0x0000002D;
#define SPI1D                           _SPI1D.Byte



/*** SPI2C1 - SPI2 Control Register 1; 0x00000030 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB First (shifter direction) */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* Clock Phase */
    byte CPOL        :1;                                       /* Clock Polarity */
    byte MSTR        :1;                                       /* Master/Slave Mode Select */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable */
    byte SPIE        :1;                                       /* SPI Interrupt Enable */
  } Bits;
} SPI2C1STR;
extern volatile SPI2C1STR _SPI2C1 @0x00000030;
#define SPI2C1                          _SPI2C1.Byte
#define SPI2C1_LSBFE                    _SPI2C1.Bits.LSBFE
#define SPI2C1_SSOE                     _SPI2C1.Bits.SSOE
#define SPI2C1_CPHA                     _SPI2C1.Bits.CPHA
#define SPI2C1_CPOL                     _SPI2C1.Bits.CPOL
#define SPI2C1_MSTR                     _SPI2C1.Bits.MSTR
#define SPI2C1_SPTIE                    _SPI2C1.Bits.SPTIE
#define SPI2C1_SPE                      _SPI2C1.Bits.SPE
#define SPI2C1_SPIE                     _SPI2C1.Bits.SPIE

#define SPI2C1_LSBFE_MASK               1
#define SPI2C1_SSOE_MASK                2
#define SPI2C1_CPHA_MASK                4
#define SPI2C1_CPOL_MASK                8
#define SPI2C1_MSTR_MASK                16
#define SPI2C1_SPTIE_MASK               32
#define SPI2C1_SPE_MASK                 64
#define SPI2C1_SPIE_MASK                128


/*** SPI2C2 - SPI2 Control Register 2; 0x00000031 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SPI2C2STR;
extern volatile SPI2C2STR _SPI2C2 @0x00000031;
#define SPI2C2                          _SPI2C2.Byte
#define SPI2C2_SPC0                     _SPI2C2.Bits.SPC0
#define SPI2C2_SPISWAI                  _SPI2C2.Bits.SPISWAI
#define SPI2C2_BIDIROE                  _SPI2C2.Bits.BIDIROE
#define SPI2C2_MODFEN                   _SPI2C2.Bits.MODFEN

#define SPI2C2_SPC0_MASK                1
#define SPI2C2_SPISWAI_MASK             2
#define SPI2C2_BIDIROE_MASK             8
#define SPI2C2_MODFEN_MASK              16


/*** SPI2BR - SPI2 Baud Rate Register; 0x00000032 ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Divisor Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Divisor Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Divisor Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 1 */
    byte SPPR2       :1;                                       /* SP1 Baud Rate Prescale Divisor Bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPI2BRSTR;
extern volatile SPI2BRSTR _SPI2BR @0x00000032;
#define SPI2BR                          _SPI2BR.Byte
#define SPI2BR_SPR0                     _SPI2BR.Bits.SPR0
#define SPI2BR_SPR1                     _SPI2BR.Bits.SPR1
#define SPI2BR_SPR2                     _SPI2BR.Bits.SPR2
#define SPI2BR_SPPR0                    _SPI2BR.Bits.SPPR0
#define SPI2BR_SPPR1                    _SPI2BR.Bits.SPPR1
#define SPI2BR_SPPR2                    _SPI2BR.Bits.SPPR2
#define SPI2BR_SPR                      _SPI2BR.MergedBits.grpSPR
#define SPI2BR_SPPR                     _SPI2BR.MergedBits.grpSPPR

#define SPI2BR_SPR0_MASK                1
#define SPI2BR_SPR1_MASK                2
#define SPI2BR_SPR2_MASK                4
#define SPI2BR_SPPR0_MASK               16
#define SPI2BR_SPPR1_MASK               32
#define SPI2BR_SPPR2_MASK               64
#define SPI2BR_SPR_MASK                 7
#define SPI2BR_SPR_BITNUM               0
#define SPI2BR_SPPR_MASK                112
#define SPI2BR_SPPR_BITNUM              4


/*** SPI2S - SPI2 Status Register; 0x00000033 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte             :1; 
    byte SPRF        :1;                                       /* SP1 Read Buffer Full Flag */
  } Bits;
} SPI2SSTR;
extern volatile SPI2SSTR _SPI2S @0x00000033;
#define SPI2S                           _SPI2S.Byte
#define SPI2S_MODF                      _SPI2S.Bits.MODF
#define SPI2S_SPTEF                     _SPI2S.Bits.SPTEF
#define SPI2S_SPRF                      _SPI2S.Bits.SPRF

#define SPI2S_MODF_MASK                 16
#define SPI2S_SPTEF_MASK                32
#define SPI2S_SPRF_MASK                 128


/*** SPI2D - SPI2 Data Register; 0x00000035 ***/
typedef union {
  byte Byte;
} SPI2DSTR;
extern volatile SPI2DSTR _SPI2D @0x00000035;
#define SPI2D                           _SPI2D.Byte



/*** ICGC1 - ICG Control Register 1; 0x00000038 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LOCD        :1;                                       /* Loss of Clock Disable */
    byte OSCSTEN     :1;                                       /* Enable Oscillator in Off Mode */
    byte CLKS0       :1;                                       /* Clock Mode Select Bit 0 */
    byte CLKS1       :1;                                       /* Clock Mode Select Bit 1 */
    byte REFS        :1;                                       /* External Reference Select */
    byte RANGE       :1;                                       /* Frequency Range Select */
    byte HGO         :1;                                       /* High Gain Oscillator Select */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpCLKS :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ICGC1STR;
extern volatile ICGC1STR _ICGC1 @0x00000038;
#define ICGC1                           _ICGC1.Byte
#define ICGC1_LOCD                      _ICGC1.Bits.LOCD
#define ICGC1_OSCSTEN                   _ICGC1.Bits.OSCSTEN
#define ICGC1_CLKS0                     _ICGC1.Bits.CLKS0
#define ICGC1_CLKS1                     _ICGC1.Bits.CLKS1
#define ICGC1_REFS                      _ICGC1.Bits.REFS
#define ICGC1_RANGE                     _ICGC1.Bits.RANGE
#define ICGC1_HGO                       _ICGC1.Bits.HGO
#define ICGC1_CLKS                      _ICGC1.MergedBits.grpCLKS

#define ICGC1_LOCD_MASK                 2
#define ICGC1_OSCSTEN_MASK              4
#define ICGC1_CLKS0_MASK                8
#define ICGC1_CLKS1_MASK                16
#define ICGC1_REFS_MASK                 32
#define ICGC1_RANGE_MASK                64
#define ICGC1_HGO_MASK                  128
#define ICGC1_CLKS_MASK                 24
#define ICGC1_CLKS_BITNUM               3


/*** ICGC2 - ICG Control Register 2; 0x00000039 ***/
typedef union {
  byte Byte;
  struct {
    byte RFD0        :1;                                       /* Reduced Frequency Divider Bit 0 */
    byte RFD1        :1;                                       /* Reduced Frequency Divider Bit 1 */
    byte RFD2        :1;                                       /* Reduced Frequency Divider Bit 2 */
    byte LOCRE       :1;                                       /* Loss of Clock Reset Enable */
    byte MFD0        :1;                                       /* Multiplication Factor Bit 0 */
    byte MFD1        :1;                                       /* Multiplication Factor Bit 1 */
    byte MFD2        :1;                                       /* Multiplication Factor Bit 2 */
    byte LOLRE       :1;                                       /* Loss of Lock Reset Enable */
  } Bits;
  struct {
    byte grpRFD  :3;
    byte         :1;
    byte grpMFD  :3;
    byte         :1;
  } MergedBits;
} ICGC2STR;
extern volatile ICGC2STR _ICGC2 @0x00000039;
#define ICGC2                           _ICGC2.Byte
#define ICGC2_RFD0                      _ICGC2.Bits.RFD0
#define ICGC2_RFD1                      _ICGC2.Bits.RFD1
#define ICGC2_RFD2                      _ICGC2.Bits.RFD2
#define ICGC2_LOCRE                     _ICGC2.Bits.LOCRE
#define ICGC2_MFD0                      _ICGC2.Bits.MFD0
#define ICGC2_MFD1                      _ICGC2.Bits.MFD1
#define ICGC2_MFD2                      _ICGC2.Bits.MFD2
#define ICGC2_LOLRE                     _ICGC2.Bits.LOLRE
#define ICGC2_RFD                       _ICGC2.MergedBits.grpRFD
#define ICGC2_MFD                       _ICGC2.MergedBits.grpMFD

#define ICGC2_RFD0_MASK                 1
#define ICGC2_RFD1_MASK                 2
#define ICGC2_RFD2_MASK                 4
#define ICGC2_LOCRE_MASK                8
#define ICGC2_MFD0_MASK                 16
#define ICGC2_MFD1_MASK                 32
#define ICGC2_MFD2_MASK                 64
#define ICGC2_LOLRE_MASK                128
#define ICGC2_RFD_MASK                  7
#define ICGC2_RFD_BITNUM                0
#define ICGC2_MFD_MASK                  112
#define ICGC2_MFD_BITNUM                4


/*** ICGS1 - ICG Status Register 1; 0x0000003A ***/
typedef union {
  byte Byte;
  struct {
    byte ICGIF       :1;                                       /* ICG Interrupt Flag */
    byte ERCS        :1;                                       /* External Reference Clock Status */
    byte LOCS        :1;                                       /* Loss Of Clock Status */
    byte LOCK        :1;                                       /* FLL Lock Status */
    byte LOLS        :1;                                       /* FLL Loss of Lock Status */
    byte REFST       :1;                                       /* Reference Clock Status */
    byte CLKST0      :1;                                       /* Clock Mode Status Bit 0 */
    byte CLKST1      :1;                                       /* Clock Mode Status Bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpCLKST :2;
  } MergedBits;
} ICGS1STR;
extern volatile ICGS1STR _ICGS1 @0x0000003A;
#define ICGS1                           _ICGS1.Byte
#define ICGS1_ICGIF                     _ICGS1.Bits.ICGIF
#define ICGS1_ERCS                      _ICGS1.Bits.ERCS
#define ICGS1_LOCS                      _ICGS1.Bits.LOCS
#define ICGS1_LOCK                      _ICGS1.Bits.LOCK
#define ICGS1_LOLS                      _ICGS1.Bits.LOLS
#define ICGS1_REFST                     _ICGS1.Bits.REFST
#define ICGS1_CLKST0                    _ICGS1.Bits.CLKST0
#define ICGS1_CLKST1                    _ICGS1.Bits.CLKST1
#define ICGS1_CLKST                     _ICGS1.MergedBits.grpCLKST

#define ICGS1_ICGIF_MASK                1
#define ICGS1_ERCS_MASK                 2
#define ICGS1_LOCS_MASK                 4
#define ICGS1_LOCK_MASK                 8
#define ICGS1_LOLS_MASK                 16
#define ICGS1_REFST_MASK                32
#define ICGS1_CLKST0_MASK               64
#define ICGS1_CLKST1_MASK               128
#define ICGS1_CLKST_MASK                192
#define ICGS1_CLKST_BITNUM              6


/*** ICGS2 - ICG Status Register 2; 0x0000003B ***/
typedef union {
  byte Byte;
  struct {
    byte DCOS        :1;                                       /* DCO Clock Stable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} ICGS2STR;
extern volatile ICGS2STR _ICGS2 @0x0000003B;
#define ICGS2                           _ICGS2.Byte
#define ICGS2_DCOS                      _ICGS2.Bits.DCOS

#define ICGS2_DCOS_MASK                 1


/*** ICGFLT - ICG Upper Filter; 0x0000003C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ICGFLTU - ICG Upper Filter Register; 0x0000003C ***/
    union {
      byte Byte;
      struct {
        byte FILT8       :1;                                       /* ICG Filter Bit 8 */
        byte FILT9       :1;                                       /* ICG Filter Bit 9 */
        byte FILT10      :1;                                       /* ICG Filter Bit 10 */
        byte FILT11      :1;                                       /* ICG Filter Bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpFILT_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ICGFLTUSTR;
    #define ICGFLTU                     _ICGFLT.Overlap_STR.ICGFLTUSTR.Byte
    #define ICGFLTU_FILT8               _ICGFLT.Overlap_STR.ICGFLTUSTR.Bits.FILT8
    #define ICGFLTU_FILT9               _ICGFLT.Overlap_STR.ICGFLTUSTR.Bits.FILT9
    #define ICGFLTU_FILT10              _ICGFLT.Overlap_STR.ICGFLTUSTR.Bits.FILT10
    #define ICGFLTU_FILT11              _ICGFLT.Overlap_STR.ICGFLTUSTR.Bits.FILT11
    
    #define ICGFLTU_FILT_8              _ICGFLT.Overlap_STR.ICGFLTUSTR.MergedBits.grpFILT_8
    #define ICGFLTU_FILT                ICGFLTU_FILT_8
    
    #define ICGFLTU_FILT8_MASK          1
    #define ICGFLTU_FILT9_MASK          2
    #define ICGFLTU_FILT10_MASK         4
    #define ICGFLTU_FILT11_MASK         8
    #define ICGFLTU_FILT_8_MASK         15
    #define ICGFLTU_FILT_8_BITNUM       0


    /*** ICGFLTL - ICG Lower Filter Register; 0x0000003D ***/
    union {
      byte Byte;
      struct {
        byte FILT0       :1;                                       /* ICG Filter Bit 0 */
        byte FILT1       :1;                                       /* ICG Filter Bit 1 */
        byte FILT2       :1;                                       /* ICG Filter Bit 2 */
        byte FILT3       :1;                                       /* ICG Filter Bit 3 */
        byte FILT4       :1;                                       /* ICG Filter Bit 4 */
        byte FILT5       :1;                                       /* ICG Filter Bit 5 */
        byte FILT6       :1;                                       /* ICG Filter Bit 6 */
        byte FILT7       :1;                                       /* ICG Filter Bit 7 */
      } Bits;
    } ICGFLTLSTR;
    #define ICGFLTL                     _ICGFLT.Overlap_STR.ICGFLTLSTR.Byte
    #define ICGFLTL_FILT0               _ICGFLT.Overlap_STR.ICGFLTLSTR.Bits.FILT0
    #define ICGFLTL_FILT1               _ICGFLT.Overlap_STR.ICGFLTLSTR.Bits.FILT1
    #define ICGFLTL_FILT2               _ICGFLT.Overlap_STR.ICGFLTLSTR.Bits.FILT2
    #define ICGFLTL_FILT3               _ICGFLT.Overlap_STR.ICGFLTLSTR.Bits.FILT3
    #define ICGFLTL_FILT4               _ICGFLT.Overlap_STR.ICGFLTLSTR.Bits.FILT4
    #define ICGFLTL_FILT5               _ICGFLT.Overlap_STR.ICGFLTLSTR.Bits.FILT5
    #define ICGFLTL_FILT6               _ICGFLT.Overlap_STR.ICGFLTLSTR.Bits.FILT6
    #define ICGFLTL_FILT7               _ICGFLT.Overlap_STR.ICGFLTLSTR.Bits.FILT7
    
    
    #define ICGFLTL_FILT0_MASK          1
    #define ICGFLTL_FILT1_MASK          2
    #define ICGFLTL_FILT2_MASK          4
    #define ICGFLTL_FILT3_MASK          8
    #define ICGFLTL_FILT4_MASK          16
    #define ICGFLTL_FILT5_MASK          32
    #define ICGFLTL_FILT6_MASK          64
    #define ICGFLTL_FILT7_MASK          128

  } Overlap_STR;

} ICGFLTSTR;
extern volatile ICGFLTSTR _ICGFLT @0x0000003C;
#define ICGFLT                          _ICGFLT.Word



/*** ICGTRM - ICG Trim Register; 0x0000003E ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* ICG Trim Bit 0 */
    byte TRIM1       :1;                                       /* ICG Trim Bit 1 */
    byte TRIM2       :1;                                       /* ICG Trim Bit 2 */
    byte TRIM3       :1;                                       /* ICG Trim Bit 3 */
    byte TRIM4       :1;                                       /* ICG Trim Bit 4 */
    byte TRIM5       :1;                                       /* ICG Trim Bit 5 */
    byte TRIM6       :1;                                       /* ICG Trim Bit 6 */
    byte TRIM7       :1;                                       /* ICG Trim Bit 7 */
  } Bits;
} ICGTRMSTR;
extern volatile ICGTRMSTR _ICGTRM @0x0000003E;
#define ICGTRM                          _ICGTRM.Byte
#define ICGTRM_TRIM0                    _ICGTRM.Bits.TRIM0
#define ICGTRM_TRIM1                    _ICGTRM.Bits.TRIM1
#define ICGTRM_TRIM2                    _ICGTRM.Bits.TRIM2
#define ICGTRM_TRIM3                    _ICGTRM.Bits.TRIM3
#define ICGTRM_TRIM4                    _ICGTRM.Bits.TRIM4
#define ICGTRM_TRIM5                    _ICGTRM.Bits.TRIM5
#define ICGTRM_TRIM6                    _ICGTRM.Bits.TRIM6
#define ICGTRM_TRIM7                    _ICGTRM.Bits.TRIM7

#define ICGTRM_TRIM0_MASK               1
#define ICGTRM_TRIM1_MASK               2
#define ICGTRM_TRIM2_MASK               4
#define ICGTRM_TRIM3_MASK               8
#define ICGTRM_TRIM4_MASK               16
#define ICGTRM_TRIM5_MASK               32
#define ICGTRM_TRIM6_MASK               64
#define ICGTRM_TRIM7_MASK               128


/*** TPM1SC - TPM 1 Status and Control Register; 0x00000040 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1SCSTR;
extern volatile TPM1SCSTR _TPM1SC @0x00000040;
#define TPM1SC                          _TPM1SC.Byte
#define TPM1SC_PS0                      _TPM1SC.Bits.PS0
#define TPM1SC_PS1                      _TPM1SC.Bits.PS1
#define TPM1SC_PS2                      _TPM1SC.Bits.PS2
#define TPM1SC_CLKSA                    _TPM1SC.Bits.CLKSA
#define TPM1SC_CLKSB                    _TPM1SC.Bits.CLKSB
#define TPM1SC_CPWMS                    _TPM1SC.Bits.CPWMS
#define TPM1SC_TOIE                     _TPM1SC.Bits.TOIE
#define TPM1SC_TOF                      _TPM1SC.Bits.TOF
#define TPM1SC_PS                       _TPM1SC.MergedBits.grpPS
#define TPM1SC_CLKSx                    _TPM1SC.MergedBits.grpCLKSx

#define TPM1SC_PS0_MASK                 1
#define TPM1SC_PS1_MASK                 2
#define TPM1SC_PS2_MASK                 4
#define TPM1SC_CLKSA_MASK               8
#define TPM1SC_CLKSB_MASK               16
#define TPM1SC_CPWMS_MASK               32
#define TPM1SC_TOIE_MASK                64
#define TPM1SC_TOF_MASK                 128
#define TPM1SC_PS_MASK                  7
#define TPM1SC_PS_BITNUM                0
#define TPM1SC_CLKSx_MASK               24
#define TPM1SC_CLKSx_BITNUM             3


/*** TPM1CNT - TPM 1 Counter Register; 0x00000041 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1CNTH - TPM 1 Counter Register High; 0x00000041 ***/
    union {
      byte Byte;
    } TPM1CNTHSTR;
    #define TPM1CNTH                    _TPM1CNT.Overlap_STR.TPM1CNTHSTR.Byte
    
    


    /*** TPM1CNTL - TPM 1 Counter Register Low; 0x00000042 ***/
    union {
      byte Byte;
    } TPM1CNTLSTR;
    #define TPM1CNTL                    _TPM1CNT.Overlap_STR.TPM1CNTLSTR.Byte
    
    

  } Overlap_STR;

} TPM1CNTSTR;
extern volatile TPM1CNTSTR _TPM1CNT @0x00000041;
#define TPM1CNT                         _TPM1CNT.Word



/*** TPM1MOD - TPM 1 Timer Counter Modulo Register; 0x00000043 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1MODH - TPM 1 Timer Counter Modulo Register High; 0x00000043 ***/
    union {
      byte Byte;
    } TPM1MODHSTR;
    #define TPM1MODH                    _TPM1MOD.Overlap_STR.TPM1MODHSTR.Byte
    
    


    /*** TPM1MODL - TPM 1 Timer Counter Modulo Register Low; 0x00000044 ***/
    union {
      byte Byte;
    } TPM1MODLSTR;
    #define TPM1MODL                    _TPM1MOD.Overlap_STR.TPM1MODLSTR.Byte
    
    

  } Overlap_STR;

} TPM1MODSTR;
extern volatile TPM1MODSTR _TPM1MOD @0x00000043;
#define TPM1MOD                         _TPM1MOD.Word



/*** TPM1C0SC - TPM 1 Timer Channel 0 Status and Control Register; 0x00000045 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C0SCSTR;
extern volatile TPM1C0SCSTR _TPM1C0SC @0x00000045;
#define TPM1C0SC                        _TPM1C0SC.Byte
#define TPM1C0SC_ELS0A                  _TPM1C0SC.Bits.ELS0A
#define TPM1C0SC_ELS0B                  _TPM1C0SC.Bits.ELS0B
#define TPM1C0SC_MS0A                   _TPM1C0SC.Bits.MS0A
#define TPM1C0SC_MS0B                   _TPM1C0SC.Bits.MS0B
#define TPM1C0SC_CH0IE                  _TPM1C0SC.Bits.CH0IE
#define TPM1C0SC_CH0F                   _TPM1C0SC.Bits.CH0F
#define TPM1C0SC_ELS0x                  _TPM1C0SC.MergedBits.grpELS0x
#define TPM1C0SC_MS0x                   _TPM1C0SC.MergedBits.grpMS0x

#define TPM1C0SC_ELS0A_MASK             4
#define TPM1C0SC_ELS0B_MASK             8
#define TPM1C0SC_MS0A_MASK              16
#define TPM1C0SC_MS0B_MASK              32
#define TPM1C0SC_CH0IE_MASK             64
#define TPM1C0SC_CH0F_MASK              128
#define TPM1C0SC_ELS0x_MASK             12
#define TPM1C0SC_ELS0x_BITNUM           2
#define TPM1C0SC_MS0x_MASK              48
#define TPM1C0SC_MS0x_BITNUM            4


/*** TPM1C0V - TPM 1 Timer Channel 0 Value Register; 0x00000046 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C0VH - TPM 1 Timer Channel 0 Value Register High; 0x00000046 ***/
    union {
      byte Byte;
    } TPM1C0VHSTR;
    #define TPM1C0VH                    _TPM1C0V.Overlap_STR.TPM1C0VHSTR.Byte
    
    


    /*** TPM1C0VL - TPM 1 Timer Channel 0 Value Register Low; 0x00000047 ***/
    union {
      byte Byte;
    } TPM1C0VLSTR;
    #define TPM1C0VL                    _TPM1C0V.Overlap_STR.TPM1C0VLSTR.Byte
    
    

  } Overlap_STR;

} TPM1C0VSTR;
extern volatile TPM1C0VSTR _TPM1C0V @0x00000046;
#define TPM1C0V                         _TPM1C0V.Word



/*** TPM1C1SC - TPM 1 Timer Channel 1 Status and Control Register; 0x00000048 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for TPM Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for TPM Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C1SCSTR;
extern volatile TPM1C1SCSTR _TPM1C1SC @0x00000048;
#define TPM1C1SC                        _TPM1C1SC.Byte
#define TPM1C1SC_ELS1A                  _TPM1C1SC.Bits.ELS1A
#define TPM1C1SC_ELS1B                  _TPM1C1SC.Bits.ELS1B
#define TPM1C1SC_MS1A                   _TPM1C1SC.Bits.MS1A
#define TPM1C1SC_MS1B                   _TPM1C1SC.Bits.MS1B
#define TPM1C1SC_CH1IE                  _TPM1C1SC.Bits.CH1IE
#define TPM1C1SC_CH1F                   _TPM1C1SC.Bits.CH1F
#define TPM1C1SC_ELS1x                  _TPM1C1SC.MergedBits.grpELS1x
#define TPM1C1SC_MS1x                   _TPM1C1SC.MergedBits.grpMS1x

#define TPM1C1SC_ELS1A_MASK             4
#define TPM1C1SC_ELS1B_MASK             8
#define TPM1C1SC_MS1A_MASK              16
#define TPM1C1SC_MS1B_MASK              32
#define TPM1C1SC_CH1IE_MASK             64
#define TPM1C1SC_CH1F_MASK              128
#define TPM1C1SC_ELS1x_MASK             12
#define TPM1C1SC_ELS1x_BITNUM           2
#define TPM1C1SC_MS1x_MASK              48
#define TPM1C1SC_MS1x_BITNUM            4


/*** TPM1C1V - TPM 1 Timer Channel 1 Value Register; 0x00000049 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C1VH - TPM 1 Timer Channel 1 Value Register High; 0x00000049 ***/
    union {
      byte Byte;
    } TPM1C1VHSTR;
    #define TPM1C1VH                    _TPM1C1V.Overlap_STR.TPM1C1VHSTR.Byte
    
    


    /*** TPM1C1VL - TPM 1 Timer Channel 1 Value Register Low; 0x0000004A ***/
    union {
      byte Byte;
    } TPM1C1VLSTR;
    #define TPM1C1VL                    _TPM1C1V.Overlap_STR.TPM1C1VLSTR.Byte
    
    

  } Overlap_STR;

} TPM1C1VSTR;
extern volatile TPM1C1VSTR _TPM1C1V @0x00000049;
#define TPM1C1V                         _TPM1C1V.Word



/*** TPM2SC - TPM 2 Status and Control Register; 0x00000050 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2SCSTR;
extern volatile TPM2SCSTR _TPM2SC @0x00000050;
#define TPM2SC                          _TPM2SC.Byte
#define TPM2SC_PS0                      _TPM2SC.Bits.PS0
#define TPM2SC_PS1                      _TPM2SC.Bits.PS1
#define TPM2SC_PS2                      _TPM2SC.Bits.PS2
#define TPM2SC_CLKSA                    _TPM2SC.Bits.CLKSA
#define TPM2SC_CLKSB                    _TPM2SC.Bits.CLKSB
#define TPM2SC_CPWMS                    _TPM2SC.Bits.CPWMS
#define TPM2SC_TOIE                     _TPM2SC.Bits.TOIE
#define TPM2SC_TOF                      _TPM2SC.Bits.TOF
#define TPM2SC_PS                       _TPM2SC.MergedBits.grpPS
#define TPM2SC_CLKSx                    _TPM2SC.MergedBits.grpCLKSx

#define TPM2SC_PS0_MASK                 1
#define TPM2SC_PS1_MASK                 2
#define TPM2SC_PS2_MASK                 4
#define TPM2SC_CLKSA_MASK               8
#define TPM2SC_CLKSB_MASK               16
#define TPM2SC_CPWMS_MASK               32
#define TPM2SC_TOIE_MASK                64
#define TPM2SC_TOF_MASK                 128
#define TPM2SC_PS_MASK                  7
#define TPM2SC_PS_BITNUM                0
#define TPM2SC_CLKSx_MASK               24
#define TPM2SC_CLKSx_BITNUM             3


/*** TPM2CNT - TPM 2 Counter Register; 0x00000051 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2CNTH - TPM 2 Counter Register High; 0x00000051 ***/
    union {
      byte Byte;
    } TPM2CNTHSTR;
    #define TPM2CNTH                    _TPM2CNT.Overlap_STR.TPM2CNTHSTR.Byte
    
    


    /*** TPM2CNTL - TPM 2 Counter Register Low; 0x00000052 ***/
    union {
      byte Byte;
    } TPM2CNTLSTR;
    #define TPM2CNTL                    _TPM2CNT.Overlap_STR.TPM2CNTLSTR.Byte
    
    

  } Overlap_STR;

} TPM2CNTSTR;
extern volatile TPM2CNTSTR _TPM2CNT @0x00000051;
#define TPM2CNT                         _TPM2CNT.Word



/*** TPM2MOD - TPM 2 Timer Counter Modulo Register; 0x00000053 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2MODH - TPM 2 Timer Counter Modulo Register High; 0x00000053 ***/
    union {
      byte Byte;
    } TPM2MODHSTR;
    #define TPM2MODH                    _TPM2MOD.Overlap_STR.TPM2MODHSTR.Byte
    
    


    /*** TPM2MODL - TPM 2 Timer Counter Modulo Register Low; 0x00000054 ***/
    union {
      byte Byte;
    } TPM2MODLSTR;
    #define TPM2MODL                    _TPM2MOD.Overlap_STR.TPM2MODLSTR.Byte
    
    

  } Overlap_STR;

} TPM2MODSTR;
extern volatile TPM2MODSTR _TPM2MOD @0x00000053;
#define TPM2MOD                         _TPM2MOD.Word



/*** TPM2C0SC - TPM 2 Timer Channel 0 Status and Control Register; 0x00000055 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C0SCSTR;
extern volatile TPM2C0SCSTR _TPM2C0SC @0x00000055;
#define TPM2C0SC                        _TPM2C0SC.Byte
#define TPM2C0SC_ELS0A                  _TPM2C0SC.Bits.ELS0A
#define TPM2C0SC_ELS0B                  _TPM2C0SC.Bits.ELS0B
#define TPM2C0SC_MS0A                   _TPM2C0SC.Bits.MS0A
#define TPM2C0SC_MS0B                   _TPM2C0SC.Bits.MS0B
#define TPM2C0SC_CH0IE                  _TPM2C0SC.Bits.CH0IE
#define TPM2C0SC_CH0F                   _TPM2C0SC.Bits.CH0F
#define TPM2C0SC_ELS0x                  _TPM2C0SC.MergedBits.grpELS0x
#define TPM2C0SC_MS0x                   _TPM2C0SC.MergedBits.grpMS0x

#define TPM2C0SC_ELS0A_MASK             4
#define TPM2C0SC_ELS0B_MASK             8
#define TPM2C0SC_MS0A_MASK              16
#define TPM2C0SC_MS0B_MASK              32
#define TPM2C0SC_CH0IE_MASK             64
#define TPM2C0SC_CH0F_MASK              128
#define TPM2C0SC_ELS0x_MASK             12
#define TPM2C0SC_ELS0x_BITNUM           2
#define TPM2C0SC_MS0x_MASK              48
#define TPM2C0SC_MS0x_BITNUM            4


/*** TPM2C0V - TPM 2 Timer Channel 0 Value Register; 0x00000056 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C0VH - TPM 2 Timer Channel 0 Value Register High; 0x00000056 ***/
    union {
      byte Byte;
    } TPM2C0VHSTR;
    #define TPM2C0VH                    _TPM2C0V.Overlap_STR.TPM2C0VHSTR.Byte
    
    


    /*** TPM2C0VL - TPM 2 Timer Channel 0 Value Register Low; 0x00000057 ***/
    union {
      byte Byte;
    } TPM2C0VLSTR;
    #define TPM2C0VL                    _TPM2C0V.Overlap_STR.TPM2C0VLSTR.Byte
    
    

  } Overlap_STR;

} TPM2C0VSTR;
extern volatile TPM2C0VSTR _TPM2C0V @0x00000056;
#define TPM2C0V                         _TPM2C0V.Word



/*** TPM2C1SC - TPM 2 Timer Channel 1 Status and Control Register; 0x00000058 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for TPM Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for TPM Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C1SCSTR;
extern volatile TPM2C1SCSTR _TPM2C1SC @0x00000058;
#define TPM2C1SC                        _TPM2C1SC.Byte
#define TPM2C1SC_ELS1A                  _TPM2C1SC.Bits.ELS1A
#define TPM2C1SC_ELS1B                  _TPM2C1SC.Bits.ELS1B
#define TPM2C1SC_MS1A                   _TPM2C1SC.Bits.MS1A
#define TPM2C1SC_MS1B                   _TPM2C1SC.Bits.MS1B
#define TPM2C1SC_CH1IE                  _TPM2C1SC.Bits.CH1IE
#define TPM2C1SC_CH1F                   _TPM2C1SC.Bits.CH1F
#define TPM2C1SC_ELS1x                  _TPM2C1SC.MergedBits.grpELS1x
#define TPM2C1SC_MS1x                   _TPM2C1SC.MergedBits.grpMS1x

#define TPM2C1SC_ELS1A_MASK             4
#define TPM2C1SC_ELS1B_MASK             8
#define TPM2C1SC_MS1A_MASK              16
#define TPM2C1SC_MS1B_MASK              32
#define TPM2C1SC_CH1IE_MASK             64
#define TPM2C1SC_CH1F_MASK              128
#define TPM2C1SC_ELS1x_MASK             12
#define TPM2C1SC_ELS1x_BITNUM           2
#define TPM2C1SC_MS1x_MASK              48
#define TPM2C1SC_MS1x_BITNUM            4


/*** TPM2C1V - TPM 2 Timer Channel 1 Value Register; 0x00000059 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C1VH - TPM 2 Timer Channel 1 Value Register High; 0x00000059 ***/
    union {
      byte Byte;
    } TPM2C1VHSTR;
    #define TPM2C1VH                    _TPM2C1V.Overlap_STR.TPM2C1VHSTR.Byte
    
    


    /*** TPM2C1VL - TPM 2 Timer Channel 1 Value Register Low; 0x0000005A ***/
    union {
      byte Byte;
    } TPM2C1VLSTR;
    #define TPM2C1VL                    _TPM2C1V.Overlap_STR.TPM2C1VLSTR.Byte
    
    

  } Overlap_STR;

} TPM2C1VSTR;
extern volatile TPM2C1VSTR _TPM2C1V @0x00000059;
#define TPM2C1V                         _TPM2C1V.Word



/*** SRS - System Reset Status; 0x00001800 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LVD         :1;                                       /* Low Voltage Detect */
    byte ICG         :1;                                       /* Internal Clock Generation Module Reset */
    byte             :1; 
    byte ILOP        :1;                                       /* Illegal Opcode */
    byte COP         :1;                                       /* Computer Operating Properly (COP) Watchdog */
    byte PIN         :1;                                       /* External Reset Pin */
    byte POR         :1;                                       /* Power-On Reset */
  } Bits;
} SRSSTR;
extern volatile SRSSTR _SRS @0x00001800;
#define SRS                             _SRS.Byte
#define SRS_LVD                         _SRS.Bits.LVD
#define SRS_ICG                         _SRS.Bits.ICG
#define SRS_ILOP                        _SRS.Bits.ILOP
#define SRS_COP                         _SRS.Bits.COP
#define SRS_PIN                         _SRS.Bits.PIN
#define SRS_POR                         _SRS.Bits.POR

#define SRS_LVD_MASK                    2
#define SRS_ICG_MASK                    4
#define SRS_ILOP_MASK                   16
#define SRS_COP_MASK                    32
#define SRS_PIN_MASK                    64
#define SRS_POR_MASK                    128


/*** SBDFR - System Background Debug Force Reset Register; 0x00001801 ***/
typedef union {
  byte Byte;
  struct {
    byte BDFR        :1;                                       /* Background Debug Force Reset */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SBDFRSTR;
extern volatile SBDFRSTR _SBDFR @0x00001801;
#define SBDFR                           _SBDFR.Byte
#define SBDFR_BDFR                      _SBDFR.Bits.BDFR

#define SBDFR_BDFR_MASK                 1


/*** SOPT1 - System Options Register 1; 0x00001802 ***/
typedef union {
  byte Byte;
  struct {
    byte RSTPE       :1;                                       /* Reset Pin Enable */
    byte BKGDPE      :1;                                       /* Background Debug Mode Pin Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte STOPE       :1;                                       /* Stop Mode Enable */
    byte COPT        :1;                                       /* COP Watchdog Timeout */
    byte COPE        :1;                                       /* COP Watchdog Enable */
  } Bits;
} SOPT1STR;
extern volatile SOPT1STR _SOPT1 @0x00001802;
#define SOPT1                           _SOPT1.Byte
#define SOPT1_RSTPE                     _SOPT1.Bits.RSTPE
#define SOPT1_BKGDPE                    _SOPT1.Bits.BKGDPE
#define SOPT1_STOPE                     _SOPT1.Bits.STOPE
#define SOPT1_COPT                      _SOPT1.Bits.COPT
#define SOPT1_COPE                      _SOPT1.Bits.COPE

#define SOPT1_RSTPE_MASK                1
#define SOPT1_BKGDPE_MASK               2
#define SOPT1_STOPE_MASK                32
#define SOPT1_COPT_MASK                 64
#define SOPT1_COPE_MASK                 128


/*** SOPT2 - System Options Register 2; 0x00001803 ***/
typedef union {
  byte Byte;
  struct {
    byte ACIC        :1;                                       /* Analog Comparator to Input Capture Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte COPCLKS     :1;                                       /* COP Watchdog Clock Select */
  } Bits;
} SOPT2STR;
extern volatile SOPT2STR _SOPT2 @0x00001803;
#define SOPT2                           _SOPT2.Byte
#define SOPT2_ACIC                      _SOPT2.Bits.ACIC
#define SOPT2_COPCLKS                   _SOPT2.Bits.COPCLKS

#define SOPT2_ACIC_MASK                 1
#define SOPT2_COPCLKS_MASK              128


/*** SDID - System Integration Module Part ID Register; 0x00001806 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SDIDH - System Integration Module Part ID Register High; 0x00001806 ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part Identification Number 8 */
        byte ID9         :1;                                       /* Part Identification Number 9 */
        byte ID10        :1;                                       /* Part Identification Number 10 */
        byte ID11        :1;                                       /* Part Identification Number 11 */
        byte REV0        :1;                                       /* Revision Number 0 */
        byte REV1        :1;                                       /* Revision Number 1 */
        byte REV2        :1;                                       /* Revision Number 2 */
        byte REV3        :1;                                       /* Revision Number 3 */
      } Bits;
      struct {
        byte grpID_8 :4;
        byte grpREV :4;
      } MergedBits;
    } SDIDHSTR;
    #define SDIDH                       _SDID.Overlap_STR.SDIDHSTR.Byte
    #define SDIDH_ID8                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID8
    #define SDIDH_ID9                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID9
    #define SDIDH_ID10                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID10
    #define SDIDH_ID11                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID11
    #define SDIDH_REV0                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV0
    #define SDIDH_REV1                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV1
    #define SDIDH_REV2                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV2
    #define SDIDH_REV3                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV3
    
    #define SDIDH_ID_8                  _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpID_8
    #define SDIDH_REV                   _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpREV
    #define SDIDH_ID                    SDIDH_ID_8
    
    #define SDIDH_ID8_MASK              1
    #define SDIDH_ID9_MASK              2
    #define SDIDH_ID10_MASK             4
    #define SDIDH_ID11_MASK             8
    #define SDIDH_REV0_MASK             16
    #define SDIDH_REV1_MASK             32
    #define SDIDH_REV2_MASK             64
    #define SDIDH_REV3_MASK             128
    #define SDIDH_ID_8_MASK             15
    #define SDIDH_ID_8_BITNUM           0
    #define SDIDH_REV_MASK              240
    #define SDIDH_REV_BITNUM            4


    /*** SDIDL - System Integration Module Part ID Register Low; 0x00001807 ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part Identification Number 0 */
        byte ID1         :1;                                       /* Part Identification Number 1 */
        byte ID2         :1;                                       /* Part Identification Number 2 */
        byte ID3         :1;                                       /* Part Identification Number 3 */
        byte ID4         :1;                                       /* Part Identification Number 4 */
        byte ID5         :1;                                       /* Part Identification Number 5 */
        byte ID6         :1;                                       /* Part Identification Number 6 */
        byte ID7         :1;                                       /* Part Identification Number 7 */
      } Bits;
    } SDIDLSTR;
    #define SDIDL                       _SDID.Overlap_STR.SDIDLSTR.Byte
    #define SDIDL_ID0                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID0
    #define SDIDL_ID1                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID1
    #define SDIDL_ID2                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID2
    #define SDIDL_ID3                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID3
    #define SDIDL_ID4                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID4
    #define SDIDL_ID5                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID5
    #define SDIDL_ID6                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID6
    #define SDIDL_ID7                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID7
    
    
    #define SDIDL_ID0_MASK              1
    #define SDIDL_ID1_MASK              2
    #define SDIDL_ID2_MASK              4
    #define SDIDL_ID3_MASK              8
    #define SDIDL_ID4_MASK              16
    #define SDIDL_ID5_MASK              32
    #define SDIDL_ID6_MASK              64
    #define SDIDL_ID7_MASK              128

  } Overlap_STR;

} SDIDSTR;
extern volatile SDIDSTR _SDID @0x00001806;
#define SDID                            _SDID.Word



/*** SRTISC - System RTI Status and Control Register; 0x00001808 ***/
typedef union {
  byte Byte;
  struct {
    byte RTIS0       :1;                                       /* Real-Time Interrupt Delay Select Bit 0 */
    byte RTIS1       :1;                                       /* Real-Time Interrupt Delay Select Bit 1 */
    byte RTIS2       :1;                                       /* Real-Time Interrupt Delay Select Bit 2 */
    byte             :1; 
    byte RTIE        :1;                                       /* Real-Time Interrupt Enable */
    byte RTICLKS     :1;                                       /* Real-Time Interrupt Clock Select */
    byte RTIACK      :1;                                       /* Real-Time Interrupt Acknowledge */
    byte RTIF        :1;                                       /* Real-Time Interrupt Flag */
  } Bits;
  struct {
    byte grpRTIS :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SRTISCSTR;
extern volatile SRTISCSTR _SRTISC @0x00001808;
#define SRTISC                          _SRTISC.Byte
#define SRTISC_RTIS0                    _SRTISC.Bits.RTIS0
#define SRTISC_RTIS1                    _SRTISC.Bits.RTIS1
#define SRTISC_RTIS2                    _SRTISC.Bits.RTIS2
#define SRTISC_RTIE                     _SRTISC.Bits.RTIE
#define SRTISC_RTICLKS                  _SRTISC.Bits.RTICLKS
#define SRTISC_RTIACK                   _SRTISC.Bits.RTIACK
#define SRTISC_RTIF                     _SRTISC.Bits.RTIF
#define SRTISC_RTIS                     _SRTISC.MergedBits.grpRTIS

#define SRTISC_RTIS0_MASK               1
#define SRTISC_RTIS1_MASK               2
#define SRTISC_RTIS2_MASK               4
#define SRTISC_RTIE_MASK                16
#define SRTISC_RTICLKS_MASK             32
#define SRTISC_RTIACK_MASK              64
#define SRTISC_RTIF_MASK                128
#define SRTISC_RTIS_MASK                7
#define SRTISC_RTIS_BITNUM              0


/*** SPMSC1 - System Power Management Status and Control 1 Register; 0x00001809 ***/
typedef union {
  byte Byte;
  struct {
    byte BGBE        :1;                                       /* Bandgap Buffer Enable */
    byte             :1; 
    byte LVDE        :1;                                       /* Low-Voltage Detect Enable */
    byte LVDSE       :1;                                       /* Low-Voltage Detect Stop Enable */
    byte LVDRE       :1;                                       /* Low-Voltage Detect Reset Enable */
    byte LVDIE       :1;                                       /* Low-Voltage Detect Interrrupt Enable */
    byte LVDACK      :1;                                       /* Low-Voltage Detect Acknowledge */
    byte LVDF        :1;                                       /* Low-Voltage Detect Flag */
  } Bits;
} SPMSC1STR;
extern volatile SPMSC1STR _SPMSC1 @0x00001809;
#define SPMSC1                          _SPMSC1.Byte
#define SPMSC1_BGBE                     _SPMSC1.Bits.BGBE
#define SPMSC1_LVDE                     _SPMSC1.Bits.LVDE
#define SPMSC1_LVDSE                    _SPMSC1.Bits.LVDSE
#define SPMSC1_LVDRE                    _SPMSC1.Bits.LVDRE
#define SPMSC1_LVDIE                    _SPMSC1.Bits.LVDIE
#define SPMSC1_LVDACK                   _SPMSC1.Bits.LVDACK
#define SPMSC1_LVDF                     _SPMSC1.Bits.LVDF

#define SPMSC1_BGBE_MASK                1
#define SPMSC1_LVDE_MASK                4
#define SPMSC1_LVDSE_MASK               8
#define SPMSC1_LVDRE_MASK               16
#define SPMSC1_LVDIE_MASK               32
#define SPMSC1_LVDACK_MASK              64
#define SPMSC1_LVDF_MASK                128


/*** SPMSC2 - System Power Management Status and Control 2 Register; 0x0000180A ***/
typedef union {
  byte Byte;
  struct {
    byte PPDC        :1;                                       /* Partial Power Down Control */
    byte PDC         :1;                                       /* Power Down Control */
    byte PPDACK      :1;                                       /* Partial Power Down Acknowledge */
    byte PPDF        :1;                                       /* Partial Power Down Flag */
    byte PDF         :1;                                       /* Power Down Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SPMSC2STR;
extern volatile SPMSC2STR _SPMSC2 @0x0000180A;
#define SPMSC2                          _SPMSC2.Byte
#define SPMSC2_PPDC                     _SPMSC2.Bits.PPDC
#define SPMSC2_PDC                      _SPMSC2.Bits.PDC
#define SPMSC2_PPDACK                   _SPMSC2.Bits.PPDACK
#define SPMSC2_PPDF                     _SPMSC2.Bits.PPDF
#define SPMSC2_PDF                      _SPMSC2.Bits.PDF

#define SPMSC2_PPDC_MASK                1
#define SPMSC2_PDC_MASK                 2
#define SPMSC2_PPDACK_MASK              4
#define SPMSC2_PPDF_MASK                8
#define SPMSC2_PDF_MASK                 16


/*** SPMSC3 - System Power Management Status and Control 3 Register; 0x0000180C ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LVWV        :1;                                       /* Low-Voltage Warning Voltage Select */
    byte LVDV        :1;                                       /* Low-Voltage Detect Voltage Select */
    byte LVWACK      :1;                                       /* Low-Voltage Warning Acknowledge */
    byte LVWF        :1;                                       /* Low-Voltage Warning Flag */
  } Bits;
} SPMSC3STR;
extern volatile SPMSC3STR _SPMSC3 @0x0000180C;
#define SPMSC3                          _SPMSC3.Byte
#define SPMSC3_LVWV                     _SPMSC3.Bits.LVWV
#define SPMSC3_LVDV                     _SPMSC3.Bits.LVDV
#define SPMSC3_LVWACK                   _SPMSC3.Bits.LVWACK
#define SPMSC3_LVWF                     _SPMSC3.Bits.LVWF

#define SPMSC3_LVWV_MASK                16
#define SPMSC3_LVDV_MASK                32
#define SPMSC3_LVWACK_MASK              64
#define SPMSC3_LVWF_MASK                128


/*** DBGCAH - Debug Comparator A High Register; 0x00001810 ***/
typedef union {
  byte Byte;
  struct {
    byte Bit8        :1;                                       /* Debug Comparator A Bit 8 */
    byte Bit9        :1;                                       /* Debug Comparator A Bit 9 */
    byte Bit10       :1;                                       /* Debug Comparator A Bit 10 */
    byte Bit11       :1;                                       /* Debug Comparator A Bit 11 */
    byte Bit12       :1;                                       /* Debug Comparator A Bit 12 */
    byte Bit13       :1;                                       /* Debug Comparator A Bit 13 */
    byte Bit14       :1;                                       /* Debug Comparator A Bit 14 */
    byte Bit15       :1;                                       /* Debug Comparator A Bit 15 */
  } Bits;
} DBGCAHSTR;
extern volatile DBGCAHSTR _DBGCAH @0x00001810;
#define DBGCAH                          _DBGCAH.Byte
#define DBGCAH_Bit8                     _DBGCAH.Bits.Bit8
#define DBGCAH_Bit9                     _DBGCAH.Bits.Bit9
#define DBGCAH_Bit10                    _DBGCAH.Bits.Bit10
#define DBGCAH_Bit11                    _DBGCAH.Bits.Bit11
#define DBGCAH_Bit12                    _DBGCAH.Bits.Bit12
#define DBGCAH_Bit13                    _DBGCAH.Bits.Bit13
#define DBGCAH_Bit14                    _DBGCAH.Bits.Bit14
#define DBGCAH_Bit15                    _DBGCAH.Bits.Bit15

#define DBGCAH_Bit8_MASK                1
#define DBGCAH_Bit9_MASK                2
#define DBGCAH_Bit10_MASK               4
#define DBGCAH_Bit11_MASK               8
#define DBGCAH_Bit12_MASK               16
#define DBGCAH_Bit13_MASK               32
#define DBGCAH_Bit14_MASK               64
#define DBGCAH_Bit15_MASK               128


/*** DBGCAL - Debug Comparator A Low Register; 0x00001811 ***/
typedef union {
  byte Byte;
  struct {
    byte Bit0        :1;                                       /* Debug Comparator A Bit 0 */
    byte Bit1        :1;                                       /* Debug Comparator A Bit 1 */
    byte Bit2        :1;                                       /* Debug Comparator A Bit 2 */
    byte Bit3        :1;                                       /* Debug Comparator A Bit 3 */
    byte Bit4        :1;                                       /* Debug Comparator A Bit 4 */
    byte Bit5        :1;                                       /* Debug Comparator A Bit 5 */
    byte Bit6        :1;                                       /* Debug Comparator A Bit 6 */
    byte Bit7        :1;                                       /* Debug Comparator A Bit 7 */
  } Bits;
} DBGCALSTR;
extern volatile DBGCALSTR _DBGCAL @0x00001811;
#define DBGCAL                          _DBGCAL.Byte
#define DBGCAL_Bit0                     _DBGCAL.Bits.Bit0
#define DBGCAL_Bit1                     _DBGCAL.Bits.Bit1
#define DBGCAL_Bit2                     _DBGCAL.Bits.Bit2
#define DBGCAL_Bit3                     _DBGCAL.Bits.Bit3
#define DBGCAL_Bit4                     _DBGCAL.Bits.Bit4
#define DBGCAL_Bit5                     _DBGCAL.Bits.Bit5
#define DBGCAL_Bit6                     _DBGCAL.Bits.Bit6
#define DBGCAL_Bit7                     _DBGCAL.Bits.Bit7

#define DBGCAL_Bit0_MASK                1
#define DBGCAL_Bit1_MASK                2
#define DBGCAL_Bit2_MASK                4
#define DBGCAL_Bit3_MASK                8
#define DBGCAL_Bit4_MASK                16
#define DBGCAL_Bit5_MASK                32
#define DBGCAL_Bit6_MASK                64
#define DBGCAL_Bit7_MASK                128


/*** DBGCBH - Debug Comparator B High Register; 0x00001812 ***/
typedef union {
  byte Byte;
  struct {
    byte Bit8        :1;                                       /* Debug Comparator B Bit 8 */
    byte Bit9        :1;                                       /* Debug Comparator B Bit 9 */
    byte Bit10       :1;                                       /* Debug Comparator B Bit 10 */
    byte Bit11       :1;                                       /* Debug Comparator B Bit 11 */
    byte Bit12       :1;                                       /* Debug Comparator B Bit 12 */
    byte Bit13       :1;                                       /* Debug Comparator B Bit 13 */
    byte Bit14       :1;                                       /* Debug Comparator B Bit 14 */
    byte Bit15       :1;                                       /* Debug Comparator B Bit 15 */
  } Bits;
} DBGCBHSTR;
extern volatile DBGCBHSTR _DBGCBH @0x00001812;
#define DBGCBH                          _DBGCBH.Byte
#define DBGCBH_Bit8                     _DBGCBH.Bits.Bit8
#define DBGCBH_Bit9                     _DBGCBH.Bits.Bit9
#define DBGCBH_Bit10                    _DBGCBH.Bits.Bit10
#define DBGCBH_Bit11                    _DBGCBH.Bits.Bit11
#define DBGCBH_Bit12                    _DBGCBH.Bits.Bit12
#define DBGCBH_Bit13                    _DBGCBH.Bits.Bit13
#define DBGCBH_Bit14                    _DBGCBH.Bits.Bit14
#define DBGCBH_Bit15                    _DBGCBH.Bits.Bit15

#define DBGCBH_Bit8_MASK                1
#define DBGCBH_Bit9_MASK                2
#define DBGCBH_Bit10_MASK               4
#define DBGCBH_Bit11_MASK               8
#define DBGCBH_Bit12_MASK               16
#define DBGCBH_Bit13_MASK               32
#define DBGCBH_Bit14_MASK               64
#define DBGCBH_Bit15_MASK               128


/*** DBGCBL - Debug Comparator B Low Register; 0x00001813 ***/
typedef union {
  byte Byte;
  struct {
    byte Bit0        :1;                                       /* Debug Comparator B Bit 0 */
    byte Bit1        :1;                                       /* Debug Comparator B Bit 1 */
    byte Bit2        :1;                                       /* Debug Comparator B Bit 2 */
    byte Bit3        :1;                                       /* Debug Comparator B Bit 3 */
    byte Bit4        :1;                                       /* Debug Comparator B Bit 4 */
    byte Bit5        :1;                                       /* Debug Comparator B Bit 5 */
    byte Bit6        :1;                                       /* Debug Comparator B Bit 6 */
    byte Bit7        :1;                                       /* Debug Comparator B Bit 7 */
  } Bits;
} DBGCBLSTR;
extern volatile DBGCBLSTR _DBGCBL @0x00001813;
#define DBGCBL                          _DBGCBL.Byte
#define DBGCBL_Bit0                     _DBGCBL.Bits.Bit0
#define DBGCBL_Bit1                     _DBGCBL.Bits.Bit1
#define DBGCBL_Bit2                     _DBGCBL.Bits.Bit2
#define DBGCBL_Bit3                     _DBGCBL.Bits.Bit3
#define DBGCBL_Bit4                     _DBGCBL.Bits.Bit4
#define DBGCBL_Bit5                     _DBGCBL.Bits.Bit5
#define DBGCBL_Bit6                     _DBGCBL.Bits.Bit6
#define DBGCBL_Bit7                     _DBGCBL.Bits.Bit7

#define DBGCBL_Bit0_MASK                1
#define DBGCBL_Bit1_MASK                2
#define DBGCBL_Bit2_MASK                4
#define DBGCBL_Bit3_MASK                8
#define DBGCBL_Bit4_MASK                16
#define DBGCBL_Bit5_MASK                32
#define DBGCBL_Bit6_MASK                64
#define DBGCBL_Bit7_MASK                128


/*** DBGF - Debug FIFO Register; 0x00001814 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGFH - Debug FIFO High Register; 0x00001814 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Debug FIFO Bit 8 */
        byte Bit9        :1;                                       /* Debug FIFO Bit 9 */
        byte Bit10       :1;                                       /* Debug FIFO Bit 10 */
        byte Bit11       :1;                                       /* Debug FIFO Bit 11 */
        byte Bit12       :1;                                       /* Debug FIFO Bit 12 */
        byte Bit13       :1;                                       /* Debug FIFO Bit 13 */
        byte Bit14       :1;                                       /* Debug FIFO Bit 14 */
        byte Bit15       :1;                                       /* Debug FIFO Bit 15 */
      } Bits;
    } DBGFHSTR;
    #define DBGFH                       _DBGF.Overlap_STR.DBGFHSTR.Byte
    #define DBGFH_Bit8                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit8
    #define DBGFH_Bit9                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit9
    #define DBGFH_Bit10                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit10
    #define DBGFH_Bit11                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit11
    #define DBGFH_Bit12                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit12
    #define DBGFH_Bit13                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit13
    #define DBGFH_Bit14                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit14
    #define DBGFH_Bit15                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit15
    
    
    #define DBGFH_Bit8_MASK             1
    #define DBGFH_Bit9_MASK             2
    #define DBGFH_Bit10_MASK            4
    #define DBGFH_Bit11_MASK            8
    #define DBGFH_Bit12_MASK            16
    #define DBGFH_Bit13_MASK            32
    #define DBGFH_Bit14_MASK            64
    #define DBGFH_Bit15_MASK            128


    /*** DBGFL - Debug FIFO Low Register; 0x00001815 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Debug FIFO Bit 0 */
        byte Bit1        :1;                                       /* Debug FIFO Bit 1 */
        byte Bit2        :1;                                       /* Debug FIFO Bit 2 */
        byte Bit3        :1;                                       /* Debug FIFO Bit 3 */
        byte Bit4        :1;                                       /* Debug FIFO Bit 4 */
        byte Bit5        :1;                                       /* Debug FIFO Bit 5 */
        byte Bit6        :1;                                       /* Debug FIFO Bit 6 */
        byte Bit7        :1;                                       /* Debug FIFO Bit 7 */
      } Bits;
    } DBGFLSTR;
    #define DBGFL                       _DBGF.Overlap_STR.DBGFLSTR.Byte
    #define DBGFL_Bit0                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit0
    #define DBGFL_Bit1                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit1
    #define DBGFL_Bit2                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit2
    #define DBGFL_Bit3                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit3
    #define DBGFL_Bit4                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit4
    #define DBGFL_Bit5                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit5
    #define DBGFL_Bit6                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit6
    #define DBGFL_Bit7                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit7
    
    
    #define DBGFL_Bit0_MASK             1
    #define DBGFL_Bit1_MASK             2
    #define DBGFL_Bit2_MASK             4
    #define DBGFL_Bit3_MASK             8
    #define DBGFL_Bit4_MASK             16
    #define DBGFL_Bit5_MASK             32
    #define DBGFL_Bit6_MASK             64
    #define DBGFL_Bit7_MASK             128

  } Overlap_STR;

} DBGFSTR;
extern volatile DBGFSTR _DBGF @0x00001814;
#define DBGF                            _DBGF.Word



/*** DBGC - Debug Control Register; 0x00001816 ***/
typedef union {
  byte Byte;
  struct {
    byte RWBEN       :1;                                       /* Enable R/W for Comparator B */
    byte RWB         :1;                                       /* R/W Comparison Value for Comparator B */
    byte RWAEN       :1;                                       /* Enable R/W for Comparator A */
    byte RWA         :1;                                       /* R/W Comparison Value for Comparator A */
    byte BRKEN       :1;                                       /* Break Enable */
    byte TAG         :1;                                       /* Tag/Force Select */
    byte ARM         :1;                                       /* Arm Control */
    byte DBGEN       :1;                                       /* Debug Module Enable */
  } Bits;
} DBGCSTR;
extern volatile DBGCSTR _DBGC @0x00001816;
#define DBGC                            _DBGC.Byte
#define DBGC_RWBEN                      _DBGC.Bits.RWBEN
#define DBGC_RWB                        _DBGC.Bits.RWB
#define DBGC_RWAEN                      _DBGC.Bits.RWAEN
#define DBGC_RWA                        _DBGC.Bits.RWA
#define DBGC_BRKEN                      _DBGC.Bits.BRKEN
#define DBGC_TAG                        _DBGC.Bits.TAG
#define DBGC_ARM                        _DBGC.Bits.ARM
#define DBGC_DBGEN                      _DBGC.Bits.DBGEN

#define DBGC_RWBEN_MASK                 1
#define DBGC_RWB_MASK                   2
#define DBGC_RWAEN_MASK                 4
#define DBGC_RWA_MASK                   8
#define DBGC_BRKEN_MASK                 16
#define DBGC_TAG_MASK                   32
#define DBGC_ARM_MASK                   64
#define DBGC_DBGEN_MASK                 128


/*** DBGT - Debug Trigger Register; 0x00001817 ***/
typedef union {
  byte Byte;
  struct {
    byte TRG0        :1;                                       /* Select Trigger Mode Bit 0 */
    byte TRG1        :1;                                       /* Select Trigger Mode Bit 1 */
    byte TRG2        :1;                                       /* Select Trigger Mode Bit 2 */
    byte TRG3        :1;                                       /* Select Trigger Mode Bit 3 */
    byte             :1; 
    byte             :1; 
    byte BEGIN       :1;                                       /* Begin/End Trigger Select */
    byte TRGSEL      :1;                                       /* Trigger Type */
  } Bits;
  struct {
    byte grpTRG  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGTSTR;
extern volatile DBGTSTR _DBGT @0x00001817;
#define DBGT                            _DBGT.Byte
#define DBGT_TRG0                       _DBGT.Bits.TRG0
#define DBGT_TRG1                       _DBGT.Bits.TRG1
#define DBGT_TRG2                       _DBGT.Bits.TRG2
#define DBGT_TRG3                       _DBGT.Bits.TRG3
#define DBGT_BEGIN                      _DBGT.Bits.BEGIN
#define DBGT_TRGSEL                     _DBGT.Bits.TRGSEL
#define DBGT_TRG                        _DBGT.MergedBits.grpTRG

#define DBGT_TRG0_MASK                  1
#define DBGT_TRG1_MASK                  2
#define DBGT_TRG2_MASK                  4
#define DBGT_TRG3_MASK                  8
#define DBGT_BEGIN_MASK                 64
#define DBGT_TRGSEL_MASK                128
#define DBGT_TRG_MASK                   15
#define DBGT_TRG_BITNUM                 0


/*** DBGS - Debug Status Register; 0x00001818 ***/
typedef union {
  byte Byte;
  struct {
    byte CNT0        :1;                                       /* FIFO Valid Count Bit 0 */
    byte CNT1        :1;                                       /* FIFO Valid Count Bit 1 */
    byte CNT2        :1;                                       /* FIFO Valid Count Bit 2 */
    byte CNT3        :1;                                       /* FIFO Valid Count Bit 3 */
    byte             :1; 
    byte ARMF        :1;                                       /* Arm Flag */
    byte BF          :1;                                       /* Trigger Match B Flag */
    byte AF          :1;                                       /* Trigger Match A Flag */
  } Bits;
  struct {
    byte grpCNT  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGSSTR;
extern volatile DBGSSTR _DBGS @0x00001818;
#define DBGS                            _DBGS.Byte
#define DBGS_CNT0                       _DBGS.Bits.CNT0
#define DBGS_CNT1                       _DBGS.Bits.CNT1
#define DBGS_CNT2                       _DBGS.Bits.CNT2
#define DBGS_CNT3                       _DBGS.Bits.CNT3
#define DBGS_ARMF                       _DBGS.Bits.ARMF
#define DBGS_BF                         _DBGS.Bits.BF
#define DBGS_AF                         _DBGS.Bits.AF
#define DBGS_CNT                        _DBGS.MergedBits.grpCNT

#define DBGS_CNT0_MASK                  1
#define DBGS_CNT1_MASK                  2
#define DBGS_CNT2_MASK                  4
#define DBGS_CNT3_MASK                  8
#define DBGS_ARMF_MASK                  32
#define DBGS_BF_MASK                    64
#define DBGS_AF_MASK                    128
#define DBGS_CNT_MASK                   15
#define DBGS_CNT_BITNUM                 0


/*** FCDIV - FLASH Clock Divider Register; 0x00001820 ***/
typedef union {
  byte Byte;
  struct {
    byte DIV0        :1;                                       /* Divisor for FLASH Clock Divider Bit 0 */
    byte DIV1        :1;                                       /* Divisor for FLASH Clock Divider Bit 1 */
    byte DIV2        :1;                                       /* Divisor for FLASH Clock Divider Bit 2 */
    byte DIV3        :1;                                       /* Divisor for FLASH Clock Divider Bit 3 */
    byte DIV4        :1;                                       /* Divisor for FLASH Clock Divider Bit 4 */
    byte DIV5        :1;                                       /* Divisor for FLASH Clock Divider Bit 5 */
    byte PRDIV8      :1;                                       /* Prescale (Divide) FLASH Clock by 8 */
    byte DIVLD       :1;                                       /* Divisor Loaded Status Flag */
  } Bits;
  struct {
    byte grpDIV  :6;
    byte grpPRDIV_8 :1;
    byte         :1;
  } MergedBits;
} FCDIVSTR;
extern volatile FCDIVSTR _FCDIV @0x00001820;
#define FCDIV                           _FCDIV.Byte
#define FCDIV_DIV0                      _FCDIV.Bits.DIV0
#define FCDIV_DIV1                      _FCDIV.Bits.DIV1
#define FCDIV_DIV2                      _FCDIV.Bits.DIV2
#define FCDIV_DIV3                      _FCDIV.Bits.DIV3
#define FCDIV_DIV4                      _FCDIV.Bits.DIV4
#define FCDIV_DIV5                      _FCDIV.Bits.DIV5
#define FCDIV_PRDIV8                    _FCDIV.Bits.PRDIV8
#define FCDIV_DIVLD                     _FCDIV.Bits.DIVLD
#define FCDIV_DIV                       _FCDIV.MergedBits.grpDIV

#define FCDIV_DIV0_MASK                 1
#define FCDIV_DIV1_MASK                 2
#define FCDIV_DIV2_MASK                 4
#define FCDIV_DIV3_MASK                 8
#define FCDIV_DIV4_MASK                 16
#define FCDIV_DIV5_MASK                 32
#define FCDIV_PRDIV8_MASK               64
#define FCDIV_DIVLD_MASK                128
#define FCDIV_DIV_MASK                  63
#define FCDIV_DIV_BITNUM                0


/*** FOPT - FLASH Options Register; 0x00001821 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC00       :1;                                       /* Security State Code Bit 0 */
    byte SEC01       :1;                                       /* Security State Code Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FNORED      :1;                                       /* Vector Redirection Disable */
    byte KEYEN       :1;                                       /* Backdoor Key Mechanism Enable */
  } Bits;
  struct {
    byte grpSEC0 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FOPTSTR;
extern volatile FOPTSTR _FOPT @0x00001821;
#define FOPT                            _FOPT.Byte
#define FOPT_SEC00                      _FOPT.Bits.SEC00
#define FOPT_SEC01                      _FOPT.Bits.SEC01
#define FOPT_FNORED                     _FOPT.Bits.FNORED
#define FOPT_KEYEN                      _FOPT.Bits.KEYEN
#define FOPT_SEC0                       _FOPT.MergedBits.grpSEC0

#define FOPT_SEC00_MASK                 1
#define FOPT_SEC01_MASK                 2
#define FOPT_FNORED_MASK                64
#define FOPT_KEYEN_MASK                 128
#define FOPT_SEC0_MASK                  3
#define FOPT_SEC0_BITNUM                0


/*** FCNFG - FLASH Configuration Register; 0x00001823 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYACC      :1;                                       /* Enable Writing of Access Key */
    byte             :1; 
    byte             :1; 
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @0x00001823;
#define FCNFG                           _FCNFG.Byte
#define FCNFG_KEYACC                    _FCNFG.Bits.KEYACC

#define FCNFG_KEYACC_MASK               32


/*** FPROT - FLASH Protection Register; 0x00001824 ***/
typedef union {
  byte Byte;
  struct {
    byte FPDIS       :1;                                       /* FLASH Protection Disable */
    byte FPS1        :1;                                       /* FLASH Protect Select Bit 1 */
    byte FPS2        :1;                                       /* FLASH Protect Select Bit 2 */
    byte FPS3        :1;                                       /* FLASH Protect Select Bit 3 */
    byte FPS4        :1;                                       /* FLASH Protect Select Bit 4 */
    byte FPS5        :1;                                       /* FLASH Protect Select Bit 5 */
    byte FPS6        :1;                                       /* FLASH Protect Select Bit 6 */
    byte FPS7        :1;                                       /* FLASH Protect Select Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS_1 :7;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @0x00001824;
#define FPROT                           _FPROT.Byte
#define FPROT_FPDIS                     _FPROT.Bits.FPDIS
#define FPROT_FPS1                      _FPROT.Bits.FPS1
#define FPROT_FPS2                      _FPROT.Bits.FPS2
#define FPROT_FPS3                      _FPROT.Bits.FPS3
#define FPROT_FPS4                      _FPROT.Bits.FPS4
#define FPROT_FPS5                      _FPROT.Bits.FPS5
#define FPROT_FPS6                      _FPROT.Bits.FPS6
#define FPROT_FPS7                      _FPROT.Bits.FPS7
#define FPROT_FPS_1                     _FPROT.MergedBits.grpFPS_1
#define FPROT_FPS                       FPROT_FPS_1

#define FPROT_FPDIS_MASK                1
#define FPROT_FPS1_MASK                 2
#define FPROT_FPS2_MASK                 4
#define FPROT_FPS3_MASK                 8
#define FPROT_FPS4_MASK                 16
#define FPROT_FPS5_MASK                 32
#define FPROT_FPS6_MASK                 64
#define FPROT_FPS7_MASK                 128
#define FPROT_FPS_1_MASK                254
#define FPROT_FPS_1_BITNUM              1


/*** FSTAT - FLASH Status Register; 0x00001825 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte FBLANK      :1;                                       /* FLASH Verified as All Blank (erased) Flag */
    byte             :1; 
    byte FACCERR     :1;                                       /* Access Error Flag */
    byte FPVIOL      :1;                                       /* Protection Violation Flag */
    byte FCCF        :1;                                       /* FLASH Command Complete Flag */
    byte FCBEF       :1;                                       /* FLASH Command Buffer Empty Flag */
  } Bits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @0x00001825;
#define FSTAT                           _FSTAT.Byte
#define FSTAT_FBLANK                    _FSTAT.Bits.FBLANK
#define FSTAT_FACCERR                   _FSTAT.Bits.FACCERR
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_FCCF                      _FSTAT.Bits.FCCF
#define FSTAT_FCBEF                     _FSTAT.Bits.FCBEF

#define FSTAT_FBLANK_MASK               4
#define FSTAT_FACCERR_MASK              16
#define FSTAT_FPVIOL_MASK               32
#define FSTAT_FCCF_MASK                 64
#define FSTAT_FCBEF_MASK                128


/*** FCMD - FLASH Command Register; 0x00001826 ***/
typedef union {
  byte Byte;
  struct {
    byte FCMD0       :1;                                       /* FLASH Command Bit 0 */
    byte FCMD1       :1;                                       /* FLASH Command Bit 1 */
    byte FCMD2       :1;                                       /* FLASH Command Bit 2 */
    byte FCMD3       :1;                                       /* FLASH Command Bit 3 */
    byte FCMD4       :1;                                       /* FLASH Command Bit 4 */
    byte FCMD5       :1;                                       /* FLASH Command Bit 5 */
    byte FCMD6       :1;                                       /* FLASH Command Bit 6 */
    byte FCMD7       :1;                                       /* FLASH Command Bit 7 */
  } Bits;
} FCMDSTR;
extern volatile FCMDSTR _FCMD @0x00001826;
#define FCMD                            _FCMD.Byte
#define FCMD_FCMD0                      _FCMD.Bits.FCMD0
#define FCMD_FCMD1                      _FCMD.Bits.FCMD1
#define FCMD_FCMD2                      _FCMD.Bits.FCMD2
#define FCMD_FCMD3                      _FCMD.Bits.FCMD3
#define FCMD_FCMD4                      _FCMD.Bits.FCMD4
#define FCMD_FCMD5                      _FCMD.Bits.FCMD5
#define FCMD_FCMD6                      _FCMD.Bits.FCMD6
#define FCMD_FCMD7                      _FCMD.Bits.FCMD7

#define FCMD_FCMD0_MASK                 1
#define FCMD_FCMD1_MASK                 2
#define FCMD_FCMD2_MASK                 4
#define FCMD_FCMD3_MASK                 8
#define FCMD_FCMD4_MASK                 16
#define FCMD_FCMD5_MASK                 32
#define FCMD_FCMD6_MASK                 64
#define FCMD_FCMD7_MASK                 128


/*** PTAPE - Pullup Enable for Port A; 0x00001830 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAPE0      :1;                                       /* Pullup Enable for Port A Bit 0 */
    byte PTAPE1      :1;                                       /* Pullup Enable for Port A Bit 1 */
    byte PTAPE2      :1;                                       /* Pullup Enable for Port A Bit 2 */
    byte PTAPE3      :1;                                       /* Pullup Enable for Port A Bit 3 */
    byte PTAPE4      :1;                                       /* Pullup Enable for Port A Bit 4 */
    byte PTAPE5      :1;                                       /* Pullup Enable for Port A Bit 5 */
    byte PTAPE6      :1;                                       /* Pullup Enable for Port A Bit 6 */
    byte PTAPE7      :1;                                       /* Pullup Enable for Port A Bit 7 */
  } Bits;
} PTAPESTR;
extern volatile PTAPESTR _PTAPE @0x00001830;
#define PTAPE                           _PTAPE.Byte
#define PTAPE_PTAPE0                    _PTAPE.Bits.PTAPE0
#define PTAPE_PTAPE1                    _PTAPE.Bits.PTAPE1
#define PTAPE_PTAPE2                    _PTAPE.Bits.PTAPE2
#define PTAPE_PTAPE3                    _PTAPE.Bits.PTAPE3
#define PTAPE_PTAPE4                    _PTAPE.Bits.PTAPE4
#define PTAPE_PTAPE5                    _PTAPE.Bits.PTAPE5
#define PTAPE_PTAPE6                    _PTAPE.Bits.PTAPE6
#define PTAPE_PTAPE7                    _PTAPE.Bits.PTAPE7

#define PTAPE_PTAPE0_MASK               1
#define PTAPE_PTAPE1_MASK               2
#define PTAPE_PTAPE2_MASK               4
#define PTAPE_PTAPE3_MASK               8
#define PTAPE_PTAPE4_MASK               16
#define PTAPE_PTAPE5_MASK               32
#define PTAPE_PTAPE6_MASK               64
#define PTAPE_PTAPE7_MASK               128


/*** PTASE - Slew Rate Control Enable for Port A; 0x00001831 ***/
typedef union {
  byte Byte;
  struct {
    byte PTASE0      :1;                                       /* Slew Rate Control Enable for Port A Bit 0 */
    byte PTASE1      :1;                                       /* Slew Rate Control Enable for Port A Bit 1 */
    byte PTASE2      :1;                                       /* Slew Rate Control Enable for Port A Bit 2 */
    byte PTASE3      :1;                                       /* Slew Rate Control Enable for Port A Bit 3 */
    byte PTASE4      :1;                                       /* Slew Rate Control Enable for Port A Bit 4 */
    byte PTASE5      :1;                                       /* Slew Rate Control Enable for Port A Bit 5 */
    byte PTASE6      :1;                                       /* Slew Rate Control Enable for Port A Bit 6 */
    byte PTASE7      :1;                                       /* Slew Rate Control Enable for Port A Bit 7 */
  } Bits;
} PTASESTR;
extern volatile PTASESTR _PTASE @0x00001831;
#define PTASE                           _PTASE.Byte
#define PTASE_PTASE0                    _PTASE.Bits.PTASE0
#define PTASE_PTASE1                    _PTASE.Bits.PTASE1
#define PTASE_PTASE2                    _PTASE.Bits.PTASE2
#define PTASE_PTASE3                    _PTASE.Bits.PTASE3
#define PTASE_PTASE4                    _PTASE.Bits.PTASE4
#define PTASE_PTASE5                    _PTASE.Bits.PTASE5
#define PTASE_PTASE6                    _PTASE.Bits.PTASE6
#define PTASE_PTASE7                    _PTASE.Bits.PTASE7

#define PTASE_PTASE0_MASK               1
#define PTASE_PTASE1_MASK               2
#define PTASE_PTASE2_MASK               4
#define PTASE_PTASE3_MASK               8
#define PTASE_PTASE4_MASK               16
#define PTASE_PTASE5_MASK               32
#define PTASE_PTASE6_MASK               64
#define PTASE_PTASE7_MASK               128


/*** PTADS - Output Drive Strength Selection for Port A; 0x00001832 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADS0      :1;                                       /* Output Drive Strength Selection for Port A Bit 0 */
    byte PTADS1      :1;                                       /* Output Drive Strength Selection for Port A Bit 1 */
    byte PTADS2      :1;                                       /* Output Drive Strength Selection for Port A Bit 2 */
    byte PTADS3      :1;                                       /* Output Drive Strength Selection for Port A Bit 3 */
    byte PTADS4      :1;                                       /* Output Drive Strength Selection for Port A Bit 4 */
    byte PTADS5      :1;                                       /* Output Drive Strength Selection for Port A Bit 5 */
    byte PTADS6      :1;                                       /* Output Drive Strength Selection for Port A Bit 6 */
    byte PTADS7      :1;                                       /* Output Drive Strength Selection for Port A Bit 7 */
  } Bits;
} PTADSSTR;
extern volatile PTADSSTR _PTADS @0x00001832;
#define PTADS                           _PTADS.Byte
#define PTADS_PTADS0                    _PTADS.Bits.PTADS0
#define PTADS_PTADS1                    _PTADS.Bits.PTADS1
#define PTADS_PTADS2                    _PTADS.Bits.PTADS2
#define PTADS_PTADS3                    _PTADS.Bits.PTADS3
#define PTADS_PTADS4                    _PTADS.Bits.PTADS4
#define PTADS_PTADS5                    _PTADS.Bits.PTADS5
#define PTADS_PTADS6                    _PTADS.Bits.PTADS6
#define PTADS_PTADS7                    _PTADS.Bits.PTADS7

#define PTADS_PTADS0_MASK               1
#define PTADS_PTADS1_MASK               2
#define PTADS_PTADS2_MASK               4
#define PTADS_PTADS3_MASK               8
#define PTADS_PTADS4_MASK               16
#define PTADS_PTADS5_MASK               32
#define PTADS_PTADS6_MASK               64
#define PTADS_PTADS7_MASK               128


/*** PTBPE - Pullup Enable for Port B; 0x00001834 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBPE0      :1;                                       /* Pullup Enable for Port B Bit 0 */
    byte PTBPE1      :1;                                       /* Pullup Enable for Port B Bit 1 */
    byte PTBPE2      :1;                                       /* Pullup Enable for Port B Bit 2 */
    byte PTBPE3      :1;                                       /* Pullup Enable for Port B Bit 3 */
    byte PTBPE4      :1;                                       /* Pullup Enable for Port B Bit 4 */
    byte PTBPE5      :1;                                       /* Pullup Enable for Port B Bit 5 */
    byte PTBPE6      :1;                                       /* Pullup Enable for Port B Bit 6 */
    byte PTBPE7      :1;                                       /* Pullup Enable for Port B Bit 7 */
  } Bits;
} PTBPESTR;
extern volatile PTBPESTR _PTBPE @0x00001834;
#define PTBPE                           _PTBPE.Byte
#define PTBPE_PTBPE0                    _PTBPE.Bits.PTBPE0
#define PTBPE_PTBPE1                    _PTBPE.Bits.PTBPE1
#define PTBPE_PTBPE2                    _PTBPE.Bits.PTBPE2
#define PTBPE_PTBPE3                    _PTBPE.Bits.PTBPE3
#define PTBPE_PTBPE4                    _PTBPE.Bits.PTBPE4
#define PTBPE_PTBPE5                    _PTBPE.Bits.PTBPE5
#define PTBPE_PTBPE6                    _PTBPE.Bits.PTBPE6
#define PTBPE_PTBPE7                    _PTBPE.Bits.PTBPE7

#define PTBPE_PTBPE0_MASK               1
#define PTBPE_PTBPE1_MASK               2
#define PTBPE_PTBPE2_MASK               4
#define PTBPE_PTBPE3_MASK               8
#define PTBPE_PTBPE4_MASK               16
#define PTBPE_PTBPE5_MASK               32
#define PTBPE_PTBPE6_MASK               64
#define PTBPE_PTBPE7_MASK               128


/*** PTBSE - Slew Rate Control Enable for Port B; 0x00001835 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBSE0      :1;                                       /* Slew Rate Control Enable for Port B Bit 0 */
    byte PTBSE1      :1;                                       /* Slew Rate Control Enable for Port B Bit 1 */
    byte PTBSE2      :1;                                       /* Slew Rate Control Enable for Port B Bit 2 */
    byte PTBSE3      :1;                                       /* Slew Rate Control Enable for Port B Bit 3 */
    byte PTBSE4      :1;                                       /* Slew Rate Control Enable for Port B Bit 4 */
    byte PTBSE5      :1;                                       /* Slew Rate Control Enable for Port B Bit 5 */
    byte PTBSE6      :1;                                       /* Slew Rate Control Enable for Port B Bit 6 */
    byte PTBSE7      :1;                                       /* Slew Rate Control Enable for Port B Bit 7 */
  } Bits;
} PTBSESTR;
extern volatile PTBSESTR _PTBSE @0x00001835;
#define PTBSE                           _PTBSE.Byte
#define PTBSE_PTBSE0                    _PTBSE.Bits.PTBSE0
#define PTBSE_PTBSE1                    _PTBSE.Bits.PTBSE1
#define PTBSE_PTBSE2                    _PTBSE.Bits.PTBSE2
#define PTBSE_PTBSE3                    _PTBSE.Bits.PTBSE3
#define PTBSE_PTBSE4                    _PTBSE.Bits.PTBSE4
#define PTBSE_PTBSE5                    _PTBSE.Bits.PTBSE5
#define PTBSE_PTBSE6                    _PTBSE.Bits.PTBSE6
#define PTBSE_PTBSE7                    _PTBSE.Bits.PTBSE7

#define PTBSE_PTBSE0_MASK               1
#define PTBSE_PTBSE1_MASK               2
#define PTBSE_PTBSE2_MASK               4
#define PTBSE_PTBSE3_MASK               8
#define PTBSE_PTBSE4_MASK               16
#define PTBSE_PTBSE5_MASK               32
#define PTBSE_PTBSE6_MASK               64
#define PTBSE_PTBSE7_MASK               128


/*** PTBDS - Output Drive Strength Selection for Port B; 0x00001836 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDS0      :1;                                       /* Output Drive Strength Selection for Port B Bit 0 */
    byte PTBDS1      :1;                                       /* Output Drive Strength Selection for Port B Bit 1 */
    byte PTBDS2      :1;                                       /* Output Drive Strength Selection for Port B Bit 2 */
    byte PTBDS3      :1;                                       /* Output Drive Strength Selection for Port B Bit 3 */
    byte PTBDS4      :1;                                       /* Output Drive Strength Selection for Port B Bit 4 */
    byte PTBDS5      :1;                                       /* Output Drive Strength Selection for Port B Bit 5 */
    byte PTBDS6      :1;                                       /* Output Drive Strength Selection for Port B Bit 6 */
    byte PTBDS7      :1;                                       /* Output Drive Strength Selection for Port B Bit 7 */
  } Bits;
} PTBDSSTR;
extern volatile PTBDSSTR _PTBDS @0x00001836;
#define PTBDS                           _PTBDS.Byte
#define PTBDS_PTBDS0                    _PTBDS.Bits.PTBDS0
#define PTBDS_PTBDS1                    _PTBDS.Bits.PTBDS1
#define PTBDS_PTBDS2                    _PTBDS.Bits.PTBDS2
#define PTBDS_PTBDS3                    _PTBDS.Bits.PTBDS3
#define PTBDS_PTBDS4                    _PTBDS.Bits.PTBDS4
#define PTBDS_PTBDS5                    _PTBDS.Bits.PTBDS5
#define PTBDS_PTBDS6                    _PTBDS.Bits.PTBDS6
#define PTBDS_PTBDS7                    _PTBDS.Bits.PTBDS7

#define PTBDS_PTBDS0_MASK               1
#define PTBDS_PTBDS1_MASK               2
#define PTBDS_PTBDS2_MASK               4
#define PTBDS_PTBDS3_MASK               8
#define PTBDS_PTBDS4_MASK               16
#define PTBDS_PTBDS5_MASK               32
#define PTBDS_PTBDS6_MASK               64
#define PTBDS_PTBDS7_MASK               128


/*** PTCPE - Pullup Enable for Port B; 0x00001838 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCPE0      :1;                                       /* Pullup Enable for Port B Bit 0 */
    byte PTCPE1      :1;                                       /* Pullup Enable for Port B Bit 1 */
    byte PTCPE2      :1;                                       /* Pullup Enable for Port B Bit 2 */
    byte PTCPE3      :1;                                       /* Pullup Enable for Port B Bit 3 */
    byte PTCPE4      :1;                                       /* Pullup Enable for Port B Bit 4 */
    byte PTCPE5      :1;                                       /* Pullup Enable for Port B Bit 5 */
    byte PTCPE6      :1;                                       /* Pullup Enable for Port B Bit 6 */
    byte PTCPE7      :1;                                       /* Pullup Enable for Port B Bit 7 */
  } Bits;
} PTCPESTR;
extern volatile PTCPESTR _PTCPE @0x00001838;
#define PTCPE                           _PTCPE.Byte
#define PTCPE_PTCPE0                    _PTCPE.Bits.PTCPE0
#define PTCPE_PTCPE1                    _PTCPE.Bits.PTCPE1
#define PTCPE_PTCPE2                    _PTCPE.Bits.PTCPE2
#define PTCPE_PTCPE3                    _PTCPE.Bits.PTCPE3
#define PTCPE_PTCPE4                    _PTCPE.Bits.PTCPE4
#define PTCPE_PTCPE5                    _PTCPE.Bits.PTCPE5
#define PTCPE_PTCPE6                    _PTCPE.Bits.PTCPE6
#define PTCPE_PTCPE7                    _PTCPE.Bits.PTCPE7

#define PTCPE_PTCPE0_MASK               1
#define PTCPE_PTCPE1_MASK               2
#define PTCPE_PTCPE2_MASK               4
#define PTCPE_PTCPE3_MASK               8
#define PTCPE_PTCPE4_MASK               16
#define PTCPE_PTCPE5_MASK               32
#define PTCPE_PTCPE6_MASK               64
#define PTCPE_PTCPE7_MASK               128


/*** PTCSE - Slew Rate Control Enable for Port B; 0x00001839 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCSE0      :1;                                       /* Slew Rate Control Enable for Port B Bit 0 */
    byte PTCSE1      :1;                                       /* Slew Rate Control Enable for Port B Bit 1 */
    byte PTCSE2      :1;                                       /* Slew Rate Control Enable for Port B Bit 2 */
    byte PTCSE3      :1;                                       /* Slew Rate Control Enable for Port B Bit 3 */
    byte PTCSE4      :1;                                       /* Slew Rate Control Enable for Port B Bit 4 */
    byte PTCSE5      :1;                                       /* Slew Rate Control Enable for Port B Bit 5 */
    byte PTCSE6      :1;                                       /* Slew Rate Control Enable for Port B Bit 6 */
    byte PTCSE7      :1;                                       /* Slew Rate Control Enable for Port B Bit 7 */
  } Bits;
} PTCSESTR;
extern volatile PTCSESTR _PTCSE @0x00001839;
#define PTCSE                           _PTCSE.Byte
#define PTCSE_PTCSE0                    _PTCSE.Bits.PTCSE0
#define PTCSE_PTCSE1                    _PTCSE.Bits.PTCSE1
#define PTCSE_PTCSE2                    _PTCSE.Bits.PTCSE2
#define PTCSE_PTCSE3                    _PTCSE.Bits.PTCSE3
#define PTCSE_PTCSE4                    _PTCSE.Bits.PTCSE4
#define PTCSE_PTCSE5                    _PTCSE.Bits.PTCSE5
#define PTCSE_PTCSE6                    _PTCSE.Bits.PTCSE6
#define PTCSE_PTCSE7                    _PTCSE.Bits.PTCSE7

#define PTCSE_PTCSE0_MASK               1
#define PTCSE_PTCSE1_MASK               2
#define PTCSE_PTCSE2_MASK               4
#define PTCSE_PTCSE3_MASK               8
#define PTCSE_PTCSE4_MASK               16
#define PTCSE_PTCSE5_MASK               32
#define PTCSE_PTCSE6_MASK               64
#define PTCSE_PTCSE7_MASK               128


/*** PTCDS - Output Drive Strength Selection for Port B; 0x0000183A ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDS0      :1;                                       /* Output Drive Strength Selection for Port B Bit 0 */
    byte PTCDS1      :1;                                       /* Output Drive Strength Selection for Port B Bit 1 */
    byte PTCDS2      :1;                                       /* Output Drive Strength Selection for Port B Bit 2 */
    byte PTCDS3      :1;                                       /* Output Drive Strength Selection for Port B Bit 3 */
    byte PTCDS4      :1;                                       /* Output Drive Strength Selection for Port B Bit 4 */
    byte PTCDS5      :1;                                       /* Output Drive Strength Selection for Port B Bit 5 */
    byte PTCDS6      :1;                                       /* Output Drive Strength Selection for Port B Bit 6 */
    byte PTCDS7      :1;                                       /* Output Drive Strength Selection for Port B Bit 7 */
  } Bits;
} PTCDSSTR;
extern volatile PTCDSSTR _PTCDS @0x0000183A;
#define PTCDS                           _PTCDS.Byte
#define PTCDS_PTCDS0                    _PTCDS.Bits.PTCDS0
#define PTCDS_PTCDS1                    _PTCDS.Bits.PTCDS1
#define PTCDS_PTCDS2                    _PTCDS.Bits.PTCDS2
#define PTCDS_PTCDS3                    _PTCDS.Bits.PTCDS3
#define PTCDS_PTCDS4                    _PTCDS.Bits.PTCDS4
#define PTCDS_PTCDS5                    _PTCDS.Bits.PTCDS5
#define PTCDS_PTCDS6                    _PTCDS.Bits.PTCDS6
#define PTCDS_PTCDS7                    _PTCDS.Bits.PTCDS7

#define PTCDS_PTCDS0_MASK               1
#define PTCDS_PTCDS1_MASK               2
#define PTCDS_PTCDS2_MASK               4
#define PTCDS_PTCDS3_MASK               8
#define PTCDS_PTCDS4_MASK               16
#define PTCDS_PTCDS5_MASK               32
#define PTCDS_PTCDS6_MASK               64
#define PTCDS_PTCDS7_MASK               128


/*** LCDCR0 - LCD Control Register 0; 0x00001840 ***/
typedef union {
  byte Byte;
  struct {
    byte DUTY0       :1;                                       /* LCD Duty Select Bit 0 */
    byte DUTY1       :1;                                       /* LCD Duty Select Bit 1 */
    byte             :1; 
    byte LCLK0       :1;                                       /* LCD Clock Prescaler Bit 0 */
    byte LCLK1       :1;                                       /* LCD Clock Prescaler Bit 1 */
    byte LCLK2       :1;                                       /* LCD Clock Prescaler Bit 2 */
    byte             :1; 
    byte LCDEN       :1;                                       /* LCD Driver Enable */
  } Bits;
  struct {
    byte grpDUTY :2;
    byte         :1;
    byte grpLCLK :3;
    byte         :1;
    byte         :1;
  } MergedBits;
} LCDCR0STR;
extern volatile LCDCR0STR _LCDCR0 @0x00001840;
#define LCDCR0                          _LCDCR0.Byte
#define LCDCR0_DUTY0                    _LCDCR0.Bits.DUTY0
#define LCDCR0_DUTY1                    _LCDCR0.Bits.DUTY1
#define LCDCR0_LCLK0                    _LCDCR0.Bits.LCLK0
#define LCDCR0_LCLK1                    _LCDCR0.Bits.LCLK1
#define LCDCR0_LCLK2                    _LCDCR0.Bits.LCLK2
#define LCDCR0_LCDEN                    _LCDCR0.Bits.LCDEN
/* LCDCR_ARR: Access 2 LCDCRx registers in an array */
#define LCDCR_ARR                       ((volatile byte * __far) &LCDCR0)
#define LCDCR0_DUTY                     _LCDCR0.MergedBits.grpDUTY
#define LCDCR0_LCLK                     _LCDCR0.MergedBits.grpLCLK

#define LCDCR0_DUTY0_MASK               1
#define LCDCR0_DUTY1_MASK               2
#define LCDCR0_LCLK0_MASK               8
#define LCDCR0_LCLK1_MASK               16
#define LCDCR0_LCLK2_MASK               32
#define LCDCR0_LCDEN_MASK               128
#define LCDCR0_DUTY_MASK                3
#define LCDCR0_DUTY_BITNUM              0
#define LCDCR0_LCLK_MASK                56
#define LCDCR0_LCLK_BITNUM              3


/*** LCDCR1 - LCD Control Register 1; 0x00001841 ***/
typedef union {
  byte Byte;
  struct {
    byte LCDSTP3     :1;                                       /* LCD Module Driver and Charge Pump Stop While in Stop3 Mode */
    byte LCDWAI      :1;                                       /* LCD Module Driver and Charge Pump Stop While in Wait Mode */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LCDIEN      :1;                                       /* LCD Module Frame Frequency Interrupt Enable */
  } Bits;
} LCDCR1STR;
extern volatile LCDCR1STR _LCDCR1 @0x00001841;
#define LCDCR1                          _LCDCR1.Byte
#define LCDCR1_LCDSTP3                  _LCDCR1.Bits.LCDSTP3
#define LCDCR1_LCDWAI                   _LCDCR1.Bits.LCDWAI
#define LCDCR1_LCDIEN                   _LCDCR1.Bits.LCDIEN

#define LCDCR1_LCDSTP3_MASK             1
#define LCDCR1_LCDWAI_MASK              2
#define LCDCR1_LCDIEN_MASK              128


/*** FPENR0 - LCD Frontplane Enable Registers 0; 0x00001842 ***/
typedef union {
  byte Byte;
  struct {
    byte FP0EN       :1;                                       /* Frontplane Output Enable Bit 0 */
    byte FP1EN       :1;                                       /* Frontplane Output Enable Bit 1 */
    byte FP2EN       :1;                                       /* Frontplane Output Enable Bit 2 */
    byte FP3EN       :1;                                       /* Frontplane Output Enable Bit 3 */
    byte FP4EN       :1;                                       /* Frontplane Output Enable Bit 4 */
    byte FP5EN       :1;                                       /* Frontplane Output Enable Bit 5 */
    byte FP6EN       :1;                                       /* Frontplane Output Enable Bit 6 */
    byte FP7EN       :1;                                       /* Frontplane Output Enable Bit 7 */
  } Bits;
} FPENR0STR;
extern volatile FPENR0STR _FPENR0 @0x00001842;
#define FPENR0                          _FPENR0.Byte
#define FPENR0_FP0EN                    _FPENR0.Bits.FP0EN
#define FPENR0_FP1EN                    _FPENR0.Bits.FP1EN
#define FPENR0_FP2EN                    _FPENR0.Bits.FP2EN
#define FPENR0_FP3EN                    _FPENR0.Bits.FP3EN
#define FPENR0_FP4EN                    _FPENR0.Bits.FP4EN
#define FPENR0_FP5EN                    _FPENR0.Bits.FP5EN
#define FPENR0_FP6EN                    _FPENR0.Bits.FP6EN
#define FPENR0_FP7EN                    _FPENR0.Bits.FP7EN
/* FPENR_ARR: Access 6 FPENRx registers in an array */
#define FPENR_ARR                       ((volatile byte * __far) &FPENR0)

#define FPENR0_FP0EN_MASK               1
#define FPENR0_FP1EN_MASK               2
#define FPENR0_FP2EN_MASK               4
#define FPENR0_FP3EN_MASK               8
#define FPENR0_FP4EN_MASK               16
#define FPENR0_FP5EN_MASK               32
#define FPENR0_FP6EN_MASK               64
#define FPENR0_FP7EN_MASK               128


/*** FPENR1 - LCD Frontplane Enable Registers 1; 0x00001843 ***/
typedef union {
  byte Byte;
  struct {
    byte FP8EN       :1;                                       /* Frontplane Output Enable Bit 8 */
    byte FP9EN       :1;                                       /* Frontplane Output Enable Bit 9 */
    byte FP10EN      :1;                                       /* Frontplane Output Enable Bit 10 */
    byte FP11EN      :1;                                       /* Frontplane Output Enable Bit 11 */
    byte FP12EN      :1;                                       /* Frontplane Output Enable Bit 12 */
    byte FP13EN      :1;                                       /* Frontplane Output Enable Bit 13 */
    byte FP14EN      :1;                                       /* Frontplane Output Enable Bit 14 */
    byte FP15EN      :1;                                       /* Frontplane Output Enable Bit 15 */
  } Bits;
} FPENR1STR;
extern volatile FPENR1STR _FPENR1 @0x00001843;
#define FPENR1                          _FPENR1.Byte
#define FPENR1_FP8EN                    _FPENR1.Bits.FP8EN
#define FPENR1_FP9EN                    _FPENR1.Bits.FP9EN
#define FPENR1_FP10EN                   _FPENR1.Bits.FP10EN
#define FPENR1_FP11EN                   _FPENR1.Bits.FP11EN
#define FPENR1_FP12EN                   _FPENR1.Bits.FP12EN
#define FPENR1_FP13EN                   _FPENR1.Bits.FP13EN
#define FPENR1_FP14EN                   _FPENR1.Bits.FP14EN
#define FPENR1_FP15EN                   _FPENR1.Bits.FP15EN

#define FPENR1_FP8EN_MASK               1
#define FPENR1_FP9EN_MASK               2
#define FPENR1_FP10EN_MASK              4
#define FPENR1_FP11EN_MASK              8
#define FPENR1_FP12EN_MASK              16
#define FPENR1_FP13EN_MASK              32
#define FPENR1_FP14EN_MASK              64
#define FPENR1_FP15EN_MASK              128


/*** FPENR2 - LCD Frontplane Enable Registers 2; 0x00001844 ***/
typedef union {
  byte Byte;
  struct {
    byte FP16EN      :1;                                       /* Frontplane Output Enable Bit 16 */
    byte FP17EN      :1;                                       /* Frontplane Output Enable Bit 17 */
    byte FP18EN      :1;                                       /* Frontplane Output Enable Bit 18 */
    byte FP19EN      :1;                                       /* Frontplane Output Enable Bit 19 */
    byte FP20EN      :1;                                       /* Frontplane Output Enable Bit 20 */
    byte FP21EN      :1;                                       /* Frontplane Output Enable Bit 21 */
    byte FP22EN      :1;                                       /* Frontplane Output Enable Bit 22 */
    byte FP23EN      :1;                                       /* Frontplane Output Enable Bit 23 */
  } Bits;
} FPENR2STR;
extern volatile FPENR2STR _FPENR2 @0x00001844;
#define FPENR2                          _FPENR2.Byte
#define FPENR2_FP16EN                   _FPENR2.Bits.FP16EN
#define FPENR2_FP17EN                   _FPENR2.Bits.FP17EN
#define FPENR2_FP18EN                   _FPENR2.Bits.FP18EN
#define FPENR2_FP19EN                   _FPENR2.Bits.FP19EN
#define FPENR2_FP20EN                   _FPENR2.Bits.FP20EN
#define FPENR2_FP21EN                   _FPENR2.Bits.FP21EN
#define FPENR2_FP22EN                   _FPENR2.Bits.FP22EN
#define FPENR2_FP23EN                   _FPENR2.Bits.FP23EN

#define FPENR2_FP16EN_MASK              1
#define FPENR2_FP17EN_MASK              2
#define FPENR2_FP18EN_MASK              4
#define FPENR2_FP19EN_MASK              8
#define FPENR2_FP20EN_MASK              16
#define FPENR2_FP21EN_MASK              32
#define FPENR2_FP22EN_MASK              64
#define FPENR2_FP23EN_MASK              128


/*** FPENR3 - LCD Frontplane Enable Registers 3; 0x00001845 ***/
typedef union {
  byte Byte;
  struct {
    byte FP24EN      :1;                                       /* Frontplane Output Enable Bit 24 */
    byte FP25EN      :1;                                       /* Frontplane Output Enable Bit 25 */
    byte FP26EN      :1;                                       /* Frontplane Output Enable Bit 26 */
    byte FP27EN      :1;                                       /* Frontplane Output Enable Bit 27 */
    byte FP28EN      :1;                                       /* Frontplane Output Enable Bit 28 */
    byte FP29EN      :1;                                       /* Frontplane Output Enable Bit 29 */
    byte FP30EN      :1;                                       /* Frontplane Output Enable Bit 30 */
    byte FP31EN      :1;                                       /* Frontplane Output Enable Bit 31 */
  } Bits;
} FPENR3STR;
extern volatile FPENR3STR _FPENR3 @0x00001845;
#define FPENR3                          _FPENR3.Byte
#define FPENR3_FP24EN                   _FPENR3.Bits.FP24EN
#define FPENR3_FP25EN                   _FPENR3.Bits.FP25EN
#define FPENR3_FP26EN                   _FPENR3.Bits.FP26EN
#define FPENR3_FP27EN                   _FPENR3.Bits.FP27EN
#define FPENR3_FP28EN                   _FPENR3.Bits.FP28EN
#define FPENR3_FP29EN                   _FPENR3.Bits.FP29EN
#define FPENR3_FP30EN                   _FPENR3.Bits.FP30EN
#define FPENR3_FP31EN                   _FPENR3.Bits.FP31EN

#define FPENR3_FP24EN_MASK              1
#define FPENR3_FP25EN_MASK              2
#define FPENR3_FP26EN_MASK              4
#define FPENR3_FP27EN_MASK              8
#define FPENR3_FP28EN_MASK              16
#define FPENR3_FP29EN_MASK              32
#define FPENR3_FP30EN_MASK              64
#define FPENR3_FP31EN_MASK              128


/*** FPENR4 - LCD Frontplane Enable Registers 4; 0x00001846 ***/
typedef union {
  byte Byte;
  struct {
    byte FP32EN      :1;                                       /* Frontplane Output Enable Bit 32 */
    byte FP33EN      :1;                                       /* Frontplane Output Enable Bit 33 */
    byte FP34EN      :1;                                       /* Frontplane Output Enable Bit 34 */
    byte FP35EN      :1;                                       /* Frontplane Output Enable Bit 35 */
    byte FP36EN      :1;                                       /* Frontplane Output Enable Bit 36 */
    byte FP37EN      :1;                                       /* Frontplane Output Enable Bit 37 */
    byte FP38EN      :1;                                       /* Frontplane Output Enable Bit 38 */
    byte FP39EN      :1;                                       /* Frontplane Output Enable Bit 39 */
  } Bits;
} FPENR4STR;
extern volatile FPENR4STR _FPENR4 @0x00001846;
#define FPENR4                          _FPENR4.Byte
#define FPENR4_FP32EN                   _FPENR4.Bits.FP32EN
#define FPENR4_FP33EN                   _FPENR4.Bits.FP33EN
#define FPENR4_FP34EN                   _FPENR4.Bits.FP34EN
#define FPENR4_FP35EN                   _FPENR4.Bits.FP35EN
#define FPENR4_FP36EN                   _FPENR4.Bits.FP36EN
#define FPENR4_FP37EN                   _FPENR4.Bits.FP37EN
#define FPENR4_FP38EN                   _FPENR4.Bits.FP38EN
#define FPENR4_FP39EN                   _FPENR4.Bits.FP39EN

#define FPENR4_FP32EN_MASK              1
#define FPENR4_FP33EN_MASK              2
#define FPENR4_FP34EN_MASK              4
#define FPENR4_FP35EN_MASK              8
#define FPENR4_FP36EN_MASK              16
#define FPENR4_FP37EN_MASK              32
#define FPENR4_FP38EN_MASK              64
#define FPENR4_FP39EN_MASK              128


/*** FPENR5 - LCD Frontplane Enable Registers 5; 0x00001847 ***/
typedef union {
  byte Byte;
  struct {
    byte FP40EN      :1;                                       /* Frontplane Output Enable Bit 40 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FPENR5STR;
extern volatile FPENR5STR _FPENR5 @0x00001847;
#define FPENR5                          _FPENR5.Byte
#define FPENR5_FP40EN                   _FPENR5.Bits.FP40EN

#define FPENR5_FP40EN_MASK              1


/*** LCDRAM0 - LCDRAM Register 0; 0x00001848 ***/
typedef union {
  byte Byte;
  struct {
    byte FP0BP0      :1;                                       /* LCD Segment 0 Data Bit 0 */
    byte FP0BP1      :1;                                       /* LCD Segment 0 Data Bit 1 */
    byte FP0BP2      :1;                                       /* LCD Segment 0 Data Bit 2 */
    byte FP0BP3      :1;                                       /* LCD Segment 0 Data Bit 3 */
    byte FP1BP0      :1;                                       /* LCD Segment 1 Data Bit 0 */
    byte FP1BP1      :1;                                       /* LCD Segment 1 Data Bit 1 */
    byte FP1BP2      :1;                                       /* LCD Segment 1 Data Bit 2 */
    byte FP1BP3      :1;                                       /* LCD Segment 1 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP0BP :4;
    byte grpFP1BP :4;
  } MergedBits;
} LCDRAM0STR;
extern volatile LCDRAM0STR _LCDRAM0 @0x00001848;
#define LCDRAM0                         _LCDRAM0.Byte
#define LCDRAM0_FP0BP0                  _LCDRAM0.Bits.FP0BP0
#define LCDRAM0_FP0BP1                  _LCDRAM0.Bits.FP0BP1
#define LCDRAM0_FP0BP2                  _LCDRAM0.Bits.FP0BP2
#define LCDRAM0_FP0BP3                  _LCDRAM0.Bits.FP0BP3
#define LCDRAM0_FP1BP0                  _LCDRAM0.Bits.FP1BP0
#define LCDRAM0_FP1BP1                  _LCDRAM0.Bits.FP1BP1
#define LCDRAM0_FP1BP2                  _LCDRAM0.Bits.FP1BP2
#define LCDRAM0_FP1BP3                  _LCDRAM0.Bits.FP1BP3
/* LCDRAM_ARR: Access 21 LCDRAMx registers in an array */
#define LCDRAM_ARR                      ((volatile byte * __far) &LCDRAM0)
#define LCDRAM0_FP0BP                   _LCDRAM0.MergedBits.grpFP0BP
#define LCDRAM0_FP1BP                   _LCDRAM0.MergedBits.grpFP1BP

#define LCDRAM0_FP0BP0_MASK             1
#define LCDRAM0_FP0BP1_MASK             2
#define LCDRAM0_FP0BP2_MASK             4
#define LCDRAM0_FP0BP3_MASK             8
#define LCDRAM0_FP1BP0_MASK             16
#define LCDRAM0_FP1BP1_MASK             32
#define LCDRAM0_FP1BP2_MASK             64
#define LCDRAM0_FP1BP3_MASK             128
#define LCDRAM0_FP0BP_MASK              15
#define LCDRAM0_FP0BP_BITNUM            0
#define LCDRAM0_FP1BP_MASK              240
#define LCDRAM0_FP1BP_BITNUM            4


/*** LCDRAM1 - LCDRAM Register 1; 0x00001849 ***/
typedef union {
  byte Byte;
  struct {
    byte FP2BP0      :1;                                       /* LCD Segment 2 Data Bit 0 */
    byte FP2BP1      :1;                                       /* LCD Segment 2 Data Bit 1 */
    byte FP2BP2      :1;                                       /* LCD Segment 2 Data Bit 2 */
    byte FP2BP3      :1;                                       /* LCD Segment 2 Data Bit 3 */
    byte FP3BP0      :1;                                       /* LCD Segment 3 Data Bit 0 */
    byte FP3BP1      :1;                                       /* LCD Segment 3 Data Bit 1 */
    byte FP3BP2      :1;                                       /* LCD Segment 3 Data Bit 2 */
    byte FP3BP3      :1;                                       /* LCD Segment 3 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP2BP :4;
    byte grpFP3BP :4;
  } MergedBits;
} LCDRAM1STR;
extern volatile LCDRAM1STR _LCDRAM1 @0x00001849;
#define LCDRAM1                         _LCDRAM1.Byte
#define LCDRAM1_FP2BP0                  _LCDRAM1.Bits.FP2BP0
#define LCDRAM1_FP2BP1                  _LCDRAM1.Bits.FP2BP1
#define LCDRAM1_FP2BP2                  _LCDRAM1.Bits.FP2BP2
#define LCDRAM1_FP2BP3                  _LCDRAM1.Bits.FP2BP3
#define LCDRAM1_FP3BP0                  _LCDRAM1.Bits.FP3BP0
#define LCDRAM1_FP3BP1                  _LCDRAM1.Bits.FP3BP1
#define LCDRAM1_FP3BP2                  _LCDRAM1.Bits.FP3BP2
#define LCDRAM1_FP3BP3                  _LCDRAM1.Bits.FP3BP3
#define LCDRAM1_FP2BP                   _LCDRAM1.MergedBits.grpFP2BP
#define LCDRAM1_FP3BP                   _LCDRAM1.MergedBits.grpFP3BP

#define LCDRAM1_FP2BP0_MASK             1
#define LCDRAM1_FP2BP1_MASK             2
#define LCDRAM1_FP2BP2_MASK             4
#define LCDRAM1_FP2BP3_MASK             8
#define LCDRAM1_FP3BP0_MASK             16
#define LCDRAM1_FP3BP1_MASK             32
#define LCDRAM1_FP3BP2_MASK             64
#define LCDRAM1_FP3BP3_MASK             128
#define LCDRAM1_FP2BP_MASK              15
#define LCDRAM1_FP2BP_BITNUM            0
#define LCDRAM1_FP3BP_MASK              240
#define LCDRAM1_FP3BP_BITNUM            4


/*** LCDRAM2 - LCDRAM Register 2; 0x0000184A ***/
typedef union {
  byte Byte;
  struct {
    byte FP4BP0      :1;                                       /* LCD Segment 4 Data Bit 0 */
    byte FP4BP1      :1;                                       /* LCD Segment 4 Data Bit 1 */
    byte FP4BP2      :1;                                       /* LCD Segment 4 Data Bit 2 */
    byte FP4BP3      :1;                                       /* LCD Segment 4 Data Bit 3 */
    byte FP5BP0      :1;                                       /* LCD Segment 5 Data Bit 0 */
    byte FP5BP1      :1;                                       /* LCD Segment 5 Data Bit 1 */
    byte FP5BP2      :1;                                       /* LCD Segment 5 Data Bit 2 */
    byte FP5BP3      :1;                                       /* LCD Segment 5 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP4BP :4;
    byte grpFP5BP :4;
  } MergedBits;
} LCDRAM2STR;
extern volatile LCDRAM2STR _LCDRAM2 @0x0000184A;
#define LCDRAM2                         _LCDRAM2.Byte
#define LCDRAM2_FP4BP0                  _LCDRAM2.Bits.FP4BP0
#define LCDRAM2_FP4BP1                  _LCDRAM2.Bits.FP4BP1
#define LCDRAM2_FP4BP2                  _LCDRAM2.Bits.FP4BP2
#define LCDRAM2_FP4BP3                  _LCDRAM2.Bits.FP4BP3
#define LCDRAM2_FP5BP0                  _LCDRAM2.Bits.FP5BP0
#define LCDRAM2_FP5BP1                  _LCDRAM2.Bits.FP5BP1
#define LCDRAM2_FP5BP2                  _LCDRAM2.Bits.FP5BP2
#define LCDRAM2_FP5BP3                  _LCDRAM2.Bits.FP5BP3
#define LCDRAM2_FP4BP                   _LCDRAM2.MergedBits.grpFP4BP
#define LCDRAM2_FP5BP                   _LCDRAM2.MergedBits.grpFP5BP

#define LCDRAM2_FP4BP0_MASK             1
#define LCDRAM2_FP4BP1_MASK             2
#define LCDRAM2_FP4BP2_MASK             4
#define LCDRAM2_FP4BP3_MASK             8
#define LCDRAM2_FP5BP0_MASK             16
#define LCDRAM2_FP5BP1_MASK             32
#define LCDRAM2_FP5BP2_MASK             64
#define LCDRAM2_FP5BP3_MASK             128
#define LCDRAM2_FP4BP_MASK              15
#define LCDRAM2_FP4BP_BITNUM            0
#define LCDRAM2_FP5BP_MASK              240
#define LCDRAM2_FP5BP_BITNUM            4


/*** LCDRAM3 - LCDRAM Register 3; 0x0000184B ***/
typedef union {
  byte Byte;
  struct {
    byte FP6BP0      :1;                                       /* LCD Segment 6 Data Bit 0 */
    byte FP6BP1      :1;                                       /* LCD Segment 6 Data Bit 1 */
    byte FP6BP2      :1;                                       /* LCD Segment 6 Data Bit 2 */
    byte FP6BP3      :1;                                       /* LCD Segment 6 Data Bit 3 */
    byte FP7BP0      :1;                                       /* LCD Segment 7 Data Bit 0 */
    byte FP7BP1      :1;                                       /* LCD Segment 7 Data Bit 1 */
    byte FP7BP2      :1;                                       /* LCD Segment 7 Data Bit 2 */
    byte FP7BP3      :1;                                       /* LCD Segment 7 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP6BP :4;
    byte grpFP7BP :4;
  } MergedBits;
} LCDRAM3STR;
extern volatile LCDRAM3STR _LCDRAM3 @0x0000184B;
#define LCDRAM3                         _LCDRAM3.Byte
#define LCDRAM3_FP6BP0                  _LCDRAM3.Bits.FP6BP0
#define LCDRAM3_FP6BP1                  _LCDRAM3.Bits.FP6BP1
#define LCDRAM3_FP6BP2                  _LCDRAM3.Bits.FP6BP2
#define LCDRAM3_FP6BP3                  _LCDRAM3.Bits.FP6BP3
#define LCDRAM3_FP7BP0                  _LCDRAM3.Bits.FP7BP0
#define LCDRAM3_FP7BP1                  _LCDRAM3.Bits.FP7BP1
#define LCDRAM3_FP7BP2                  _LCDRAM3.Bits.FP7BP2
#define LCDRAM3_FP7BP3                  _LCDRAM3.Bits.FP7BP3
#define LCDRAM3_FP6BP                   _LCDRAM3.MergedBits.grpFP6BP
#define LCDRAM3_FP7BP                   _LCDRAM3.MergedBits.grpFP7BP

#define LCDRAM3_FP6BP0_MASK             1
#define LCDRAM3_FP6BP1_MASK             2
#define LCDRAM3_FP6BP2_MASK             4
#define LCDRAM3_FP6BP3_MASK             8
#define LCDRAM3_FP7BP0_MASK             16
#define LCDRAM3_FP7BP1_MASK             32
#define LCDRAM3_FP7BP2_MASK             64
#define LCDRAM3_FP7BP3_MASK             128
#define LCDRAM3_FP6BP_MASK              15
#define LCDRAM3_FP6BP_BITNUM            0
#define LCDRAM3_FP7BP_MASK              240
#define LCDRAM3_FP7BP_BITNUM            4


/*** LCDRAM4 - LCDRAM Register 4; 0x0000184C ***/
typedef union {
  byte Byte;
  struct {
    byte FP8BP0      :1;                                       /* LCD Segment 8 Data Bit 0 */
    byte FP8BP1      :1;                                       /* LCD Segment 8 Data Bit 1 */
    byte FP8BP2      :1;                                       /* LCD Segment 8 Data Bit 2 */
    byte FP8BP3      :1;                                       /* LCD Segment 8 Data Bit 3 */
    byte FP9BP0      :1;                                       /* LCD Segment 9 Data Bit 0 */
    byte FP9BP1      :1;                                       /* LCD Segment 9 Data Bit 1 */
    byte FP9BP2      :1;                                       /* LCD Segment 9 Data Bit 2 */
    byte FP9BP3      :1;                                       /* LCD Segment 9 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP8BP :4;
    byte grpFP9BP :4;
  } MergedBits;
} LCDRAM4STR;
extern volatile LCDRAM4STR _LCDRAM4 @0x0000184C;
#define LCDRAM4                         _LCDRAM4.Byte
#define LCDRAM4_FP8BP0                  _LCDRAM4.Bits.FP8BP0
#define LCDRAM4_FP8BP1                  _LCDRAM4.Bits.FP8BP1
#define LCDRAM4_FP8BP2                  _LCDRAM4.Bits.FP8BP2
#define LCDRAM4_FP8BP3                  _LCDRAM4.Bits.FP8BP3
#define LCDRAM4_FP9BP0                  _LCDRAM4.Bits.FP9BP0
#define LCDRAM4_FP9BP1                  _LCDRAM4.Bits.FP9BP1
#define LCDRAM4_FP9BP2                  _LCDRAM4.Bits.FP9BP2
#define LCDRAM4_FP9BP3                  _LCDRAM4.Bits.FP9BP3
#define LCDRAM4_FP8BP                   _LCDRAM4.MergedBits.grpFP8BP
#define LCDRAM4_FP9BP                   _LCDRAM4.MergedBits.grpFP9BP

#define LCDRAM4_FP8BP0_MASK             1
#define LCDRAM4_FP8BP1_MASK             2
#define LCDRAM4_FP8BP2_MASK             4
#define LCDRAM4_FP8BP3_MASK             8
#define LCDRAM4_FP9BP0_MASK             16
#define LCDRAM4_FP9BP1_MASK             32
#define LCDRAM4_FP9BP2_MASK             64
#define LCDRAM4_FP9BP3_MASK             128
#define LCDRAM4_FP8BP_MASK              15
#define LCDRAM4_FP8BP_BITNUM            0
#define LCDRAM4_FP9BP_MASK              240
#define LCDRAM4_FP9BP_BITNUM            4


/*** LCDRAM5 - LCDRAM Register 5; 0x0000184D ***/
typedef union {
  byte Byte;
  struct {
    byte FP10BP0     :1;                                       /* LCD Segment 10 Data Bit 0 */
    byte FP10BP1     :1;                                       /* LCD Segment 10 Data Bit 1 */
    byte FP10BP2     :1;                                       /* LCD Segment 10 Data Bit 2 */
    byte FP10BP3     :1;                                       /* LCD Segment 10 Data Bit 3 */
    byte FP11BP0     :1;                                       /* LCD Segment 11 Data Bit 0 */
    byte FP11BP1     :1;                                       /* LCD Segment 11 Data Bit 1 */
    byte FP11BP2     :1;                                       /* LCD Segment 11 Data Bit 2 */
    byte FP11BP3     :1;                                       /* LCD Segment 11 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP10BP :4;
    byte grpFP11BP :4;
  } MergedBits;
} LCDRAM5STR;
extern volatile LCDRAM5STR _LCDRAM5 @0x0000184D;
#define LCDRAM5                         _LCDRAM5.Byte
#define LCDRAM5_FP10BP0                 _LCDRAM5.Bits.FP10BP0
#define LCDRAM5_FP10BP1                 _LCDRAM5.Bits.FP10BP1
#define LCDRAM5_FP10BP2                 _LCDRAM5.Bits.FP10BP2
#define LCDRAM5_FP10BP3                 _LCDRAM5.Bits.FP10BP3
#define LCDRAM5_FP11BP0                 _LCDRAM5.Bits.FP11BP0
#define LCDRAM5_FP11BP1                 _LCDRAM5.Bits.FP11BP1
#define LCDRAM5_FP11BP2                 _LCDRAM5.Bits.FP11BP2
#define LCDRAM5_FP11BP3                 _LCDRAM5.Bits.FP11BP3
#define LCDRAM5_FP10BP                  _LCDRAM5.MergedBits.grpFP10BP
#define LCDRAM5_FP11BP                  _LCDRAM5.MergedBits.grpFP11BP

#define LCDRAM5_FP10BP0_MASK            1
#define LCDRAM5_FP10BP1_MASK            2
#define LCDRAM5_FP10BP2_MASK            4
#define LCDRAM5_FP10BP3_MASK            8
#define LCDRAM5_FP11BP0_MASK            16
#define LCDRAM5_FP11BP1_MASK            32
#define LCDRAM5_FP11BP2_MASK            64
#define LCDRAM5_FP11BP3_MASK            128
#define LCDRAM5_FP10BP_MASK             15
#define LCDRAM5_FP10BP_BITNUM           0
#define LCDRAM5_FP11BP_MASK             240
#define LCDRAM5_FP11BP_BITNUM           4


/*** LCDRAM6 - LCDRAM Register 6; 0x0000184E ***/
typedef union {
  byte Byte;
  struct {
    byte FP12BP0     :1;                                       /* LCD Segment 12 Data Bit 0 */
    byte FP12BP1     :1;                                       /* LCD Segment 12 Data Bit 1 */
    byte FP12BP2     :1;                                       /* LCD Segment 12 Data Bit 2 */
    byte FP12BP3     :1;                                       /* LCD Segment 12 Data Bit 3 */
    byte FP13BP0     :1;                                       /* LCD Segment 13 Data Bit 0 */
    byte FP13BP1     :1;                                       /* LCD Segment 13 Data Bit 1 */
    byte FP13BP2     :1;                                       /* LCD Segment 13 Data Bit 2 */
    byte FP13BP3     :1;                                       /* LCD Segment 13 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP12BP :4;
    byte grpFP13BP :4;
  } MergedBits;
} LCDRAM6STR;
extern volatile LCDRAM6STR _LCDRAM6 @0x0000184E;
#define LCDRAM6                         _LCDRAM6.Byte
#define LCDRAM6_FP12BP0                 _LCDRAM6.Bits.FP12BP0
#define LCDRAM6_FP12BP1                 _LCDRAM6.Bits.FP12BP1
#define LCDRAM6_FP12BP2                 _LCDRAM6.Bits.FP12BP2
#define LCDRAM6_FP12BP3                 _LCDRAM6.Bits.FP12BP3
#define LCDRAM6_FP13BP0                 _LCDRAM6.Bits.FP13BP0
#define LCDRAM6_FP13BP1                 _LCDRAM6.Bits.FP13BP1
#define LCDRAM6_FP13BP2                 _LCDRAM6.Bits.FP13BP2
#define LCDRAM6_FP13BP3                 _LCDRAM6.Bits.FP13BP3
#define LCDRAM6_FP12BP                  _LCDRAM6.MergedBits.grpFP12BP
#define LCDRAM6_FP13BP                  _LCDRAM6.MergedBits.grpFP13BP

#define LCDRAM6_FP12BP0_MASK            1
#define LCDRAM6_FP12BP1_MASK            2
#define LCDRAM6_FP12BP2_MASK            4
#define LCDRAM6_FP12BP3_MASK            8
#define LCDRAM6_FP13BP0_MASK            16
#define LCDRAM6_FP13BP1_MASK            32
#define LCDRAM6_FP13BP2_MASK            64
#define LCDRAM6_FP13BP3_MASK            128
#define LCDRAM6_FP12BP_MASK             15
#define LCDRAM6_FP12BP_BITNUM           0
#define LCDRAM6_FP13BP_MASK             240
#define LCDRAM6_FP13BP_BITNUM           4


/*** LCDRAM7 - LCDRAM Register 7; 0x0000184F ***/
typedef union {
  byte Byte;
  struct {
    byte FP14BP0     :1;                                       /* LCD Segment 14 Data Bit 0 */
    byte FP14BP1     :1;                                       /* LCD Segment 14 Data Bit 1 */
    byte FP14BP2     :1;                                       /* LCD Segment 14 Data Bit 2 */
    byte FP14BP3     :1;                                       /* LCD Segment 14 Data Bit 3 */
    byte FP15BP0     :1;                                       /* LCD Segment 15 Data Bit 0 */
    byte FP15BP1     :1;                                       /* LCD Segment 15 Data Bit 1 */
    byte FP15BP2     :1;                                       /* LCD Segment 15 Data Bit 2 */
    byte FP15BP3     :1;                                       /* LCD Segment 15 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP14BP :4;
    byte grpFP15BP :4;
  } MergedBits;
} LCDRAM7STR;
extern volatile LCDRAM7STR _LCDRAM7 @0x0000184F;
#define LCDRAM7                         _LCDRAM7.Byte
#define LCDRAM7_FP14BP0                 _LCDRAM7.Bits.FP14BP0
#define LCDRAM7_FP14BP1                 _LCDRAM7.Bits.FP14BP1
#define LCDRAM7_FP14BP2                 _LCDRAM7.Bits.FP14BP2
#define LCDRAM7_FP14BP3                 _LCDRAM7.Bits.FP14BP3
#define LCDRAM7_FP15BP0                 _LCDRAM7.Bits.FP15BP0
#define LCDRAM7_FP15BP1                 _LCDRAM7.Bits.FP15BP1
#define LCDRAM7_FP15BP2                 _LCDRAM7.Bits.FP15BP2
#define LCDRAM7_FP15BP3                 _LCDRAM7.Bits.FP15BP3
#define LCDRAM7_FP14BP                  _LCDRAM7.MergedBits.grpFP14BP
#define LCDRAM7_FP15BP                  _LCDRAM7.MergedBits.grpFP15BP

#define LCDRAM7_FP14BP0_MASK            1
#define LCDRAM7_FP14BP1_MASK            2
#define LCDRAM7_FP14BP2_MASK            4
#define LCDRAM7_FP14BP3_MASK            8
#define LCDRAM7_FP15BP0_MASK            16
#define LCDRAM7_FP15BP1_MASK            32
#define LCDRAM7_FP15BP2_MASK            64
#define LCDRAM7_FP15BP3_MASK            128
#define LCDRAM7_FP14BP_MASK             15
#define LCDRAM7_FP14BP_BITNUM           0
#define LCDRAM7_FP15BP_MASK             240
#define LCDRAM7_FP15BP_BITNUM           4


/*** LCDRAM8 - LCDRAM Register 8; 0x00001850 ***/
typedef union {
  byte Byte;
  struct {
    byte FP16BP0     :1;                                       /* LCD Segment 16 Data Bit 0 */
    byte FP16BP1     :1;                                       /* LCD Segment 16 Data Bit 1 */
    byte FP16BP2     :1;                                       /* LCD Segment 16 Data Bit 2 */
    byte FP16BP3     :1;                                       /* LCD Segment 16 Data Bit 3 */
    byte FP17BP0     :1;                                       /* LCD Segment 17 Data Bit 0 */
    byte FP17BP1     :1;                                       /* LCD Segment 17 Data Bit 1 */
    byte FP17BP2     :1;                                       /* LCD Segment 17 Data Bit 2 */
    byte FP17BP3     :1;                                       /* LCD Segment 17 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP16BP :4;
    byte grpFP17BP :4;
  } MergedBits;
} LCDRAM8STR;
extern volatile LCDRAM8STR _LCDRAM8 @0x00001850;
#define LCDRAM8                         _LCDRAM8.Byte
#define LCDRAM8_FP16BP0                 _LCDRAM8.Bits.FP16BP0
#define LCDRAM8_FP16BP1                 _LCDRAM8.Bits.FP16BP1
#define LCDRAM8_FP16BP2                 _LCDRAM8.Bits.FP16BP2
#define LCDRAM8_FP16BP3                 _LCDRAM8.Bits.FP16BP3
#define LCDRAM8_FP17BP0                 _LCDRAM8.Bits.FP17BP0
#define LCDRAM8_FP17BP1                 _LCDRAM8.Bits.FP17BP1
#define LCDRAM8_FP17BP2                 _LCDRAM8.Bits.FP17BP2
#define LCDRAM8_FP17BP3                 _LCDRAM8.Bits.FP17BP3
#define LCDRAM8_FP16BP                  _LCDRAM8.MergedBits.grpFP16BP
#define LCDRAM8_FP17BP                  _LCDRAM8.MergedBits.grpFP17BP

#define LCDRAM8_FP16BP0_MASK            1
#define LCDRAM8_FP16BP1_MASK            2
#define LCDRAM8_FP16BP2_MASK            4
#define LCDRAM8_FP16BP3_MASK            8
#define LCDRAM8_FP17BP0_MASK            16
#define LCDRAM8_FP17BP1_MASK            32
#define LCDRAM8_FP17BP2_MASK            64
#define LCDRAM8_FP17BP3_MASK            128
#define LCDRAM8_FP16BP_MASK             15
#define LCDRAM8_FP16BP_BITNUM           0
#define LCDRAM8_FP17BP_MASK             240
#define LCDRAM8_FP17BP_BITNUM           4


/*** LCDRAM9 - LCDRAM Register 9; 0x00001851 ***/
typedef union {
  byte Byte;
  struct {
    byte FP18BP0     :1;                                       /* LCD Segment 18 Data Bit 0 */
    byte FP18BP1     :1;                                       /* LCD Segment 18 Data Bit 1 */
    byte FP18BP2     :1;                                       /* LCD Segment 18 Data Bit 2 */
    byte FP18BP3     :1;                                       /* LCD Segment 18 Data Bit 3 */
    byte FP19BP0     :1;                                       /* LCD Segment 19 Data Bit 0 */
    byte FP19BP1     :1;                                       /* LCD Segment 19 Data Bit 1 */
    byte FP19BP2     :1;                                       /* LCD Segment 19 Data Bit 2 */
    byte FP19BP3     :1;                                       /* LCD Segment 19 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP18BP :4;
    byte grpFP19BP :4;
  } MergedBits;
} LCDRAM9STR;
extern volatile LCDRAM9STR _LCDRAM9 @0x00001851;
#define LCDRAM9                         _LCDRAM9.Byte
#define LCDRAM9_FP18BP0                 _LCDRAM9.Bits.FP18BP0
#define LCDRAM9_FP18BP1                 _LCDRAM9.Bits.FP18BP1
#define LCDRAM9_FP18BP2                 _LCDRAM9.Bits.FP18BP2
#define LCDRAM9_FP18BP3                 _LCDRAM9.Bits.FP18BP3
#define LCDRAM9_FP19BP0                 _LCDRAM9.Bits.FP19BP0
#define LCDRAM9_FP19BP1                 _LCDRAM9.Bits.FP19BP1
#define LCDRAM9_FP19BP2                 _LCDRAM9.Bits.FP19BP2
#define LCDRAM9_FP19BP3                 _LCDRAM9.Bits.FP19BP3
#define LCDRAM9_FP18BP                  _LCDRAM9.MergedBits.grpFP18BP
#define LCDRAM9_FP19BP                  _LCDRAM9.MergedBits.grpFP19BP

#define LCDRAM9_FP18BP0_MASK            1
#define LCDRAM9_FP18BP1_MASK            2
#define LCDRAM9_FP18BP2_MASK            4
#define LCDRAM9_FP18BP3_MASK            8
#define LCDRAM9_FP19BP0_MASK            16
#define LCDRAM9_FP19BP1_MASK            32
#define LCDRAM9_FP19BP2_MASK            64
#define LCDRAM9_FP19BP3_MASK            128
#define LCDRAM9_FP18BP_MASK             15
#define LCDRAM9_FP18BP_BITNUM           0
#define LCDRAM9_FP19BP_MASK             240
#define LCDRAM9_FP19BP_BITNUM           4


/*** LCDRAM10 - LCDRAM Register 10; 0x00001852 ***/
typedef union {
  byte Byte;
  struct {
    byte FP20BP0     :1;                                       /* LCD Segment 20 Data Bit 0 */
    byte FP20BP1     :1;                                       /* LCD Segment 20 Data Bit 1 */
    byte FP20BP2     :1;                                       /* LCD Segment 20 Data Bit 2 */
    byte FP20BP3     :1;                                       /* LCD Segment 20 Data Bit 3 */
    byte FP21BP0     :1;                                       /* LCD Segment 21 Data Bit 0 */
    byte FP21BP1     :1;                                       /* LCD Segment 21 Data Bit 1 */
    byte FP21BP2     :1;                                       /* LCD Segment 21 Data Bit 2 */
    byte FP21BP3     :1;                                       /* LCD Segment 21 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP20BP :4;
    byte grpFP21BP :4;
  } MergedBits;
} LCDRAM10STR;
extern volatile LCDRAM10STR _LCDRAM10 @0x00001852;
#define LCDRAM10                        _LCDRAM10.Byte
#define LCDRAM10_FP20BP0                _LCDRAM10.Bits.FP20BP0
#define LCDRAM10_FP20BP1                _LCDRAM10.Bits.FP20BP1
#define LCDRAM10_FP20BP2                _LCDRAM10.Bits.FP20BP2
#define LCDRAM10_FP20BP3                _LCDRAM10.Bits.FP20BP3
#define LCDRAM10_FP21BP0                _LCDRAM10.Bits.FP21BP0
#define LCDRAM10_FP21BP1                _LCDRAM10.Bits.FP21BP1
#define LCDRAM10_FP21BP2                _LCDRAM10.Bits.FP21BP2
#define LCDRAM10_FP21BP3                _LCDRAM10.Bits.FP21BP3
#define LCDRAM10_FP20BP                 _LCDRAM10.MergedBits.grpFP20BP
#define LCDRAM10_FP21BP                 _LCDRAM10.MergedBits.grpFP21BP

#define LCDRAM10_FP20BP0_MASK           1
#define LCDRAM10_FP20BP1_MASK           2
#define LCDRAM10_FP20BP2_MASK           4
#define LCDRAM10_FP20BP3_MASK           8
#define LCDRAM10_FP21BP0_MASK           16
#define LCDRAM10_FP21BP1_MASK           32
#define LCDRAM10_FP21BP2_MASK           64
#define LCDRAM10_FP21BP3_MASK           128
#define LCDRAM10_FP20BP_MASK            15
#define LCDRAM10_FP20BP_BITNUM          0
#define LCDRAM10_FP21BP_MASK            240
#define LCDRAM10_FP21BP_BITNUM          4


/*** LCDRAM11 - LCDRAM Register 11; 0x00001853 ***/
typedef union {
  byte Byte;
  struct {
    byte FP22BP0     :1;                                       /* LCD Segment 22 Data Bit 0 */
    byte FP22BP1     :1;                                       /* LCD Segment 22 Data Bit 1 */
    byte FP22BP2     :1;                                       /* LCD Segment 22 Data Bit 2 */
    byte FP22BP3     :1;                                       /* LCD Segment 22 Data Bit 3 */
    byte FP23BP0     :1;                                       /* LCD Segment 23 Data Bit 0 */
    byte FP23BP1     :1;                                       /* LCD Segment 23 Data Bit 1 */
    byte FP23BP2     :1;                                       /* LCD Segment 23 Data Bit 2 */
    byte FP23BP3     :1;                                       /* LCD Segment 23 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP22BP :4;
    byte grpFP23BP :4;
  } MergedBits;
} LCDRAM11STR;
extern volatile LCDRAM11STR _LCDRAM11 @0x00001853;
#define LCDRAM11                        _LCDRAM11.Byte
#define LCDRAM11_FP22BP0                _LCDRAM11.Bits.FP22BP0
#define LCDRAM11_FP22BP1                _LCDRAM11.Bits.FP22BP1
#define LCDRAM11_FP22BP2                _LCDRAM11.Bits.FP22BP2
#define LCDRAM11_FP22BP3                _LCDRAM11.Bits.FP22BP3
#define LCDRAM11_FP23BP0                _LCDRAM11.Bits.FP23BP0
#define LCDRAM11_FP23BP1                _LCDRAM11.Bits.FP23BP1
#define LCDRAM11_FP23BP2                _LCDRAM11.Bits.FP23BP2
#define LCDRAM11_FP23BP3                _LCDRAM11.Bits.FP23BP3
#define LCDRAM11_FP22BP                 _LCDRAM11.MergedBits.grpFP22BP
#define LCDRAM11_FP23BP                 _LCDRAM11.MergedBits.grpFP23BP

#define LCDRAM11_FP22BP0_MASK           1
#define LCDRAM11_FP22BP1_MASK           2
#define LCDRAM11_FP22BP2_MASK           4
#define LCDRAM11_FP22BP3_MASK           8
#define LCDRAM11_FP23BP0_MASK           16
#define LCDRAM11_FP23BP1_MASK           32
#define LCDRAM11_FP23BP2_MASK           64
#define LCDRAM11_FP23BP3_MASK           128
#define LCDRAM11_FP22BP_MASK            15
#define LCDRAM11_FP22BP_BITNUM          0
#define LCDRAM11_FP23BP_MASK            240
#define LCDRAM11_FP23BP_BITNUM          4


/*** LCDRAM12 - LCDRAM Register 12; 0x00001854 ***/
typedef union {
  byte Byte;
  struct {
    byte FP24BP0     :1;                                       /* LCD Segment 24 Data Bit 0 */
    byte FP24BP1     :1;                                       /* LCD Segment 24 Data Bit 1 */
    byte FP24BP2     :1;                                       /* LCD Segment 24 Data Bit 2 */
    byte FP24BP3     :1;                                       /* LCD Segment 24 Data Bit 3 */
    byte FP25BP0     :1;                                       /* LCD Segment 25 Data Bit 0 */
    byte FP25BP1     :1;                                       /* LCD Segment 25 Data Bit 1 */
    byte FP25BP2     :1;                                       /* LCD Segment 25 Data Bit 2 */
    byte FP25BP3     :1;                                       /* LCD Segment 25 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP24BP :4;
    byte grpFP25BP :4;
  } MergedBits;
} LCDRAM12STR;
extern volatile LCDRAM12STR _LCDRAM12 @0x00001854;
#define LCDRAM12                        _LCDRAM12.Byte
#define LCDRAM12_FP24BP0                _LCDRAM12.Bits.FP24BP0
#define LCDRAM12_FP24BP1                _LCDRAM12.Bits.FP24BP1
#define LCDRAM12_FP24BP2                _LCDRAM12.Bits.FP24BP2
#define LCDRAM12_FP24BP3                _LCDRAM12.Bits.FP24BP3
#define LCDRAM12_FP25BP0                _LCDRAM12.Bits.FP25BP0
#define LCDRAM12_FP25BP1                _LCDRAM12.Bits.FP25BP1
#define LCDRAM12_FP25BP2                _LCDRAM12.Bits.FP25BP2
#define LCDRAM12_FP25BP3                _LCDRAM12.Bits.FP25BP3
#define LCDRAM12_FP24BP                 _LCDRAM12.MergedBits.grpFP24BP
#define LCDRAM12_FP25BP                 _LCDRAM12.MergedBits.grpFP25BP

#define LCDRAM12_FP24BP0_MASK           1
#define LCDRAM12_FP24BP1_MASK           2
#define LCDRAM12_FP24BP2_MASK           4
#define LCDRAM12_FP24BP3_MASK           8
#define LCDRAM12_FP25BP0_MASK           16
#define LCDRAM12_FP25BP1_MASK           32
#define LCDRAM12_FP25BP2_MASK           64
#define LCDRAM12_FP25BP3_MASK           128
#define LCDRAM12_FP24BP_MASK            15
#define LCDRAM12_FP24BP_BITNUM          0
#define LCDRAM12_FP25BP_MASK            240
#define LCDRAM12_FP25BP_BITNUM          4


/*** LCDRAM13 - LCDRAM Register 13; 0x00001855 ***/
typedef union {
  byte Byte;
  struct {
    byte FP26BP0     :1;                                       /* LCD Segment 26 Data Bit 0 */
    byte FP26BP1     :1;                                       /* LCD Segment 26 Data Bit 1 */
    byte FP26BP2     :1;                                       /* LCD Segment 26 Data Bit 2 */
    byte FP26BP3     :1;                                       /* LCD Segment 26 Data Bit 3 */
    byte FP27BP0     :1;                                       /* LCD Segment 27 Data Bit 0 */
    byte FP27BP1     :1;                                       /* LCD Segment 27 Data Bit 1 */
    byte FP27BP2     :1;                                       /* LCD Segment 27 Data Bit 2 */
    byte FP27BP3     :1;                                       /* LCD Segment 27 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP26BP :4;
    byte grpFP27BP :4;
  } MergedBits;
} LCDRAM13STR;
extern volatile LCDRAM13STR _LCDRAM13 @0x00001855;
#define LCDRAM13                        _LCDRAM13.Byte
#define LCDRAM13_FP26BP0                _LCDRAM13.Bits.FP26BP0
#define LCDRAM13_FP26BP1                _LCDRAM13.Bits.FP26BP1
#define LCDRAM13_FP26BP2                _LCDRAM13.Bits.FP26BP2
#define LCDRAM13_FP26BP3                _LCDRAM13.Bits.FP26BP3
#define LCDRAM13_FP27BP0                _LCDRAM13.Bits.FP27BP0
#define LCDRAM13_FP27BP1                _LCDRAM13.Bits.FP27BP1
#define LCDRAM13_FP27BP2                _LCDRAM13.Bits.FP27BP2
#define LCDRAM13_FP27BP3                _LCDRAM13.Bits.FP27BP3
#define LCDRAM13_FP26BP                 _LCDRAM13.MergedBits.grpFP26BP
#define LCDRAM13_FP27BP                 _LCDRAM13.MergedBits.grpFP27BP

#define LCDRAM13_FP26BP0_MASK           1
#define LCDRAM13_FP26BP1_MASK           2
#define LCDRAM13_FP26BP2_MASK           4
#define LCDRAM13_FP26BP3_MASK           8
#define LCDRAM13_FP27BP0_MASK           16
#define LCDRAM13_FP27BP1_MASK           32
#define LCDRAM13_FP27BP2_MASK           64
#define LCDRAM13_FP27BP3_MASK           128
#define LCDRAM13_FP26BP_MASK            15
#define LCDRAM13_FP26BP_BITNUM          0
#define LCDRAM13_FP27BP_MASK            240
#define LCDRAM13_FP27BP_BITNUM          4


/*** LCDRAM14 - LCDRAM Register 14; 0x00001856 ***/
typedef union {
  byte Byte;
  struct {
    byte FP28BP0     :1;                                       /* LCD Segment 28 Data Bit 0 */
    byte FP28BP1     :1;                                       /* LCD Segment 28 Data Bit 1 */
    byte FP28BP2     :1;                                       /* LCD Segment 28 Data Bit 2 */
    byte FP28BP3     :1;                                       /* LCD Segment 28 Data Bit 3 */
    byte FP29BP0     :1;                                       /* LCD Segment 29 Data Bit 0 */
    byte FP29BP1     :1;                                       /* LCD Segment 29 Data Bit 1 */
    byte FP29BP2     :1;                                       /* LCD Segment 29 Data Bit 2 */
    byte FP29BP3     :1;                                       /* LCD Segment 29 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP28BP :4;
    byte grpFP29BP :4;
  } MergedBits;
} LCDRAM14STR;
extern volatile LCDRAM14STR _LCDRAM14 @0x00001856;
#define LCDRAM14                        _LCDRAM14.Byte
#define LCDRAM14_FP28BP0                _LCDRAM14.Bits.FP28BP0
#define LCDRAM14_FP28BP1                _LCDRAM14.Bits.FP28BP1
#define LCDRAM14_FP28BP2                _LCDRAM14.Bits.FP28BP2
#define LCDRAM14_FP28BP3                _LCDRAM14.Bits.FP28BP3
#define LCDRAM14_FP29BP0                _LCDRAM14.Bits.FP29BP0
#define LCDRAM14_FP29BP1                _LCDRAM14.Bits.FP29BP1
#define LCDRAM14_FP29BP2                _LCDRAM14.Bits.FP29BP2
#define LCDRAM14_FP29BP3                _LCDRAM14.Bits.FP29BP3
#define LCDRAM14_FP28BP                 _LCDRAM14.MergedBits.grpFP28BP
#define LCDRAM14_FP29BP                 _LCDRAM14.MergedBits.grpFP29BP

#define LCDRAM14_FP28BP0_MASK           1
#define LCDRAM14_FP28BP1_MASK           2
#define LCDRAM14_FP28BP2_MASK           4
#define LCDRAM14_FP28BP3_MASK           8
#define LCDRAM14_FP29BP0_MASK           16
#define LCDRAM14_FP29BP1_MASK           32
#define LCDRAM14_FP29BP2_MASK           64
#define LCDRAM14_FP29BP3_MASK           128
#define LCDRAM14_FP28BP_MASK            15
#define LCDRAM14_FP28BP_BITNUM          0
#define LCDRAM14_FP29BP_MASK            240
#define LCDRAM14_FP29BP_BITNUM          4


/*** LCDRAM15 - LCDRAM Register 15; 0x00001857 ***/
typedef union {
  byte Byte;
  struct {
    byte FP30BP0     :1;                                       /* LCD Segment 30 Data Bit 0 */
    byte FP30BP1     :1;                                       /* LCD Segment 30 Data Bit 1 */
    byte FP30BP2     :1;                                       /* LCD Segment 30 Data Bit 2 */
    byte FP30BP3     :1;                                       /* LCD Segment 30 Data Bit 3 */
    byte FP31BP0     :1;                                       /* LCD Segment 31 Data Bit 0 */
    byte FP31BP1     :1;                                       /* LCD Segment 31 Data Bit 1 */
    byte FP31BP2     :1;                                       /* LCD Segment 31 Data Bit 2 */
    byte FP31BP3     :1;                                       /* LCD Segment 31 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP30BP :4;
    byte grpFP31BP :4;
  } MergedBits;
} LCDRAM15STR;
extern volatile LCDRAM15STR _LCDRAM15 @0x00001857;
#define LCDRAM15                        _LCDRAM15.Byte
#define LCDRAM15_FP30BP0                _LCDRAM15.Bits.FP30BP0
#define LCDRAM15_FP30BP1                _LCDRAM15.Bits.FP30BP1
#define LCDRAM15_FP30BP2                _LCDRAM15.Bits.FP30BP2
#define LCDRAM15_FP30BP3                _LCDRAM15.Bits.FP30BP3
#define LCDRAM15_FP31BP0                _LCDRAM15.Bits.FP31BP0
#define LCDRAM15_FP31BP1                _LCDRAM15.Bits.FP31BP1
#define LCDRAM15_FP31BP2                _LCDRAM15.Bits.FP31BP2
#define LCDRAM15_FP31BP3                _LCDRAM15.Bits.FP31BP3
#define LCDRAM15_FP30BP                 _LCDRAM15.MergedBits.grpFP30BP
#define LCDRAM15_FP31BP                 _LCDRAM15.MergedBits.grpFP31BP

#define LCDRAM15_FP30BP0_MASK           1
#define LCDRAM15_FP30BP1_MASK           2
#define LCDRAM15_FP30BP2_MASK           4
#define LCDRAM15_FP30BP3_MASK           8
#define LCDRAM15_FP31BP0_MASK           16
#define LCDRAM15_FP31BP1_MASK           32
#define LCDRAM15_FP31BP2_MASK           64
#define LCDRAM15_FP31BP3_MASK           128
#define LCDRAM15_FP30BP_MASK            15
#define LCDRAM15_FP30BP_BITNUM          0
#define LCDRAM15_FP31BP_MASK            240
#define LCDRAM15_FP31BP_BITNUM          4


/*** LCDRAM16 - LCDRAM Register 16; 0x00001858 ***/
typedef union {
  byte Byte;
  struct {
    byte FP32BP0     :1;                                       /* LCD Segment 32 Data Bit 0 */
    byte FP32BP1     :1;                                       /* LCD Segment 32 Data Bit 1 */
    byte FP32BP2     :1;                                       /* LCD Segment 32 Data Bit 2 */
    byte FP32BP3     :1;                                       /* LCD Segment 32 Data Bit 3 */
    byte FP33BP0     :1;                                       /* LCD Segment 33 Data Bit 0 */
    byte FP33BP1     :1;                                       /* LCD Segment 33 Data Bit 1 */
    byte FP33BP2     :1;                                       /* LCD Segment 33 Data Bit 2 */
    byte FP33BP3     :1;                                       /* LCD Segment 33 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP32BP :4;
    byte grpFP33BP :4;
  } MergedBits;
} LCDRAM16STR;
extern volatile LCDRAM16STR _LCDRAM16 @0x00001858;
#define LCDRAM16                        _LCDRAM16.Byte
#define LCDRAM16_FP32BP0                _LCDRAM16.Bits.FP32BP0
#define LCDRAM16_FP32BP1                _LCDRAM16.Bits.FP32BP1
#define LCDRAM16_FP32BP2                _LCDRAM16.Bits.FP32BP2
#define LCDRAM16_FP32BP3                _LCDRAM16.Bits.FP32BP3
#define LCDRAM16_FP33BP0                _LCDRAM16.Bits.FP33BP0
#define LCDRAM16_FP33BP1                _LCDRAM16.Bits.FP33BP1
#define LCDRAM16_FP33BP2                _LCDRAM16.Bits.FP33BP2
#define LCDRAM16_FP33BP3                _LCDRAM16.Bits.FP33BP3
#define LCDRAM16_FP32BP                 _LCDRAM16.MergedBits.grpFP32BP
#define LCDRAM16_FP33BP                 _LCDRAM16.MergedBits.grpFP33BP

#define LCDRAM16_FP32BP0_MASK           1
#define LCDRAM16_FP32BP1_MASK           2
#define LCDRAM16_FP32BP2_MASK           4
#define LCDRAM16_FP32BP3_MASK           8
#define LCDRAM16_FP33BP0_MASK           16
#define LCDRAM16_FP33BP1_MASK           32
#define LCDRAM16_FP33BP2_MASK           64
#define LCDRAM16_FP33BP3_MASK           128
#define LCDRAM16_FP32BP_MASK            15
#define LCDRAM16_FP32BP_BITNUM          0
#define LCDRAM16_FP33BP_MASK            240
#define LCDRAM16_FP33BP_BITNUM          4


/*** LCDRAM17 - LCDRAM Register 17; 0x00001859 ***/
typedef union {
  byte Byte;
  struct {
    byte FP34BP0     :1;                                       /* LCD Segment 34 Data Bit 0 */
    byte FP34BP1     :1;                                       /* LCD Segment 34 Data Bit 1 */
    byte FP34BP2     :1;                                       /* LCD Segment 34 Data Bit 2 */
    byte FP34BP3     :1;                                       /* LCD Segment 34 Data Bit 3 */
    byte FP35BP0     :1;                                       /* LCD Segment 35 Data Bit 0 */
    byte FP35BP1     :1;                                       /* LCD Segment 35 Data Bit 1 */
    byte FP35BP2     :1;                                       /* LCD Segment 35 Data Bit 2 */
    byte FP35BP3     :1;                                       /* LCD Segment 35 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP34BP :4;
    byte grpFP35BP :4;
  } MergedBits;
} LCDRAM17STR;
extern volatile LCDRAM17STR _LCDRAM17 @0x00001859;
#define LCDRAM17                        _LCDRAM17.Byte
#define LCDRAM17_FP34BP0                _LCDRAM17.Bits.FP34BP0
#define LCDRAM17_FP34BP1                _LCDRAM17.Bits.FP34BP1
#define LCDRAM17_FP34BP2                _LCDRAM17.Bits.FP34BP2
#define LCDRAM17_FP34BP3                _LCDRAM17.Bits.FP34BP3
#define LCDRAM17_FP35BP0                _LCDRAM17.Bits.FP35BP0
#define LCDRAM17_FP35BP1                _LCDRAM17.Bits.FP35BP1
#define LCDRAM17_FP35BP2                _LCDRAM17.Bits.FP35BP2
#define LCDRAM17_FP35BP3                _LCDRAM17.Bits.FP35BP3
#define LCDRAM17_FP34BP                 _LCDRAM17.MergedBits.grpFP34BP
#define LCDRAM17_FP35BP                 _LCDRAM17.MergedBits.grpFP35BP

#define LCDRAM17_FP34BP0_MASK           1
#define LCDRAM17_FP34BP1_MASK           2
#define LCDRAM17_FP34BP2_MASK           4
#define LCDRAM17_FP34BP3_MASK           8
#define LCDRAM17_FP35BP0_MASK           16
#define LCDRAM17_FP35BP1_MASK           32
#define LCDRAM17_FP35BP2_MASK           64
#define LCDRAM17_FP35BP3_MASK           128
#define LCDRAM17_FP34BP_MASK            15
#define LCDRAM17_FP34BP_BITNUM          0
#define LCDRAM17_FP35BP_MASK            240
#define LCDRAM17_FP35BP_BITNUM          4


/*** LCDRAM18 - LCDRAM Register 18; 0x0000185A ***/
typedef union {
  byte Byte;
  struct {
    byte FP36BP0     :1;                                       /* LCD Segment 36 Data Bit 0 */
    byte FP36BP1     :1;                                       /* LCD Segment 36 Data Bit 1 */
    byte FP36BP2     :1;                                       /* LCD Segment 36 Data Bit 2 */
    byte FP36BP3     :1;                                       /* LCD Segment 36 Data Bit 3 */
    byte FP37BP0     :1;                                       /* LCD Segment 37 Data Bit 0 */
    byte FP37BP1     :1;                                       /* LCD Segment 37 Data Bit 1 */
    byte FP37BP2     :1;                                       /* LCD Segment 37 Data Bit 2 */
    byte FP37BP3     :1;                                       /* LCD Segment 37 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP36BP :4;
    byte grpFP37BP :4;
  } MergedBits;
} LCDRAM18STR;
extern volatile LCDRAM18STR _LCDRAM18 @0x0000185A;
#define LCDRAM18                        _LCDRAM18.Byte
#define LCDRAM18_FP36BP0                _LCDRAM18.Bits.FP36BP0
#define LCDRAM18_FP36BP1                _LCDRAM18.Bits.FP36BP1
#define LCDRAM18_FP36BP2                _LCDRAM18.Bits.FP36BP2
#define LCDRAM18_FP36BP3                _LCDRAM18.Bits.FP36BP3
#define LCDRAM18_FP37BP0                _LCDRAM18.Bits.FP37BP0
#define LCDRAM18_FP37BP1                _LCDRAM18.Bits.FP37BP1
#define LCDRAM18_FP37BP2                _LCDRAM18.Bits.FP37BP2
#define LCDRAM18_FP37BP3                _LCDRAM18.Bits.FP37BP3
#define LCDRAM18_FP36BP                 _LCDRAM18.MergedBits.grpFP36BP
#define LCDRAM18_FP37BP                 _LCDRAM18.MergedBits.grpFP37BP

#define LCDRAM18_FP36BP0_MASK           1
#define LCDRAM18_FP36BP1_MASK           2
#define LCDRAM18_FP36BP2_MASK           4
#define LCDRAM18_FP36BP3_MASK           8
#define LCDRAM18_FP37BP0_MASK           16
#define LCDRAM18_FP37BP1_MASK           32
#define LCDRAM18_FP37BP2_MASK           64
#define LCDRAM18_FP37BP3_MASK           128
#define LCDRAM18_FP36BP_MASK            15
#define LCDRAM18_FP36BP_BITNUM          0
#define LCDRAM18_FP37BP_MASK            240
#define LCDRAM18_FP37BP_BITNUM          4


/*** LCDRAM19 - LCDRAM Register 19; 0x0000185B ***/
typedef union {
  byte Byte;
  struct {
    byte FP38BP0     :1;                                       /* LCD Segment 38 Data Bit 0 */
    byte FP38BP1     :1;                                       /* LCD Segment 38 Data Bit 1 */
    byte FP38BP2     :1;                                       /* LCD Segment 38 Data Bit 2 */
    byte FP38BP3     :1;                                       /* LCD Segment 38 Data Bit 3 */
    byte FP39BP0     :1;                                       /* LCD Segment 39 Data Bit 0 */
    byte FP39BP1     :1;                                       /* LCD Segment 39 Data Bit 1 */
    byte FP39BP2     :1;                                       /* LCD Segment 39 Data Bit 2 */
    byte FP39BP3     :1;                                       /* LCD Segment 39 Data Bit 3 */
  } Bits;
  struct {
    byte grpFP38BP :4;
    byte grpFP39BP :4;
  } MergedBits;
} LCDRAM19STR;
extern volatile LCDRAM19STR _LCDRAM19 @0x0000185B;
#define LCDRAM19                        _LCDRAM19.Byte
#define LCDRAM19_FP38BP0                _LCDRAM19.Bits.FP38BP0
#define LCDRAM19_FP38BP1                _LCDRAM19.Bits.FP38BP1
#define LCDRAM19_FP38BP2                _LCDRAM19.Bits.FP38BP2
#define LCDRAM19_FP38BP3                _LCDRAM19.Bits.FP38BP3
#define LCDRAM19_FP39BP0                _LCDRAM19.Bits.FP39BP0
#define LCDRAM19_FP39BP1                _LCDRAM19.Bits.FP39BP1
#define LCDRAM19_FP39BP2                _LCDRAM19.Bits.FP39BP2
#define LCDRAM19_FP39BP3                _LCDRAM19.Bits.FP39BP3
#define LCDRAM19_FP38BP                 _LCDRAM19.MergedBits.grpFP38BP
#define LCDRAM19_FP39BP                 _LCDRAM19.MergedBits.grpFP39BP

#define LCDRAM19_FP38BP0_MASK           1
#define LCDRAM19_FP38BP1_MASK           2
#define LCDRAM19_FP38BP2_MASK           4
#define LCDRAM19_FP38BP3_MASK           8
#define LCDRAM19_FP39BP0_MASK           16
#define LCDRAM19_FP39BP1_MASK           32
#define LCDRAM19_FP39BP2_MASK           64
#define LCDRAM19_FP39BP3_MASK           128
#define LCDRAM19_FP38BP_MASK            15
#define LCDRAM19_FP38BP_BITNUM          0
#define LCDRAM19_FP39BP_MASK            240
#define LCDRAM19_FP39BP_BITNUM          4


/*** LCDRAM20 - LCDRAM Register 20; 0x0000185C ***/
typedef union {
  byte Byte;
  struct {
    byte FP40BP0     :1;                                       /* LCD Segment 40 Data Bit 0 */
    byte FP40BP1     :1;                                       /* LCD Segment 40 Data Bit 1 */
    byte FP40BP2     :1;                                       /* LCD Segment 40 Data Bit 2 */
    byte FP40BP3     :1;                                       /* LCD Segment 40 Data Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFP40BP :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} LCDRAM20STR;
extern volatile LCDRAM20STR _LCDRAM20 @0x0000185C;
#define LCDRAM20                        _LCDRAM20.Byte
#define LCDRAM20_FP40BP0                _LCDRAM20.Bits.FP40BP0
#define LCDRAM20_FP40BP1                _LCDRAM20.Bits.FP40BP1
#define LCDRAM20_FP40BP2                _LCDRAM20.Bits.FP40BP2
#define LCDRAM20_FP40BP3                _LCDRAM20.Bits.FP40BP3
#define LCDRAM20_FP40BP                 _LCDRAM20.MergedBits.grpFP40BP

#define LCDRAM20_FP40BP0_MASK           1
#define LCDRAM20_FP40BP1_MASK           2
#define LCDRAM20_FP40BP2_MASK           4
#define LCDRAM20_FP40BP3_MASK           8
#define LCDRAM20_FP40BP_MASK            15
#define LCDRAM20_FP40BP_BITNUM          0


/*** LCDCLKS - LCD Clock Source Register; 0x00001862 ***/
typedef union {
  byte Byte;
  struct {
    byte CLKADJ0     :1;                                       /* LCD Clock Source Divider Bit 0 */
    byte CLKADJ1     :1;                                       /* LCD Clock Source Divider Bit 1 */
    byte CLKADJ2     :1;                                       /* LCD Clock Source Divider Bit 2 */
    byte CLKADJ3     :1;                                       /* LCD Clock Source Divider Bit 3 */
    byte CLKADJ4     :1;                                       /* LCD Clock Source Divider Bit 4 */
    byte CLKADJ5     :1;                                       /* LCD Clock Source Divider Bit 5 */
    byte DIV16       :1;                                       /* LCD Clock Prescaler Enable */
    byte SOURCE      :1;                                       /* LCD Clock Source Select */
  } Bits;
  struct {
    byte grpCLKADJ :6;
    byte grpDIV_16 :1;
    byte         :1;
  } MergedBits;
} LCDCLKSSTR;
extern volatile LCDCLKSSTR _LCDCLKS @0x00001862;
#define LCDCLKS                         _LCDCLKS.Byte
#define LCDCLKS_CLKADJ0                 _LCDCLKS.Bits.CLKADJ0
#define LCDCLKS_CLKADJ1                 _LCDCLKS.Bits.CLKADJ1
#define LCDCLKS_CLKADJ2                 _LCDCLKS.Bits.CLKADJ2
#define LCDCLKS_CLKADJ3                 _LCDCLKS.Bits.CLKADJ3
#define LCDCLKS_CLKADJ4                 _LCDCLKS.Bits.CLKADJ4
#define LCDCLKS_CLKADJ5                 _LCDCLKS.Bits.CLKADJ5
#define LCDCLKS_DIV16                   _LCDCLKS.Bits.DIV16
#define LCDCLKS_SOURCE                  _LCDCLKS.Bits.SOURCE
#define LCDCLKS_CLKADJ                  _LCDCLKS.MergedBits.grpCLKADJ

#define LCDCLKS_CLKADJ0_MASK            1
#define LCDCLKS_CLKADJ1_MASK            2
#define LCDCLKS_CLKADJ2_MASK            4
#define LCDCLKS_CLKADJ3_MASK            8
#define LCDCLKS_CLKADJ4_MASK            16
#define LCDCLKS_CLKADJ5_MASK            32
#define LCDCLKS_DIV16_MASK              64
#define LCDCLKS_SOURCE_MASK             128
#define LCDCLKS_CLKADJ_MASK             63
#define LCDCLKS_CLKADJ_BITNUM           0


/*** LCDSUPPLY - LCD Voltage Supply Register; 0x00001863 ***/
typedef union {
  byte Byte;
  struct {
    byte VSUPPLY0    :1;                                       /* Blink Rate Configuration Bit 0 */
    byte VSUPPLY1    :1;                                       /* Blink Rate Configuration Bit 1 */
    byte BBYPASS     :1;                                       /* Op Amp Control */
    byte             :1; 
    byte CPCADJ0     :1;                                       /* LCD Module Charge Pump Clock Adjust Bit 0 */
    byte CPCADJ1     :1;                                       /* LCD Module Charge Pump Clock Adjust Bit 1 */
    byte LCDCPMS     :1;                                       /* LCD Module Charge Pump Mode Select */
    byte LCDCPEN     :1;                                       /* LCD Module Charge Pump Enable */
  } Bits;
  struct {
    byte grpVSUPPLY :2;
    byte         :1;
    byte         :1;
    byte grpCPCADJ :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} LCDSUPPLYSTR;
extern volatile LCDSUPPLYSTR _LCDSUPPLY @0x00001863;
#define LCDSUPPLY                       _LCDSUPPLY.Byte
#define LCDSUPPLY_VSUPPLY0              _LCDSUPPLY.Bits.VSUPPLY0
#define LCDSUPPLY_VSUPPLY1              _LCDSUPPLY.Bits.VSUPPLY1
#define LCDSUPPLY_BBYPASS               _LCDSUPPLY.Bits.BBYPASS
#define LCDSUPPLY_CPCADJ0               _LCDSUPPLY.Bits.CPCADJ0
#define LCDSUPPLY_CPCADJ1               _LCDSUPPLY.Bits.CPCADJ1
#define LCDSUPPLY_LCDCPMS               _LCDSUPPLY.Bits.LCDCPMS
#define LCDSUPPLY_LCDCPEN               _LCDSUPPLY.Bits.LCDCPEN
#define LCDSUPPLY_VSUPPLY               _LCDSUPPLY.MergedBits.grpVSUPPLY
#define LCDSUPPLY_CPCADJ                _LCDSUPPLY.MergedBits.grpCPCADJ

#define LCDSUPPLY_VSUPPLY0_MASK         1
#define LCDSUPPLY_VSUPPLY1_MASK         2
#define LCDSUPPLY_BBYPASS_MASK          4
#define LCDSUPPLY_CPCADJ0_MASK          16
#define LCDSUPPLY_CPCADJ1_MASK          32
#define LCDSUPPLY_LCDCPMS_MASK          64
#define LCDSUPPLY_LCDCPEN_MASK          128
#define LCDSUPPLY_VSUPPLY_MASK          3
#define LCDSUPPLY_VSUPPLY_BITNUM        0
#define LCDSUPPLY_CPCADJ_MASK           48
#define LCDSUPPLY_CPCADJ_BITNUM         4


/*** LCDBCTL - LCD Blink Control Register; 0x00001864 ***/
typedef union {
  byte Byte;
  struct {
    byte BRATE0      :1;                                       /* Blink Rate Configuration Bit 0 */
    byte BRATE1      :1;                                       /* Blink Rate Configuration Bit 1 */
    byte BRATE2      :1;                                       /* Blink Rate Configuration Bit 2 */
    byte BLKMODE     :1;                                       /* Blink Mode Select */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte BLINK       :1;                                       /* Blink Command */
  } Bits;
  struct {
    byte grpBRATE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} LCDBCTLSTR;
extern volatile LCDBCTLSTR _LCDBCTL @0x00001864;
#define LCDBCTL                         _LCDBCTL.Byte
#define LCDBCTL_BRATE0                  _LCDBCTL.Bits.BRATE0
#define LCDBCTL_BRATE1                  _LCDBCTL.Bits.BRATE1
#define LCDBCTL_BRATE2                  _LCDBCTL.Bits.BRATE2
#define LCDBCTL_BLKMODE                 _LCDBCTL.Bits.BLKMODE
#define LCDBCTL_BLINK                   _LCDBCTL.Bits.BLINK
#define LCDBCTL_BRATE                   _LCDBCTL.MergedBits.grpBRATE

#define LCDBCTL_BRATE0_MASK             1
#define LCDBCTL_BRATE1_MASK             2
#define LCDBCTL_BRATE2_MASK             4
#define LCDBCTL_BLKMODE_MASK            8
#define LCDBCTL_BLINK_MASK              128
#define LCDBCTL_BRATE_MASK              7
#define LCDBCTL_BRATE_BITNUM            0


/*** LCDCMD - LCD Command and Status Register; 0x00001865 ***/
typedef union {
  byte Byte;
  struct {
    byte BLANK       :1;                                       /* LCD Display Blank Command */
    byte LCDCLR      :1;                                       /* LCD Data Register Clear Command */
    byte             :1; 
    byte LCDDRMS     :1;                                       /* LCD Module Data Register Mode Select */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LCDIF       :1;                                       /* LCD Interrupt Flag */
  } Bits;
} LCDCMDSTR;
extern volatile LCDCMDSTR _LCDCMD @0x00001865;
#define LCDCMD                          _LCDCMD.Byte
#define LCDCMD_BLANK                    _LCDCMD.Bits.BLANK
#define LCDCMD_LCDCLR                   _LCDCMD.Bits.LCDCLR
#define LCDCMD_LCDDRMS                  _LCDCMD.Bits.LCDDRMS
#define LCDCMD_LCDIF                    _LCDCMD.Bits.LCDIF

#define LCDCMD_BLANK_MASK               1
#define LCDCMD_LCDCLR_MASK              2
#define LCDCMD_LCDDRMS_MASK             8
#define LCDCMD_LCDIF_MASK               128


/*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x0000FFB0 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key bits, bit 7 */
  } Bits;
} NVBACKKEY0STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x0000FFB0 = <NVBACKKEY0_INITVAL>; */
#define _NVBACKKEY0 (*(const NVBACKKEY0STR * __far)0x0000FFB0)
#define NVBACKKEY0                      _NVBACKKEY0.Byte
#define NVBACKKEY0_KEY0                 _NVBACKKEY0.Bits.KEY0
#define NVBACKKEY0_KEY1                 _NVBACKKEY0.Bits.KEY1
#define NVBACKKEY0_KEY2                 _NVBACKKEY0.Bits.KEY2
#define NVBACKKEY0_KEY3                 _NVBACKKEY0.Bits.KEY3
#define NVBACKKEY0_KEY4                 _NVBACKKEY0.Bits.KEY4
#define NVBACKKEY0_KEY5                 _NVBACKKEY0.Bits.KEY5
#define NVBACKKEY0_KEY6                 _NVBACKKEY0.Bits.KEY6
#define NVBACKKEY0_KEY7                 _NVBACKKEY0.Bits.KEY7
/* NVBACKKEY_ARR: Access 8 NVBACKKEYx registers in an array */
#define NVBACKKEY_ARR                   ((volatile byte * __far) &NVBACKKEY0)

#define NVBACKKEY0_KEY0_MASK            1
#define NVBACKKEY0_KEY1_MASK            2
#define NVBACKKEY0_KEY2_MASK            4
#define NVBACKKEY0_KEY3_MASK            8
#define NVBACKKEY0_KEY4_MASK            16
#define NVBACKKEY0_KEY5_MASK            32
#define NVBACKKEY0_KEY6_MASK            64
#define NVBACKKEY0_KEY7_MASK            128


/*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x0000FFB1 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key bits, bit 7 */
  } Bits;
} NVBACKKEY1STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x0000FFB1 = <NVBACKKEY1_INITVAL>; */
#define _NVBACKKEY1 (*(const NVBACKKEY1STR * __far)0x0000FFB1)
#define NVBACKKEY1                      _NVBACKKEY1.Byte
#define NVBACKKEY1_KEY0                 _NVBACKKEY1.Bits.KEY0
#define NVBACKKEY1_KEY1                 _NVBACKKEY1.Bits.KEY1
#define NVBACKKEY1_KEY2                 _NVBACKKEY1.Bits.KEY2
#define NVBACKKEY1_KEY3                 _NVBACKKEY1.Bits.KEY3
#define NVBACKKEY1_KEY4                 _NVBACKKEY1.Bits.KEY4
#define NVBACKKEY1_KEY5                 _NVBACKKEY1.Bits.KEY5
#define NVBACKKEY1_KEY6                 _NVBACKKEY1.Bits.KEY6
#define NVBACKKEY1_KEY7                 _NVBACKKEY1.Bits.KEY7

#define NVBACKKEY1_KEY0_MASK            1
#define NVBACKKEY1_KEY1_MASK            2
#define NVBACKKEY1_KEY2_MASK            4
#define NVBACKKEY1_KEY3_MASK            8
#define NVBACKKEY1_KEY4_MASK            16
#define NVBACKKEY1_KEY5_MASK            32
#define NVBACKKEY1_KEY6_MASK            64
#define NVBACKKEY1_KEY7_MASK            128


/*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x0000FFB2 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key bits, bit 7 */
  } Bits;
} NVBACKKEY2STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x0000FFB2 = <NVBACKKEY2_INITVAL>; */
#define _NVBACKKEY2 (*(const NVBACKKEY2STR * __far)0x0000FFB2)
#define NVBACKKEY2                      _NVBACKKEY2.Byte
#define NVBACKKEY2_KEY0                 _NVBACKKEY2.Bits.KEY0
#define NVBACKKEY2_KEY1                 _NVBACKKEY2.Bits.KEY1
#define NVBACKKEY2_KEY2                 _NVBACKKEY2.Bits.KEY2
#define NVBACKKEY2_KEY3                 _NVBACKKEY2.Bits.KEY3
#define NVBACKKEY2_KEY4                 _NVBACKKEY2.Bits.KEY4
#define NVBACKKEY2_KEY5                 _NVBACKKEY2.Bits.KEY5
#define NVBACKKEY2_KEY6                 _NVBACKKEY2.Bits.KEY6
#define NVBACKKEY2_KEY7                 _NVBACKKEY2.Bits.KEY7

#define NVBACKKEY2_KEY0_MASK            1
#define NVBACKKEY2_KEY1_MASK            2
#define NVBACKKEY2_KEY2_MASK            4
#define NVBACKKEY2_KEY3_MASK            8
#define NVBACKKEY2_KEY4_MASK            16
#define NVBACKKEY2_KEY5_MASK            32
#define NVBACKKEY2_KEY6_MASK            64
#define NVBACKKEY2_KEY7_MASK            128


/*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x0000FFB3 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key bits, bit 7 */
  } Bits;
} NVBACKKEY3STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x0000FFB3 = <NVBACKKEY3_INITVAL>; */
#define _NVBACKKEY3 (*(const NVBACKKEY3STR * __far)0x0000FFB3)
#define NVBACKKEY3                      _NVBACKKEY3.Byte
#define NVBACKKEY3_KEY0                 _NVBACKKEY3.Bits.KEY0
#define NVBACKKEY3_KEY1                 _NVBACKKEY3.Bits.KEY1
#define NVBACKKEY3_KEY2                 _NVBACKKEY3.Bits.KEY2
#define NVBACKKEY3_KEY3                 _NVBACKKEY3.Bits.KEY3
#define NVBACKKEY3_KEY4                 _NVBACKKEY3.Bits.KEY4
#define NVBACKKEY3_KEY5                 _NVBACKKEY3.Bits.KEY5
#define NVBACKKEY3_KEY6                 _NVBACKKEY3.Bits.KEY6
#define NVBACKKEY3_KEY7                 _NVBACKKEY3.Bits.KEY7

#define NVBACKKEY3_KEY0_MASK            1
#define NVBACKKEY3_KEY1_MASK            2
#define NVBACKKEY3_KEY2_MASK            4
#define NVBACKKEY3_KEY3_MASK            8
#define NVBACKKEY3_KEY4_MASK            16
#define NVBACKKEY3_KEY5_MASK            32
#define NVBACKKEY3_KEY6_MASK            64
#define NVBACKKEY3_KEY7_MASK            128


/*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x0000FFB4 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key bits, bit 7 */
  } Bits;
} NVBACKKEY4STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x0000FFB4 = <NVBACKKEY4_INITVAL>; */
#define _NVBACKKEY4 (*(const NVBACKKEY4STR * __far)0x0000FFB4)
#define NVBACKKEY4                      _NVBACKKEY4.Byte
#define NVBACKKEY4_KEY0                 _NVBACKKEY4.Bits.KEY0
#define NVBACKKEY4_KEY1                 _NVBACKKEY4.Bits.KEY1
#define NVBACKKEY4_KEY2                 _NVBACKKEY4.Bits.KEY2
#define NVBACKKEY4_KEY3                 _NVBACKKEY4.Bits.KEY3
#define NVBACKKEY4_KEY4                 _NVBACKKEY4.Bits.KEY4
#define NVBACKKEY4_KEY5                 _NVBACKKEY4.Bits.KEY5
#define NVBACKKEY4_KEY6                 _NVBACKKEY4.Bits.KEY6
#define NVBACKKEY4_KEY7                 _NVBACKKEY4.Bits.KEY7

#define NVBACKKEY4_KEY0_MASK            1
#define NVBACKKEY4_KEY1_MASK            2
#define NVBACKKEY4_KEY2_MASK            4
#define NVBACKKEY4_KEY3_MASK            8
#define NVBACKKEY4_KEY4_MASK            16
#define NVBACKKEY4_KEY5_MASK            32
#define NVBACKKEY4_KEY6_MASK            64
#define NVBACKKEY4_KEY7_MASK            128


/*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x0000FFB5 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key bits, bit 7 */
  } Bits;
} NVBACKKEY5STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x0000FFB5 = <NVBACKKEY5_INITVAL>; */
#define _NVBACKKEY5 (*(const NVBACKKEY5STR * __far)0x0000FFB5)
#define NVBACKKEY5                      _NVBACKKEY5.Byte
#define NVBACKKEY5_KEY0                 _NVBACKKEY5.Bits.KEY0
#define NVBACKKEY5_KEY1                 _NVBACKKEY5.Bits.KEY1
#define NVBACKKEY5_KEY2                 _NVBACKKEY5.Bits.KEY2
#define NVBACKKEY5_KEY3                 _NVBACKKEY5.Bits.KEY3
#define NVBACKKEY5_KEY4                 _NVBACKKEY5.Bits.KEY4
#define NVBACKKEY5_KEY5                 _NVBACKKEY5.Bits.KEY5
#define NVBACKKEY5_KEY6                 _NVBACKKEY5.Bits.KEY6
#define NVBACKKEY5_KEY7                 _NVBACKKEY5.Bits.KEY7

#define NVBACKKEY5_KEY0_MASK            1
#define NVBACKKEY5_KEY1_MASK            2
#define NVBACKKEY5_KEY2_MASK            4
#define NVBACKKEY5_KEY3_MASK            8
#define NVBACKKEY5_KEY4_MASK            16
#define NVBACKKEY5_KEY5_MASK            32
#define NVBACKKEY5_KEY6_MASK            64
#define NVBACKKEY5_KEY7_MASK            128


/*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x0000FFB6 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key bits, bit 7 */
  } Bits;
} NVBACKKEY6STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x0000FFB6 = <NVBACKKEY6_INITVAL>; */
#define _NVBACKKEY6 (*(const NVBACKKEY6STR * __far)0x0000FFB6)
#define NVBACKKEY6                      _NVBACKKEY6.Byte
#define NVBACKKEY6_KEY0                 _NVBACKKEY6.Bits.KEY0
#define NVBACKKEY6_KEY1                 _NVBACKKEY6.Bits.KEY1
#define NVBACKKEY6_KEY2                 _NVBACKKEY6.Bits.KEY2
#define NVBACKKEY6_KEY3                 _NVBACKKEY6.Bits.KEY3
#define NVBACKKEY6_KEY4                 _NVBACKKEY6.Bits.KEY4
#define NVBACKKEY6_KEY5                 _NVBACKKEY6.Bits.KEY5
#define NVBACKKEY6_KEY6                 _NVBACKKEY6.Bits.KEY6
#define NVBACKKEY6_KEY7                 _NVBACKKEY6.Bits.KEY7

#define NVBACKKEY6_KEY0_MASK            1
#define NVBACKKEY6_KEY1_MASK            2
#define NVBACKKEY6_KEY2_MASK            4
#define NVBACKKEY6_KEY3_MASK            8
#define NVBACKKEY6_KEY4_MASK            16
#define NVBACKKEY6_KEY5_MASK            32
#define NVBACKKEY6_KEY6_MASK            64
#define NVBACKKEY6_KEY7_MASK            128


/*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x0000FFB7 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key bits, bit 7 */
  } Bits;
} NVBACKKEY7STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x0000FFB7 = <NVBACKKEY7_INITVAL>; */
#define _NVBACKKEY7 (*(const NVBACKKEY7STR * __far)0x0000FFB7)
#define NVBACKKEY7                      _NVBACKKEY7.Byte
#define NVBACKKEY7_KEY0                 _NVBACKKEY7.Bits.KEY0
#define NVBACKKEY7_KEY1                 _NVBACKKEY7.Bits.KEY1
#define NVBACKKEY7_KEY2                 _NVBACKKEY7.Bits.KEY2
#define NVBACKKEY7_KEY3                 _NVBACKKEY7.Bits.KEY3
#define NVBACKKEY7_KEY4                 _NVBACKKEY7.Bits.KEY4
#define NVBACKKEY7_KEY5                 _NVBACKKEY7.Bits.KEY5
#define NVBACKKEY7_KEY6                 _NVBACKKEY7.Bits.KEY6
#define NVBACKKEY7_KEY7                 _NVBACKKEY7.Bits.KEY7

#define NVBACKKEY7_KEY0_MASK            1
#define NVBACKKEY7_KEY1_MASK            2
#define NVBACKKEY7_KEY2_MASK            4
#define NVBACKKEY7_KEY3_MASK            8
#define NVBACKKEY7_KEY4_MASK            16
#define NVBACKKEY7_KEY5_MASK            32
#define NVBACKKEY7_KEY6_MASK            64
#define NVBACKKEY7_KEY7_MASK            128


/*** NVPROT - Nonvolatile FLASH Protection Register; 0x0000FFBD ***/
typedef union {
  byte Byte;
  struct {
    byte FPDIS       :1;                                       /* FLASH Protection Disable */
    byte FPS1        :1;                                       /* FLASH Protect Select Bit 1 */
    byte FPS2        :1;                                       /* FLASH Protect Select Bit 2 */
    byte FPS3        :1;                                       /* FLASH Protect Select Bit 3 */
    byte FPS4        :1;                                       /* FLASH Protect Select Bit 4 */
    byte FPS5        :1;                                       /* FLASH Protect Select Bit 5 */
    byte FPS6        :1;                                       /* FLASH Protect Select Bit 6 */
    byte FPS7        :1;                                       /* FLASH Protect Select Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS_1 :7;
  } MergedBits;
} NVPROTSTR;
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000FFBD = <NVPROT_INITVAL>; */
#define _NVPROT (*(const NVPROTSTR * __far)0x0000FFBD)
#define NVPROT                          _NVPROT.Byte
#define NVPROT_FPDIS                    _NVPROT.Bits.FPDIS
#define NVPROT_FPS1                     _NVPROT.Bits.FPS1
#define NVPROT_FPS2                     _NVPROT.Bits.FPS2
#define NVPROT_FPS3                     _NVPROT.Bits.FPS3
#define NVPROT_FPS4                     _NVPROT.Bits.FPS4
#define NVPROT_FPS5                     _NVPROT.Bits.FPS5
#define NVPROT_FPS6                     _NVPROT.Bits.FPS6
#define NVPROT_FPS7                     _NVPROT.Bits.FPS7
#define NVPROT_FPS_1                    _NVPROT.MergedBits.grpFPS_1
#define NVPROT_FPS                      NVPROT_FPS_1

#define NVPROT_FPDIS_MASK               1
#define NVPROT_FPS1_MASK                2
#define NVPROT_FPS2_MASK                4
#define NVPROT_FPS3_MASK                8
#define NVPROT_FPS4_MASK                16
#define NVPROT_FPS5_MASK                32
#define NVPROT_FPS6_MASK                64
#define NVPROT_FPS7_MASK                128
#define NVPROT_FPS_1_MASK               254
#define NVPROT_FPS_1_BITNUM             1


/*** NVICGTRM - ICG Trim Register; 0x0000FFBE ***/
typedef union {
  byte Byte;
  struct {
    byte NVTRIM0     :1;                                       /* ICG Trim Bit 0 */
    byte NVTRIM1     :1;                                       /* ICG Trim Bit 1 */
    byte NVTRIM2     :1;                                       /* ICG Trim Bit 2 */
    byte NVTRIM3     :1;                                       /* ICG Trim Bit 3 */
    byte NVTRIM4     :1;                                       /* ICG Trim Bit 4 */
    byte NVTRIM5     :1;                                       /* ICG Trim Bit 5 */
    byte NVTRIM6     :1;                                       /* ICG Trim Bit 6 */
    byte NVTRIM7     :1;                                       /* ICG Trim Bit 7 */
  } Bits;
} NVICGTRMSTR;
extern volatile NVICGTRMSTR _NVICGTRM @0x0000FFBE;
#define NVICGTRM                        _NVICGTRM.Byte
#define NVICGTRM_NVTRIM0                _NVICGTRM.Bits.NVTRIM0
#define NVICGTRM_NVTRIM1                _NVICGTRM.Bits.NVTRIM1
#define NVICGTRM_NVTRIM2                _NVICGTRM.Bits.NVTRIM2
#define NVICGTRM_NVTRIM3                _NVICGTRM.Bits.NVTRIM3
#define NVICGTRM_NVTRIM4                _NVICGTRM.Bits.NVTRIM4
#define NVICGTRM_NVTRIM5                _NVICGTRM.Bits.NVTRIM5
#define NVICGTRM_NVTRIM6                _NVICGTRM.Bits.NVTRIM6
#define NVICGTRM_NVTRIM7                _NVICGTRM.Bits.NVTRIM7

#define NVICGTRM_NVTRIM0_MASK           1
#define NVICGTRM_NVTRIM1_MASK           2
#define NVICGTRM_NVTRIM2_MASK           4
#define NVICGTRM_NVTRIM3_MASK           8
#define NVICGTRM_NVTRIM4_MASK           16
#define NVICGTRM_NVTRIM5_MASK           32
#define NVICGTRM_NVTRIM6_MASK           64
#define NVICGTRM_NVTRIM7_MASK           128


/*** NVOPT - Nonvolatile FLASH Options Register; 0x0000FFBF ***/
typedef union {
  byte Byte;
  struct {
    byte SEC00       :1;                                       /* Security State Code Bit 0 */
    byte SEC01       :1;                                       /* Security State Code Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FNORED      :1;                                       /* Vector Redirection Disable */
    byte KEYEN       :1;                                       /* Backdoor Key Mechanism Enable */
  } Bits;
  struct {
    byte grpSEC0 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVOPTSTR;
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000FFBF = <NVOPT_INITVAL>; */
#define _NVOPT (*(const NVOPTSTR * __far)0x0000FFBF)
#define NVOPT                           _NVOPT.Byte
#define NVOPT_SEC00                     _NVOPT.Bits.SEC00
#define NVOPT_SEC01                     _NVOPT.Bits.SEC01
#define NVOPT_FNORED                    _NVOPT.Bits.FNORED
#define NVOPT_KEYEN                     _NVOPT.Bits.KEYEN
#define NVOPT_SEC0                      _NVOPT.MergedBits.grpSEC0

#define NVOPT_SEC00_MASK                1
#define NVOPT_SEC01_MASK                2
#define NVOPT_FNORED_MASK               64
#define NVOPT_KEYEN_MASK                128
#define NVOPT_SEC0_MASK                 3
#define NVOPT_SEC0_BITNUM               0



#endif
