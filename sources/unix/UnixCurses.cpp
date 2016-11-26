#include "UIInterface.hpp"
#include <iostream>

UIInterface::UIInterface()
{
  initscr();
  raw();
  keypad(stdscr, TRUE);
}

UIInterface::~UIInterface()
{
  endwin();
}

/* Input Utilities */
char	UIInterface::Getch() const
{
  return getch();
}

/* Screen Utilities */
void	UIInterface::RefreshScreen() const
{
  refresh();
}

void	UIInterface::GetScreenLimits(int &y, int &x) const
{
  getmaxyx(stdscr, y, x);
}

void	UIInterface::Noecho() const
{
  noecho();

}

void	UIInterface::Echo() const
{
  echo();
}

/* Output Utilities */
void	UIInterface::MoveCursor(int y, int x) const
{
  move(y, x);
}

void	UIInterface::Write(char c) const
{
  addch(c);
}

void	UIInterface::Write(const char *c) const
{
  addstr(c);
}

void	UIInterface::Write(const std::string &str) const
{
  addstr(str.c_str());
}

void	UIInterface::MoveWrite(int y, int x, char c) const
{
  mvaddch(y, x, c);
}

void	UIInterface::MoveWrite(int y, int x, const char *c) const
{
  mvaddstr(y, x, c);
}

void	UIInterface::MoveWrite(int y, int x, const std::string &str) const
{
  mvaddstr(y, x, str.c_str());
}

