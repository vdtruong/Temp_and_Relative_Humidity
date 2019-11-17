/* Based on CPU DB MC9S08LC60_80, version 2.87.175 (RegistersPrg V2.03) */
/* DataSheet : MC9S08LC60 Rev. 0.08 1/10/2006 */

#include "MC9S08LC60.h"

/*lint -save -esym(765, *) */


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile PTADSTR _PTAD;                                    /* Port A Data Register; 0x00000000 */
volatile PTADDSTR _PTADD;                                  /* Data Direction Register A; 0x00000001 */
volatile PTBDSTR _PTBD;                                    /* Port B Data Register; 0x00000002 */
volatile PTBDDSTR _PTBDD;                                  /* Data Direction Register B; 0x00000003 */
volatile PTCDSTR _PTCD;                                    /* Port C Data Register; 0x00000004 */
volatile PTCDDSTR _PTCDD;                                  /* Data Direction Register C; 0x00000005 */
volatile IRQSCSTR _IRQSC;                                  /* Interrupt Request Status and Control Register; 0x00000006 */
volatile KBI1SCSTR _KBI1SC;                                /* KBI1 Status and Control; 0x00000008 */
volatile KBI1PESTR _KBI1PE;                                /* KBI1 Pin Enable Register; 0x00000009 */
volatile KBI1ESSTR _KBI1ES;                                /* KBI1 Edge Select Register; 0x0000000A */
volatile KBI2SCSTR _KBI2SC;                                /* KBI2 Status and Control; 0x0000000C */
volatile KBI2PESTR _KBI2PE;                                /* KBI2 Pin Enable Register; 0x0000000D */
volatile KBI2ESSTR _KBI2ES;                                /* KBI2 Edge Select Register; 0x0000000E */
volatile ACMPSCSTR _ACMPSC;                                /* Analog Comparator Status and Control Register; 0x0000000F */
volatile ADCSC1STR _ADCSC1;                                /* Status and Control Register; 0x00000010 */
volatile ADCSC2STR _ADCSC2;                                /* Status and Control Register 2; 0x00000011 */
volatile ADCCFGSTR _ADCCFG;                                /* Configuration Register; 0x00000016 */
volatile APCTL1STR _APCTL1;                                /* ADC Pin Control 1 Register; 0x00000017 */
volatile IICASTR _IICA;                                    /* IIC Address Register; 0x00000018 */
volatile IICFSTR _IICF;                                    /* IIC Frequency Divider Register; 0x00000019 */
volatile IICCSTR _IICC;                                    /* IIC Control Register; 0x0000001A */
volatile IICSSTR _IICS;                                    /* IIC Status Register; 0x0000001B */
volatile IICDSTR _IICD;                                    /* IIC Data I/O Register; 0x0000001C */
volatile SCIC1STR _SCIC1;                                  /* SCI Control Register 1; 0x00000022 */
volatile SCIC2STR _SCIC2;                                  /* SCI Control Register 2; 0x00000023 */
volatile SCIS1STR _SCIS1;                                  /* SCI Status Register 1; 0x00000024 */
volatile SCIS2STR _SCIS2;                                  /* SCI Status Register 2; 0x00000025 */
volatile SCIC3STR _SCIC3;                                  /* SCI Control Register 3; 0x00000026 */
volatile SCIDSTR _SCID;                                    /* SCI Data Register; 0x00000027 */
volatile SPI1C1STR _SPI1C1;                                /* SPI1 Control Register 1; 0x00000028 */
volatile SPI1C2STR _SPI1C2;                                /* SPI1 Control Register 2; 0x00000029 */
volatile SPI1BRSTR _SPI1BR;                                /* SPI1 Baud Rate Register; 0x0000002A */
volatile SPI1SSTR _SPI1S;                                  /* SPI1 Status Register; 0x0000002B */
volatile SPI1DSTR _SPI1D;                                  /* SPI1 Data Register; 0x0000002D */
volatile SPI2C1STR _SPI2C1;                                /* SPI2 Control Register 1; 0x00000030 */
volatile SPI2C2STR _SPI2C2;                                /* SPI2 Control Register 2; 0x00000031 */
volatile SPI2BRSTR _SPI2BR;                                /* SPI2 Baud Rate Register; 0x00000032 */
volatile SPI2SSTR _SPI2S;                                  /* SPI2 Status Register; 0x00000033 */
volatile SPI2DSTR _SPI2D;                                  /* SPI2 Data Register; 0x00000035 */
volatile ICGC1STR _ICGC1;                                  /* ICG Control Register 1; 0x00000038 */
volatile ICGC2STR _ICGC2;                                  /* ICG Control Register 2; 0x00000039 */
volatile ICGS1STR _ICGS1;                                  /* ICG Status Register 1; 0x0000003A */
volatile ICGS2STR _ICGS2;                                  /* ICG Status Register 2; 0x0000003B */
volatile ICGTRMSTR _ICGTRM;                                /* ICG Trim Register; 0x0000003E */
volatile TPM1SCSTR _TPM1SC;                                /* TPM 1 Status and Control Register; 0x00000040 */
volatile TPM1C0SCSTR _TPM1C0SC;                            /* TPM 1 Timer Channel 0 Status and Control Register; 0x00000045 */
volatile TPM1C1SCSTR _TPM1C1SC;                            /* TPM 1 Timer Channel 1 Status and Control Register; 0x00000048 */
volatile TPM2SCSTR _TPM2SC;                                /* TPM 2 Status and Control Register; 0x00000050 */
volatile TPM2C0SCSTR _TPM2C0SC;                            /* TPM 2 Timer Channel 0 Status and Control Register; 0x00000055 */
volatile TPM2C1SCSTR _TPM2C1SC;                            /* TPM 2 Timer Channel 1 Status and Control Register; 0x00000058 */
volatile SRSSTR _SRS;                                      /* System Reset Status; 0x00001800 */
volatile SBDFRSTR _SBDFR;                                  /* System Background Debug Force Reset Register; 0x00001801 */
volatile SOPT1STR _SOPT1;                                  /* System Options Register 1; 0x00001802 */
volatile SOPT2STR _SOPT2;                                  /* System Options Register 2; 0x00001803 */
volatile SRTISCSTR _SRTISC;                                /* System RTI Status and Control Register; 0x00001808 */
volatile SPMSC1STR _SPMSC1;                                /* System Power Management Status and Control 1 Register; 0x00001809 */
volatile SPMSC2STR _SPMSC2;                                /* System Power Management Status and Control 2 Register; 0x0000180A */
volatile SPMSC3STR _SPMSC3;                                /* System Power Management Status and Control 3 Register; 0x0000180C */
volatile DBGCAHSTR _DBGCAH;                                /* Debug Comparator A High Register; 0x00001810 */
volatile DBGCALSTR _DBGCAL;                                /* Debug Comparator A Low Register; 0x00001811 */
volatile DBGCBHSTR _DBGCBH;                                /* Debug Comparator B High Register; 0x00001812 */
volatile DBGCBLSTR _DBGCBL;                                /* Debug Comparator B Low Register; 0x00001813 */
volatile DBGCSTR _DBGC;                                    /* Debug Control Register; 0x00001816 */
volatile DBGTSTR _DBGT;                                    /* Debug Trigger Register; 0x00001817 */
volatile DBGSSTR _DBGS;                                    /* Debug Status Register; 0x00001818 */
volatile FCDIVSTR _FCDIV;                                  /* FLASH Clock Divider Register; 0x00001820 */
volatile FOPTSTR _FOPT;                                    /* FLASH Options Register; 0x00001821 */
volatile FCNFGSTR _FCNFG;                                  /* FLASH Configuration Register; 0x00001823 */
volatile FPROTSTR _FPROT;                                  /* FLASH Protection Register; 0x00001824 */
volatile FSTATSTR _FSTAT;                                  /* FLASH Status Register; 0x00001825 */
volatile FCMDSTR _FCMD;                                    /* FLASH Command Register; 0x00001826 */
volatile PTAPESTR _PTAPE;                                  /* Pullup Enable for Port A; 0x00001830 */
volatile PTASESTR _PTASE;                                  /* Slew Rate Control Enable for Port A; 0x00001831 */
volatile PTADSSTR _PTADS;                                  /* Output Drive Strength Selection for Port A; 0x00001832 */
volatile PTBPESTR _PTBPE;                                  /* Pullup Enable for Port B; 0x00001834 */
volatile PTBSESTR _PTBSE;                                  /* Slew Rate Control Enable for Port B; 0x00001835 */
volatile PTBDSSTR _PTBDS;                                  /* Output Drive Strength Selection for Port B; 0x00001836 */
volatile PTCPESTR _PTCPE;                                  /* Pullup Enable for Port B; 0x00001838 */
volatile PTCSESTR _PTCSE;                                  /* Slew Rate Control Enable for Port B; 0x00001839 */
volatile PTCDSSTR _PTCDS;                                  /* Output Drive Strength Selection for Port B; 0x0000183A */
volatile LCDCR0STR _LCDCR0;                                /* LCD Control Register 0; 0x00001840 */
volatile LCDCR1STR _LCDCR1;                                /* LCD Control Register 1; 0x00001841 */
volatile FPENR0STR _FPENR0;                                /* LCD Frontplane Enable Registers 0; 0x00001842 */
volatile FPENR1STR _FPENR1;                                /* LCD Frontplane Enable Registers 1; 0x00001843 */
volatile FPENR2STR _FPENR2;                                /* LCD Frontplane Enable Registers 2; 0x00001844 */
volatile FPENR3STR _FPENR3;                                /* LCD Frontplane Enable Registers 3; 0x00001845 */
volatile FPENR4STR _FPENR4;                                /* LCD Frontplane Enable Registers 4; 0x00001846 */
volatile FPENR5STR _FPENR5;                                /* LCD Frontplane Enable Registers 5; 0x00001847 */
volatile LCDRAM0STR _LCDRAM0;                              /* LCDRAM Register 0; 0x00001848 */
volatile LCDRAM1STR _LCDRAM1;                              /* LCDRAM Register 1; 0x00001849 */
volatile LCDRAM2STR _LCDRAM2;                              /* LCDRAM Register 2; 0x0000184A */
volatile LCDRAM3STR _LCDRAM3;                              /* LCDRAM Register 3; 0x0000184B */
volatile LCDRAM4STR _LCDRAM4;                              /* LCDRAM Register 4; 0x0000184C */
volatile LCDRAM5STR _LCDRAM5;                              /* LCDRAM Register 5; 0x0000184D */
volatile LCDRAM6STR _LCDRAM6;                              /* LCDRAM Register 6; 0x0000184E */
volatile LCDRAM7STR _LCDRAM7;                              /* LCDRAM Register 7; 0x0000184F */
volatile LCDRAM8STR _LCDRAM8;                              /* LCDRAM Register 8; 0x00001850 */
volatile LCDRAM9STR _LCDRAM9;                              /* LCDRAM Register 9; 0x00001851 */
volatile LCDRAM10STR _LCDRAM10;                            /* LCDRAM Register 10; 0x00001852 */
volatile LCDRAM11STR _LCDRAM11;                            /* LCDRAM Register 11; 0x00001853 */
volatile LCDRAM12STR _LCDRAM12;                            /* LCDRAM Register 12; 0x00001854 */
volatile LCDRAM13STR _LCDRAM13;                            /* LCDRAM Register 13; 0x00001855 */
volatile LCDRAM14STR _LCDRAM14;                            /* LCDRAM Register 14; 0x00001856 */
volatile LCDRAM15STR _LCDRAM15;                            /* LCDRAM Register 15; 0x00001857 */
volatile LCDRAM16STR _LCDRAM16;                            /* LCDRAM Register 16; 0x00001858 */
volatile LCDRAM17STR _LCDRAM17;                            /* LCDRAM Register 17; 0x00001859 */
volatile LCDRAM18STR _LCDRAM18;                            /* LCDRAM Register 18; 0x0000185A */
volatile LCDRAM19STR _LCDRAM19;                            /* LCDRAM Register 19; 0x0000185B */
volatile LCDRAM20STR _LCDRAM20;                            /* LCDRAM Register 20; 0x0000185C */
volatile LCDCLKSSTR _LCDCLKS;                              /* LCD Clock Source Register; 0x00001862 */
volatile LCDSUPPLYSTR _LCDSUPPLY;                          /* LCD Voltage Supply Register; 0x00001863 */
volatile LCDBCTLSTR _LCDBCTL;                              /* LCD Blink Control Register; 0x00001864 */
volatile LCDCMDSTR _LCDCMD;                                /* LCD Command and Status Register; 0x00001865 */
/* NVBACKKEY0 - macro for reading non volatile register    Backdoor Comparison Key 0; 0x0000FFB0 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x0000FFB0 = <NVBACKKEY0_INITVAL>; */
/* NVBACKKEY1 - macro for reading non volatile register    Backdoor Comparison Key 1; 0x0000FFB1 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x0000FFB1 = <NVBACKKEY1_INITVAL>; */
/* NVBACKKEY2 - macro for reading non volatile register    Backdoor Comparison Key 2; 0x0000FFB2 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x0000FFB2 = <NVBACKKEY2_INITVAL>; */
/* NVBACKKEY3 - macro for reading non volatile register    Backdoor Comparison Key 3; 0x0000FFB3 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x0000FFB3 = <NVBACKKEY3_INITVAL>; */
/* NVBACKKEY4 - macro for reading non volatile register    Backdoor Comparison Key 4; 0x0000FFB4 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x0000FFB4 = <NVBACKKEY4_INITVAL>; */
/* NVBACKKEY5 - macro for reading non volatile register    Backdoor Comparison Key 5; 0x0000FFB5 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x0000FFB5 = <NVBACKKEY5_INITVAL>; */
/* NVBACKKEY6 - macro for reading non volatile register    Backdoor Comparison Key 6; 0x0000FFB6 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x0000FFB6 = <NVBACKKEY6_INITVAL>; */
/* NVBACKKEY7 - macro for reading non volatile register    Backdoor Comparison Key 7; 0x0000FFB7 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x0000FFB7 = <NVBACKKEY7_INITVAL>; */
/* NVPROT - macro for reading non volatile register        Nonvolatile FLASH Protection Register; 0x0000FFBD */
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000FFBD = <NVPROT_INITVAL>; */
volatile NVICGTRMSTR _NVICGTRM;                            /* ICG Trim Register; 0x0000FFBE */
/* NVOPT - macro for reading non volatile register         Nonvolatile FLASH Options Register; 0x0000FFBF */
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000FFBF = <NVOPT_INITVAL>; */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile ADCRSTR _ADCR;                                    /* ADC Result Data Right Justified; 0x00000012 */
volatile ADCCVSTR _ADCCV;                                  /* Compare Value Register; 0x00000014 */
volatile SCIBDSTR _SCIBD;                                  /* SCI Baud Rate Register; 0x00000020 */
volatile ICGFLTSTR _ICGFLT;                                /* ICG Upper Filter; 0x0000003C */
volatile TPM1CNTSTR _TPM1CNT;                              /* TPM 1 Counter Register; 0x00000041 */
volatile TPM1MODSTR _TPM1MOD;                              /* TPM 1 Timer Counter Modulo Register; 0x00000043 */
volatile TPM1C0VSTR _TPM1C0V;                              /* TPM 1 Timer Channel 0 Value Register; 0x00000046 */
volatile TPM1C1VSTR _TPM1C1V;                              /* TPM 1 Timer Channel 1 Value Register; 0x00000049 */
volatile TPM2CNTSTR _TPM2CNT;                              /* TPM 2 Counter Register; 0x00000051 */
volatile TPM2MODSTR _TPM2MOD;                              /* TPM 2 Timer Counter Modulo Register; 0x00000053 */
volatile TPM2C0VSTR _TPM2C0V;                              /* TPM 2 Timer Channel 0 Value Register; 0x00000056 */
volatile TPM2C1VSTR _TPM2C1V;                              /* TPM 2 Timer Channel 1 Value Register; 0x00000059 */
volatile SDIDSTR _SDID;                                    /* System Integration Module Part ID Register; 0x00001806 */
volatile DBGFSTR _DBGF;                                    /* Debug FIFO Register; 0x00001814 */

/*lint -restore */

/* EOF */
