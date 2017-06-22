#pragma once

namespace npp {
  typedef enum {
    NONE = 0,
    BUFFERING = 1,
    KEYPAD = 2,
    NOCURSOR = 4
  } initFlags;

  typedef struct {
    initFlags flag;
    int (*f)(bool);
    bool defaultValue;
  } initFunction;

  int init(unsigned int flags);
  int setBuffering(bool active);
  int setKeypad(bool active);
  int setCursor(bool active);

  extern initFunction initFunctions[];
};
