// Step 1: Import required libraries
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Step 2: Initialize LCD object 
// lcd( hex I2C Address, int #columns, int #rows)
// We are using a 16x2 LCD
LiquidCrystal_I2C lcd(0x27,  16, 2);

void setup() {
  // Step 3: Initialize the LCD and turn on the light
  // Initialize lcd screen
  lcd.init();
  // Turn on the backlight
  lcd.backlight();
}
void loop() {
  // Step 4: Print out Sample Text
  // Short delay for a second
  delay(1000)
  // Set where we will begin to write (Column, Row) = top left
  lcd.setCursor(0,0);
  // Print string "Hello World"
  lcd.print(“Hello World”);
  // Move to the next row 
  lcd.setCursor(0,1);
  // Print string "This is a test"
  lcd.print(“This is a test”);
}
