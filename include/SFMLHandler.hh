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
    map<string,sf::Texture> _map;

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
   * \param réel, échelle de l'image
   * \param entier, rotation en degrés de l'image
   */
  void	loadAsset(const std::string & key, const std::string & filename, float scale = 1, int rotation = 0);

  /** \brief Charge un asset dans la map d'assets, en permettant de recadrer l'image;
   * \param chaine, clé d'une sprite
   * \param chaine, chemin relatif de l'emplacement de l'asset
   * \param réel, échelle de l'image
   * \param entier, rotation en degrés de l'image
   * \param entier, (pixels) espace à gauche à partir du bord gauche de l'image pour définir le cadre visible de l'asset
   * \param entier, (pixels) espace en haut à partir du bord haut de l'image pour définir le cadre visible de l'asset
   * \param entier, (pixels) largeur de l'image pour définir le cadre visible de l'asset
   * \param entier, (pixels) hauteur de l'image pour définir le cadre visible de l'asset
   */
  void	loadAsset(const std::string & key, const std::string & filename, float scale, int rotation, int RectLeft, int RectTop, int RectWidth, int RectHeight);

  /** \brief Dessine l'objet dans la fenêtre
   * \param chaine, clé d'une sprite
   * \param Position, position de l'objet à dessiner
   */
  void	draw(const std::string & key, Position pos);

  /** \brief Dessine l'objet dans la fenêtre [Surcharge]
   * \param chaine, clé d'une sprite
   * \param reel, coordonée x
   * \param reel, coordonée y
   */
  void	draw(const std::string & key, float x, float y); // temporaire, pour les tests

  /** \brief Affiche l'ensemble des objet dessinés
   *
   */
  void  display();

  /** \brief Ferme la fenêtre
   */
  void  close();

  /** \brief Accesseur de la fenêtre
   * \return sf::RenderWindow
   */
  sf::RenderWindow& getWindow();

  /** \brief Défini la position de la fenêtre
   * \param coordonée x de la fenêtre sur le bureau
   * \param coordonée y de la fenêtre sur le bureau
   */
  void setPosition(int x, int y);

  /** \brief Retourne la taile de la fenêtre
   * \return sf::Vector2u
   */
  sf::Vector2u getSize();
};

#endif
