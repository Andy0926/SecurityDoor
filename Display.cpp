#include "Arduino.h"
#include "Display.h"
#include "LiquidCrystal_PCF8574.h"
LiquidCrystal_PCF8574 lcd(0x27);

Display::Display(int relayPin, int buttonPin, int ledPin, int redPin, int buzzerPin)
{
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  _buttonPin=buttonPin;
  _relayPin=relayPin;
  _ledPin = ledPin;
  _redPin = redPin;
  _buzzerPin = buzzerPin;
}

void Display::buzzer()
{
  digitalWrite(_buzzerPin, HIGH);
  delay(50);
  digitalWrite(_buzzerPin, LOW);
  delay(50);
  digitalWrite(_buzzerPin, HIGH);
  delay(50);
  digitalWrite(_buzzerPin, LOW);
}

void Display::close()
{
  digitalWrite(_redPin, HIGH);
  digitalWrite(_relayPin, HIGH);
  digitalWrite(_ledPin, LOW);
  buzzer();
  lcdStart();
}

void Display::open()
{
  digitalWrite(_relayPin, LOW);
  digitalWrite(_redPin, LOW);
  digitalWrite(_ledPin, HIGH);
  buzzer();
}

void Display::lcdDenied()
{
  lcd.begin(16, 2);
  lcd.print("Access Denied");
}

void Display::lcdAuthorised()
{
  lcd.begin(16, 2);
  lcd.print("Access Granted");
}

void Display::lcdStart()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("   Welcome to");
  lcd.setCursor(0, 1);
  //Print a message to second line of LCD
  lcd.print("    Incubator");
}
