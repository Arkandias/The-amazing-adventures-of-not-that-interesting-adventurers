#ifndef UIINTERFACE_HPP_
# define UIINTERFACE_HPP_

# include <ncurses.h>
# include <iostream>
# include <cstdarg>

# define VARARG_MAX_SIZE 256

class UIInterface {

public:
  UIInterface();
  virtual ~UIInterface();
  UIInterface(const UIInterface &) = delete;
  UIInterface& operator=(const UIInterface&) = delete;

  /* Input utilities */
  char		Getch() const;
  int		Scanw(const char * &format, ...) const;
  int		Scanw(const std::string &format, ...) const;
  int		MvScanw(int y, int x, const char * &format, ...) const;
  int		MvScanw(int y, int x, const std::string &format, ...) const;
  
  /* Screen Utilities */
  void		RefreshScreen() const;
  void		GetScreenLimits(int &y, int &x) const;
  void		Noecho() const;
  void		Echo() const;
  int		InitScreen(const char *file) const;
  int		InitScreen(const std::string &file) const;
  int		ScreenDump(const char *file) const;
  int		ScreenDump(const std::string &file) const;
  int		ScreenRestore(const char *file) const;
  int		ScreenRestore(const std::string &file) const;

  
  /* Window Utilities */
  /*** TO BE IMPLEMENTED ***/
  
  /* Output Utilities */
  void		MoveCursor(int y, int x) const;
  void		Write(char c) const;
  void		Write(const char *c) const;
  void		Write(const std::string &c) const;
  void		MoveWrite(int y, int x, char c) const;
  void		MoveWrite(int y, int x, const char *c) const;
  void		MoveWrite(int y, int x, const std::string &c) const;

};

#endif // UIINTERFACE_HPP_
