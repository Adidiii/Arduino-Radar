# Yet Another Arduino Radar

This script will control the rotation of a servo motor, which will in of itself rotate an ultrasonic sensor. It will then scan for distance every degree spun. The collected data will be mapped onto an embedded screen in a radar-tracker-like view.

## Dependencies

 * Adafruit SSD1306 Arduino Library
 * Adafruit GFX
 * NewPing
 * HC-SR04 Ultrasonic Sensor
 * SG90 Servo Motor
 * GM009605 Display

## Installation

1. Install the [Arduino IDE](https://www.arduino.cc/en/software/)
2. Import the script
3. Install the dependencies using the [Arduino library manager](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/)
4. Upload the chip to an Arduino UNO

## Pinout

 * **Ultrasonic Sensor:**
    - **TRIG:** 9
    - **ECHO:** 10
 * **Servo Motor**
    - **Control:** 11
 * **Display**
    - **SCK:** A4
    - **SDA** A5
## Demonstration

https://github.com/user-attachments/assets/24835165-2d93-40bb-9782-433eb4b1d155

The blue line's length symbolise the distance of the object: longer lines mean a further object. When an object is scanned over, yellow text in the corner of the screen displays the precise distance of said object.
