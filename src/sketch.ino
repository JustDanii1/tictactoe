#include <Arduino.h>
#include <SPI.h>
#include "joystick.h"
#include "display.h"
#include "game.h"

Joystick player[] = {
  {14, 27, 26},
  {25, 33, 32}
};




Display display;
Game game;

void setup() {
  display.init();


  digitalWrite(18, 1);
  digitalWrite(19, 1);

}

void loop() {

  digitalWrite(18, !game.playerTurn);
  digitalWrite(19, game.playerTurn);

  display.refresh(game);

  for (int i = 0; i < 2; i++) {
    player[i].updateVal();
  }

  game.checkAction(player);


 // printf("\n");
  delay(100);
}




