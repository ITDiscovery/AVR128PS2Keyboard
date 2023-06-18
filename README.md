# AVR128PS2Keyboard
This project started as a way to attach a USB Keyboard to a retro computer, the ZX-81. The schematic and board will
accomodate most any retro PC that uses a matrix. It has the ability for both Shift, CTRL, ALT and one other "function key". The board is an extension of the AVR128DB28 Breakout board, so I've included the ability to get at all the ports this device has.

Design Goals:
1. USB to ZX-81 (done)
1. USB to ZX Spectrum (or Harlequin) (done)
1. USB to Dragon
1. USB to Color Computer 2/3
1. Model 1/2/3/4/4P/16/6000? 
1. Commodore64/VIC20?
1. Classic MacIntosh (M0110 keyboard) via the J9 Connector, and Mouse via J6 Connector. (https://github.com/altercation/tmk_firrmware_hhkb_teensy2/blob/master/protocol/m0110.c) -Done: Needs more work, and I need to correct some issues with my MacClassicPlus 1Mb. This code base will be standalone...how this old Mac handles keys is different from the other retro computers.
1. Have it so that you can select or change on the fly which system you are emulating (done)
1. Have it store a default emulation in EEPROM (done)
1. Have it display via keyboard led which emulation it's doing (keyboard.setLEDs seems to be broken, next board can have LEDs added)
1. Provide a serial connection or a Composite TV, so a quicky dumb terminal (combines a couple of projects)

I didn't need to re-write the PS2Advanced Library. After a couple of iterations of DXCore updates, 
it started working. A guess is that it was a problem with attachInterupt...which if you change the setting of, 
the library doesn't work at all.

Here's Ben Eater's description of how the Keyboard works. All that is done via the PSAdvanced library.
https://www.youtube.com/watch?v=7aXbh9VUB3U

PS2Advanced Libary is at https://github.com/techpaul/PS2KeyAdvanced

For the ZX-81:

Connect on the board:
1. H3A-1 to H6-1
1. H4A-6 to H6-2

Connect the board to the ZX-81:
1. H7-5 to +5V
1. H7-6 to Gnd
1. H3-1 to KBD0
1. H3-2 to KBD1
1. H3-3 to KBD2
1. H3-4 to KBD3
1. H3-5 to KBD4
1. H4-1 to D1
1. H4-2 to D2
1. H4-3 to D3
1. H4-4 to D4
1. H4-5 to D5
1. H4-6 to D6
1. H4-7 to D7
1. H4-8 to D8

For the ZX-Spectrum/Harlequin:

Connect on the board:
1. H3A-1 to H6-1
1. H4A-6 to H6-2
1. H3A-2 to H6-3
1. H4A-8 to H6-4

Connect the board to the ZX-Spectrum:
1. H7-5 to +5V
1. H7-6 to Gnd
1. H3-1 to KBD0
1. H3-2 to KBD1
1. H3-3 to KBD2
1. H3-4 to KBD3
1. H3-5 to KBD4
1. H4-1 to D1
1. H4-2 to D2
1. H4-3 to D3
1. H4-4 to D4
1. H4-5 to D5
1. H4-6 to D6
1. H4-7 to D7
1. H4-8 to D8

Connection to the Mac Classic:
J9-1(Gnd) to H5-1 
J9-2(Clk) to H5-4
J9-3(Data) to H5-3
J9-4(+5v) to H5-2 (Don't populate R4 or R5)
J6-1(Gnd) H7-1
J6-2(+5V) H7-2
J6-3 N/C
J6-4(X2) H7-3
J6-5(X1) H7-4
J6-6 N/C
J6-7(SW-) to U4-12
J6-8(Y2) to H7-5
J6-9(Y1) to H7-6

Connection to Commodore64 (CN-1):
Pin 1 H7-6 (Gnd)
Pin 2   (Key)
Pin 3 to H6-8 (Restore) (H6-7 then to GND)
Pin 4 to H7-5 (+5V)
Pin 5 to H3-1 (Row 3, Pin 13/PB3)
Pin 6 to H3-2 (Row 6, Pin 16/PB6)
Pin 7 to H3-3 (Row 5, Pin 15/PB5)
Pin 8 to H3-4 (Row 4, Pin 14/PB4)
Pin 9 to H3-5 (Row 7, Pin 17/PB7)
Pin 10 to H3-6 (Row 2, Pin 12/PB2)
Pin 11 to H3-7 (Row 1, Pin 11/PB1)
Pin 12 to H3-8 (Row 0, Pin 10/PB0)
Pin 13 to H4-1 (Col 0, Pin 2/PA0)
Pin 14 to H4-2 (Col 6, Pin 8/PA6)
Pin 15 to H4-3 (Col 5, Pin 7/PA5)
Pin 16 to H4-4 (Col 4, Pin 6/PA4)
Pin 17 to H4-5 (Col 3, Pin 5/PA3)
Pin 18 to H4-6 (Col 2, Pin 4/PA2)
Pin 19 to H4-7 (Col 1, Pin 3/PA1)
Pin 20 to H4-8 (Col 7, Pin 9/PA7)

CTRL Key: 
H3A-8 to H6-1
H4A-8 to H6-2

Left Shift:
H4A-7 to H6-3
H3A-5 to H6-4

Right Shift:
H4A-2 to H6-5
H3A-4 to H6-6

This code is untested!!!
| Key | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 |
| - | - | - | - | - | - | - | - | - | - |
| Row/Col | R0C0 | R7C0 | R3C7 | R7C1 | R0C2 | R7C2 | R0C3 | R7C3 | R0C4 | R7C4 |
| USB Code| 49 | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 | 48 | 


| Mux Code|    |    |    |    |    |    |    |    |   |   |


```
//Unshifted C64 - Tabletop=
  {  
  {0,49,B000000},{0,50,B000001},{0,51,B000010},{0,52,B000011},{0,53,B000100},{0,54,B010100},{0,55,B010011},{0,56,B010010},{0,57,B010001},{0,48,B010000},
  {0,81,B001000},{0,87,B001001},{0,69,B001010},{0,82,B001011},{0,84,B001100},{0,89,B100100},{0,85,B100011},{0,73,B100010},{0,79,B100001},{0,80,B100000},
  {0,65,B011000},{0,83,B011001},{0,68,B011010},{0,70,B011011},{0,71,B011100},{0,72,B110100},{0,74,B110011},{0,75,B110010},{0,76,B110001},{0,286,B110000},
                 {0,90,B101001},{0,88,B101010},{0,67,B101011},{0,86,B101100},{0,66,B111100},{0,78,B111011},{0,77,B111010},{0,61,B111001},{0,287,B111000},
  //Shifted C64
  {0,16384+49,B1000000},{0,16384+50,B1000001},{0,16384+51,B1000010},{0,16384+52,B1000011},{0,16384+53,B1000100},{0,16384+54,B1010100},{0,16384+55,B1010011},{0,16384+56,B1010010},{0,16384+57,B1010001},{0,16384+48,B1010000},
  {0,16384+81,B1001000},{0,16384+87,B1001001},{0,16384+69,B1001010},{0,16384+82,B1001011},{0,16384+84,B1001100},{0,16384+89,B1100100},{0,16384+85,B1100011},{0,16384+73,B1100010},{0,16384+79,B1100001},{0,16384+80,B1100000},
  {0,16384+65,B1011000},{0,16384+83,B1011001},{0,16384+68,B1011010},{0,16384+70,B1011011},{0,16384+71,B1011100},{0,16384+72,B1110100},{0,16384+74,B1110011},{0,16384+75,B1110010},{0,16384+76,B1110001},{0,16384+286,B1110000},
                        {0,16384+90,B1101001},{0,16384+88,B1101010},{0,16384+67,B1101011},{0,16384+86,B1101100},{0,16384+66,B1111100},{0,16384+78,B1111011},{0,16384+77,B1111010},{0,16384+61,B1111001},{0,16384+287,B1111000},
  //Special Keys C64
  {0,58,B1100000},{0,59,B1111001},{0,60,B1110011},{0,62,B1101100},{0,91,B1101001},{0,95,B1110001},{0,284,B1010000},{0,16442,B1100000},{0,16446,B1101011},{0,16475,B1101010},{0,16479,B1110010}
  }, 
```

