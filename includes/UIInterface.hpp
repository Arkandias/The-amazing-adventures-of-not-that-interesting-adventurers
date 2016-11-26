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

  /* Input utilities */
  char		Getch() const;
  
  /* Screen Utilities */
  void		RefreshScreen() const;
  void		GetScreenLimits(int &y, int &x) const;
  void		Noecho() const;
  void		Echo() const;

  /* Output Utilities */
  void		MoveCursor(int y, int x) const;
  void		Write(char c) const;
  void		Write(const char *c) const;
  void		Write(const std::string &c) const;
  void		MoveWrite(int y, int x, char c) const;
  void		MoveWrite(int y, int x, const char *c) const;
  void		MoveWrite(int y, int x, const std::string &c) const;

};

#endif  /* UIINTERFACE_HPP_ */
