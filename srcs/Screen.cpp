#include <stdexcept>
#include <vector>
#include "Screen.hpp"
#include "init.hpp"
#include "status.hpp"
#include "ncurses.h"

npp::Screen::Screen(unsigned int flags) {
  if (initscr() == nullptr)
    throw std::runtime_error("The screen could not be initialized.");

  for (unsigned int i = 0; i < npp::initFunctions.size(); ++i) {
    if (initFunctions[i].flag & flags)
      initFunctions[i].f(initFunctions[i].defaultValue);
    else
      initFunctions[i].f(!initFunctions[i].defaultValue);
  }
}

npp::Screen::~Screen() {
  endwin();
}

void npp::Screen::refresh(void) const {
  ::refresh();
}
