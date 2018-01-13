#ifndef MENU_H
#define MENU_H


class Menu
{
    public:
        Menu(SFMLHandler &window);
        void	launch();
    private:
        void	_draw();
};

#endif // MENU_H
