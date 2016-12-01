#include "UIInterface.hpp"
#include <curses.h>
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
template<typename... Args>
int	UIInterface::Scanw(const std::string &format, Args&&... args) const
{
  return scanw(format.c_str(), args...);
}

template<typename... Args>
int	UIInterface::MvScanw(int y, int x, const std::string &format, Args&&... args) const
{
  return mvscanw(y, x, format.c_str(), args...);
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

template<typename... Args>
int    UIInterface::Printw(const std::string &format, Args&&... args) const
{
  return printw(format, args...)
}

template<typename... Args>
int    UIInterface::MvPrintw(int y, int x, const std::string &format, Args&&... args) const
{
  return mvprintw(y, x, format, args...)
}

template<typename... Args>
int    UIInterface::WPrintw(unsigned int win_id, const std::string &format, Args&&... args) const
{
  if (win_id > this->window_list_.size())
    return -1;
  return wprintw((WINDOW *)(this->window_list_[win_id]), format, args...)
}

template<typename... Args>
int    UIInterface::WMvPrintw(unsigned int win_id, int y, int x, const std::string &format, Args&&... args) const
{
  if (win_id > this->window_list_.size())
    return -1;
  return mvwprintw((WINDOW *)(this->window_list_[win_id]), y, x, format, args...)
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

void  UIInterface::Chgat(int length, long unsigned int attrs, short color, const void *opts) const
{
  chgat(length, attrs, color, opts);
}

void  UIInterface::MvChgat(int y, int x, int length, long unsigned int attrs, short color, const void *opts) const
{
  mvchgat(y, x, length, attrs, color, opts);
}


/* Color Utilities */
bool  UIInterface::HasColors() const
{
  return has_colors();
}

int   UIInterface::InitPair(short pair, short front, short back) const
{
  return init_pair(pair, front, back);
}

int   UIInterface::StartColor() const
{
  return start_color();
}


/* Mouse Utilities */
long unsigned int UIInterface::Mousemask(long unsigned int newmask, long unsigned int *oldmask) const
{
  return mousemask(newmask, oldmask);
}

int   UIInterface::Getmouse(void *event)
{
  return nc_getmouse((MEVENT *)event);
}


/* Keyboard Utilities */
int   UIInterface::Keypad(unsigned int win_id, bool enabled)
{
  if (win_id > this->window_list_.size())
    return -1;
  return keypad((WINDOW *)(this->window_list_[win_id]), enabled);
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

int   UIInterface::Attron(int attrs) const
{
  return attron(attrs);
}

int   UIInterface::Attroff(int attrs) const
{
  return attroff(attrs);
}

int   UIInterface::Attrset(int attrs) const
{
  return attrset(attrs);
}

int   UIInterface::AttrGet(unsigned long int *attrs, short *pair) const
{
  return attr_get(attrs, pair, NULL);
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

int   UIInterface::WAttron(unsigned int win_id, int attrs) const
{
  if (win_id > this->window_list_.size())
    return -1;
  return wattron((WINDOW *)(this->window_list_[win_id]), attrs);
}

int   UIInterface::WAttroff(unsigned int win_id, int attrs) const
{
  if (win_id > this->window_list_.size())
    return -1;
  return wattroff((WINDOW *)(this->window_list_[win_id]), attrs);
}

int   UIInterface::WAttrset(unsigned int win_id, int attrs) const
{
  if (win_id > this->window_list_.size())
    return -1;
  return wattrset((WINDOW *)(this->window_list_[win_id]), attrs);
}

int   UIInterface::WAttrGet(unsigned int win_id, unsigned long int *attrs, short *pair) const
{
  if (win_id > this->window_list_.size())
    return -1;
  return wattr_get((WINDOW *)(this->window_list_[win_id]), attrs, pair, NULL);
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
