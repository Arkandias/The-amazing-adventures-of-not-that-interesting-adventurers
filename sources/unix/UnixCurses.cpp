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

int	UIInterface::Scanw(const char * &format, ...) const
{
  char buff[VARARG_MAX_SIZE];
  va_list args;
  va_start(args, format);
  vsprintf(buff, format, args);
  va_end(args);
  return scanw(format, args);
}

int	UIInterface::Scanw(const std::string &format, ...) const
{
  char buff[VARARG_MAX_SIZE];
  va_list args;
  va_start(args, format);
  vsprintf(buff, format.c_str(), args);
  va_end(args);
  return scanw(format.c_str(), args);
}

int	UIInterface::MvScanw(int y, int x, const char * &format, ...) const
{
  char buff[VARARG_MAX_SIZE];
  va_list args;
  va_start(args, format);
  vsprintf(buff, format, args);
  va_end(args);
  return mvscanw(y, x, format, args);
}

int	UIInterface::MvScanw(int y, int x, const std::string &format, ...) const
{
  char buff[VARARG_MAX_SIZE];
  va_list args;
  va_start(args, format);
  vsprintf(buff, format.c_str(), args);
  va_end(args);
  return mvscanw(y, x, format.c_str(), args);
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

int	UIInterface::InitScreen(const char *file) const
{
  return scr_init(file);
}

int	UIInterface::InitScreen(const std::string &file) const
{
  return scr_init(file.c_str());
}

int	UIInterface::ScreenDump(const char *file) const
{
  return scr_dump(file);
}

int	UIInterface::ScreenDump(const std::string &file) const
{
  return scr_dump(file.c_str());
}

int	UIInterface::ScreenRestore(const char *file) const
{
  return scr_restore(file);
}

int	UIInterface::ScreenRestore(const std::string &file) const
{
  return scr_restore(file.c_str());
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

