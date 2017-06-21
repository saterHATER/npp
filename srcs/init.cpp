#include <ncurses.h>
#include "init.hpp"
#include "status.hpp"

int init(const unsigned int flags = 0) {
  if (initscr() == nullptr)
    return FAILURE;

  return SUCCESS;
}
