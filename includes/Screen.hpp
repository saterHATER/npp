#pragma once

#include "Window.hpp"
#include <vector>

namespace Ncurses {
  class Screen {
    public:
      void refresh();

    private:
      std::vector<Window> windows;
  };
}
