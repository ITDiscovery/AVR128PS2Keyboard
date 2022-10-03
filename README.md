# AVR128PS2Keyboard
This project started as a way to attach a USB Keyboard to a retro computer, the ZX-81. The schematic and board will
accomodate most any retro PC that uses a matrix. It has the ability for both Shift, CTRL, ALT and one other "function key". The board is an extension of the AVR128DB28 Breakout board, so I've included the ability to get at all the ports this device has.

Design Goals:
1. USB to ZX-81
1. USB to ZX Spectrum (or Harlequin)
1. USB to Dragon
1. USB to Color Computer 2/3
1. Have it so that you can select or change on the fly which system you are emulating
1. Have it store a default emulation in EEPROM
1. Provide a serial connection to Composite TV, so a quicky dumb terminal (combines a couple of projects)

I didn't need to re-write the PS2Advanced Library. After a couple of iterations of DXCore updates, 
it started working. A guess is that it was a problem with attachInterupt...which if you change the setting of, 
the library doesn't work at all.

Here's Ben Eater's description of how the Keyboard works. All that is done via the PSAdvanced library.
https://www.youtube.com/watch?v=7aXbh9VUB3U

PS2Advanced Libary is at https://github.com/techpaul/PS2KeyAdvanced

For the ZX-81:

Connect on the board:
1. H3A-1 to H6-1
1. H4A-8 to H6-2

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



Codes:
```
/* Single Byte Key Codes */
USB_KC_CAPS     0x03
USB_KC_PRNTSCN. 0x04
USB_KC_L_SHIFT  0x06
USB_KC_R_SHIFT  0x07
USB_KC_L_CTRL   0X08
USB_KC_R_CTRL   0X09
USB_KC_L_ALT    0x0A
USB_KC_R_ALT    0x0B
USB_KC_L_START  0x0C
USB_KC_R_START  0x0D
USB_KC_R_BOX    0x0E
USB_KC_HOME.    0x11
USB_KC_END      0x12
USB_KC_PGUP.    0x13
USB_KC_PGDN     0x14
USB_KC_L_ARROW  0x15
USB_KC_R_ARROW  0x16
USB_KC_U_ARROW  0x17
USB_KC_D_ARROW  0x18
USB_KC_INSERT   0x19
USB_KC_DEL      0x1A
USB_KC_ESC      0x1B
USB_KC_BS.      0x1C
USB_KC_TAB      0x1D
USB_KC_ENTER    0x1E
USB_KC_SPACE    0x1F
USB_KC_KP0.     0x20
USB_KC_KP1      0x21
USB_KC_KP2      0x22
USB_KC_KP3      0x23
USB_KC_KP4      0x24
USB_KC_KP5      0x25
USB_KC_KP6      0x26
USB_KC_KP7      0x27
USB_KC_KP8      0x28
USB_KC_KP9      0x29
USB_KC_KP_DOT   0x2A
USB_KC_KPENT    0x2B
USB_KC_KP_PLUS  0x2C
USB_KC_KP_MINUS 0x2D
USB_KC_KP_TIMES 0x2E
USB_KC_KP/      0x2F
USB_KC_0        0X30
USB_KC_1        0X31
USB_KC_2        0X32
USB_KC_3        0X33
USB_KC_4        0X34
USB_KC_5        0X35
USB_KC_6        0X36
USB_KC_7        0X37
USB_KC_8        0X38
USB_KC_9        0X39
USB_KC_DASH.    0x3C
USB_KC_APOS     0x40
USB_KC_A        0X41
USB_KC_B        0X42
USB_KC_C        0X43
USB_KC_D        0X44
USB_KC_E        0X45
USB_KC_F        0X46
USB_KC_G        0X47
USB_KC_H        0X48
USB_KC_I        0X49
USB_KC_J        0X4A
USB_KC_K        0X4B
USB_KC_L        0X4C
USB_KC_M        0X4D
USB_KC_N        0X4E
USB_KC_O        0X4F
USB_KC_P        0X50
USB_KC_Q        0X51
USB_KC_R        0X52
USB_KC_S        0X53
USB_KC_T        0X54
USB_KC_U        0X55
USB_KC_V        0X56
USB_KC_W        0X57
USB_KC_X        0X58
USB_KC_Y        0X59
USB_KC_Z        0X5A
USB_KC_SEMI     0X5B
USB_KC_SLASH.   0x5C
USB_KC_OPEN_SQ  0X5D
USB_KC_CLOSE_SQ 0X5E
USB_KC_EQUAL.   0x5F
USB_KC_F1       0X61
USB_KC_F2       0X62
USB_KC_F3       0X63
USB_KC_F4       0X64
USB_KC_F5       0X65
USB_KC_F6       0X66
USB_KC_F7       0X67
USB_KC_F8       0X68
USB_KC_F9       0X69
USB_KC_F10      0X6A
USB_KC_F11      0X6B
USB_KC_F12      0X6C
USB_KC_NUM      0x77 
USB_KC_SCROLL   0x7E
```
