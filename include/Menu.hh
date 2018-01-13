#ifndef MENU_H
#define MENU_H
#include "MissileCommand.hh"
#include "SFMLHandler.hh"


class Menu
{
    public:
        Menu(SFMLHandler &_window, MissileCommand &_game);
        void	launch();
    private:
        void	_draw();
        void	_pollEvents();
};

#endif // MENU_H
