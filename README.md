# HIDButtons

Arduino USB HID button interface written for ATMEGA32u4 and ported to PlatformIO IDE.  

#### Version 1.0.0
## Features

Provides 4 x Independent HID buttons capable of simultaneous operation.  Button ID range is 0x30 to 0x33 on pins D6, D7, IO8 and IO9 respectively on the Arduino Micro board.
## Details

A 25 millisecond key debounce delay is used by default.

Four single pole normally open pushbuttons can be
connected by wiring them between ground and one of the
abovementioned input pins. There is no need for an external  
pullup resistor, as internal pullups are enabled.

A small capacitor may be required across the switch contacts should RF interference cause false triggering.

It is recommended that USB cables with integral ferrite filters be used if exposed to high RF power.

## Programming

Easiest way is to select Upload on the PlatformIO Project Tasks menu for the appropriate board. Alternatively, firmware can be manually flashed to the Arduino Micro using:

avrdude -p atmega32u4 -c avr109 -b 57600 -D -P /dev/ttyACM0 -U flash:w:firmware.hex:i

Change target serial port to suit. :-)
