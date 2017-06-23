#include <ncurses.h>
#include <string>
#include <stdexcept>
#include "Window.hpp"

npp::Window::Window(const int h, const int w,
    const int y, const int x) {
  window = newwin(h, w, y, x);
  if (window == nullptr)
    throw std::runtime_error("The window could not be created.");
}

npp::Window::~Window() {
  delwin(window);
}

void npp::Window::box(const chtype v, const chtype h) const {
  ::box(window, v, h);
}

void npp::Window::refresh(void) const {
  wrefresh(window);
}

int npp::Window::getchar(void) const {
  int c = wgetch(window);
  return c;
}

void npp::Window::write(const std::string str, ...) const {
  va_list args;
  va_start(args, str);
  vw_printw(window, str.c_str(), args);
  va_end(args);
}

WINDOW *npp::Window::c_ptr() const {
  return window;
}
