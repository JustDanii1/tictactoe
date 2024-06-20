#pragma once

#include <Arduino.h>
#include "joystick.h"

class Game {
  private:

  public:
    Game();
    void checkAction(Joystick* player);
    void setLed();
    int board[3][3];//0 - нулики, 1 - хрестики, -1 - пустота
    bool playerTurn;
    int cursorX;
    int cursorY;

};