/* Initial lcd test
 *   2015-.09.24
 *   ../../designs/LCDpanel_1.design
 */

#include "../Library/Library_18f4520.h"

// Function declerations
unsigned int analogPercentage(float analogValue);
unsigned int ananlogKeyDifference(unsigned int percentVoltageRange, unsigned int keypadNumber_2);
unsigned int keypadNumberUpdate(char press, unsigned int keypadNumber_0);

// Global Variables
float voltageRange = 6.0;
//float Vres = 5.0 / 1023.0;
float Vres = 6.0 / 1023.0;
float Voltage;

#INT_AD
void int_ad_isr(){
  Voltage = (*ADRESL * Vres) - 3;
}

main(){

  unsigned int percentVoltageRange = 0;
  unsigned int keypadNumber_0 = 0;
  unsigned int keypadNumber_1 = 0;
  unsigned int ananlogKeyNumber = 0;
  char press;

  lcd_init();

  ADCON0->ADON = 1;
  ADCON0->CHSx = 0;
  ADCON1->PCFGX = 8;

  *TRISA = 0x01;  // set A0 as input

  ADCON2->ADFM = 1; // right justify

  // enable references
  ADCON1->VCFG0 = 1;
  ADCON1->VCFG1 = 1;


  // interrupt setup
  PIE1->ADIE = 1;
  INTCON->GIE = 1;
  INTCON->PEIE = 1;

  *TRISB = 0xF0;
  *TRISC = 0x00;
  ADCON1->PCFGx = 0x0F;
  INTCON2->RBPU = 0;

  while(1){

    ADCON0->GODONE = 1;

    press = keyPress();

    percentVoltageRange = analogPercentage(Voltage);

    if( press != defaultPress){
      keypadNumber_1 = keypadNumberUpdate(press, keypadNumber_0);
      keypadNumber_0 = keypadNumber_1;
      //test
      //printf(lcd_putc, "\fNumber = %d", keypadNumber_1);
      //KeypadNumber_0 = ananlogKeyDifference(press, currentNumber);

      ananlogKeyNumber = ananlogKeyDifference(percentVoltageRange, keypadNumber_1);
    }

    printf(lcd_putc, "\fV:%03.4fV KP:%c\nP:%d%%\tS:%d\tN:%d", Voltage, press, percentVoltageRange, ananlogKeyNumber, keypadNumber_1);

    delay_ms(20);
  }
}

// Function definitions

// Calculate analog percentage
unsigned int analogPercentage(float analogValue){
  return(((analogValue+3)/voltageRange)*100);
}

// update keypad number
unsigned int keypadNumberUpdate(char press, unsigned int keypadNumber_0){
  unsigned int keypadNumber_1 = 0;
  keypadNumber_1 =  press - 0x30;
  if (keypadNumber_1 >= 0 && keypadNumber_1 <= 9){
    if (keypadNumber_0 < 10){
      keypadNumber_1 = (keypadNumber_0 * 10) + (keypadNumber_1);
      return(keypadNumber_1);
    }
    else{
      return(keypadNumber_1);
    }
  }
  else{
    return(0);
  }
}

// Calculate difference
unsigned int ananlogKeyDifference(unsigned int percentVoltageRange, unsigned int keypadNumber_2){
  unsigned int ananlogKeyNumber = 0;
  if (percentVoltageRange > keypadNumber_2){
    ananlogKeyNumber = percentVoltageRange - keypadNumber_2;
  }
  else{
    ananlogKeyNumber = keypadNumber_2 - percentVoltageRange;
  }
  return(ananlogKeyNumber);
}


