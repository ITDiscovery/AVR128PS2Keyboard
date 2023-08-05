# Commodore C64 VIC20 and Pet page (Untested)
This file contains the connection and keyboard info for the Commodore C64 and VIC 20. This code has not been tested. There will also need to be an additonal wedge to trip the reset line connected to H6-7,8.

## VIC-20

### Connections

Connection to VIC-20 (CN-1):
1. Pin 1 H7-6 (Gnd)
1. Pin 2   (Key)
1. Pin 3 to H6-8 (Restore) (H6-7 then to GND)
1. Pin 4 to H7-5 (+5V)
1. Pin 5 to H4-8 (Row 7, Pin 2/PA7)
1. Pin 6 to H4-7 (Row 6, Pin 3/PA6)
1. Pin 7 to H4-6 (Row 5, Pin 4/PA5)
1. Pin 8 to H4-5 (Row 4, Pin 5/PA4)
1. Pin 9 to H4-4 (Row 3, Pin 6/PA3)
1. Pin 10 to H4-3 (Row 2, Pin 7/PA2)
1. Pin 11 to H4-2 (Row 1, Pin 8/PA1)
1. Pin 12 to H4-1 (Row 0, Pin 9/PA0)
1. Pin 13 to H3-1 (Col 7, Pin 10/PB0)
1. Pin 14 to H3-2 (Col 6, Pin 11/PB1)
1. Pin 15 to H3-3 (Col 5, Pin 12/PB2)
1. Pin 16 to H3-4 (Col 4, Pin 13/PB3)
1. Pin 17 to H3-5 (Col 3, Pin 14/PB4)
1. Pin 18 to H3-6 (Col 2, Pin 15/PB5)
1. Pin 19 to H3-7 (Col 1, Pin 16/PB6)
1. Pin 20 to H3-8 (Col 0, Pin 17/PB7)

Left Shift:
1. H4A-4 to H6-1
1. H3A-2 to H6-2

CTRL Key: 
1. H4A-1 to H6-4
1. H3A-6 to H6-3

### Keychart VIC-20

| Key | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 49 | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 | 48 | 
| Row/Col | R0C0    | R0C7    | R1C0    | R1C7    | R2C0    | R2C7    | R3C0    | R3C7    | R4C0    | R4C7    |
| Mux Code| B000000 | B111000 | B000001 | B111001 | B000010 | B111010 | B000011 | B111011 | B000100 | B111100 |

| Key | Q | W | E | R | T | Y | U | I | O | P |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 81 | 87 | 69 | 82 | 84 | 89 | 85 | 73 | 79 | 80 | 
| Row/Col | R0C6    | R1C1    | R1C6    | R2C1    | R2C6    | R3C1   | R3C6    | R4C1    | R4C6    | R5C1    |
| Mux Code| B110000 | B001001 | B001110 | B001010 | B110010 | B001011 | B110011 | B001100 | B110100 | B001101 |

| Key | A | S | D | F | G | H | J | K | L | ENTER |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 65 | 83 | 68 | 70 | 71 | 72 | 74 | 75 | 76 | 286 | 
| Row/Col | R1C2    | R1C5    | R2C2    | R2C5    | R3C2    | R3C5    | R4C2    | R4C5    | R5C2    | R7C1    |
| Mux Code| B010001 | B101001 | B010010 | B101010 | B010011 | B101011 | B010100 | B101100 | B010101 | B001111 |

| Key | Z | X | C | V | B | N | M | . | SPACE | @ |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 90 | 88 | 67 | 86 | 66 | 78 | 77 | 61 | 287 | 16434 | 
| Row/Col | R1C4    | R2C3    | R2C4    | R3C3    | R3C4    | R4C3    | R4C4    | R5C4    | R0C4    | R5C6 |
| Mux Code| B100001 | B011010 | B100010 | B011011 | B100011 | B011100 | B100100 | B100101 | B100000 | B110101 |

| Key  | , | - | ' | / | + | * | : | = | ; |
| - | - | - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 59      | 60      | 58        | 62      | 16479   | 16440   | 16475   | 16647   | 95      | 91      |
| Row/Col | R5C3    | R5C7    | Shift+R3C0| R6C3    | R5C0    | R67C1   | R6C3    | R1C3    | R6C5    | R6C2    |
| Mux Code| B011101 | B111101 | B1000011  | B011110 | B000101 | B001110 | B011110 | B011001 | B101110 | B010110 |

| Key | TAB | HOME | DEL | L-Arrow | CD | U-Arrow | CR | CTRL | L-Shift | R-Shift |
| - | - | - | - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 285     | 273     | 282     | 277     | 280     | 279     | 278     | 8456/8457 | 16646   | 16647   |
| Row/Col | R6C0    | R6C7    | R7C0    | R0C1    | R7C3    | R6C6    | R7C2    |    R0C2   | R1C3    | R6C4    |
| Mux Code| B000110 | B111110 | B000111 | B001000 | B011111 | B110110 | B010111 |  B010000  | B011001 | B100110 |

| Key | F1 | F3 | F5 | F7 | Run/Stop | CMDRE | F2 | F4 | F6 | F8 |
| - | - | - | - | - | - | - | - | - | - |
| USB Code| 353 | 355 | 357 | 359 | 283 | 780 | 354 | 356 | 358 | 360 |
| Row/Col  | R7C4    | R7C5    | R7C6    | R7C7    | R0C3    | R0C5    | S + R7C4 | S + R7C5     | S + R7C6 | S + R7C7 | 
| Mux Code | B100111 | B101111 | B110111 | B111111 | B011000 | B101000 | B1100111 | B1101111 | B1110111 | B1111111 | 

ESC = Run Stop
Up Arrow = CR
Right Arrow = CD
Windows = Commodore
Tab = British Pound 
' = Shifted 7
" = Shifted 2
Shifted 2 = @
(  = Shifted 8
) = Shifted 9

## C64


Connection to Commodore64 (CN-1):
1. Pin 1 H7-6 (Gnd)
1. Pin 2   (Key)
1. Pin 3 to H6-8 (Restore) (H6-7 then to GND)
1. Pin 4 to H7-5 (+5V)
1. Pin 5 to H3-1 (Row 3, Pin 13/PB3)
1. Pin 6 to H3-2 (Row 6, Pin 16/PB6)
1. Pin 7 to H3-3 (Row 5, Pin 15/PB5)
1. Pin 8 to H3-4 (Row 4, Pin 14/PB4)
1. Pin 9 to H3-5 (Row 7, Pin 17/PB7)
1. Pin 10 to H3-6 (Row 2, Pin 12/PB2)
1. Pin 11 to H3-7 (Row 1, Pin 11/PB1)
1. Pin 12 to H3-8 (Row 0, Pin 10/PB0)
1. Pin 13 to H4-1 (Col 0, Pin 2/PA0)
1. Pin 14 to H4-2 (Col 6, Pin 8/PA6)
1. Pin 15 to H4-3 (Col 5, Pin 7/PA5)
1. Pin 16 to H4-4 (Col 4, Pin 6/PA4)
1. Pin 17 to H4-5 (Col 3, Pin 5/PA3)
1. Pin 18 to H4-6 (Col 2, Pin 4/PA2)
1. Pin 19 to H4-7 (Col 1, Pin 3/PA1)
1. Pin 20 to H4-8 (Col 7, Pin 9/PA7)

Left Shift:
1. H4A-7 to H6-1
1. H3A-5 to H6-2

CTRL Key: 
1. H3A-8 to H6-3
1. H4A-8 to H6-4
