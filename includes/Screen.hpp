#pragma once

#include "Window.hpp"
#include <vector>

namespace npp {
  class Screen {
    public:
      void refresh();

    private:
      std::vector<Window> windows;
  };
}
