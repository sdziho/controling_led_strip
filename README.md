# Controling RGB led strip with arduino
In this project, we will make led strip controling with TV Remote Control. 
The idea is to create a program that will automatically change the color by default and the ability to select the color manually.
  
As the name suggest, there are 3 types of diodes built in RGB strip; red (R), green (G) and blue (B).
Each of the colors is coded with number from 0 to 255 and represents intesity of light (0 - the lowest intesity, 255 - the highest intesity).
Combination of these 3 colors could give 16,777,216 combinations of different colors. 
For more information about colors [visit this page](https://www.rapidtables.com/web/color/RGB_Color.html)
## Finding HEX codes
Choose right buttons on your TV Remote Control and find out theirs HEX codes using [IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote) librery for Arduino.
My hex codes are given in controling_led_strip.ino file.
```
//------------- CODE INFO ----------
// 0x37 or 0x837 is code for red button on my TV remote controller
// 0x36 or 0x836 is code for green button on my TV remote controller
// 0x34 or 0x834 is code for blue button on my TV remote controller

// 0x23 or 0x823 is code for UP ARROW on my TV remote controller
// 0xE or 0x80E is code for DOWN ARROW on my TV remote controller
// 0x16 or 0x816 is code for ZERO (0) on my TV remote controller

// 0x32  or 0x832 is code for yellow button on my TV remote controller which turns on automaticlly changing color mode
```
The idea is that when you click on the R, G or B button, the appropriate color is selected for which you want to change in the intensity.
Intesity is changing by clicking UP or DOWN button on Remote Controler, or clicking button zero (0) to set intensity to zero. 
The yellow button represents the mode in which the colors change automatically and this is default mode.

## Parts
- RGB led strip 5m
- DC power supply 12V, 2A
- Arduino Nano
- C945 transistor (3x)
- 390 Ohm resistor (3x) 
- IR reciever
- TV remote controller

## Schematics
![image](https://user-images.githubusercontent.com/73039566/149667054-caf4c6b0-2384-4b56-a299-007b4fa2853d.png)

