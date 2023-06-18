# Sinclair ZX-80/81 and Spectrum page
This file contains the connection and keyboard info for the ZX-80/81 and the ZX Spectrum (Harlequin). This code has been tested.

## ZX-80/81

### Connections
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

### Keychart

| Key | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 49 | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 | 48 | 
| Row/Col | D1KBD0 | D1KBD1 | D1KBD2 | D1KBD3 | D1KBD4 | D3KBD4 | D3KBD3 | D3KBD2 | D3KBD1 | D3KBD0 |
| Mux Code| B000000 |  B000001  | B000010 | B000011 | B000100 | B010100 | B010011 | B010010 | B010001 | B010000 |

| Key | Q | W | E | R | T | Y | U | I | O | P |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 81 | 87 | 69 | 82 | 84 | 89 | 85 | 73 | 79 | 80 | 
| Row/Col | D2 | D2 | D2 | D2 | D2 | D5 | D5 | D5 | D5 | D5  |
| Mux Code| B001000 | B001001 | B001010 | B001011  | B001100 | B100100 | B100011 | B100010 | B100001 | B100000 |

| Key | A | S | D | F | G | H | J | K | L | ENTER |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 65 | 83 | 68 | 70 | 71 | 72 | 74 | 75 | 76 | 286 | 
| Row/Col | D4KBD0 | D4KBD1 | D4KBD2 | D4KBD3 | D4KBD4 | D7KBD4 | D7KBD3 | D7KBD2 | D7KBD1 | D7KBD0 |
| Mux Code| B011000   | B011001  |  B011010  | B011011   |  B011100  | B110100   | B110011   | B110010   | B110001  |  B110000 |

| Key | Z | X | C | V | B | N | M | . | SPACE |
| - | - | - | - | - | - | - | - | - | - |
| USB Code| 90 | 88 | 67 | 86 | 66 | 78 | 77 | 61 | 287 |
| Row/Col | D6 | D6 | D6 | D6 | D6 | D8 | D8 | D8 | D8 |
| Mux Code| B101001 | B101010 | B101011 | B101100 | B111100 | B111011 | B111010 | B111001 | B111000 |

| Key | ' | , | - | / | ; | = | DEL | " | ? | : | + | 
| - | - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 58 | 59 | 60 | 62 | 91 | 95 | 284 | 16442 | 16446 | 16475 | 16479 | 
| Mux Code| B1100000 | B1111001 | B1110011 | B1101100 | B1101001 | B1110001 | B1010000 | B1100000 | B1101011 | B1101010 |B1110010 |

## For the ZX-Spectrum/Harlequin:

### Connections

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

### Keychart

| Key | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 49 | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 | 48 | 
| Row/Col | D1KBD0 | D1KBD1 | D1KBD2 | D1KBD3 | D1KBD4 | D3KBD4 | D3KBD3 | D3KBD2 | D3KBD1 | D3KBD0 |
| Mux Code| B000000 |  B000001  | B000010 | B000011 | B000100 | B010100 | B010011 | B010010 | B010001 | B010000 |
| Shift Code| 

  {1,49,B000000},{1,50,B000001},{1,51,B000010},{1,52,B000011},{1,53,B000100},{1,54,B011100},{1,55,B011011},{1,56,B011010},{1,57,B011001},{1,48,B011000},

| Key | Q | W | E | R | T | Y | U | I | O | P |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 81 | 87 | 69 | 82 | 84 | 89 | 85 | 73 | 79 | 80 | 
| Row/Col | D2 | D2 | D2 | D2 | D2 | D5 | D5 | D5 | D5 | D5  |
| Mux Code| B001000 | B001001 | B001010 | B001011  | B001100 | B100100 | B100011 | B100010 | B100001 | B100000 |

   {1,81,B001000},{1,87,B001001},{1,69,B001010},{1,82,B001011},{1,84,B001100},{1,89,B100100},{1,85,B100011},{1,73,B100010},{1,79,B100001},{1,80,B100000},


| Key | A | S | D | F | G | H | J | K | L | ENTER |
| - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 65 | 83 | 68 | 70 | 71 | 72 | 74 | 75 | 76 | 286 | 
| Row/Col | D4KBD0 | D4KBD1 | D4KBD2 | D4KBD3 | D4KBD4 | D7KBD4 | D7KBD3 | D7KBD2 | D7KBD1 | D7KBD0 |
| Mux Code| B011000   | B011001  |  B011010  | B011011   |  B011100  | B110100   | B110011   | B110010   | B110001  |  B110000 |

  {1,65,B010000},{1,83,B010001},{1,68,B010010},{1,70,B010011},{1,71,B010100},{1,72,B110100},{1,74,B110011},{1,75,B110010},{1,76,B110001},{1,286,B110000},

| Key | Z | X | C | V | B | N | M | . | SPACE |
| - | - | - | - | - | - | - | - | - | - |
| USB Code| 90 | 88 | 67 | 86 | 66 | 78 | 77 | 61 | 287 |
| Row/Col | D6 | D6 | D6 | D6 | D6 | D8 | D8 | D8 | D8 |
| Mux Code| B101001 | B101010 | B101011 | B101100 | B111100 | B111011 | B111010 | B111001 | B111000 |

     {1,90,B101001},{1,88,B101010},{1,67,B101011},{1,86,B101100},{1,66,B111100},{1,78,B111011},{1,77,B111010},{1,287,B111000},

| Key | ' | , | - | / | ; | = | DEL | " | ? | : | + | 
| - | - | - | - | - | - | - | - | - | - | - | - |
| USB Code| 58 | 59 | 60 | 62 | 91 | 95 | 284 | 16442 | 16446 | 16475 | 16479 | 
| Mux Code| B1100000 | B1111001 | B1110011 | B1101100 | B1101001 | B1110001 | B1010000 | B1100000 | B1101011 | B1101010 |B1110010 |

  {1,16646,B01101000},