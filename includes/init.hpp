#pragma once

#include <functional>

namespace npp {
  typedef enum {
    NONE = 0,
    BUFFERING = 1,
    KEYPAD = 2,
    NOCURSOR = 4
  } initFlags;

  typedef struct {
    initFlags flag;
    std::function<int(bool)> f;
    bool defaultValue;
  } initFunction;

  int setBuffering(bool active);
  int setKeypad(bool active);
  int setCursor(bool active);

  extern std::vector<initFunction> initFunctions;
};
