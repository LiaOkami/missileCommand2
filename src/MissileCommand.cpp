#include "MissileCommand.hh"
#include "Missile.hh"
#include "Object.hh"
#include "Explosion.hh"
#include <vector>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <iostream>


MissileCommand::MissileCommand() :
  _window(800, 600)
{
    _canonPosition.x = 368; _canonPosition.y = 467;
    _dureeMax = sf::milliseconds(100);
    _dureeApparition = sf::seconds(1);

    /* Chargement des Assets */
    _window.loadAsset("MISSILE_ALLY","assets/Missile_Ally.png",0.5, 0);
    _window.loadAsset("MISSILE_FOE","assets/Missile_Foe.png",0.5, 0);
    _window.loadAsset("CANON","assets/Canon.png");
    _window.loadAsset("TARGET", "assets/TargetCursor.png");
    _window.loadAsset("BACKGROUND", "assets/MissileCommand_Background.jpg");
}


void	MissileCommand::launch()
{
    /* Boucle Principale */

    while (_window.getWindow().isOpen())
    {
	/* Boucle d'évènements */

	while (_window.getWindow().pollEvent(_event))
	{
	    if (_event.type == sf::Event::Closed)
		_window.close();
	    if (_event.type == sf::Event::KeyPressed)
		_window.close();


	    /** \brief Si l'utilisateur clique sur le missile, il est supprimé
	    UPDATE: Le clic sur l'écran doit envoyer un missile */

	    if(_event.type == sf::Event::MouseButtonPressed)
	    {
		if (_event.mouseButton.button == sf::Mouse::Left && _tabMissiles.size()>0)
		{
		    Missile m1(12, _canonPosition, _window.getMouse(), "MISSILE_ALLY");
		    _tabMissAlly.push_back(m1);
		}
	    }
	}

	_update();
	_draw();
    }
}

void	MissileCommand::_update()
{
  /** \brief fait bouger les missiles*/
  if (_chrono.getElapsedTime() > _dureeMax)
    {
      for (int cpt = 0; cpt < _tabMissiles.size(); cpt++)
	{
	  _tabMissiles[cpt].move(0,7);
	}
      _chrono.restart();
    }


  /** \brief ajoute un missile au tableau de missiles lorsque la duée d'apparition est écoulée */
  if (_apparition.getElapsedTime() > _dureeApparition)
    {
  //Créer un missile ennemi
  //_tabMissiles.push_back(sprite_missile);
      _apparition.restart();
      cout << "Création d'un missile" << endl;
    }


  /** \brief supprime les missiles en dehors de la fenêtre */
  for(int cpt1 = 0; cpt1 < _tabMissiles.size(); cpt1++)
    {
      if(_tabMissiles[cpt1].getPosition().y > _window.getSize().y-50)
	{
	  cout << "Missile sorti ( " << _tabMissiles[cpt1].getPosition().y << " > " << _window.getSize().y-50 << " ). ";
	  for(int cpt2 = cpt1; cpt2 < _tabMissiles.size() - 1; cpt2++)
	    {
	      _tabMissiles[cpt2] = _tabMissiles[cpt2+1];
	    }
	  cout << "Missile supprimé." << endl;
	  _tabMissiles.pop_back();
	}
    }

  /** \brief Provoque une explosion quand un missile allié atteint sa position finale */
  for(int cpt = 0; cpt<_tabMissAlly.size();cpt++)
    {
      if (_tabMissAlly[cpt].isEnded())
	{
	  Explosion e1(_tabMissAlly[cpt].getPos());
	  //Supprimer du vecteur le missile
	}
    }
}

void	MissileCommand::_draw()
{
  /* Instructions d'affichage */
  _window.clearWindow();
  _window.draw("BACKGROUND",0,0);

  //Instruction d'affichage à placer ici pour tester. Les objets dessinés en premier seront à l'arrière-plan et ceux dessinés en dernier seront au premier plan
  for (int cpt = 0; cpt < _tabMissiles.size(); cpt++)
    {
      _window.draw("MISSILE_FOE", _tabMissiles[cpt].getPosition().x, _tabMissiles[cpt].getPosition().y);
    }
  _window.draw("CANON", _canonPosition);
  _window.draw("TARGET", _window.getMouse());
  _window.display();
}
