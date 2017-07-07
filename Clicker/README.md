Introduction
============
I made a video at https://www.youtube.com/watch?v=Ji2-2ehLCOQ for how to automate a clicker game on your phone using hardware.  This is a tutorial for how to make a clicker for "Switch Science 2455".  I was able to click the relay quickly without burning it out during any of my testing.  I found that any faster than 16ms @ 50/50 duty cycle and the phone didn't register it as a click, so that's the upper bound for my phone and game.



You will need
=============
1) A computer (I'm using Windows 10, so directions are based on that)
2) An Arduino Uno.
3) A USB cable (for connecting your computer to the Arduino)
4) A "Switch Science 2455" touch driver
5) Wires
6) Breadboard (optional, you could just use wires)

*If your touch driver does not come with 3 wires attached, then you will also need:
1) A solding iron
2) Solder
3) 3 Wires



Add wires to your touch driver if needed
========================================
The touch driver I bought had no wires on the one I bought, so I had to solder 3 wires to the pads.
Be very careful to make sure the solder for each wire is only on one pad.  
The three pads are labeled 5V, GND & EN.
If you have your choice of wire colors, I would recommend soldering one end of:
   a red wire to the +5V pad
   a blue wire to the GND pad
   a yellow wire to the EN pad



Connecting to Arduino
=====================
Connect the 5V wire from the touch driver to the breadboard's +5 rail.
Connect the GND wire from the driver to the breadboard's GND rail.
Connect the EN wire from the driver to a row of the breadboard (like row 16).
Connect the 5V pin of Arduino to the breadboard's +5 rail.
Connect one of the GND pins of the Arduino to the breadboard's GND rail.
Connect pin 13 of the Arduino to the same row as the EN driver (row 16 in our above example).



Program the Arudino to blink
============================
Download the Arudio.CC 1.8.3 (or newer) IDE from https://www.arduino.cc/en/Main/Software
Install the application
Run the IDE.
Load the blink example (LoadBlinkArduinoExample.png)       File-Examples-01.Basics-Blink
Choose your Arduino board (ChooseArduino.png)              Tools-Board-Arduino/Genuino Uno
Connect the USB cable between Arduino and the computer
Choose the port with the Arduino attached                  Tools-Port-COM3
Upload your program to the Arduino (UploadToArduino.png)   Sketch-Upload



At this point once a second the relay driver should click on/off.  
Touch the driver against a touch screen and it should start tapping.



Connect a second touch driver
=============================
Connect the 5V wire from the touch driver to the breadboard's +5 rail.
Connect the GND wire from the driver to the breadboard's GND rail.
Conenct EN pin from the driver to a row of the breadboard (like row 3).
Connect pin 11 of the Arduino to the same row as the EN driver (row 3 in our example).



Program the Arudino to blink both
=================================
Load the Clicker.ino file from this web site.
Choose your Arduino board (ChooseArduino.png)              Tools-Board-Arduino/Genuino Uno
Connect the USB cable between Arduino and the computer
Choose the port with the Arduino attached                  Tools-Port-COM3
Upload your program to the Arduino (UploadToArduino.png)   Sketch-Upload



At this point the first relay driver should tap 3 times, followed by the other clicker tapping one time.  
The pattern should repeat.


Edit the code to click faster (instead of "500" replace with "100" and it should click every 0.100 seconds).
Edit the code to click in a different pattern.
 
