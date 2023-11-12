#include <TFT_eSPI.h>
#include "Free_Fonts.h"
#include <SPI.h>

// Create an instance of the TFT_eSPI class for the LCD display
TFT_eSPI lcd = TFT_eSPI();

// Variables to keep track of the X position for each chart
int posX = 0;
int posX1 = 0;

// Variable to store the light sensor reading
int light = 0;

// Variables to control the timing of different actions
long int time = 0;
long int time1 = 0;

// Function to draw a bar chart with a line for a given value
int chart1(int value, int max, int min, int positionX, int positionY, int sizeX, int sizeY, uint32_t background, uint32_t line) {
  // Check if the chart has reached the end
  if (sizeX > posX) {
    // Map the sensor value to the size of the chart
    int acVal = map(value, max, min, sizeY, 0);

    // Clear the previous column and draw the new one
    lcd.fillRect(posX + positionX, positionY, 2, sizeY, background);
    lcd.drawPixel(positionX + posX, acVal + positionY, line);

    // Move to the next X position
    posX++;
  } else {
    // Reset X position when the chart is complete
    posX = 0;
  }
}

// Function to draw a bar chart with an upper limit line for a given value
int chart2(int value, int max, int min, int positionX, int positionY, int sizeX, int sizeY, uint32_t background, uint32_t line, uint32_t upper) {
  // Check if the chart has reached the end
  if (sizeX > posX1) {
    // Map the sensor value to the size of the chart
    int acVal = map(value, max, min, sizeY, 0);

    // Clear the previous column and draw the upper limit line
    if (positionX - posX1 < sizeX) {
      lcd.fillRect(posX1 + positionX, positionY, 1, sizeY, background);
    }
    lcd.fillRect(posX1 + positionX, positionY, 1, acVal, upper);
    lcd.drawPixel(positionX + posX1, acVal + positionY, line);

    // Move to the next X position
    posX1++;
  } else {
    // Reset X position when the chart is complete
    posX1 = 0;
  }
}

void setup() {
  // Initialize the timing variables
  time, time1 = millis();

  // Initialize the LCD display
  lcd.init();
  lcd.setRotation(3);

  // Display initial information on the LCD
  lcd.setCursor(20, 12);
  lcd.fillScreen(TFT_WHITE);
  Serial.begin(9600);
  lcd.setTextColor(TFT_BLACK);
  lcd.setFreeFont(FF1);
  lcd.print("Simple charts example");
  lcd.println();
  lcd.print( "The value used in charts is  the amount of light sensed by the sensor.");
  delay(5000);
  lcd.fillScreen(TFT_WHITE);
  lcd.fillRect(20, 0, 300, 100, TFT_BLACK);
  lcd.fillRect(20, 120, 300, 100, TFT_BLUE);
}

void loop() {
  // Read the light sensor value
  light = analogRead(WIO_LIGHT);

  // Update the first chart every 20 milliseconds
  while (millis() > time + 20) {
    chart1(light, 1024, 0, 20, 0, 300, 100, TFT_BLACK, TFT_WHITE);
    chart2(light, 1024, 0, 20, 120, 300, 100, TFT_BLUE, TFT_BLACK, TFT_WHITE);

    // Update the timing variable
    time = millis();
  }

  // Update the LCD display every 300 milliseconds with the current light sensor value
  while (millis() > time1 + 300) {
    lcd.fillRect(0, 220, 50, 13, TFT_WHITE);
    lcd.setCursor(0, 232);
    Serial.begin(9600);
    lcd.setTextColor(TFT_BLACK);
    lcd.setFreeFont(FF1);
    lcd.print(light);

    // Update the timing variable
    time1 = millis();
  }
}