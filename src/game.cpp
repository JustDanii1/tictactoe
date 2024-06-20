#include "game.h"


Game::Game() {
  playerTurn = 1;
  cursorX = 1;
  cursorY = 1;

  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      board[j][i] = -1;
    }
  }
}

void Game::checkAction(Joystick* player) {
 if (player[playerTurn].vertVal >= 4095) {
    cursorY--;
    if(cursorY < 0){
      cursorY = 0;
    }
    delay(200);
  }
  if (player[playerTurn].vertVal <= 0) {
    cursorY++;
    if(cursorY > 2){
      cursorY = 2;
    }
    delay(200);
  }

  if (player[playerTurn].horzVal >= 4095) {
    cursorX--;
    if(cursorX < 0){
      cursorX = 0;
    }
    delay(200);
  }
  if (player[playerTurn].horzVal <= 0) {
    cursorX++;
    if(cursorX > 2){
      cursorX = 2;
    }
    delay(200);
  }

  if(player[playerTurn].buttState == 0   &&   board[cursorY][cursorX] == -1){
    board[cursorY][cursorX] = playerTurn;
    playerTurn = !playerTurn;
    delay(200);
  }
  

  digitalWrite(0, !game.playerTurn);
  digitalWrite(1, game.playerTurn);



}
