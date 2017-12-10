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

      _pollEvents();
      _update();
      _draw();
    }
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


      /** \brief Si l'utilisateur clique sur le missile, il est supprimé
	  UPDATE: Le clic sur l'écran doit envoyer un missile */

      if(event.type == sf::Event::MouseButtonPressed &&
	 event.mouseButton.button == sf::Mouse::Left)
	{
	  Missile m1(12, _canonPosition, _window.getMouse(), "MISSILE_ALLY");
	  _tabMissAlly.push_back(m1);
	  cout << "Création d'un missile allié" << endl;
	}
    }
}

void	MissileCommand::_update()
{
  /** \brief fait bouger les missiles*/
  if (_chrono.getElapsedTime() > _dureeMax)
    {
      for (Missile & missile:_tabMissFoe)
	missile.move(1);
      for (Missile & missile:_tabMissAlly)
	missile.move(1);
      _chrono.restart();
    }


  /** \brief ajoute un missile au tableau de missiles lorsque la duée d'apparition est écoulée */
  if (_apparition.getElapsedTime() > _dureeApparition)
    {
  //Créer un missile ennemi
  //_tabMissiles.push_back(sprite_missile);
      Position	pos1;
      Position	pos2;
      pos1.x = rand() % (_window.getSize().x - 78 / 2) + 78 / 2;
      pos1.y = 0;
      pos2.x = rand() % (_window.getSize().x - 78 / 2) + 78 / 2;
      pos2.y = 800;
      Missile	m1(7, pos1, pos2, "MISSILE_FOE");
      _tabMissFoe.push_back(m1);
      _apparition.restart();
      cout << "Création d'un missile" << endl;
    }


  /** \brief supprime les missiles en dehors de la fenêtre */
  for(int cpt1 = 0; cpt1 < _tabMissFoe.size(); cpt1++)
    {
      if(_tabMissFoe[cpt1].getPos().y > _window.getSize().y-50)
	{
	  cout << "Missile sorti ( " << _tabMissFoe[cpt1].getPos().y << " > " << _window.getSize().y-50 << " ). ";
	  for(int cpt2 = cpt1; cpt2 < _tabMissFoe.size() - 1; cpt2++)
	    {
	      _tabMissFoe[cpt2] = _tabMissFoe[cpt2+1];
	    }
	  cout << "Missile supprimé." << endl;
	  _tabMissFoe.pop_back();
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
  for (const Missile & missile:_tabMissFoe)
    _window.draw("MISSILE_FOE", missile.getPos());
  for (const Missile & missile:_tabMissAlly)
    _window.draw("MISSILE_ALLY", missile.getPos());
  _window.draw("CANON", _canonPosition);
  _window.draw("TARGET", _window.getMouse());
  _window.display();
}
