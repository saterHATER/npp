#include "ncurses.h"
#include "init.hpp"
#include "status.hpp"

namespace npp {
  initFunction initFunctions[] = {
    {BUFFERING, setBuffering, false},
    {KEYPAD, setKeypad, false},
    {NOCURSOR, setCursor, true}
  };
}

int npp::setCursor(bool state) {
  curs_set(state);
  return state;
};

int npp::setKeypad(bool state) {
  keypad(stdscr, state);
  return state;
}

int npp::setBuffering(bool state) {
  if (state)
    cbreak();
  return state;
}
