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
char	UIInterface::Getch()
{
  return getch();
}

/* Screen Utilities */
void	UIInterface::RefreshScreen()
{
  refrsh();
}

void	UIInterface::GetScreenLimits(int &y, int &x)
{
  getmaxyx(stdscr, y, x);
}

void	UIInterface::Noecho()
{
  noecho();

}

void	UIInterface::Echo()
{
  echo();
}

/* Output Utilities */
void	UIInterface::MoveCursor(int y, int x)
{
  move(y, x);
}

void	UIInterface::Write(char c)
{
  addch(c);
}

void	UIInterface::Write(const char *c)
{
  addstr(c);
}

void	UIInterface::Write(const std::string &str)
{
  addstr(str.c_str());
}

void	UIInterface::MoveWrite(int y, int x, char c)
{
  mvaddch(y, x, c);
}

void	UIInterface::MoveWrite(int y, int x, const char *c)
{
  mvaddstr(y, x, c);
}

void	UIInterface::MoveWrite(int y, int x, const std::string &str)
{
  mvaddstr(y, x, str.c_str());
}

