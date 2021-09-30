#include <Arduino.h>

/*
 *  Project     HID Buttons Library
 *  @author     David Madison
 *  @link       github.com/dmadison/HID_Buttons
 *  @license    MIT - Copyright (c) 2019 David Madison
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *  Example:      JoystickButton
 *  Description:  Use the HID Buttons library with Joystick buttons. Requires the
 *                Arduino Joystick library:
 *                https://github.com/MHeironimus/ArduinoJoystickLibrary
 *
 *  Modified by phil61 to support 4 concurrent PTT buttons.
 *  
 *                Provides 4 x Independent HID buttons capable of simultaneous 
 *                operation.  Button ID range is 0x30 to 0x33 on pins
 *                D6, D7, IO8 and IO9 respectively on the Arduino Micro board.
 *                
 *                A 25 millisecond key debounce delay is used by default.
 *                
 *                Four single pole normally open pushbuttons can be
 *                connected by wiring them between ground and one of the
 *                abovementioned input pins. There is no need for an external  
 *                pullup resistor, as internal pullups are enabled.
 *                A small capacitor may be required across the switch contacts
 *                if RF interference causes false triggering.
 *                
 *                It is recommended that USB cables with integral ferrite filters 
 *                be used.
 *
 */

#ifndef TEENSYDUINO
#include <Joystick.h>  // Use MHeironimus's Joystick library

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
	4, 0,                  // Button Count, Hat Switch Count
	false, false, false,    // No X, Y, or Z axes
	false, false, false,    // No Rx, Ry, or Rz
	false, false,           // No rudder or throttle
	false, false, false);   // No accelerator, brake, or steering

const uint8_t ButtonOffset = 1; // Arduino Joystick buttons are indexed at 0
#else
const uint8_t ButtonOffset = 0;  // Teensy Joystick buttons are indexed at 1
#endif

#include <HID_Buttons.h>  // Must import AFTER Joystick.h

const uint8_t Button1Pin = 6;  // Pin for hardware button 1
const uint8_t Button1Number = 1 - ButtonOffset;  // Press this Joystick button # when the pin 1 is grounded
const uint8_t Button2Pin = 7;  // Pin for hardware button 2
const uint8_t Button2Number = 2 - ButtonOffset;  // Press this Joystick button # when the pin 2 is grounded
const uint8_t Button3Pin = 8;  // Pin for hardware button 3
const uint8_t Button3Number = 3 - ButtonOffset;  // Press this Joystick button # when the pin 3 is grounded
const uint8_t Button4Pin = 9;  // Pin for hardware button 4
const uint8_t Button4Number = 4 - ButtonOffset;  // Press this Joystick button # when the pin 4 is grounded

JoystickButton myButton1(Button1Number);
JoystickButton myButton2(Button2Number);
JoystickButton myButton3(Button3Number);
JoystickButton myButton4(Button4Number);

void setup() {
	pinMode(Button1Pin, INPUT_PULLUP);
	pinMode(Button2Pin, INPUT_PULLUP);
	pinMode(Button3Pin, INPUT_PULLUP);
	pinMode(Button4Pin, INPUT_PULLUP);
	Joystick.begin();
}

void loop() {
	myButton1.set(!digitalRead(Button1Pin));
	myButton2.set(!digitalRead(Button2Pin));
	myButton3.set(!digitalRead(Button3Pin));
	myButton4.set(!digitalRead(Button4Pin));
	delay(25); // Key debounce delay in milliseconds
}