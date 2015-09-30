/*
 * Peripheral_Interrupts.h
 * 
 * Peripheral Interrupts Control Registers
 * 
 */

struct PIE_1{
	int TMR1IE:1;
	int TMR2IE:1;
	int CCP1IE:1;
	int SSPIE:1;
	int TXIE:1;
	int RCIE:1;
	int ADIE:1;
	int PSPIE:1;
	};
struct PIE_1 *PIE1 = REGISTER_INTCON;
