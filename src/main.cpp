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
    sf::CircleShape       cercle(50.0);
    cercle.setFillColor(sf::Color::White);

    sf::CircleShape     pointeurSouris(10.0);
    pointeurSouris.setFillColor(sf::Color::Red);

    sf::Clock chrono, apparition;
    sf::Time dureeMax = sf::microseconds(10), dureeApparition = sf::seconds(3);

    vector<sf::CircleShape> tabC(0);

    sf::Vector2u tailleF = window.getSize();

    // Images
    sf::Texture missile;
    sf::Sprite sprite_missile;
    if(!missile.loadFromFile("Images/missile_01.png"))
    {
        cout << "Erreur chargement texture (missile_01.png)" << endl;
    }
    sprite_missile.setTexture(missile);

    while (window.isOpen())
    {
        window.clear();
        window.draw(cercle);
        window.draw(pointeurSouris);
        window.draw(sprite_missile);

        int tabCSize = tabC.size();
        for(int cpt=0; cpt < tabCSize; cpt++)
        {
            window.draw(tabC[cpt]);
        }

        window.display(); //Affichage

        /* Boucle d'évènements */
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                window.close();

            /** \brief Si l'utilisateur clique sur le BGS, met à jour la position du cercle blanc
            */
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    cercle.setPosition(event.mouseButton.x-50.0, event.mouseButton.y-50.0);
                }
            }
            /** \brief met à jour la position du pointeur avec la position du curseur de la souris
            */
            sf::Vector2f positionSouris(sf::Mouse::getPosition(window));
            if (event.MouseMoved)
            {
                pointeurSouris.setPosition(positionSouris);
            }
            /** \brief Si l'utilisateur clique sur le cercle, il est supprimé */
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right && tabC.size()>0)
                {
                    tabC.pop_back();
                }
            }
        }

        /** \brief fait bouger le cercle blanc*/
        if ( chrono.getElapsedTime() > dureeMax)
        {
            cercle.move(0.01,0.01);
            chrono.restart();
        }

        /** \brief crée un Cercle lorsque la duée d'apparition est écoulée */
        if (apparition.getElapsedTime() > dureeApparition)
        {
            sf::CircleShape nveauCercle(30.0);
            nveauCercle.setFillColor(sf::Color::Blue);
            int x = (rand()%(tailleF.y-((int)nveauCercle.getRadius())*2));
            int y = (rand()%(tailleF.y-((int)nveauCercle.getRadius())*2));
            nveauCercle.setPosition(x,y);
            tabC.push_back(nveauCercle);
            apparition.restart();
        }

    }
    game.launch();
    return (0);
}
