#include "Arduino.h"
#include "Display.h"
#include "LiquidCrystal_PCF8574.h"
LiquidCrystal_PCF8574 lcd(0x27);

Display::Display(int relayPin, int ledPin, int redPin, int buzzerPin)
{
  
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  _relayPin = relayPin;
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
  lcd.setBacklight(1);
  lcd.begin(16, 2);
  lcd.print("Access Denied");
}

void Display::lcdAuthorised()
{
  lcd.setBacklight(1);
  lcd.begin(16, 2);
  lcd.print("Access Granted");
}

void Display::lcdStart()
{
  // set up the LCD's number of columns and rows:
  lcd.setBacklight(1);
  lcd.begin(16, 2);
  lcd.print("   Welcome to");
  lcd.setCursor(0, 1);
  //Print a message to second line of LCD
  lcd.print("    Incubator");
}

void Display::lcdPassword()
{
  lcd.setBacklight(1);
  lcd.begin(16, 2);
  lcd.print("Enter Password");
  lcd.setCursor(0, 1);
  lcd.print("Press * to Enter");
}

void Display::printPassword(String pw)
{
  lcd.setBacklight(1);
  lcd.begin(16, 2);
  lcd.print("Enter Password");
  lcd.setCursor(0, 1);
  lcd.print(pw);
}

void Display::lcdFpAccess(int fingerID)
{
  lcd.setBacklight(1);
  switch (fingerID)
  {
  case 1:
    lcd.begin(16, 2);
    lcd.print("Welcome Andy");
    break;
  case 2:
    lcd.begin(16, 2);
    lcd.print("Welcome ChiaLing");

    break;
  case 3:
    lcd.begin(16, 2);
    lcd.print("Welcome Boonie");

    break;
  case 4:
    lcd.begin(16, 2);
    lcd.print("Welcome Li En");

    break;
  case 5:
    lcd.begin(16, 2);
    lcd.print("Welcome Kevin");

    break;
  case 6:
    lcd.begin(16, 2);
    lcd.print("Welcome Jeff");

    break;
  default:
    break;
  }
}

void Display::fpNewID(String sFingerID)
{
  lcd.setBacklight(1);
  lcd.begin(16, 2);
  lcd.print("Fingerprint ID");
  lcd.setCursor(0, 1);
  lcd.print(sFingerID);
}

void Display::lcdInvalidID()
{
  lcd.setBacklight(1);
  lcd.begin(16, 2);
  lcd.print("Invalid ID");
  lcd.setCursor(0, 1);
  close();
}

void Display::lcdFpStored(){
  lcd.setBacklight(1);
  lcd.begin(16, 2);
        lcd.print("FingerprintStored");
        buzzer();
}
