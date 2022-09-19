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

#include <PS2KeyAdvanced.h>

/* Keyboard constants  Change to suit your Arduino
   define pins used for data and clock from keyboard */

// Make sure to have attachInterupt=All Pins

#define DATAPIN PIN_PA3
#define IRQPIN  PIN_PA2
#define XX 0

uint16_t c;

// ZX-81 Table
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

uint16_t d [100][2]= {
  //Unshifted
  {49,B000000},{50,B000100},{51,B000010},{52,XX},{53,B000001},{54,B010001},{55,XX},{56,B010010},{57,XX},{48,B010000},
  {81,B100000},{87,XX},{69,B100010},{82,XX},{84,B100001},{89,XX},{85,B001001},{73,B001010},{79,XX},{80,B001000},
  {65,B110000},{83,XX},{68,B110010},{70,XX},{71,B110001},{72,B011001},{74,B010001},{75,B011010},{76,XX},{286,B011000},
               {90,XX},{88,B101010},{67,XX},{86,B101001},{66,B111001},{78,XX},{77,B111010},{61,B111100},{287,B111000},
  //Shifted
  {16384+49,XX},{16384+50,XX},{16384+51,XX},{16384+52,XX},{16384+53,XX},{16384+54,XX},{16384+55,XX},{16384+56,XX},{16384+57,XX},{16384+48,XX},
  {16384+81,XX},{16384+87,XX},{16384+69,XX},{16384+82,XX},{16384+84,XX},{16384+89,XX},{16384+85,XX},{16384+73,XX},{16384+79,XX},{16384+80,XX},
  {16384+65,XX},{16384+83,XX},{16384+68,XX},{16384+70,XX},{16384+71,XX},{16384+72,XX},{16384+74,XX},{16384+75,XX},{16384+76,XX},{16384+286,XX},
          {16384+90,XX},{16384+88,XX},{16384+67,XX},{16384+86,XX},{16384+66,XX},{16384+78,XX},{16384+77,XX},{16384+61,XX},{16384+287,XX}
};

const byte kbdPins[] = {PIN_PD1, PIN_PD2, PIN_PD3, PIN_PD4, PIN_PD5, PIN_PD6, PIN_PD7};

PS2KeyAdvanced keyboard;


void setup( )
{
  // Configure the keyboard library
  keyboard.begin(DATAPIN,IRQPIN);

  for (int d = 0; d < 7; d++)
  {
    pinMode(kbdPins[d], OUTPUT);
    digitalWrite(kbdPins[d], HIGH); //initial LED state
  }
  Serial.begin(115200);
  Serial.println( "PS2 Advanced Key Simple Test:" );
}

void loop( )
{
  if( keyboard.available( ) )
  {
  // read the next key
  c = keyboard.read( );
  //Ignore Keyboard break and only look at make
  if( (c>0) & (c<32768)) 
    {
      Serial.println("keypress");
      ALDLOutput(B001011);
      delay(1000);
    }
  }
}

void ALDLOutput(int d) 
{
  for (int q = 0; q < 6; q++)
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
  digitalWrite(kbdPins[6],LOW);
  delay(200);
  digitalWrite(kbdPins[6],HIGH);
}
