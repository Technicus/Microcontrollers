/*
 *   Challenge - 1
 *   2015.10.08
 *   ../../designs/LCDpanel_1.design
 */

// Library, it includes other libraries and lockbits
#include "../Library/Library_18f4520.h"

// Function declerations
unsigned int analogPercentage(float analogValue);
unsigned int ananlogKeyDifference(unsigned int percentVoltageRange, unsigned int keypadNumber_2);
unsigned int keypadNumberUpdate(char press, unsigned int keypadNumber_0);

// Global Variables (why global?  Can I do this without global variables?)
float voltageRange = 6.0;
float bitRange = 1023.0;
float Vres = 0;
Vres = voltageRange/bitRange;
float Voltage;

// Interrupt routines
#INT_AD
void int_ad_isr(){
  Voltage = (*ADRESL * Vres) - 3;
}

// Main program!!!!
int main(int argc, char *argv[]){

  unsigned int percentVoltageRange = 0;  // Value holder for voltage percentage
  unsigned int keypadNumber_0 = 0;       // Value holder for first keypress
  unsigned int keypadNumber_1 = 0;       // Value holder for new keypress
  unsigned int ananlogKeyNumber = 0;     // Value holder for difference between percentage and 2 digit keypad number
  char press;                            // Value holder for readign keypress

  lcd_init();         // Initalize the LCD

  *TRISA = 0x01;      // Set A0 as input
  *TRISB = 0xF0;      // ???
  *TRISC = 0x00;      // ???

  // Analog setup
  ADCON0->ADON = 1;     // Turn on the analog circuits
  ADCON0->CHSx = 0;     // Choose the pin for reading analog value
  ADCON1->PCFGX = 8;    // ???
  ADCON2->ADFM = 1;     // Right justify
  ADCON1->VCFG0 = 1;    // Enable references high
  ADCON1->VCFG1 = 1;    // Enable references low
  ADCON1->PCFGx = 0x0F; // ???

  // Interrupt setup
  PIE1->ADIE = 1;       // ???
  INTCON->GIE = 1;      // ???
  INTCON->PEIE = 1;     // ???
  INTCON2->RBPU = 0;    // ???

  // Main process loop
  while(1){

    ADCON0->GODONE = 1;  // ???

    // Get input from keypad and check if it is pressed, if pressed update keypadNumber_0 and keypadNumber_1
    press = keyPress();
    if( press != defaultPress){
      keypadNumber_1 = keypadNumberUpdate(press, keypadNumber_0);
      keypadNumber_0 = keypadNumber_1;
    }

    // Get percentage of voltage range and calculate the difference between voltage% and keypad number
    percentVoltageRange = analogPercentage(Voltage);
    ananlogKeyNumber = ananlogKeyDifference(percentVoltageRange, keypadNumber_1);

    // Formate data and update the LCD
    printf(lcd_putc, "\fV:%03.4fV KP:%c\nP:%d%%\tD:%d\tN:%d", Voltage, press, percentVoltageRange, ananlogKeyNumber, keypadNumber_1);

    delay_ms(20); // Slow down!!!
  }
  return(0);
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