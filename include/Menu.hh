#ifndef MENU_H
#define MENU_H
#include "MissileCommand.hh"
#include "SFMLHandler.hh"

class Menu
{
public:
  Menu(SFMLHandler *window, MissileCommand *game);
  void	launch();

private:
  MissileCommand	*_game;
  SFMLHandler		*_window;

	void	_draw();
	void	_pollEvents();
};

#endif // MENU_H
