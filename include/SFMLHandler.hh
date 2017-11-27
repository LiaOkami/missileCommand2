/** \file SFMLHandler.hh
 *  \brief Classe SFMLHandler
 */

#ifndef _SFMLHANDLER_HH_
# define _SFMLHANDLER_HH_

#include <SFML/Graphics.hpp>
# include "Position.hh"

#include <map>
using namespace std;

/** \brief Classe encapsulant la bibliothèque SFML
 *  \author Etienne Berrié
 */
class SFMLHandler
{
private:
    sf::RenderWindow _window;
    map<string,sf::Sprite> _mapAssets;

public:
  /** \brief Constructeur par défaut
   *
   * \param largeur de la fenêtre
   * \param hauteur de la fenêtre
   * \param titre de la fenêtre
   * \param style de la fenêtre (optionnel, à faire plus tard)
   */
  SFMLHandler(int width = 200, int height = 200, string title = "MissileCommand");

  /** \brief Destructeur par défaut
   */
  ~SFMLHandler();

  /** \brief Efface les objets affichés dans la fenêtre
   */
  void	clearWindow();

  /** \brief Charge un asset dans la map d'assets;
   * \param chaine, clé d'une sprite
   * \param chaine, chemin relatif de l'emplacement de l'asset
   */
  void	loadAsset(const std::string & key, const std::string & filename);

  /** \brief Dessine l'objet dans la fenêtre
   * \param chaine, clé d'une sprite
   * \param Position, position de l'objet à dessiner
   */
  void	draw(const std::string & key, Position pos);

  /** \brief Affiche l'ensemble des objet dessinés
   *
   */
  void  display();
};

#endif
