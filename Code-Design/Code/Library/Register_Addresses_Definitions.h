/* 
 * Register_Addresses_Definitions.h
 * 
 * Register addresses
 * 	The addresses are all defined as:
 * 		#define REGISTER_<name-of-register> <hex-of-address>
 * 
 * Notes:
 * 	1: This is not a physical register.
 * 	2: Unimplemented registers are read as ‘0’.
 * 	3: This register is not available on 28-pin devices.
 * 
 */

#define REGISTER_TOSU 0xFFF               // Comments needed
#define REGISTER_TOSH 0xFFE               // Comments needed
#define REGISTER_TOSL 0xFFD               // Comments needed
                                             
#define REGISTER_STKPTR 0xFFC             // Comments needed
                                             
#define REGISTER_PCLATU 0xFFB             // Comments needed
#define REGISTER_PCLATH 0xFFA             // Comments needed
#define REGISTER_PCL 0xFF9                // Comments needed
                                            
#define REGISTER_TBLPTRU 0xFF8            // Comments needed
#define REGISTER_TBLPTRH 0xFF7            // Comments needed
#define REGISTER_TBLPTRL 0xFF6            // Comments needed
#define REGISTER_TABLAT 0xFF5             // Comments needed
                                             
#define REGISTER_PRODH 0xFF4              // Comments needed
#define REGISTER_PRODL 0xFF3              // Comments needed
                                             
#define REGISTER_INTCON 0xFF2             // Comments needed
#define REGISTER_INTCON2 0xFF1            // Comments needed
#define REGISTER_INTCON3 0xFF0            // Comments needed
#define REGISTER_INDF0 0xFEF              // 1: This is not a physical register.

#define REGISTER_POSTINC0 0xFEE           // 1: This is not a physical register.
#define REGISTER_POSTDEC0 0xFED           // 1: This is not a physical register.
#define REGISTER_PREINC0 0xFEC            // 1: This is not a physical register.

#define REGISTER_PLUSW0 0xFEB             // 1: This is not a physical register.

#define REGISTER_FSR0H 0xFEA              // Comments needed
#define REGISTER_FSR0L 0xFE9              // Comments needed

#define REGISTER_WREG 0xFE8               // Comments needed

#define REGISTER_INDF1 0xFE7              // 1: This is not a physical register.

#define REGISTER_POSTINC1 0xFE6           // 1: This is not a physical register.
#define REGISTER_POSTDEC1 0xFE5           // 1: This is not a physical register.

#define REGISTER_PREINC1 0xFE4            // 1: This is not a physical register.

#define REGISTER_PLUSW1 0xFE3             // 1: This is not a physical register.

#define REGISTER_FSR1H 0xFE2              // Comments needed
#define REGISTER_FSR1L 0xFE1              // Comments needed

#define REGISTER_BSR 0xFE0                // Comments needed

#define REGISTER_INDF2 0xFDF              // 1: This is not a physical register.

#define REGISTER_POSTINC2 0xFDE           // 1: This is not a physical register.
#define REGISTER_POSTDEC2 0xFDD           // 1: This is not a physical register.
#define REGISTER_PREINC2 0xFDC            // 1: This is not a physical register.

#define REGISTER_PLUSW2 0xFDB             // 1: This is not a physical register.

#define REGISTER_FSR2H 0xFDA              // Comments needed
#define REGISTER_FSR2L 0xFD9              // Comments needed

#define REGISTER_STATUS 0xFD8             // Comments needed

#define REGISTER_TMR0H 0xFD7              // Comments needed
#define REGISTER_TMR0L 0xFD6              // Comments needed
#define REGISTER_T0CON 0xFD5              // Comments needed

#define REGISTER_UNIMPLEMENTED_0 0xFD4    // 2: Unimplemented registers are read as ‘0’.

#define REGISTER_OSCCON 0xFD3             // Comments needed

#define REGISTER_HLVDCON 0xFD2            // Comments needed

#define REGISTER_WDTCON 0xFD1             // Comments needed

#define REGISTER_RCON 0xFD0               // Comments needed

#define REGISTER_TMR1H 0xFCF              // Comments needed
#define REGISTER_TMR1L 0xFCE              // Comments needed
#define REGISTER_T1CON 0xFCD              // Comments needed
#define REGISTER_TMR2 0xFCC               // Comments needed

#define REGISTER_PR2 0xFCB                // Comments needed

#define REGISTER_T2CON 0xFCA              // Comments needed

#define REGISTER_SSPBUF 0xFC9             // Comments needed
#define REGISTER_SSPADD 0xFC8             // Comments needed
#define REGISTER_SSPSTAT 0xFC7            // Comments needed
#define REGISTER_SSPCON1 0xFC6            // Comments needed
#define REGISTER_SSPCON2 0xFC5            // Comments needed

#define REGISTER_ADRESH 0xFC4             // Comments needed
#define REGISTER_ADRESL 0xFC3             // Comments needed
#define REGISTER_ADCON0 0xFC2             // Comments needed
#define REGISTER_ADCON1 0xFC1             // Comments needed
#define REGISTER_ADCON2 0xFC0             // Comments needed

#define REGISTER_CCPR1H 0xFBF             // Comments needed
#define REGISTER_CCPR1L 0xFBE             // Comments needed
#define REGISTER_CCP1CON 0xFBD            // Comments needed
#define REGISTER_CCPR2H 0xFBC             // Comments needed
#define REGISTER_CCPR2L 0xFBB             // Comments needed
#define REGISTER_CCP2CON 0xFBA            // Comments needed

#define REGISTER_UNIMPLEMENTED_1 0xFB9    // 2: Unimplemented registers are read as ‘0’.

#define REGISTER_BAUDCON 0xFB8            // Comments needed

#define REGISTER_PWM1CON 0xFB7            // 3: This register is not available on 28-pin devices.

#define REGISTER_ECCP1AS 0xFB6            // 3: This register is not available on 28-pin devices.

#define REGISTER_CVRCON 0xFB5             // Comments needed
#define REGISTER_CMCON 0xFB4              // Comments needed
#define REGISTER_TMR3H 0xFB3              // Comments needed
#define REGISTER_TMR3L 0xFB2              // Comments needed
#define REGISTER_T3CON 0xFB1              // Comments needed

#define REGISTER_SPBRGH 0xFB0             // Comments needed
#define REGISTER_SPBRG 0xFAF              // Comments needed
#define REGISTER_RCREG 0xFAE              // Comments needed

#define REGISTER_TXREG 0xFAD              // Comments needed
#define REGISTER_TXSTA 0xFAC              // Comments needed
#define REGISTER_RCSTA 0xFAB              // Comments needed

#define REGISTER_UNIMPLEMENTED_2 0xFAA    // 2: Unimplemented registers are read as ‘0’.

#define REGISTER_EEADR 0xFA9              // Comments needed
#define REGISTER_EEDATA 0xFA8             // Comments needed
#define REGISTER_EECON2 0xFA7             // 1: This is not a physical register.
#define REGISTER_EECON1 0xFA6             // Comments needed

#define REGISTER_UNIMPLEMENTED_3 0xFA5    // 2: Unimplemented registers are read as ‘0’.
#define REGISTER_UNIMPLEMENTED_4 0xFA4    // 2: Unimplemented registers are read as ‘0’.
#define REGISTER_UNIMPLEMENTED_5 0xFA3    // 2: Unimplemented registers are read as ‘0’.

#define REGISTER_IPR2 0xFA2               // Comments needed
#define REGISTER_PIR2 0xFA1               // Comments needed
#define REGISTER_PIE2 0xFA0               // Comments needed
#define REGISTER_IPR1 0xF9F               // Comments needed
#define REGISTER_PIR1 0xF9E               // Comments needed
#define REGISTER_PIE1 0xF9D               // Comments needed

#define REGISTER_UNIMPLEMENTED_6 0xF9C    // 2: Unimplemented registers are read as ‘0’.

#define REGISTER_OSCTUNE 0xF9B            // Comments needed

#define REGISTER_UNIMPLEMENTED_7 0xF9A    // 2: Unimplemented registers are read as ‘0’.
#define REGISTER_UNIMPLEMENTED_8 0xF99    // 2: Unimplemented registers are read as ‘0’.
#define REGISTER_UNIMPLEMENTED_9 0xF98    // 2: Unimplemented registers are read as ‘0’.
#define REGISTER_UNIMPLEMENTED_10 0xF97   // 2: Unimplemented registers are read as ‘0’.

#define REGISTER_TRISE 0xF96              // 3: This register is not available on 28-pin devices.
#define REGISTER_TRISD 0xF95              // Comments needed
#define REGISTER_TRISC 0xF94              // Comments needed
#define REGISTER_TRISB 0xF93              // Comments needed
#define REGISTER_TRISA 0xF92              // Comments needed

#define REGISTER_UNIMPLEMENTED_11 0xF91   // 2: Unimplemented registers are read as ‘0’.
#define REGISTER_UNIMPLEMENTED_12 0xF90   // 2: Unimplemented registers are read as ‘0’.
#define REGISTER_UNIMPLEMENTED_13 0xF8F   // 2: Unimplemented registers are read as ‘0’.
#define REGISTER_UNIMPLEMENTED_14 0xF8E   // 2: Unimplemented registers are read as ‘0’.

#define REGISTER_LATE 0xF8D               // 3: This register is not available on 28-pin devices.
#define REGISTER_LATD 0xF8C               // 3: This register is not available on 28-pin devices.
#define REGISTER_LATC 0xF8B               // Comments needed
#define REGISTER_LATB 0xF8A               // Comments needed
#define REGISTER_LATA 0xF89               // Comments needed

#define REGISTER_UNIMPLEMENTED_15 0xF88   // 2: Unimplemented registers are read as ‘0’.
#define REGISTER_UNIMPLEMENTED_16 0xF87   // 2: Unimplemented registers are read as ‘0’.
#define REGISTER_UNIMPLEMENTED_17 0xF86   // 2: Unimplemented registers are read as ‘0’.
#define REGISTER_UNIMPLEMENTED_18 0xF85   // 2: Unimplemented registers are read as ‘0’.

#define REGISTER_PORTE 0xF84              // 3: This register is not available on 28-pin devices.
#define REGISTER_PORTD 0xF83              // 3: This register is not available on 28-pin devices.
#define REGISTER_PORTC 0xF82              // Comments needed
#define REGISTER_PORTB 0xF81              // Comments needed
#define REGISTER_PORTA 0xF80              // Comments needed
