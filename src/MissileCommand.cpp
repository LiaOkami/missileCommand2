#include "MissileCommand.hh"
#include "Missile.hh"
#include "Object.hh"
#include "Explosion.hh"
#include "Menu.hh"
#include "Level.hh"
#include <vector>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <iostream>


MissileCommand::MissileCommand() :
  _window(WINDOW_WIDTH, WINDOW_HEIGHT)
{
    _dureeMax = sf::milliseconds(100);
    _dureeApparition = sf::seconds(1);

    /* Chargement des Assets */
    _window.loadAsset("MISSILE_ALLY","assets/Missile_Ally.png",0.5, 0, 65/2, 250/2);
    _window.loadAsset("MISSILE_FOE","assets/Missile_Foe.png",0.5, 0, 65/2, 250/2);
    _window.loadAsset("CANON","assets/Canon.png");
    _window.loadAsset("CITY","assets/City.png");
    _window.loadAsset("TARGET", "assets/TargetCursor.png");
    _window.loadAsset("BACKGROUND", "assets/MissileCommand_Background.png");

    _cities.push_back(City(Position(100, WINDOW_HEIGHT - 70)));
    _cities.push_back(City(Position(270, WINDOW_HEIGHT - 70)));
    _cities.push_back(City(Position(847, WINDOW_HEIGHT - 70)));
    _cities.push_back(City(Position(697, WINDOW_HEIGHT - 70)));
    _canons.push_back(Canon(Position(0, WINDOW_HEIGHT - 133)));
    _canons.push_back(Canon(Position(WINDOW_WIDTH / 2 - 32, WINDOW_HEIGHT - 133)));
    _canons.push_back(Canon(Position(WINDOW_WIDTH - 64, WINDOW_HEIGHT - 133)));
}


void	MissileCommand::launch()
{
    _menu(_window, this);
    score = 0;
    numLevel=1;
    nbMissileFoe=0;
    /* Boucle Principale */
    while (_window.getWindow().isOpen())
    {
      _pollEvents();
      _update();
      _draw();
    }
}

void	MissileCommand::_pollEvents()
{
  sf::Event	event;

  /* Boucle d'évènements */
  while (_window.getWindow().pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	_menu.launch();
      if (event.type == sf::Event::KeyPressed)
	_menu.launch();


      /** \brief Si l'utilisateur clique sur le missile, il est supprimé
	  UPDATE: Le clic sur l'écran doit envoyer un missile */

      if(event.type == sf::Event::MouseButtonPressed &&
	 event.mouseButton.button == sf::Mouse::Left && nbMissileAlly>0)
	{
	  unsigned int numCanon = _window.getMouse().x / (WINDOW_WIDTH / 3);
	  _tabMissAlly.push_back(_canons[numCanon].shoot(_window.getMouse()));
	  cout << "Création d'un missile allié" << endl;
	  nbMissileAlly--;
	}
    }
}

void	MissileCommand::_update()
{
  unsigned int cpt;

  /** \brief fait bouger les missiles*/
  if (_chrono.getElapsedTime() > _dureeMax)
    {
      for (Missile & missile:_tabMissFoe)
	missile.move(1);
      for (Missile & missile:_tabMissAlly)
	missile.move(1);
      _chrono.restart();
    }


  /** \brief ajoute un missile au tableau de missiles lorsque la durée d'apparition est écoulée */
  if (_apparition.getElapsedTime() > _dureeApparition && nbMissileFoe>0)
    {
      Position	posBeg(rand() % (_window.getSize().x - 78 / 2) + 78 / 2, 0);
      Position	posEnd(rand() % (_window.getSize().x - 78 / 2) + 78 / 2, 800);
      Missile	m1(7, posBeg, posEnd, "MISSILE_FOE");

      _tabMissFoe.push_back(m1);
      _apparition.restart();
      cout << "Création d'un missile" << endl;
      nbMissileFoe--;
    }

  /** \brief Agrandit les Explosions */
  cpt = 0;
  while (cpt < _explosions.size())
    {
      _explosions[cpt].update(1);
      if (_explosions[cpt].isEnded())
	_explosions.erase(_explosions.begin() + cpt);
      else
	cpt += 1;
    }

  /** \brief supprime les missiles ennemis arrivés */
  cpt = 0;
  while (cpt < _tabMissFoe.size())
    {
      if (_tabMissFoe[cpt].isEnded())
	{
	  _checkCollision(_tabMissFoe[cpt], _cities);
	  _explosions.push_back(Explosion(_tabMissFoe[cpt].getPos()));
	  _tabMissFoe.erase(_tabMissFoe.begin() + cpt);
	}
      else
	cpt += 1;
    }

  /* TMP Détruit un missile et les missiles ennemis le touchant */
  cpt = 0;
  while (cpt < _tabMissAlly.size())
    {
      if (_tabMissAlly[cpt].isEnded())
	{
	  _checkCollision(_tabMissAlly[cpt], _tabMissFoe);
	  _explosions.push_back(Explosion(_tabMissAlly[cpt].getPos()));
	  _tabMissAlly.erase(_tabMissAlly.begin() + cpt);
      /* TMP Affiche le score dans la fenetre de commande */
      cout << score << endl;
	}
      else
	cpt += 1;
    }


  /** TODO \brief Provoque une explosion quand un missile allié atteint sa position finale */
  for (unsigned int cpt = 0; cpt<_tabMissAlly.size();cpt++)
    {
      if (_tabMissAlly[cpt].isEnded())
	{
	    Explosion e1(_tabMissAlly[cpt].getPos());
	    //Supprimer du vecteur le missile
	}
    }

    if(nbMissileFoe<=0 && _tabMissFoe.size()==0)
    {
        numLevel++;
        defLevel(numLevel, nbMissileAlly, nbMissileFoe);
    }
}

void		MissileCommand::_checkCollision(const Object &object, std::vector<Missile> &objects)
{
  unsigned int	cpt = 0;

  while (cpt < objects.size())
    {
      if (_window.objectIntersects(object.getKey(), object.getPos(),
				   objects[cpt].getKey(), objects[cpt].getPos()))
	{
	  objects.erase(objects.begin() + cpt);
	  score++;
	}
      else
	cpt += 1;
    }
}

void		MissileCommand::_checkCollision(const Object &object, std::vector<City> &objects)
{
  unsigned int	cpt = 0;

  while (cpt < objects.size())
    {
      if (_window.objectIntersects(object.getKey(), object.getPos(),
				   objects[cpt].getKey(), objects[cpt].getPos()))
	{
	  objects.erase(objects.begin() + cpt);
	}
      else
	cpt += 1;
	  if(objects.empty())
	{
	  //Defaite du joueur
	}
    }
}

void	MissileCommand::_draw()
{
  /* Instructions d'affichage */
  _window.clearWindow();
  _window.draw("BACKGROUND", Position(0, 0));

  //Instruction d'affichage à placer ici pour tester. Les objets dessinés en premier seront à l'arrière-plan et ceux dessinés en dernier seront au premier plan
  for (const Missile & missile:_tabMissFoe)
    _window.draw("MISSILE_FOE", missile.getPos(), missile.getAngle());
  for (const Missile & missile:_tabMissAlly)
    _window.draw("MISSILE_ALLY", missile.getPos(), missile.getAngle());
  for (const City & city:_cities)
    _window.draw("CITY", city.getPos());
  for (const Canon & canon:_canons)
    _window.draw("CANON", canon.getPos());
  for (const Explosion & explosion:_explosions)
    _window.drawExplosion(explosion.getRay(), explosion.getPos());
  _window.draw("TARGET", _window.getMouse());
  _window.display();
}
