
# TRS (Tandy Radio Shack) Color Computer 1,2,3 and Model 1,2,3,4,4P,12,6000 (Untested)
This file contains the connection and keyboard info for the ZX-80/81 and the ZX Spectrum (Harlequin). This code has been tested.

## Color Computer 2

### Connections
Connect on the board:
1. H3A-7 to H6-1
1. H4A-8 to H6-2

Connect the board to the ZX-81:
1. H7-5 to +5V
1. H7-6 to Gnd
1. H3-1 to J5-1 (R1/Pin 2/PA0)
1. H3-2 to J5-2 (R2/Pin 3/PA1)
1. H3-3 to J5-4 (R3/Pin 4/PA2)
1. H3-4 to J5-5 (R4/Pin 5/PA3)
1. H3-5 to J5-6 (R5/Pin 6/PA4)
1. H3-6 to J5-7 (R6/Pin 7/PA5)
1. H3-7 to J5-8 (R7/Pin 8/PA6)
1. H4-1 to J5-9 (C9/Pin 9/PB0)
1. H4-2 to J5-10 (C10/Pin 10/PB1)
1. H4-3 to J5-11 (C11/Pin 11/PB2)
1. H4-4 to J5-12 (C12/Pin 12/PB3)
1. H4-5 to J5-13 (C13/Pin 13/PB4)
1. H4-6 to J5-14 (C14/Pin 14/PB5)
1. H4-7 to J5-15 (C15/Pin 15/PB6)
1. H4-8 to J5-16 (C16/Pin 16/PB7)

**Note: PA7 goes to the DAC (U3)

### Keychart

| Key | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 49 | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 | 48 | 
| Row/Col | R5C10 | R5C11 | R5C12 | R5C13 | R5C14 | R5C15 | R5C16 | R6C9 | R6C10 | R5C9 |
| Mux Code|  |   |  | |  |  |  |  |  |  |

| Key | Q | W | E | R | T | Y | U | I | O | P |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 81 | 87 | 69 | 82 | 84 | 89 | 85 | 73 | 79 | 80 | 
| Row/Col | R3C10 | R3C16 | R1C14 | R3C11 | R3C13 | R4C10 | R3C14 | R2C10 | R2C16 | R3C9 |
| Mux Code| |  | |   |  | | |  | | |

| Key | A | S | D | F | G | H | J | K | L | ENTER |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 65 | 83 | 68 | 70 | 71 | 72 | 74 | 75 | 76 | 286 | 
| Row/Col | R1C10 | R3C12 | R1C13 | R1C15 | R1C16 | R2C9 | R2C11 | R2C12 | R2C13 | R7C9 |
| Mux Code|  |   |   |   |   |  |   |    | |  |

| Key | Z | X | C | V | B | N | M | . | SPACE |
| - | - | - | - | - | - | - | - | - | - |
| USB Code| 90 | 88 | 67 | 86 | 66 | 78 | 77 | 61 | 287 |
| Row/Col | R4C11 | R4C9 | R1C12 | R3C15 | R1C11 | R2C15 | R2C14 | R6C15 | R4C16 |
| Mux Code|  | |  |  |  |  |  |  |  |

| Key | U-Arrow | D-Arrow | L-Arrow | R-Arrow | : | ; | , | - | . | / | 
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 279 | 280 | 277 | 278 | 16475 | 91 | 59 | 60 | 61 | 62 | 
| Row/Col | R4C12 | R4C13 | R4C14 | R4C15 | R6C11 | R6C12 | R6C13 | R6C14 | R6C15 | R6C16 |
| Mux Code|  |  |  |  |  |  |  |  |  |  |

| Key | Clear | Break | L-Shift | R-Shift | * | + | < | = | > | ? | 
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 284 | 283 | 16646 | 16647 | 16440 | 16479 | 16443 | 95 | 16445 | 16446 |
| Row/Col | R7C10 | R7C11 | R7C16 | R7C16 | R7C16 & R6C11 | R7C16 & R6C12 | R7C16 & R6C13 | R7C16 & R6C14 | R7C16 & R6C15 | R7C16 & R6C16 |
| Mux Code|  |  |  |  |  |  |  |  |  |  |
