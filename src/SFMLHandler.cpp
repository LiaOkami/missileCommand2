/** \file SFMLHandler.cpp
 *  \brief Classe SFMLHandler
 */

#include "SFMLHandler.hh"
#include <math.h>

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

void SFMLHandler::loadAsset(const std::string & key, const std::string & filename, float scale, int rotation, int originX, int originY)
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
    spriteTemp.setOrigin(originX, originY);
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

bool SFMLHandler::cursorHover(const string & key, Position pos)
{
    _mapAssets[key].setPosition(pos.x, pos.y);
    sf::Vector2f mousePosition(sf::Mouse::getPosition(_window));
    return _mapAssets[key].getGlobalBounds().contains(mousePosition);
}

bool SFMLHandler::objectIntersects(const string & key1, Position pos1, const string & key2, Position pos2)
{
    _mapAssets[key1].setPosition(pos1.x, pos1.y);
    _mapAssets[key2].setPosition(pos2.x, pos2.y);
    return _mapAssets[key1].getGlobalBounds().intersects(_mapAssets[key2].getGlobalBounds());
}

bool SFMLHandler::explosionCollides(float radius, Position explosionPos, const string & key, Position assetPos)
{
    //explosion
    sf::CircleShape explosion(radius,0);
    sf::Vector2f exPos(explosionPos.x,explosionPos.y);
    explosion.setPosition(exPos);
    //asset
    _mapAssets[key].setPosition(assetPos.x, assetPos.y);
    return _mapAssets[key].getGlobalBounds().intersects(explosion.getGlobalBounds());
}

bool SFMLHandler::explosionCollides(float radius1, Position pos1, float radius2, Position pos2)
{
    float distance = sqrt(pow(pos2.x-pos1.x,2)+pow(pos2.y-pos1.y,2));
    bool collision = distance >= (radius1+radius2);
    return collision;
}


/* AFFICHAGE */

void SFMLHandler::clearWindow()
{
    _window.clear();
}

void SFMLHandler::draw(const std::string & key, Position pos)
{
    _mapAssets[key].setPosition(pos.x, pos.y);
    _window.draw(_mapAssets[key]);
}

void SFMLHandler::draw(const std::string & key, Position pos, double rot)
{
    _mapAssets[key].setPosition(pos.x, pos.y);
    _mapAssets[key].setRotation(180 * rot / M_PI - 90);
    _window.draw(_mapAssets[key]);
}

void SFMLHandler::drawExplosion(float radius, Position pos)
{
    sf::CircleShape explosion(radius,0);
    sf::Vector2f exPos(pos.x,pos.y);
    explosion.setPosition(exPos);
    //Couleur
    sf::Color explosionColor(240,224,83,1);
    explosion.setFillColor(explosionColor);
    _window.draw(explosion);
}

void SFMLHandler::display()
{
    _window.display();
}

void SFMLHandler::close()
{
    _window.close();
}


/* ACCESSEURS */

sf::RenderWindow& SFMLHandler::getWindow()
{
    return _window;
}

void SFMLHandler::setPosition(const PositionI &pos)
{
    _window.setPosition(sf::Vector2i(pos.x, pos.y));
}

PositionI	SFMLHandler::getSize() const
{
  sf::Vector2u	vect = _window.getSize();
  PositionI	pos;

  pos.x = vect.x;
  pos.y = vect.y;
  return (pos);
}

Position	SFMLHandler::getMouse() const
{
  sf::Vector2f	mouse(sf::Mouse::getPosition(_window));
  Position	pos;

  pos.x = mouse.x;
  pos.y = mouse.y;
  return (pos);
}
