#include <ncurses.h>
#include <iostream>
#include "Window.hpp"

npp::Window::Window(const int h, const int w,
    const int y, const int x) {
  window = newwin(h, w, y, x);
  if (window == nullptr)
    throw std::runtime_error("The window could not be created.");
}

void npp::Window::box(const chtype v, const chtype h) {
  if (window == nullptr)
    throw std::runtime_error("The window does not exist.");
  ::box(window, v, h);
}

void npp::Window::refresh(void) {
  if (window == nullptr)
    throw std::runtime_error("The window does not exist.");
  wrefresh(window);
}

void npp::Window::usual(void) {
  if (window == nullptr)
    throw std::runtime_error("The window does not exist.");
  this->box(0, 0);
  this->refresh();
}
