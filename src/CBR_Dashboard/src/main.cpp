#include <Arduino.h>
#include <TFT_eSPI.h>  // Include TFT library

TFT_eSPI tft = TFT_eSPI();  // Create TFT object

void setup() {
  // Initialize TFT
  tft.init();
  tft.setRotation(1);  // Landscape mode
  tft.fillScreen(TFT_BLACK);

  // Set text properties
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);

  // Static labels
  tft.drawString("Speed:", 10, 10, 2);
  tft.drawString("RPM:", 10, 50, 2);
  tft.drawString("Gear:", 10, 90, 2);

  // Draw RPM box
  tft.drawRect(150, 50, 100, 20, TFT_RED);
}

void loop() {
  // Dummy data
  int speed = 65;
  int rpm = 8000;
  int gear = 4;

  // Update speed
  tft.fillRect(80, 10, 60, 20, TFT_BLACK);  // Clear old value
  tft.setCursor(80, 10);
  tft.print(speed);
  tft.drawString("mph", 120, 10, 2);

  // Update RPM
  tft.fillRect(80, 50, 60, 20, TFT_BLACK);
  tft.setCursor(80, 50);
  tft.print(rpm);

  // RPM bar
  int rpmBarWidth = map(rpm, 0, 14000, 0, 98);
  tft.fillRect(151, 51, rpmBarWidth, 18, TFT_RED);

  // Update gear
  tft.fillRect(80, 90, 20, 20, TFT_BLACK);
  tft.setCursor(80, 90);
  tft.print(gear);

  delay(1000);  // Refresh every second
}