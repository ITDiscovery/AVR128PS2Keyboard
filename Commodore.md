# Commodore C64 VIC20 and Pet page (Untested)
This file contains the connection and keyboard info for the Commodore C64 and VIC 20. This code has not been tested. There will also need to be an additonal wedge to trip the reset line connected to H6-7,8.

## C64

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

| Key | L-Arrow | ! | " | # | $ | % | & | ' | ( | ) | + | - | Pound | HOME | DEL | 
| - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - |
| USB Code|  | 59 | 16475 | 60 | 277  | 16440 | 91 | 62 | 16646 | 16647| 8456 | 95 | 279 | 273 | 58 | 16442 |
| Row/Col | R5C0    | R5C3    | R5C5    | R5C7    | R0C1    | R6C1    | R6C2    | R6C3    | R1C3    | R6C4    | R0C2    | R6C5    | R7C2    | R7C3 | S+R3C0 | S+R0C7 |
| Mux Code| B000101 | B011101 | B101101 | B111101 | B001000 | B001110 | B010110 | B011110 | B011001 | B100110 | B010000 | B101110 | B010111 | B011111 | B1000011 | B1111000 | 

| Key | Up Arrow | L-R | U-D | F1 | F3 | F5 | F7 | Run/Stop | CMDRE | F2 | F4 | F6 | F8 |
| - | - | - | - | - | - | - | - | - | - |
| USB Code| 279 | 277 | 278 | 353 | 355 | 357 | 359 | 283 | 780 | 354 | 356 | 358 | 360 |
| Row/Col | R7C0    | R7C2    | R7C3    | R7C4    | R7C5    | R7C6    | R7C7    | R0C3    | R0C5    | S + R7C4 | S + R7C5     | S + R7C6 | S + R7C7 | 
| Mux Code| B000111 | B010111 | B011111 | B100111 | B101111 | B110111 | B111111 | B011000 | B101000 | B1100111 | B1101111 | B1110111 | B1111111 | 


```
//Unshifted VIC20 - Tabletop=146
  {  
  {3,49,B000000},{3,50,B111000},{3,51,B000001 },{3,52,B111001},{3,53,B000010},{3,54,B111010},{3,55,B000011},{3,56,B111011},{3,57,B000100},{3,48,B111100},
  {3,81,B110000},{3,87,B001001},{3,69,B001110},{3,82,B001010},{3,84,B110010},{3,89,B001011},{3,85,B110011},{3,73,B001100},{3,79,B110100},{3,80,B001101},
  {3,65,B010001},{3,83,B101001},{3,68,B010010},{3,70,B101010},{3,71,B010011},{3,72,B101011},{3,74,B010100},{3,75,B101100},{3,76,B010101},{3,286,B001111},
  {3,90,B100001},{3,88,B011010},{3,67,B100010},{3,86,B011011},{1,66,B100011},{3,78,B011100},{3,77,B100100},{3,61,B100101},{3,287,B100000},{3,16434,BB110101},

  //Special Keys VIC20
  {3,16479,B000101},{3,59,B011101},{3,16475,B101101},{3,60,B111101},{3,277,B001000},{3,16436,B000110},{3,16440,B001110},{3,91,B010110},{3,62,B011110},{3,16646,B011001},{3,16647,B100110},{3,8456,B010000},{3,95,B101110},{3,279,B010111},{3,273,B011111},
  {3,284,B000111},{3,277,B010111},{3,278,B011111},{3,353,B100111},{1,355,B101111},{3,357,B110111},{3,359,B111111},{3,283,B011000},{3,780,B101000},{3,354,B1100111},{3,356,B1101111},{3,358,B1110111},{3,360,B1111111},



```


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







### Keychart C64

| Key | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 49 | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 | 48 | 
| Row/Col | R0C0    | R7C0    | R3C7    | R7C1    | R0C2    | R7C2    | R0C3    | R7C3    | R0C4    | R7C4    |
| Mux Code| B000000 | B000111 | B111011 | B001111 | B010000 | B010111 | B011000 | B011111 | B100000 | B100111 |

| Key | Q | W | E | R | T | Y | U | I | O | P |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 81 | 87 | 69 | 82 | 84 | 89 | 85 | 73 | 79 | 80 | 
| Row/Col | R6C0    | R1C1    | R6C1    | R1C2    | R6C2    | R1C3    | R6C3    | R1C4    | R6C4    | R1C5    |
| Mux Code| B000110 | B011001 | B001110 | B010001 | B010110 | B011001 | B011110 | B100001 | B100110 | B101001 |

| Key | A | S | D | F | G | H | J | K | L | ENTER |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 65 | 83 | 68 | 70 | 71 | 72 | 74 | 75 | 76 | 286 | 
| Row/Col | R2C1    | R5C1    | R2C2    | R5C2    | R2C3    | R5C3    | R2C4    | R5C4    | R2C5    | R1C7    |
| Mux Code| B001010 | B001101 | B010010 | B010101 | B011010 | B011101 | B100010 | B100101 | B101010 | B111001 |

| Key | Z | X | C | V | B | N | M | . | SPACE | @ |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 90 | 88 | 67 | 86 | 66 | 78 | 77 | 61 | 287 | 16434 | 
| Row/Col | R4C1     | R3C2    | R4C2    | R3C3    | R4C3    | R3C4    | R4C4    | R4C5    | R4C0    | R6C5 |
| Mux Code|  B011100 | B010011 | B010100 | B011011 | B011100 | B100011 | B100100 | B101100 | B000100 | B101110 |

| Key | + | , | : | - | L-Arrow | $ | * | ; | / | L-SHIFT | R-SHIFT | CTRL | = | Up | HOME |
| - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 16479 | 59 | 16475 | 60 | 277 | 16436 | 16440 | 91 | 62 | 16646 | 16647| 8456 | 95 | 279 | 273 |
| Row/Col | R0C5    | R3C5    | R5C5    | R7C5    | R1C0    | R0C6    | R1C6    | R2C6    | R3C6    | R3C1    | R4C6    | R0C2    | R5C6    | R6C6    | R7C6 |
| Mux Code| B101000 | B101011 | B101101 | B101111 | B000001 | B110000 | B110001 | B110010 | B110011 | B011011 | B110100 | B010000 | B110101 | B110110 | B110111 |

| Key | DEL | L-R | U-D | F1 | F3 | F5 | F7 | Run/Stop | CMDRE | F2 | F4 | F6 | F8 |
| - | - | - | - | - | - | - | - | - | - |
| USB Code| 284 | 277 | 278 | 353 | 355 | 357 | 359 | 283 | 780 | 354 | 356 | 358 | 360 |
| Row/Col | R0C7    | R2C7    | R3C7    | R4C7    | R5C7    | R6C7    | R7C7    | R3C0    | R5C0    | S + R4C7 | S + R5C7 | S + R6C7 | S + R7C7 | 
| Mux Code| B111000 | B111010 | B111011 | B111100 | B111101 | B111110 | B111111 | B000011 | B000101 | B1111100 | B1111101 | B1111110 | B1111111 | 


