#include "display.h"

Display::Display() : u8g2(U8G2_R0, U8X8_PIN_NONE) {

}

void Display::init() {
  u8g2.begin();
}

void Display::refresh(Game &game) {
  u8g2.firstPage();
  do {
    u8g2.drawRFrame(31, 1, 61, 61, 3);
    u8g2.drawLine(32, 42, 32 + 59, 42);
    u8g2.drawLine(32, 22, 32 + 59, 22);
    u8g2.drawLine(51, 2, 51, 2 + 59);
    u8g2.drawLine(71, 2, 71, 2 + 59);

    // cross(0, 0);
    // circle(1, 1);
    // crossCursor(0, 0);
    // circleCursor(1, 0);

    for (int y = 0; y < 3; y++) {
      for (int x = 0; x < 3; x++) {
        if (game.board[y][x] == 1) {
          cross(x, y);
        }
        if (game.board[y][x] == 0) {
          circle(x, y);
        }
      }
    }

    if (game.playerTurn == 1) {
      crossCursor(game.cursorX, game.cursorY);
    } else {
      circleCursor(game.cursorX, game.cursorY);
    }

  } while ( u8g2.nextPage() );
}

void Display::cross(int x, int y) {
  u8g2.drawLine(34 + (20 * x),    4 + (20 * y),     49 + (20 * x),     19 + (20 * y));
  u8g2.drawLine(34 + (20 * x),    19 + (20 * y),    49 + (20 * x),     4 + (20 * y));
}

void Display::circle(int x, int y) {
  u8g2.drawCircle(41 + (20 * x), 11 + (20 * y), 7, U8G2_DRAW_ALL);
}

void Display::crossCursor(int x, int y) {
  u8g2.drawLine(38 + (20 * x),    8 + (20 * y),     45 + (20 * x),     15 + (20 * y));
  u8g2.drawLine(38 + (20 * x),    15 + (20 * y),    45 + (20 * x),     8 + (20 * y));
}

void Display::circleCursor(int x, int y) {
  u8g2.drawCircle(41 + (20 * x), 11 + (20 * y), 3, U8G2_DRAW_ALL);
}