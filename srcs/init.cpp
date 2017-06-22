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

int npp::init(unsigned int flags) {
  if (initscr() == nullptr)
    return FAILURE;

  if (flags == NONE)
    return SUCCESS;

  constexpr int nb_flags = sizeof(initFunctions) /
    sizeof(initFunction);
  for (int i = 0; i < nb_flags; ++i) {
    if (initFunctions[i].flag & flags)
      initFunctions[i].f(initFunctions[i].defaultValue);
    else
      initFunctions[i].f(!initFunctions[i].defaultValue);
  }

  return SUCCESS;
}
