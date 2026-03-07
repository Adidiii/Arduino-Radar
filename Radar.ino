#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>
#include <NewPing.h>

// Screen data
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

// Radar data
#define TRIGGER_PIN  9
#define ECHO_PIN     10
#define MAX_DISTANCE 30

// Objects
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo servo;

// Center Radar
const int centerX = 64;
const int centerY = 60;
const int radius = 50;

// Memory to store the distance at each angle
byte distances[180]; 

void setup() {
  servo.attach(11);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    for(;;); // Don't proceed, loop forever if display fails
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  // Sweep from 0 to 170
  for(int angle = 0; angle <= 170; angle += 2) {
    updateRadar(angle);
  }
  // Sweep back from 170 to 0
  for(int angle = 170; angle >= 0; angle -= 2) {
    updateRadar(angle);
  }
}

void updateRadar(int angle) {
  int distance = sonar.ping_cm();
  
  // Add scan to memory
  distances[angle] = distance;
  
  display.clearDisplay();
  
  // Draw the semicricles
  display.drawCircle(centerX, centerY, radius, WHITE);
  display.drawCircle(centerX, centerY, radius/2, WHITE);
  
  // Loop over memory
  for (int i = 0; i <= 170; i += 2) {
    // If the scan has an object (non-zero)
    if (distances[i] > 0) {
      // Map the distance to a coresponding point in the circle
      float rad = (180 - i) * 3.14159 / 180.0;
      int blipRadius = map(distances[i], 0, MAX_DISTANCE, 0, radius);
      int xBlip = centerX + blipRadius * cos(rad);
      int yBlip = centerY - blipRadius * sin(rad);
      
      // Cast a line to that point
      display.drawLine(centerX, centerY, xBlip, yBlip, WHITE); 
    }
  }

  // Draw scanline
  float currentRadian = (180 - angle) * 3.14159 / 180.0;
  int xEnd = centerX + radius * cos(currentRadian);
  int yEnd = centerY - radius * sin(currentRadian);
  display.drawLine(centerX, centerY, xEnd, yEnd, WHITE);
  
  // Print current distance at top (only if something is currently detected)
  if (distance > 0 && distance <= MAX_DISTANCE) {
    display.setCursor(0,0);
    display.print("Dist: ");
    display.print(distance);
    display.print("cm");
  }

  display.display();
  servo.write(angle);
  delay(30); // Adjust for speed
}
