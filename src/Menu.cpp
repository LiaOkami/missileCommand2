#include "Menu.hh"

Menu::Menu(SFMLHandler &window)
{
    window.loadAsset("BUTTON_START","assets/Button_Start.png");
    window.loadAsset("BUTTON_SCORE","assets/Button_Score.png");
    window.loadAsset("BUTTON_EXIT","assets/Button_Exit.png");
    window.loadAsset("BACKGROUND", "assets/MissileCommand_Background.jpg");
}

void Menu::launch()
{

}

void Menu::draw()
{
    _window.clearWindow();
    _window.draw("BACKGROUND", Position(0, 0));
}
