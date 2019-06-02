#ifndef Display_h
#define Display_h
#include "Arduino.h"

class Display
{
  public:
    Display(int relayPin, int ledPin, int redPin,
            int buzzerPin);
    void lcdStart();
    void lcdAuthorised();
    void lcdDenied();
    void open();
    void close();
    void buzzer();
    void lcdPassword();
    void printPassword(String pw);
    void lcdFpAccess(int fingerID);
    void fpNewID(String sFingerID);
    void lcdInvalidID();
    void lcdFpStored();
    void placeFpAgain();
    void removeFinger();

  private:
    int _relayPin;
    int _buttonPin;
    int _ledPin;
    int _redPin;
    int _buzzerPin;
};

#endif
