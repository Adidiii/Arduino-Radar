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
