/*
 * Library_18f4520.h
 *
 *
 */

// Included for compilerkeypadNumber_2

//
// #include <18f452.h> // Different compiler
// #include <18f4520.h> // Class compiler
#include "../library/18f4520.h"

// Set lock bits and fuses
#include "../library/FusesLockBits.h"

// All register addresses are defined as: #define REGISTER_<name-of-register> <hex-of-address>
#include "../library/Register_Addresses_Definitions.h"

// Pointers to TRIS PORT and LAT registers
#include "../library/TRIS_PORT_LAT.h"

// Structures for analog to digital circuits and defins for Q and L
#include "../library/Analog_To_Digital.h"

// Structures for interrupt curcuits
#include "../library/Interrupts.h"

// Custom libraries for keypad and LCD connections
#include "../library/Keypad_Connection.h"
#include "../library/Modified_LCD.h"
