/*  Business Card USB to ZX-81 Keyboard
    via PS2KeyAdvanced library Written by Paul Carpenter, PC Services <sales@pcserviceselectronics.co.uk>

   The connector to mate with USB keyboard is a 4 pin USB Type A
   USB Pins to signal to AVR128DB28
    1   +5V
    2   KBD Clock PIN_PA2
    3   KBD Data  PIN_PA3
    4   Gnd

   The Keyboard connections:
   KPD0  PIN_PA0
   KPD1  PIN_PA1
   KPD2  PIN_PA4
   KPD3  PIN_PA5
   KPD3  PIN_PA6
   KPA8  PIN_PA7
   KPA9  PIN_PD1
   KPA10  PIN_PD2
   KPA11  PIN_PD3
   KPA12  PIN_PD4
   KPA13  PIN_PD5
   KPA14  PIN_PD6
   KPA15  PIN_PD7

   The Configurable Custom Logic:
   A0 PIN_PC0
   !RD PIN_PC1
   !IORQ PIN_PC2


   
  Read method Returns an UNSIGNED INT containing
        Make/Break status
        Caps status
        Shift, CTRL, ALT, ALT GR, GUI keys
        Flag for function key not a displayable/printable character
        8 bit key code

  Code Ranges (bottom byte of unsigned int)
        0       invalid/error
        1-1F    Functions (Caps, Shift, ALT, Enter, DEL... )
        1A-1F   Functions with ASCII control code
                    (DEL, BS, TAB, ESC, ENTER, SPACE)
        20-61   Printable characters noting
                    0-9 = 0x30 to 0x39 as ASCII
                    A to Z = 0x41 to 0x5A as upper case ASCII type codes
                    8B Extra European key
        61-A0   Function keys and other special keys (plus F2 and F1)
                    61-78 F1 to F24
                    79-8A Multimedia
                    8B NOT included
                    8C-8E ACPI power
                    91-A0 and F2 and F1 - Special multilingual
        A8-FF   Keyboard communications commands (note F2 and F1 are special
                codes for special multi-lingual keyboards)

    By using these ranges it is possible to perform detection of any key and do
    easy translation to ASCII/UTF-8 avoiding keys that do not have a valid code.

    Top Byte is 8 bits denoting as follows with defines for bit code

        Define name bit     description
        PS2_BREAK   15      1 = Break key code
                   (MSB)    0 = Make Key code
        PS2_SHIFT   14      1 = Shift key pressed as well (either side)
                            0 = NO shift key
        PS2_CTRL    13      1 = Ctrl key pressed as well (either side)
                            0 = NO Ctrl key
        PS2_CAPS    12      1 = Caps Lock ON
                            0 = Caps lock OFF
        PS2_ALT     11      1 = Left Alt key pressed as well
                            0 = NO Left Alt key
        PS2_ALT_GR  10      1 = Right Alt (Alt GR) key pressed as well
                            0 = NO Right Alt key
        PS2_GUI      9      1 = GUI key pressed as well (either)
                            0 = NO GUI key
        PS2_FUNCTION 8      1 = FUNCTION key non-printable character (plus space, tab, enter)
                            0 = standard character key

  Error Codes
     Most functions return 0 or 0xFFFF as error, other codes to note and
     handle appropriately
        0xAA   keyboard has reset and passed power up tests
               will happen if keyboard plugged in after code start
        0xFC   Keyboard General error or power up fail

  See PS2Keyboard.h file for returned definitions of Keys

  Note defines starting
            PS2_KEY_* are the codes this library returns
            PS2_*     remaining defines for use in higher levels

  To get the key as ASCII/UTF-8 single byte character conversion requires use
  of PS2KeyMap library AS WELL.

*/
#include <EEPROM.h>
#include <PS2KeyAdvanced.h>

/* Keyboard constants  Change to suit your Arduino
   define pins used for data and clock from keyboard */

// Make sure to have attachInterupt=All Pins

// PIN_PA0 Serial
// PIN_PA1 Serial
// PIN_PA2 USB IRQ
// PIN_PA3 USB Data
// PIN_PD1 DLSel0
// PIN_PD2 DLSel1
// PIN_PD3 DLSel2
// PIN_PD4 ALSel0
// PIN_PD5 ALSel1
// PIN_PD6 ALSel2
// PIN_PD7 KPress
// PIN_PA4 Shift
// PIN_PA5 ALT/SymShift
// PIN_PA6 CTRL
// PIN_PA7 Shift4

#define DATAPIN PIN_PA3
#define IRQPIN  PIN_PA2
const byte kbdPins[] = {PIN_PD1, PIN_PD2, PIN_PD3, PIN_PD4, PIN_PD5, PIN_PD6, PIN_PA4, PIN_PA5, PIN_PA6, PIN_PA7, PIN_PD7};

uint16_t lookup[6][200][3] = {
//Unshifted ZX81 - Tabletop=89
  {  
  {0,49,B000000},{0,50,B000001},{0,51,B000010},{0,52,B000011},{0,53,B000100},{0,54,B010100},{0,55,B010011},{0,56,B010010},{0,57,B010001},{0,48,B010000},
  {0,81,B001000},{0,87,B001001},{0,69,B001010},{0,82,B001011},{0,84,B001100},{0,89,B100100},{0,85,B100011},{0,73,B100010},{0,79,B100001},{0,80,B100000},
  {0,65,B011000},{0,83,B011001},{0,68,B011010},{0,70,B011011},{0,71,B011100},{0,72,B110100},{0,74,B110011},{0,75,B110010},{0,76,B110001},{0,286,B110000},
                 {0,90,B101001},{0,88,B101010},{0,67,B101011},{0,86,B101100},{0,66,B111100},{0,78,B111011},{0,77,B111010},{0,61,B111001},{0,287,B111000},
  //Shifted ZX81
  {0,16384+49,B1000000},{0,16384+50,B1000001},{0,16384+51,B1000010},{0,16384+52,B1000011},{0,16384+53,B1000100},{0,16384+54,B1010100},{0,16384+55,B1010011},{0,16384+56,B1010010},{0,16384+57,B1010001},{0,16384+48,B1010000},
  {0,16384+81,B1001000},{0,16384+87,B1001001},{0,16384+69,B1001010},{0,16384+82,B1001011},{0,16384+84,B1001100},{0,16384+89,B1100100},{0,16384+85,B1100011},{0,16384+73,B1100010},{0,16384+79,B1100001},{0,16384+80,B1100000},
  {0,16384+65,B1011000},{0,16384+83,B1011001},{0,16384+68,B1011010},{0,16384+70,B1011011},{0,16384+71,B1011100},{0,16384+72,B1110100},{0,16384+74,B1110011},{0,16384+75,B1110010},{0,16384+76,B1110001},{0,16384+286,B1110000},
                        {0,16384+90,B1101001},{0,16384+88,B1101010},{0,16384+67,B1101011},{0,16384+86,B1101100},{0,16384+66,B1111100},{0,16384+78,B1111011},{0,16384+77,B1111010},{0,16384+61,B1111001},{0,16384+287,B1111000},
  //Special Keys ZX81
  {0,58,B1100000},{0,59,B1111001},{0,60,B1110011},{0,62,B1101100},{0,91,B1101001},{0,95,B1110001},{0,284,B1010000},{0,16442,B1100000},{0,16446,B1101011},{0,16475,B1101010},{0,16479,B1110010}
  }, 

  //Unshifted ZX-Spectrum - Tabletop=166
  {  
  {1,49,B000000},{1,50,B000001},{1,51,B000010},{1,52,B000011},{1,53,B000100},{1,54,B011100},{1,55,B011011},{1,56,B011010},{1,57,B011001},{1,48,B011000},
  {1,81,B001000},{1,87,B001001},{1,69,B001010},{1,82,B001011},{1,84,B001100},{1,89,B100100},{1,85,B100011},{1,73,B100010},{1,79,B100001},{1,80,B100000},
  {1,65,B010000},{1,83,B010001},{1,68,B010010},{1,70,B010011},{1,71,B010100},{1,72,B110100},{1,74,B110011},{1,75,B110010},{1,76,B110001},{1,286,B110000},
                 {1,90,B101001},{1,88,B101010},{1,67,B101011},{1,86,B101100},{1,66,B111100},{1,78,B111011},{1,77,B111010},{1,287,B111000},
  {1,16646,B01101000},

  //Shifted ZX-Spectrum
  {1,16384+49,B1000000},{1,16384+50,B1000001},{1,16384+51,B1000010},{1,16384+52,B1000011},{1,16384+53,B1000100},{1,16384+54,B1011100},{1,16384+55,B1011011},{1,16384+56,B1011010},{1,16384+57,B1011001},{1,16384+48,B1011000},
  {1,16384+81,B1001000},{1,16384+87,B1001001},{1,16384+69,B1001010},{1,16384+82,B1001011},{1,16384+84,B1001100},{1,16384+89,B1100100},{1,16384+85,B1100011},{1,16384+73,B1100010},{1,16384+79,B1100001},{1,16384+80,B1100000},
  {1,16384+65,B1010000},{1,16384+83,B1010001},{1,16384+68,B1010010},{1,16384+70,B1010011},{1,16384+71,B1010100},{1,16384+72,B1110100},{1,16384+74,B1110011},{1,16384+75,B1110010},{1,16384+76,B1110001},{1,16384+286,B1110000},
                        {1,16384+90,B1101001},{1,16384+88,B1101010},{1,16384+67,B1101011},{1,16384+86,B1101100},{1,16384+66,B1111100},{1,16384+78,B1111011},{1,16384+287,B1111000},

  //Left-Alt Symbol Shift ZX-Spectrum
  {1,1024+49,B10000000},{1,1024+50,B10000001},{1,1024+51,B10000010},{1,1024+52,B10000011},{1,1024+53,B10000100},{1,1024+54,B10011100},{1,1024+55,B10011011},{1,1024+56,B10011010},{1,1024+57,B10011001},{1,1024+48,B10011000},
  {1,1024+81,B10001000},{1,1024+87,B10001001},{1,1024+69,B10001010},{1,1024+82,B10001011},{1,1024+84,B10001100},{1,1024+89,B10100100},{1,1024+85,B10100011},{1,1024+73,B10100010},{1,1024+79,B10100001},{1,1024+80,B10100000},
  {1,1024+65,B10010000},{1,1024+83,B10010001},{1,1024+68,B10010010},{1,1024+70,B10010011},{1,1024+71,B10010100},{1,1024+72,B10110100},{1,1024+74,B10110011},{1,1024+75,B10110010},{1,1024+76,B10110001},{1,1024+286,B10110000},
                        {1,1024+90,B10101001},{1,1024+88,B10101010},{1,1024+67,B10101011},{1,1024+86,B10101100},{1,1024+66,B10111100},{1,1024+78,B10111011},{1,1024+77,B10111010},{1,1024+287,B10111000},
  {1,2314,B10111001},{1,1291,B10111001},
  
  //Right-Alt Symbol Shift ZX-Spectrum
  {1,2048+49,B10000000},{1,2048+50,B10000001},{1,2048+51,B10000010},{1,2048+52,B10000011},{1,2048+53,B10000100},{1,2048+54,B10011100},{1,2048+55,B10011011},{1,2048+56,B10011010},{1,2048+57,B10011001},{1,2048+48,B10011000},
  {1,2048+81,B10001000},{1,2048+87,B10001001},{1,2048+69,B10001010},{1,2048+82,B10001011},{1,2048+84,B10001100},{1,2048+89,B10100100},{1,2048+85,B10100011},{1,2048+73,B10100010},{1,2048+79,B10100001},{1,2048+80,B10100000},
  {1,2048+65,B10010000},{1,2048+83,B10010001},{1,2048+68,B10010010},{1,2048+70,B10010011},{1,2048+71,B10010100},{1,2048+72,B10110100},{1,2048+74,B10110011},{1,2048+75,B10110010},{1,2048+76,B10110001},{1,2048+286,B10110000},
                        {1,2048+90,B10101001},{1,2048+88,B10101010},{1,2048+67,B10101011},{1,2048+86,B10101100},{1,2048+66,B10111100},{1,2048+78,B10111011},{1,2048+77,B10111010},{1,2048+287,B10111000},

  //Special Keys Spectrum
  {1,58,B10011011},{1,59,B10111011},{1,60,B10110011},{1,61,B10111010},{1,62,B10101100},{1,91,B10100001},{1,95,B10110001},{1,284,B01011000},{1,16442,B10100000},{1,16446,B10101011},{1,16475,B10101001},{1,16479,B10110010},{1,16444,B10011000}
  }  
};

PS2KeyAdvanced keyboard;
byte kbdtmp, tabletop;

void setup( )
{
  // Configure the keyboard library
  keyboard.begin(DATAPIN,IRQPIN);

  for (int d = 0; d < 11; d++)
  {
    pinMode(kbdPins[d], OUTPUT);
    digitalWrite(kbdPins[d], HIGH); //initial LED state
  }
  //Send the Shift Keys Low
  digitalWrite(kbdPins[6],LOW);
  digitalWrite(kbdPins[7],LOW);
  digitalWrite(kbdPins[8],LOW);
  digitalWrite(kbdPins[9],LOW);
  
  //Storing saved default template at EEPROM(0) and size of table at EEPROM(1)
  kbdtmp = EEPROM.read(0);
  tabletop = EEPROM.read(1);
  if (kbdtmp > 2) {
    // Keyboard Template defaults to ZX-81
    kbdtmp = 0;
    // This template has 89 entries
    tabletop = 89;
  }   
  Serial.begin(115200);
  Serial.println( "USB Keyboard Debug Output:" );
  Serial.print("Template ");
  Serial.print(kbdtmp);
  Serial.print(" Entries:");
  Serial.println(tabletop);
  //Setting Keyboard LEDs not working
  //keyboard.setLock(1);
}

void loop( )
{
  if( keyboard.available( ) )
  {
  // read the next key
  uint16_t c = keyboard.read( );

  //Ignore Keyboard break and only look at make
  if (c>0) 
    {
      //F12 Key=364 Code Goes Here
      if (c==364) {
        ChgTmplate();
      }
      Serial.print("Keycode=");
      Serial.print(c);
      uint16_t e = 0;
      while (lookup[kbdtmp][e][1] != c and e < tabletop) {
        e++;
      }
      Serial.print(" lookup[");
      Serial.print(kbdtmp);
      Serial.print("][");
      Serial.print(e);
      Serial.print("][1] = ");
      if (e < tabletop) {
        Serial.print(lookup[kbdtmp][e][2]);
        Serial.print(" Out:");
        ALDLOutput(lookup[kbdtmp][e][2]);  
      }
      else Serial.println("Not Found");
    }
  }
}

void ALDLOutput(int d) 
{
  for (int q = 0; q < 8; q++)
   {
    if (((d >> q) & 1) == 1) {
      Serial.print("1");
      digitalWrite(kbdPins[q],HIGH);
    }
    else {
      Serial.print("0");
      digitalWrite(kbdPins[q],LOW);
    }
   }     
  Serial.println("");
  digitalWrite(kbdPins[10],LOW);
  delay(200);
  digitalWrite(kbdPins[6],LOW);
  digitalWrite(kbdPins[7],LOW);
  //digitalWrite(kbdPins[8],LOW);
  //digitalWrite(kbdPins[9],LOW);
  digitalWrite(kbdPins[10],HIGH);
}

void ChgTmplate()
{
  if (kbdtmp == 0) {
    kbdtmp=1;
    tabletop=172;
    EEPROM.write(0,1);
    EEPROM.write(1,172);
  }
  else {
    kbdtmp=0;
    tabletop=89;
    EEPROM.write(0,0);
    EEPROM.write(1,89);     
  }
  Serial.print("Changed to template ");
  Serial.println(kbdtmp);
}
