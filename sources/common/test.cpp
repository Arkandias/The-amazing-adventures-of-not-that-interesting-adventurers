#include "UIInterface.hpp"
#include <iostream>

int main()
{
	UIInterface UI;

	/* Input utilities */
	UI.Write("Type a character : ");
	char getchChar = UI.Getch();
	UI.Write("");
	UI.Scanw(const std::string &format, Args&&...);
	UI.MvScanw(int y, int x, std::string &format, Args&&...);

	/* Output Utilities */
	UI.Move(int y, int x);
	UI.Write(char c);
	UI.Write(const std::string &c);
	UI.WWrite(unsigned int win_id, char c);
	UI.WWrite(unsigned int win_id, std::string &c);
	UI.MvWrite(int y, int x, char c);
	UI.MvWrite(int y, int x, std::string &c);
	UI.MvWWrite(unsigned int win_id, int y, int x, char c);
	UI.MvWWrite(unsigned int win_id, int y, int x, std::string &c);
	UI.Chgat(int length, long unsigned int attrs, short color, void *opts);
	UI.MvChgat(int y, int x, int length, long unsigned int attrs, short color, void *opts);

	/* Color Utilities */
	UI.HasColors();
	UI.InitPair(short pair, short front, short back);
	UI.StartColor();

	/* Mouse Utilities */
	UI.Mousemask(long unsigned int newmask, long unsigned int *oldmask);
	UI.Getmouse(void *event);

	/* Keyboard Utilities */
	int    Keypad(unsigned int win_id, bool enabled);

	/* Screen Utilities */
	UI.Refresh();
	UI.GetScreenLimits(int &y, int &x);
	UI.Noecho();
	UI.Echo();
	UI.Attron(int attrs);
	UI.Attroff(int attrs);
	UI.Attrset(int attrs);
	UI.AttrGet(unsigned long int *attrs, short *pair);

	/* Window Utilities */
	UI.CreateWindow(int height, int width, int starty, int startx);
	UI.CreateWindow(int height, int width, int starty, int startx, std::string &border);
	UI.Delwin(unsigned int win_id);
	UI.WBorder(unsigned int win_id, char *border);
	UI.WRefresh(unsigned int win_id);
	UI.WAttron(unsigned int win_id, int attrs);
	UI.WAttroff(unsigned int win_id, int attrs);
	UI.WAttrset(unsigned int win_id, int attrs);
	UI.WAttrGet(unsigned int win_id, unsigned long int *attrs, short *pair);

	/* Screendumping Utilities */
	UI.InitScreen(const std::string &file);
	UI.ScreenDump(const std::string &file);
	UI.ScreenRestore(const std::string &file);

	return 0;
}