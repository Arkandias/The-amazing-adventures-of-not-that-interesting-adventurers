#include "UIInterface.hpp"
#include <iostream>
#include <cstring>

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

int	UIInterface::Scanw(const std::string &format, ...) const
{
  char buff[VARARG_MAX_SIZE];
  va_list args;
  va_start(args, format);
  vsprintf(buff, format.c_str(), args);
  va_end(args);
  return scanw(format.c_str(), args);
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

/* Output Utilities */
void	UIInterface::Move(int y, int x) const
{
  move(y, x);
}

void  UIInterface::Write(char c) const
{
  addch(c);
}

void  UIInterface::Write(const std::string &str) const
{
  addstr(str.c_str());
}

void  UIInterface::WWrite(unsigned int win_id, char c) const
{
  if (win_id > this->window_list_.size() - 1)
    return ;
  waddch((WINDOW *)(this->window_list_[win_id]), c);
}

void  UIInterface::WWrite(unsigned int win_id, const std::string &str) const
{
  if (win_id > this->window_list_.size() - 1)
    return ;
  waddstr((WINDOW *)(this->window_list_[win_id]), str.c_str());
}

void  UIInterface::MvWrite(int y, int x, char c) const
{
  mvaddch(y, x, c);
}

void  UIInterface::MvWrite(int y, int x, const std::string &str) const
{
  mvaddstr(y, x, str.c_str());
}

void  UIInterface::MvWWrite(unsigned int win_id, int y, int x, char c) const
{
  if (win_id > this->window_list_.size() - 1)
    return ;
  mvwaddch((WINDOW *)(this->window_list_[win_id]), y, x, c);
}

void  UIInterface::MvWWrite(unsigned int win_id, int y, int x, const std::string &str) const
{
  if (win_id > this->window_list_.size() - 1)
    return ;
  mvwaddstr((WINDOW *)(this->window_list_[win_id]), y, x, str.c_str());
}


/* Screen Utilities */
void	UIInterface::Refresh() const
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


/* Window Utilities */
int	UIInterface::CreateWindow(int height, int width, int starty, int startx)
{
  WINDOW*	win;

  // Creating new window
  if ((win = newwin(height, width, starty, startx)) == NULL)
    return -1;
  // Adding window to list
  this->window_list_.push_back(win);
  // Returning win_id
  return this->window_list_.size() - 1;
}

int	UIInterface::CreateWindow(int height, int width, int starty, int startx, const std::string &border)
{
  WINDOW*	win;

  // Creating new window
  if ((win = newwin(height, width, starty, startx)) == NULL)
    return -1;
  // Applying border if format is correct
  this->WBorder(win, border.c_str());
  // Adding window to list
  this->window_list_.push_back(win);
  // Returning win_id
  return this->window_list_.size() - 1;
}

void	UIInterface::WBorder(unsigned int win_id, const char *border)
{
  if (win_id > this->window_list_.size() - 1)
    return ;
  if (border != NULL)
    {
      // Sides border only
      if (strlen(border) == 2)
	box((WINDOW *)(this->window_list_[win_id]), border[0], border[1]);
      // Complete border
      if (strlen(border) == 8)
	wborder((WINDOW *)(this->window_list_[win_id]), border[0], border[1], border[2], border[3], border[4], border[5], border[6], border[7]);
    }
}

void	UIInterface::WBorder(void *win, const char *border)
{
  if (win == NULL)
    return ;
  if (border != NULL)
    {
      // Sides border only
      if (strlen(border) == 2)
	box((WINDOW *)win, border[0], border[1]);
      // Complete border
      if (strlen(border) == 8)
	wborder((WINDOW *)win, border[0], border[1], border[2], border[3], border[4], border[5], border[6], border[7]);
    }
}

void  UIInterface::Delwin(unsigned int win_id)
{
  if (win_id > this->window_list_.size() - 1)
    return ;
  this->WBorder(window_list_[win_id], "        ");
  this->WRefresh(window_list_[win_id]);
  delwin((WINDOW *)(this->window_list_[win_id]));
}

void	UIInterface::WRefresh(unsigned int win_id)
{
  if (win_id > this->window_list_.size() - 1)
    return ;
  wrefresh((WINDOW *)(this->window_list_[win_id]));
}

void  UIInterface::WRefresh(void *win)
{
  if (win == NULL)
    return ;
  wrefresh((WINDOW *)(win));
}


/* Screendumping Utilities */
int	UIInterface::InitScreen(const std::string &file) const
{
  return scr_init(file.c_str());
}

int	UIInterface::ScreenDump(const std::string &file) const
{
  return scr_dump(file.c_str());
}

int	UIInterface::ScreenRestore(const std::string &file) const
{
  return scr_restore(file.c_str());
}
