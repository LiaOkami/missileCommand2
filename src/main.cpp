#include <SFML/Graphics.hpp>
#include "MissileCommand.hh"

int     main()
{
  MissileCommand        game;
  sf::RenderWindow      window(sf::VideoMode(200, 200), "Missile Command");
  sf::Event             event;

  while (window.isOpen())
  {
    window.clear();
    window.display();
    while (window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
          window.close();
    }
  }
  game.launch();
  return (0);
}
