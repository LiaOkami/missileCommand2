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
    while (_window.getWindow().isOpen())
    {
      _pollEvents();
      _update();
      _draw();
    }
}

void Menu::_draw()
{
    _window.clearWindow();
    _window.draw("BACKGROUND", Position(0, 0));
}

void	MissileCommand::_pollEvents()
{
    sf::Event	event;
    while (_window.getWindow().pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _window.close();
        if (event.type == sf::Event::KeyPressed)
            _window.close();

        if(event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left)
        {
            Position cursor=_window.getMouse();
            //Tester le bouton selectionne et declencher action
        }
    }
}
