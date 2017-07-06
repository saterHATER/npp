#include <vector>
#include "ncurses.h"
#include "init.hpp"
#include "status.hpp"

namespace npp {
  std::vector<initFunction> initFunctions = {
    {BUFFERING, setBuffering, false},
    {KEYPAD, setKeypad, false},
    {NOCURSOR, setCursor, false},
  };

  int setCursor(bool state) {
    curs_set(state);
    return state;
  };

  int setKeypad(bool state) {
    keypad(stdscr, state);
    return state;
  }

  int setBuffering(bool state) {
    if (state)
      cbreak();
    return state;
  }
}
