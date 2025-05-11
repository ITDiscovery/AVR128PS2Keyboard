# AVR128PS2Keyboard
This project started as a way to attach a USB Keyboard to a retro computer, the ZX-81. The schematic and board will
accomodate most any retro PC that uses a matrix. It has the ability for both Shift, CTRL, ALT and one other "function key". The board is an extension of the AVR128DB28 Breakout board, so I've included the ability to get at all the ports this device has.

Design Goals:
1. USB to ZX-81 (done)
1. USB to ZX Spectrum (or Harlequin) (done)
1. USB to Dragon
1. USB to Color Computer 2/3 (in progess for version 5)
1. USB to Model 1/2/3/4/4P/16/6000? 
1. USB to Commodore VIC20 (done) /C64/PET
1. Classic MacIntosh (M0110 keyboard) via the J9 Connector, and Mouse via J6 Connector. (https://github.com/altercation/tmk_firrmware_hhkb_teensy2/blob/master/protocol/m0110.c) -Done: Needs more work, and I need to correct some issues with my MacClassicPlus 1Mb. This code base will be standalone...how this old Mac handles keys is different from the other retro computers.
1. Have it so that you can select or change on the fly which system you are emulating (done)
1. Have it store a default emulation in EEPROM (done)
1. Provide the ability to do a reset/restore (Using 4Z gate, Pin 7 and 8 on H6). -done
1. Have it display via keyboard led which emulation it's doing (keyboard.setLEDs seems to be broken, next board can have LEDs added)
1. Provide a serial connection or a Composite TV, so a quicky dumb terminal (combines a couple of projects)
1. Move the lookup tables to Flash (PROGMEM)


I didn't need to re-write the PS2Advanced Library. After a couple of iterations of DXCore updates, it started working. A guess is that it was a problem with attachInterupt...which if you change the setting of, the library doesn't work at all.

Here's Ben Eater's description of how the Keyboard works. All that is done via the PSAdvanced library.
https://www.youtube.com/watch?v=7aXbh9VUB3U

PS2Advanced Libary is at https://github.com/techpaul/PS2KeyAdvanced

Specific support for the various lines have been broken out:
- [Sinclair](https://github.com/ITDiscovery/AVR128PS2Keyboard/blob/main/Sinclair.md) full support of the ZX-80/81 and the Spectrum.
- [Tandy/RadioShack](https://github.com/ITDiscovery/AVR128PS2Keyboard/blob/main/TRS.md) untested code for the Color Computer and Model 3.
- [Commodore](https://github.com/ITDiscovery/AVR128PS2Keyboard/blob/main/Commodore.md) untested code for the C64, and VIC20.

Mux Code is driven by the follwing:

| Connection | Bits  7/6 | Bits 5/4/3 | Bits 2/1/0 |
| - | - | - | - |
| H3-1 | XX | XXX | 000 | 
| H3-2 | XX | XXX | 001 | 
| H3-3 | XX | XXX | 010 | 
| H3-4 | XX | XXX | 011 | 
| H3-5 | XX | XXX | 100 | 
| H3-6 | XX | XXX | 101 | 
| H3-7 | XX | XXX | 110 | 
| H3-8 | XX | XXX | 111 | 
| H4-1 | XX | 000 | XXX | 
| H4-2 | XX | 001 | XXX | 
| H4-3 | XX | 010 | XXX | 
| H4-4 | XX | 011 | XXX | 
| H4-5 | XX | 100 | XXX | 
| H4-6 | XX | 101 | XXX | 
| H4-7 | XX | 110 | XXX | 
| H4-8 | XX | 111 | XXX | 
| No-Shift| 00 | XXX | XXX |
| H6-1/2 | 01 | XXX | XXX |
| H6-3/4 | 10 | XXX | XXX |
| H6-5/6 | 11 | XXX | XXX |

A reset or other switched line (Restore on Commodore for instance) can be
connected to pins H6-7 and H6-8 where the code will perform make contact for 100mSec
when the Pause/Break (Code 6) is typed. A handy ground pin at H5-1 can be used to with a
dropping resistor to H6-8 for a nice reset button.

Connection to the Mac Classic (This is a separate code base):
1. J9-1(Gnd) to H5-1 
1. J9-2(Clk) to H5-4
1. J9-3(Data) to H5-3
1. J9-4(+5v) to H5-2 (Don't populate R4 or R5)
1. J6-1(Gnd) H7-1
1. J6-2(+5V) H7-2
1. J6-3 N/C
1. J6-4(X2) H7-3
1. J6-5(X1) H7-4
1. J6-6 N/C
1. J6-7(SW-) to U4-12
1. J6-8(Y2) to H7-5
1. J6-9(Y1) to H7-6
