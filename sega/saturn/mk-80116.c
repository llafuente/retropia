// from: http://forums.modretro.com/index.php?threads/saturn-controller-protocol-mk80116-mk80100.11328/

/*******************************************************************************
SEGA Saturn 6 Button Controller Tester/Interface (Tested on the MK80116 and MK80100)

PIC16F1516 @16MHz Internal OSC

Select Bits S1 and S0, will always start at 11 and end at 11, but are never
11 while reading data from the D3, D2, D1 and D0 lines.

The Select Bit "stepping" for the MK80116 and MK80100 pads are..

11    // Waiting
10    // First half of Data1 (Byte1) on the D3, D2, D1 and D0 lines = DR, DL, DD, DU
01    // Second half of Data1 = ST, A, C, B
00    // First half of Data2 = R, X, Y, Z
11    // Second half of Data2, = L, -, -

There is roughly a 16ms interval between reading the last bits of data
and then starting over, so the controller is checked every 16ms or so
for any changes to the button states

The Saturn controllers run from a 5v power source. They can run from 3.3v at the very least, but a 5v source is recommended

2013 RDC
*******************************************************************************/

char DR, DL, DU, DD, ST, AB, CB, BB, RB, XB, YB, ZB, LB;

char TEMP_NIBBLE;
char BYTE1, BYTE2;


// Initialize the PIC
void INIT() {
    OSCCON = 0b01111010;                     // 8MHz 0b01110010; // 16MHz 0b01111010;
    ANSELA = 0b00000000;                     // All AN are Digital
    ANSELB = 0b00000000;                     // All AN are Digital
    ANSELC = 0b00000000;                     // All AN are Digital
    TRISA = 0b00000000;                      // PORTA
    TRISB = 0b11000000;                      // PORTB 6 and 7 reserved for ICSP
    TRISC = 0b00001111;                      // PORTC
    PORTC = 0b00110000;                      // Select Bits, S1 = 1 and S0 = 1
}


void main() {

  INIT();

  while(1){

    PORTC = 0b00100000;                      // Select Bits are 10

    TEMP_NIBBLE = PORTC & 0b00001111;        // Read lower 4 bits from PORTC

    BYTE1 = TEMP_NIBBLE <<= 4;               // Shift that data over and save

    PORTC = 0b00010000;                      // Select Bits are 01

    TEMP_NIBBLE = PORTC & 0b00001111;        // Read lower 4 bits from PORTC

    BYTE1 = BYTE1 + TEMP_NIBBLE;             // Add new data to shifted data
                                             // this makes the 8 Bits of Byte1
    PORTC = 0b00000000;                      // Select Bits are 00

    TEMP_NIBBLE = PORTC & 0b00001111;        // Read lower 4 bits from PORTC

    BYTE2 = TEMP_NIBBLE <<= 4;               // Shift that data over and save

    PORTC = 0b00110000;                      // Select Bits are 11

    TEMP_NIBBLE = PORTC & 0b00001111;        // Read lower 4 bits from PORTC

    BYTE2 = BYTE2 + TEMP_NIBBLE;             // Add new data to shifted data
                                             // this makes the 8 Bits of Byte2

// Masking to look at each bit of the Bytes individually
// The Bit is >= 1 when not pressed, or 0 when pressed

    DR = BYTE1 & 0b10000000;
    DL = BYTE1 & 0b01000000;
    DD = BYTE1 & 0b00100000;
    DU = BYTE1 & 0b00010000;
    ST = BYTE1 & 0b00001000;
    AB = BYTE1 & 0b00000100;
    CB = BYTE1 & 0b00000010;
    BB = BYTE1 & 0b00000001;

    RB = BYTE2 & 0b10000000;
    XB = BYTE2 & 0b01000000;
    YB = BYTE2 & 0b00100000;
    ZB = BYTE2 & 0b00010000;
    LB = BYTE2 & 0b00001000;


// From here on out you can code for whatever you're wanting the PIC to do
// when a button on the controller is pressed.

// This is where some of the LCD output code was from my testing, but anything can be put here.

/******************************* EXAMPLE 1 *************************************

  if (DU == 0)     // If DU is pressed..
  {}               // ..run this code

  else             // Otherwise..
  {}               // ..run this code

******************************** EXAMPLE 2 *************************************

  PORTA = BYTE1;    // PORTS A and B display the button states
                    // LEDS would be on, then turn off with button press
  PORTB = BYTE2;

  // Alternately

  PORTA = ~BYTE1;   // Would make the LEDs turn on when a button is pressed

*******************************************************************************/

     delay_ms(15);

  }
}
