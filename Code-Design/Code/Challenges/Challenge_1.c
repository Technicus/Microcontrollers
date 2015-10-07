/* Initial lcd test
   2015-.09.24
   ../../designs/LCDpanel_1.design
*/

#include "../Library/Library_18f4520.h"

// Function declerations
int analogPercentage(float analogValue);
int ananlogKeyDifference(char press, int currentNumber);

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
   unsigned int currentNumber = 0;
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
      
            currentNumber = ananlogKeyDifference(press, currentNumber);
            
            printf(lcd_putc, "\fV:%03.4fV KP:%c\nP:%d\t\t\t\t%i", Voltage, press, percentVoltageRange, currentNumber);
      }
      
      delay_ms(10);
   }
}

// Function definitions

int analogPercentage(float analogValue){
      return(((analogValue+3)/voltageRange)*100);
}

int ananlogKeyDifference(char press, int currentNumber){
      int keypadNumber;
      int newNumber;
      keypadNumber = press-0x30;
      newNumber = currentNumber;
      /*if (keypadNumber >= 0 && keypadNumber <= 10){
      
            newNumber = (currentNumber*10)+keypadNumber;
            
            if (currentNumber >= 10){
                  
                  newNumber = (currentNumber*10^1)+keypadNumber;     
            }
            else{
                  newNumber = currentNumber + keypadNumber;     
            }
      }
      else{
            newNumber = 0;
      }*/
      currentNumber = currentNumber + keypadNumber;
      return(currentNumber);  
}


