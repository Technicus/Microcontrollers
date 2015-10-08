/*
 * Keypad_Connection.h
 *
 * Keypad Connection to PORTB
 *
 */

// Coloum references
#define C0 0x3
#define C1 0x5
#define C2 0x6

// Row references
#define R0 0xE
#define R1 0xD
#define R2 0xB
#define R3 0x7

// Default press
#define defaultPress '@'

struct KeypadConnection{
   int COL:3;
   int unused:1;
   int ROW:4;
};
struct KeypadConnection *KEYPAD = REGISTER_PORTB; // PORTB

// Declarations
char keyPress(void);

// Definitions
char keyPress(void){
   char press = defaultPress;

   KEYPAD->COL=C0;
   switch(KEYPAD->ROW){
      case R0:
         press = '1';
         break;
      case R1:
         press = '4';
         break;
      case R2:
         press = '7';
         break;
      case R3:
         press = '*';
         break;
      default:
   }

   KEYPAD->COL=C1;
   switch(KEYPAD->ROW){
      case R0:
         press = '2';
         break;
      case R1:
         press = '5';
         break;
      case R2:
         press = '8';
         break;
      case R3:
         press = '0';
         break;
      default:
   }

   KEYPAD->COL=C2;
   switch(KEYPAD->ROW){
      case R0:
         press = '3';
         break;
      case R1:
         press = '6';
         break;
      case R2:
         press = '9';
         break;
      case R3:
         press = '#';
         break;
      default:
   }

   return(press);
}
