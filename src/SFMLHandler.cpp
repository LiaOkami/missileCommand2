/** \file SFMLHandler.cpp
 *  \brief Classe SFMLHandler
 */

#include "SFMLHandler.hh"

#include <map>
#include <iostream>
using namespace std;

/* Constructeur */
SFMLHandler::SFMLHandler(int width, int height, string title) :
    _window(sf::VideoMode(width, height), title), _mapAssets(), _mapTextures()
{
    cout << "Création de la fenêtre" << endl;
    // rends invisible le curseur système
    _window.setMouseCursorVisible(false);
    //centre la fenêtre sur le bureau
    _window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width /2 -(width/2), sf::VideoMode::getDesktopMode().height /2 -(height/2)));
}

/* Destructeur */
SFMLHandler::~SFMLHandler()
{

}


/* Méthodes */

void SFMLHandler::loadAsset(const std::string & key, const std::string & filename, float scale, int rotation)
{
    sf::Texture textureTemp;
    if(!textureTemp.loadFromFile(filename))
    {
        cout << "Erreur chargement texture" << endl;
    }
    else
    {
        cout << filename << " chargé" << endl;
    }

    _mapTextures[key] = textureTemp;
    sf::Sprite spriteTemp;
    spriteTemp.setTexture(_mapTextures[key]);
    spriteTemp.scale(scale,scale);
    spriteTemp.setRotation(rotation);

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
        cout << filename << " chargé" << endl;
    }

    _mapTextures[key] = textureTemp;
    sf::Sprite spriteTemp;
    spriteTemp.setTexture(_mapTextures[key]);
    spriteTemp.scale(scale,scale);
    spriteTemp.setRotation(rotation);

    _mapAssets[key] = spriteTemp;
}

void SFMLHandler::clearWindow()
{
    _window.clear();
}

void SFMLHandler::draw(const std::string & key, Position pos)
{
    _mapAssets[key].setPosition(pos.x, pos.y);
    _window.draw(_mapAssets[key]);
}

void SFMLHandler::draw(const std::string & key, float x, float y)
{
    _mapAssets[key].setPosition(x, y);
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


/* Accesseurs */

sf::RenderWindow& SFMLHandler::getWindow()
{
    return _window;
}

void SFMLHandler::setPosition(int x, int y)
{
    _window.setPosition(sf::Vector2i(x,y));
}

sf::Vector2u SFMLHandler::getSize()const
{
    return _window.getSize();
}
