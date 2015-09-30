/*
 * Analog_To_Digital.h
 * 
 * Analog to digital circuit connections
 * 
 */

#define L *ADRESH
#define Q *ADRESL

int16 *ADRESH = REGISTER_ADRESH;
int16 *ADRESL = REGISTER_ADRESL;

struct ADCON_0{
   int ADON:1;
   int GODONE:1;
   int CHSx:4;
   int unused:2;
};
struct ADCON_0 *ADCON0 = REGISTER_ADCON0;

struct ADCON_1{
   int PCFGx:4;
   int VCFG0:1;
   int VCFG1:1;
   int unused:2;
};
struct ADCON_1 *ADCON1 = REGISTER_ADCON1;

struct ADCON_2{
   int ADCSx:3;
   int ACQTx:3;
   int unused:1;
   int ADFM:1;
};
struct ADCON_2 *ADCON2 = REGISTER_ADCON2;
