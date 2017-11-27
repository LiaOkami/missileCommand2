/** \file SFMLHandler.cpp
 *  \brief Classe SFMLHandler
 */

#include "SFMLHandler.hh"

#include <map>
#include <iostream>
using namespace std;

/* Constructeur */
SFMLHandler::SFMLHandler(int width, int height, string title) :
    _window(sf::VideoMode(width, height), title), _mapAssets()
{
    cout << "Création de la fenêtre" << endl;
}

/* Destructeur */
SFMLHandler::~SFMLHandler()
{

}

/* Méthodes */
void SFMLHandler::clearWindow()
{
    _window.clear();
}

void SFMLHandler::loadAsset(const std::string & key, const std::string & filename) // ! \\ Cadre à modifier
{
    sf::Texture textureTemp;
    if(!textureTemp.loadFromFile(filename, sf::IntRect(0,50,253,78))) //[1] Chemin de l'image, [2] Cadre de l'image
    {
	cout << "Erreur chargement texture" << endl;
    }

    sf::Sprite spriteTemp;
    spriteTemp.setTexture(textureTemp);

    _mapAssets[key] = spriteTemp;

}

void SFMLHandler::draw(const std::string & key, Position pos)
{
    sf::Sprite spriteDraw;
    spriteDraw = _mapAssets[key];
    spriteDraw.setPosition(pos.x, pos.y);
    _window.draw(spriteDraw);
}

void SFMLHandler::display()
{
    _window.display();
}

sf::RenderWindow& SFMLHandler::getWindow()
{
    return _window;
}
