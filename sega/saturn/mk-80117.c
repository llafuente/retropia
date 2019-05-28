// from: https://nfggames.com/forum2/index.php?topic=5055.msg33242#msg33242

/*******************************************************************************
SEGA SATURN 3D CONTROLLER EMULATOR

PIC16F1516
EXTERNAL OSC @ 16MHz
5v POWER FROM SATURN

RDC 2013
*******************************************************************************/

char SPID, DATA_SIZE;

char DATA1_1, DATA1_2;
char DATA2_1, DATA2_2;
char DATA3_1, DATA3_2;

#define TH_SEL RA3_bit                   // Configure as Input
#define TR_REQ RA4_bit                   // Configure as Input
#define TL_ACK RA5_bit                   // Configure as Output

// Initialize the PIC
void INIT() {
ANSELA = 0b00000011;                     // AN0 and AN1 Analog to X and Y Axis
ANSELB = 0b00000000;                     // All AN are Digital
ANSELC = 0b00000000;                     // All AN are Digital
TRISA = 0b00011111;                      // PORTA
TRISB = 0b11111111;                      // PORTB, pins 6 and 7 also for ICSP
TRISC = 0b11110000;                      // PORTC
TRISE = 0b00001000;                      // PORTE, only 1 pin, RE3
TL_ACK = 1;
}


void main() {

   INIT();

  SPID = 0b00000000;
  DATA_SIZE = 0b00000010;

///// DIGITAL:

/////  Set Initial Button DATA for power up

    DATA1_1 = 0b11111111;                 // DATA1_1
    DATA1_2 = 0b11111111;                 // DATA1_2
    DATA2_1 = 0b11111111;                 // DATA2_1
    DATA2_2 = 0b11111111;                 // DATA2_2
    DATA3_1 = 0b00000000;                 // DATA3_1
    DATA3_2 = 0b00000001;                 // DATA3_2

  delay_ms(500);   // Wait for the Saturn to start up (takes around 1.5s)

  while(1) {

///// START COMMS WITH SATURN

    while(TH_SEL == 1) {}   // Wait for the Saturn to select controller
    delay_us(40);

    while (TR_REQ == 1 && TH_SEL == 0) {}  // Wait for Saturn to request SPID
    PORTC = SPID;           // SPID  0000 = Digital  // 0001 = Analog
    TL_ACK = 0;             // Here is the data

    while (TR_REQ == 0 && TH_SEL == 0) {}  // Wait for Saturn to request Data Size
    PORTC = DATA_SIZE;      // DATA_SIZE  0010 = 2 Bytes, 0110 = 6 Bytes
    TL_ACK = 1;             // Here is the data

///// START FIRST BYTE

    while (TR_REQ == 1 && TH_SEL == 0) {}  // Wait for Saturn to request first half of Data1
    PORTC = DATA1_1;        // DR, DL, DD, DU
    TL_ACK = 0;             // Here is the data

    while (TR_REQ == 0 && TH_SEL == 0) {}  // Wait for Saturn to request second half of Data1
    PORTC = DATA1_2;        // ST, A, C, B
    TL_ACK = 1;             // Here is the data

///// END FIRST BYTE

///// START SECOND BYTE

    while (TR_REQ == 1 && TH_SEL == 0) {}  // Wait for Saturn to request first half of Data2
    PORTC = DATA2_1;        // R, X, Y, Z
    TL_ACK = 0;             // Here is the data

    while (TR_REQ == 0 && TH_SEL == 0) {}  // Wait for Saturn to request second half of Data2
    PORTC = DATA2_2;        // L, 1, 1, 1
    TL_ACK = 1;             // Here is the data

///// END SECOND BYTE

///// START THIRD BYTE, END OF DATA

    while (TR_REQ == 1 && TH_SEL == 0) {}  // Wait for Saturn to request first half End
    PORTC = DATA3_1;        // 0000
    TL_ACK = 0;             // Here is the data

    while (TR_REQ == 0 && TH_SEL == 0) {}  // Wait for Saturn to request second half of End
    PORTC = DATA3_2;        // 0001
    TL_ACK = 1;             // Here is the data

///// END THIRD BYTE

    while(TH_SEL == 0) {}   // Wait for the Saturn to deselect controller

///// END COMMS WITH SATURN

/////  Get Current Button DATA (in less than 15ms, less than 300us if an Action Replay is used)

    DATA1_1 = PORTC >> 4;                 // DATA1_1
    DATA1_2 = PORTB;                      // DATA1_2
    DATA2_1 = PORTB >> 4;                 // DATA2_1
    DATA2_2 = (PORTA << 1) + 7;           // DATA2_2
    DATA3_1 = 0b00000000;                 // DATA3_1
    DATA3_2 = 0b00000001;                 // DATA3_2

  }
}
