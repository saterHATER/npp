#include <ncurses.h>
#include <string>
#include <stdexcept>
#include "Window.hpp"

npp::Window::Window(const int h, const int w,
    const int y, const int x) {
  _container = newwin(h, w, y, x);
  _window = newwin(h - 2, w - 2, y + 1, x + 1);
  if (_window == nullptr || _container == nullptr)
    throw std::runtime_error("The _window could not be created.");
}

npp::Window::~Window() {
  delwin(_window);
  delwin(_container);
}

void npp::Window::box(const chtype v, const chtype h) const {
  ::box(_container, v, h);
  wrefresh(_container);
}

void npp::Window::refresh(void) const {
  wrefresh(_window);
}

int npp::Window::getchar(void) const {
  const int c = wgetch(_window);
  return c;
}

void npp::Window::write(const int y, const int x,
    const std::string str, ...) const {
  wmove(_window, y, x);
  va_list args;
  va_start(args, str);
  vw_printw(_window, str.c_str(), args);
  va_end(args);
}

WINDOW *npp::Window::c_ptr() const {
  return _window;
}
