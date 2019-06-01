#ifndef Display_h
#define Display_h
#include "Arduino.h"

class Display
{
  public:
    Display(int relayPin, int buttonPin, int ledPin, int redPin,
            int buzzerPin);
    void lcdStart();
    void lcdAuthorised();
    void lcdDenied();
    void open();
    void close();
    void buzzer();

  private:
    int _relayPin;
    int _buttonPin;
    int _ledPin;
    int _redPin;
    int _buzzerPin;
};

#endif
