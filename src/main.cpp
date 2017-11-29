#include "MissileCommand.hh"
#include "SFMLHandler.hh"

#include <vector>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <iostream>

int     main()
{
    srand(time(NULL));

    /* Initialisations */

    MissileCommand        game;
    sf::Event             event;
    SFMLHandler           window(400,400);
    window.setPosition(600,200);

    // Pointeur de la souris
    sf::CircleShape     pointeurSouris(10.0);
    pointeurSouris.setFillColor(sf::Color::Red);
    Position cursorTarget; //version pour le sprite "TARGET"
    Position p; p.x=50; p.y=50; //Test pour le Map de Sprites

    // Horloges
    sf::Clock chrono, apparition;
    sf::Time dureeMax = sf::milliseconds(100), dureeApparition = sf::seconds(1);

    // Vecteur de Sprites-missiles
    vector <sf::Sprite> tabMissiles(0);
    sf::Vector2u tailleF = window.getWindow().getSize(); //taille de la fenêtre

    /* Chargement des Assets */
    sf::Texture missile;
    if(!missile.loadFromFile("assets/Missile.png", sf::IntRect(0,50,253,78))) //[1] Chemin de l'image, [2] Cadre de l'image
    {
	cout << "Erreur chargement texture (missile_01.png)" << endl;
    }

    window.loadAsset("MISSILE","assets/Missile.png",0.5, 90, 0, 50, 253, 78);
    window.loadAsset("TARGET", "assets/cible.png");



    while (window.getWindow().isOpen())
    {
	int tabMSize = tabMissiles.size();
	/* Boucle d'évènements */
	while (window.getWindow().pollEvent(event))
	{
	    if (event.type == sf::Event::Closed)
		window.close();
	    if (event.type == sf::Event::KeyPressed)
		window.close();


	    /** \brief met à jour la position du pointeur avec la position du curseur de la souris */
	    sf::Vector2f positionSouris(sf::Mouse::getPosition(window.getWindow()));
	    if (event.MouseMoved)
	    {
		pointeurSouris.setPosition(positionSouris);

		cursorTarget.x = positionSouris.x; //Version pour le sprite "TARGET" du curseur de la souris
		cursorTarget.y = positionSouris.y;
	    }


	    /** \brief Si l'utilisateur clique sur le missile, il est supprimé */

	    if(event.type == sf::Event::MouseButtonPressed)
	    {
		if (event.mouseButton.button == sf::Mouse::Left && tabMissiles.size()>0)
		{
		    tabMSize = tabMissiles.size();
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

	/* Instructions d'affichage */
	window.clearWindow();
	window.getWindow().draw(pointeurSouris);

	//window.draw("TARGET",cursorTarget); // Tests appels SFMLHandler.draw
	window.draw("MISSILE",p);

	tabMSize = tabMissiles.size();
	for (int cpt = 0; cpt < tabMSize; cpt++)
	{
	    window.getWindow().draw(tabMissiles[cpt]);
	}

	window.display();

    }
    game.launch();
    return (0);
}
