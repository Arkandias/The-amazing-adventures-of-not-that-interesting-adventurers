#ifndef UIINTERFACE_HPP_
# define UIINTERFACE_HPP_

# include <ncurses.h>
# include <iostream>
# include <cstdarg>
# include <vector>

# define VARARG_MAX_SIZE 256

class UIInterface {

public:
  UIInterface();
  virtual ~UIInterface();
  UIInterface(const UIInterface &) = delete;
  UIInterface& operator=(const UIInterface&) = delete;


private:
  std::vector<void *>	window_list_;
  
private:
  void    WBorder(void *win, const char *border);
  void    WRefresh(void *win);
  
public:

  /* Input utilities */
  char	 Getch() const;
  int		 Scanw(const std::string &format, ...) const;
  int		 MvScanw(int y, int x, const std::string &format, ...) const;
  
  /* Output Utilities */
  void	 Move(int y, int x) const;
  void	 Write(char c) const;
  void	 Write(const std::string &c) const;
  void   WWrite(unsigned int win_id, char c) const;
  void   WWrite(unsigned int win_id, const std::string &c) const;
  void   MvWrite(int y, int x, char c) const;
  void   MvWrite(int y, int x, const std::string &c) const;
  void   MvWWrite(unsigned int win_id, int y, int x, char c) const;
  void   MvWWrite(unsigned int win_id, int y, int x, const std::string &c) const;

  /* Screen Utilities */
  void	 Refresh() const;
  void	 GetScreenLimits(int &y, int &x) const;
  void	 Noecho() const;
  void	 Echo() const;

  /* Window Utilities */
  int		 CreateWindow(int height, int width, int starty, int startx);
  int		 CreateWindow(int height, int width, int starty, int startx, const std::string &border);
  void   Delwin(unsigned int win_id);
  void	 WBorder(unsigned int win_id, const char *border);
  void	 WRefresh(unsigned int win_id);
  
  /* Screendumping Utilities */
  int		 InitScreen(const std::string &file) const;
  int		 ScreenDump(const std::string &file) const;
  int		 ScreenRestore(const std::string &file) const;
};

#endif // UIINTERFACE_HPP_
