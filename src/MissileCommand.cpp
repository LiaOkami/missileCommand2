#include "MissileCommand.hh"
#include "Missile.hh"
#include "Object.hh"
#include "SFMLHandler.hh"
#include "Explosion.hh"
#include <vector>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <iostream>


MissileCommand::MissileCommand()
{

}

void	MissileCommand::launch()
{
    srand(time(NULL));

    /* Initialisations */

    sf::Event             event;
    SFMLHandler           window(800,600);

    // Horloges
    sf::Clock chrono, apparition;
    sf::Time dureeMax = sf::milliseconds(100), dureeApparition = sf::seconds(1);

    // Vecteur de Sprites-missiles
    vector <sf::Sprite> tabMissiles(0);
    int tabMSize = tabMissiles.size();

    //Vecteur des missiles aliés
    vector<Missile> tabMissAlly;

    // Pointeur de la souris
    Position cursorPosition;

    //Positions de tests
    Position canonPosition, allyMissilePosition;
    canonPosition.x = 368; canonPosition.y = 467; allyMissilePosition.x = 100; allyMissilePosition.y = 50;

    /* Chargement des Assets */
    sf::Texture missile;
    if(!missile.loadFromFile("assets/Missile.png", sf::IntRect(0,50,253,78))) //[1] Chemin de l'image, [2] Cadre de l'image
    {
	cout << "Erreur chargement texture (missile_01.png)" << endl;
    }

    window.loadAsset("MISSILE_ALLY","assets/Missile_Ally.png",0.5, 0);
    window.loadAsset("MISSILE_FOE","assets/Missile_Foe.png",0.5, 0);
    window.loadAsset("CANON","assets/Canon.png");
    window.loadAsset("TARGET", "assets/TargetCursor.png");
    window.loadAsset("BACKGROUND", "assets/MissileCommand_Background.jpg");



    /* Boucle Principale */

    while (window.getWindow().isOpen())
    {
	/* Boucle d'évènements */

	while (window.getWindow().pollEvent(event))
	{
	    if (event.type == sf::Event::Closed)
		window.close();
	    if (event.type == sf::Event::KeyPressed)
		window.close();


	    /** \brief met à jour la position du pointeur avec la position du curseur de la souris */
	    sf::Vector2f mousePosition(sf::Mouse::getPosition(window.getWindow()));
	    if (event.MouseMoved)
	    {
		cursorPosition.x = mousePosition.x;
		cursorPosition.y = mousePosition.y;
	    }


	    /** \brief Si l'utilisateur clique sur le missile, il est supprimé
	    UPDATE: Le clic sur l'écran doit envoyer un missile */

	    if(event.type == sf::Event::MouseButtonPressed)
	    {
		if (event.mouseButton.button == sf::Mouse::Left && tabMissiles.size()>0)
		{
		    /*tabMSize = tabMissiles.size();
		    sf::Vector2f positionSouris2(sf::Mouse::getPosition(window.getWindow()));
		    for(int cpt1 = 0; cpt1 < tabMSize; cpt1++) // vérification pour chaque missile
		    {
			if(tabMissiles[cpt1].getGlobalBounds().contains(positionSouris2)) // Si la souris est sur le sprite, décalage et suppression
			{
			    cout << "Missile cliqué. ";
			    for(int cpt2 = cpt1; cpt2 < tabMSize-1; cpt2++)
			    {
				tabMissiles[cpt2] = tabMissiles[cpt2+1];
			    }
			    cout << "Missile supprimé." << endl;
			    tabMissiles.pop_back();
			}
		    }*/
		    Position pFinal=window.getMouse();
		    Position pInit;
		    pInit=canonPosition;
		    float speed=12;
		    Missile m1(speed,pInit,pFinal,"MISSILE_ALLY");
		    m1.draw(window);
		    tabMissAlly.push_back(m1);
		}
	    }
	}

	/* Mise à jour des éléments */

	/** \brief fait bouger les missiles*/
	if ( chrono.getElapsedTime() > dureeMax)
	{
	    tabMSize = tabMissiles.size();
	    for (int cpt = 0; cpt < tabMSize; cpt++)
	    {
		tabMissiles[cpt].move(0,7);
	    }
	    chrono.restart();
	}


	/** \brief ajoute un missile au tableau de missiles lorsque la duée d'apparition est écoulée */
	if (apparition.getElapsedTime() > dureeApparition)
	{
	    sf::Sprite sprite_missile;
	    int x = (rand()%(window.getSize().x-78/2)) +78/2;

	    sprite_missile.setTexture(missile);
	    sprite_missile.scale(0.5,0.5);
	    sprite_missile.setRotation(90.0);
	    sprite_missile.setPosition(x,0);
	    tabMissiles.push_back(sprite_missile);
	    apparition.restart();
	    cout << "Création d'un missile" << endl;
	}


	/** \brief supprime les missiles en dehors de la fenêtre */
	for(int cpt1 = 0; cpt1 < tabMissiles.size(); cpt1++)
	{
	    if(tabMissiles[cpt1].getPosition().y > window.getSize().y-50)
	    {
		cout << "Missile sorti ( " << tabMissiles[cpt1].getPosition().y << " > " << window.getSize().y-50 << " ). ";
		for(int cpt2 = cpt1; cpt2 < tabMSize-1; cpt2++)
		{
		    tabMissiles[cpt2] = tabMissiles[cpt2+1];
		}
		cout << "Missile supprimé." << endl;
		tabMissiles.pop_back();
	    }
	}

	/** \brief Provoque une explosion quand un missile allié atteint sa position finale */
	for(int cpt = 0; cpt<tabMissAlly.size();cpt++)
	{
	  if (tabMissAlly[cpt].isEnded())
	    {
		Explosion e1(tabMissAlly[cpt].getPos());
		//Supprimer du vecteur le missile
	    }
	}


	/* Instructions d'affichage */
	window.clearWindow();
	window.draw("BACKGROUND",0,0);

	//Instruction d'affichage à placer ici pour tester. Les objets dessinés en premier seront à l'arrière-plan et ceux dessinés en dernier seront au premier plan
	for (int cpt = 0; cpt < tabMissiles.size(); cpt++)
	{
	    window.draw("MISSILE_FOE", tabMissiles[cpt].getPosition().x, tabMissiles[cpt].getPosition().y);
	}
	window.draw("CANON", canonPosition);
	window.draw("MISSILE_ALLY", allyMissilePosition);


	window.draw("TARGET",cursorPosition);
	window.display();

    }
}
