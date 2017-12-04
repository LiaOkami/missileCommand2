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
    SFMLHandler           window(800,600);

    // Pointeur de la souris
    Position cursorPosition;

    // Horloges
    sf::Clock chrono, apparition;
    sf::Time dureeMax = sf::milliseconds(100), dureeApparition = sf::seconds(1);

    // Vecteur de Sprites-missiles
    vector <sf::Sprite> tabMissiles(0);
    int tabMSize = tabMissiles.size();

    /* Chargement des Assets */
    sf::Texture missile;
    if(!missile.loadFromFile("assets/Missile.png", sf::IntRect(0,50,253,78))) //[1] Chemin de l'image, [2] Cadre de l'image
    {
        cout << "Erreur chargement texture (missile_01.png)" << endl;
    }

    window.loadAsset("MISSILE","assets/Missile.png",0.5, 90, 0, 50, 253, 78);
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

        /* Instructions d'affichage */
        window.clearWindow();
        window.draw("BACKGROUND",0,0);

        //Instruction d'affichage à placer ici pour tester. Les objets dessinés en premier seront à l'arrière-plan et ceux dessinés en dernier seront au premier plan
        for (int cpt = 0; cpt < tabMissiles.size(); cpt++)
        {
            window.draw("MISSILE", tabMissiles[cpt].getPosition().x, tabMissiles[cpt].getPosition().y);
        }


        window.draw("TARGET",cursorPosition);
        window.display();

    }
    game.launch();
    return (0);
}
