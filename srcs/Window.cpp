#include <ncurses.h>
#include <iostream>
#include "Window.hpp"

Ncurses::Window::Window(const int h, const int w,
    const int y, const int x) {
  window = newwin(h, w, y, x);
  if (window == nullptr)
    throw std::runtime_error("The window could not be created.");
}

void Ncurses::Window::box(const chtype v, const chtype h) {
  if (window == nullptr)
    throw std::runtime_error("The window does not exist.");
  ::box(window, v, h);
}

void Ncurses::Window::refresh(void) {
  wrefresh(window);
}
