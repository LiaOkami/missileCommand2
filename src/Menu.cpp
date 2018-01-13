#include "Menu.hh"

Menu::Menu(SFMLHandler *window, MissileCommand *game)
{
  _window = window;
  _game = game;
    _window->loadAsset("BUTTON_START","assets/Button_Start.png");
    _window->loadAsset("BUTTON_EXIT","assets/Button_Exit.png");
    _window->loadAsset("BACKGROUND", "assets/MissileCommand_Background.png");
}

void Menu::launch()
{
    while (_window->getWindow().isOpen())
    {
      _pollEvents();
      _draw();
    }
}

void Menu::_draw()
{
    _window->clearWindow();
    _window->draw("BACKGROUND", Position(0, 0));
    _window->draw("BUTTON_START", Position(WINDOW_WIDTH/2 -150, WINDOW_HEIGHT/2 -300));
    _window->draw("BUTTON_EXIT", Position(WINDOW_WIDTH/2 -150, WINDOW_HEIGHT/2 +192));
}

void	Menu::_pollEvents()
{
    sf::Event	event;
    while (_window->getWindow().pollEvent(event))
    {
	if (event.type == sf::Event::Closed)
	    _window->close();
	if (event.type == sf::Event::KeyPressed)
	    _window->close();

	if(event.type == sf::Event::MouseButtonPressed &&
	event.mouseButton.button == sf::Mouse::Left)
	{
	    if(_window->getMouse().x > WINDOW_WIDTH/2 -150 &&
	    _window->getMouse().x < WINDOW_WIDTH/2 +150 &&
	    _window->getMouse().y > WINDOW_HEIGHT/2 -300 &&
	    _window->getMouse().y < WINDOW_HEIGHT/2 -192)
	    {
		_game->launch();
	    }
	    if(_window->getMouse().x > WINDOW_WIDTH/2 -150 &&
	    _window->getMouse().x < WINDOW_WIDTH/2 +150 &&
	    _window->getMouse().y > WINDOW_HEIGHT/2 +192 &&
	    _window->getMouse().y < WINDOW_HEIGHT/2 -300)
	    {
		_window->close();
	    }
	}
    }
}
