#pragma once

namespace npp {
  enum class initFlags {
    none = 0,
    buffering = 1,
    keypad = 2,
    nocursor = 4
  };

  unsigned int operator&(const initFlags f1, const initFlags f2) {
    return static_cast<unsigned int>(f1) & static_cast<unsigned int>(f2);
  }

  unsigned int operator|(const initFlags f1, const initFlags f2) {
    return static_cast<unsigned int>(f1) | static_cast<unsigned int>(f2);
  }

  int init(npp::initFlags flags = npp::initFlags::none);
};
