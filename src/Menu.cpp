#include "Menu.hh"

Menu::Menu(SFMLHandler &window)
{
    window.loadAsset("BUTTON_START","assets/Button_Start.png");
    window.loadAsset("BUTTON_SCORE","assets/Button_Score.png");
    window.loadAsset("BUTTON_EXIT","assets/Button_Exit.png");
    window.loadAsset("BACKGROUND", "assets/MissileCommand_Background.jpg");
}
