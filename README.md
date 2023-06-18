# AVR128PS2Keyboard
This project started as a way to attach a USB Keyboard to a retro computer, the ZX-81. The schematic and board will
accomodate most any retro PC that uses a matrix. It has the ability for both Shift, CTRL, ALT and one other "function key". The board is an extension of the AVR128DB28 Breakout board, so I've included the ability to get at all the ports this device has.

Design Goals:
1. USB to ZX-81 (done)
1. USB to ZX Spectrum (or Harlequin) (done)
1. USB to Dragon
1. USB to Color Computer 2/3?
1. USB to Model 1/2/3/4/4P/16/6000? 
1. USB to Commodore64/VIC20/PET?
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

Specific support for the various lines have been broken out:
- [Sinclair](https://github.com/ITDiscovery/AVR128PS2Keyboard/blob/main/Sinclair.md) full support of the ZX-80/81 and the Spectrum.
- [Tandy/RadioShack](https://github.com/ITDiscovery/AVR128PS2Keyboard/blob/main/TRS.md) untested code for the Color Computer and Model 3.
- [Commodore](https://github.com/ITDiscovery/AVR128PS2Keyboard/blob/main/Commodore.md) untested code for the C64, and VIC20.


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
