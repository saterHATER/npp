#pragma once

#include <ncurses.h>

namespace npp {
  class Window {
    public:
      Window(const int h, const int w, const int y, const int x);
      void box(const chtype v, const chtype h);
      void refresh();
      void usual();

    private:
      WINDOW *window;
  };
};
