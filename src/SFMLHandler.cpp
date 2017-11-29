/** \file SFMLHandler.cpp
 *  \brief Classe SFMLHandler
 */

#include "SFMLHandler.hh"

#include <map>
#include <iostream>
using namespace std;

/* Constructeur */
SFMLHandler::SFMLHandler(int width, int height, string title) :
    _window(sf::VideoMode(width, height), title), _mapAssets(), _map()
{
    cout << "Création de la fenêtre" << endl;
    _window.setMouseCursorVisible(false);
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

void SFMLHandler::loadAsset(const std::string & key, const std::string & filename, float scale, int rotation)
{
    sf::Texture textureTemp;
    if(!textureTemp.loadFromFile(filename))
    {
        cout << "Erreur chargement texture" << endl;
    }
    else
    {
        cout << filename << " chargé, nb de sprite :" << _mapAssets.size() << endl;
    }

    sf::Sprite spriteTemp;
    spriteTemp.setTexture(textureTemp);
    spriteTemp.scale(scale,scale);
    spriteTemp.setRotation(rotation);

    _map[key] = textureTemp;
    _mapAssets[key] = spriteTemp;

}

void SFMLHandler::loadAsset(const std::string & key, const std::string & filename, float scale, int rotation, int RectLeft, int RectTop, int RectWidth, int RectHeight)
{
    sf::Texture textureTemp;
    if(!textureTemp.loadFromFile(filename, sf::IntRect(RectLeft, RectTop, RectWidth, RectHeight))) //[1] Chemin de l'image, [2] Cadre de l'image
    {
	cout << "Erreur chargement texture" << endl;
    }
    else
    {
        cout << filename << " chargé, nb de sprite :" << _mapAssets.size() << endl;
    }

    sf::Sprite spriteTemp;
    spriteTemp.setTexture(textureTemp);
    spriteTemp.scale(scale,scale);
    spriteTemp.setRotation(rotation);

    _map[key] = textureTemp;
    _mapAssets[key] = spriteTemp;
    cout << &(_map[key]) << "\t" << &(_mapAssets[key]) << endl;
}

void SFMLHandler::draw(const std::string & key, Position pos)
{
    cout << &(_map[key]) << "\t" << &(_mapAssets[key]) << endl;
    _mapAssets[key].setPosition(pos.x, pos.y);
    _window.draw(_mapAssets[key]);
}

void SFMLHandler::display()
{
    _window.display();
}

void SFMLHandler::close()
{
    _window.close();
}

sf::RenderWindow& SFMLHandler::getWindow()
{
    return _window;
}

void SFMLHandler::setPosition(int x, int y)
{
    _window.setPosition(sf::Vector2i(x,y));
}
