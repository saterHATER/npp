#pragma once

#include <string>
#include "ncurses.h"

namespace npp {
  class Window {
    public:
      Window(const int h, const int w, const int y, const int x);
      ~Window();

    public:
      void box(const chtype v, const chtype h) const;
      void refresh(void) const;
      int getchar(void) const;
      void write(const int y, const int x, const std::string str, ...) const;

    public:
      WINDOW *c_ptr() const;

    private:
      WINDOW *_window;
      WINDOW *_container;
  };
};
