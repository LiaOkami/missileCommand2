#include <SFML/Graphics.hpp>
#include "MissileCommand.hh"

#include <vector>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <iostream>

int     main()
{
    MissileCommand        game;
    sf::RenderWindow      window(sf::VideoMode(400, 400), "Missile Command");
    window.setPosition(sf::Vector2i(200,200));
    sf::Event             event;

    srand(time(NULL));

    /* Initialisations */
    sf::CircleShape     pointeurSouris(10.0);
    pointeurSouris.setFillColor(sf::Color::Red);

    sf::Clock chrono, apparition;
    sf::Time dureeMax = sf::milliseconds(100), dureeApparition = sf::seconds(1);

    vector <sf::Sprite> tabMissiles(0);
    sf::Vector2u tailleF = window.getSize(); //taille de la fenêtre

    // Chargement de l'image
    sf::Texture missile;
    if(!missile.loadFromFile("assets/Missile.png", sf::IntRect(0,50,253,78))) //[1] Chemin de l'image, [2] Cadre de l'image
    {
	cout << "Erreur chargement texture (missile_01.png)" << endl;
    }


    while (window.isOpen())
    {
	/* Instructions d'affichage */
	window.clear();
	window.draw(pointeurSouris);

	int tabMSize = tabMissiles.size();
	for (int cpt = 0; cpt < tabMSize; cpt++)
	{
	    window.draw(tabMissiles[cpt]);
	}

	window.display(); //Affichage

	/* Boucle d'évènements */
	while (window.pollEvent(event))
	{
	    if (event.type == sf::Event::Closed) //
		window.close();
	    if (event.type == sf::Event::KeyPressed)
		window.close();


	    /** \brief met à jour la position du pointeur avec la position du curseur de la souris */
	    sf::Vector2f positionSouris(sf::Mouse::getPosition(window));
	    if (event.MouseMoved)
	    {
		pointeurSouris.setPosition(positionSouris);
	    }


	    /** \brief Si l'utilisateur clique sur le missile, il est supprimé */

	    if(event.type == sf::Event::MouseButtonPressed)
	    {
		if (event.mouseButton.button == sf::Mouse::Left && tabMissiles.size()>0)
		{
		    tabMSize = tabMissiles.size();
		    sf::Vector2f positionSouris2(sf::Mouse::getPosition(window));
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
		    }
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
	    int x = (rand()%(tailleF.x-78/2)) +78/2;

	    sprite_missile.setTexture(missile);
	    sprite_missile.scale(0.5,0.5);
	    sprite_missile.setRotation(90.0);
	    sprite_missile.setPosition(x,0);
	    tabMissiles.push_back(sprite_missile);
	    apparition.restart();
	    cout << "Création d'un missile" << endl;
	}


	/** \brief supprime les missiles en dehors de la fenêtre */
	tabMSize = tabMissiles.size();
	for(int cpt1 = 0; cpt1 < tabMSize; cpt1++)
	{
	    if(tabMissiles[cpt1].getPosition().y > tailleF.y-50)
	    {
		cout << "Missile sorti ( " << tabMissiles[cpt1].getPosition().y << " > " << tailleF.y-50 << " ). ";
		for(int cpt2 = cpt1; cpt2 < tabMSize-1; cpt2++)
		{
		    tabMissiles[cpt2] = tabMissiles[cpt2+1];
		}
		cout << "Missile supprimé." << endl;
		tabMissiles.pop_back();
	    }
	}

    }
    game.launch();
    return (0);
}
