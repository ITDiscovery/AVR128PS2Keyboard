# AVR128PS2Keyboard
This project started as a way to attach a USB Keyboard to a retro computer, the ZX-81. The schematic and board will
accomodate most any retro PC that uses a matrix. It has the ability for both Shift, CTRL, ALT and one other "function key". The board is an extension of the AVR128DB28 Breakout board, so I've included the ability to get at all the ports this device has.

Design Goals:
1. USB to ZX-81 (done)
1. USB to ZX Spectrum (or Harlequin) (done)
1. USB to Dragon
1. USB to Color Computer 2/3
1. Model 1/2/3/4/4P/16/6000? 
1. Mac Classic (M0110, M0110A and M0120 keyboards) via the J9 Connector, and Mouse via J6 Connector. (https://github.com/altercation/tmk_firrmware_hhkb_teensy2/blob/master/protocol/m0110.c)
1. Have it so that you can select or change on the fly which system you are emulating (done)
1. Have it store a default emulation in EEPROM (done)
1. Have it display via keyboard led which emulation it's doing (keyboard.setLEDs seems to be broken, next board can have LEDs added)
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

Connection to the Mac Classic:
H5-1: Gnd
H5-3: PF1
H5-4: PF0
H7-2: +5V
