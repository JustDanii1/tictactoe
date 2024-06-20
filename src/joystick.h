#pragma once

class Joystick {
  public:
    int vertPin;
    int horzPin;
    int buttonPin;
    int vertVal;
    int horzVal;
    bool buttState;

    Joystick(int vPin, int hPin, int bPin);
    void updateVal();

  private:
    int x;
};