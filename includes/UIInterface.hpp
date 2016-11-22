#ifndef UIINTERFACE_HPP_
#define UIINTERFACE_HPP_

#include <ncurses.h>
#include <iostream>

class UIInterface {

public:
  UIInterface();
  virtual ~UIInterface();
  UIInterface(const UIInterface &) = delete;
  UIInterface& operator=(const UIInterface&) = delete;

  void		GetScreenLimits(int &y, int &x);
  void		MoveCursor(int y, int x);
  void		Write(char c);
  void		Write(const char *c);
  void		Write(const std::string &c);
  void		MoveWrite(int y, int x, char c);
  void		MoveWrite(int y, int x, const char *c);
  void		MoveWrite(int y, int x, const std::string &c);

};

#endif  /* UIINTERFACE_HPP_ */
