#include "Screen.hpp"
#include "ncurses.h"

void npp::Screen::refresh(void) {
  ::refresh();
}
