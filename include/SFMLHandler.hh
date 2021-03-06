/** \file SFMLHandler.hh
 *  \brief Classe SFMLHandler
 */

#ifndef _SFMLHANDLER_HH_
# define _SFMLHANDLER_HH_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
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
    map<string,sf::Texture> _mapTextures;

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

  /** \brief Charge un asset dans la map d'assets
   * \param chaine, clé d'une sprite
   * \param chaine, chemin relatif de l'emplacement de l'asset
   * \param réel, échelle de l'image
   * \param entier, rotation en degrés de l'image
   */
  void	loadAsset(const std::string & key, const std::string & filename, float scale = 1, int rotation = 0);

    /** \brief Charge un asset dans la map d'assets, en permettant de changer l'origine du sprite
   * \param chaine, clé d'une sprite
   * \param chaine, chemin relatif de l'emplacement de l'asset
   * \param réel, échelle de l'image
   * \param entier, rotation en degrés de l'image
   * \param entier, coordonnée x de l'origine
   * \param entier, coordonnée y de l'origine
   */
  void loadAsset(const std::string & key, const std::string & filename, float scale, int rotation, int originX, int originY);

  /** \brief Charge un asset dans la map d'assets, en permettant de recadrer l'image
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

    /** \brief Vérifie si le curseur est dans les bordures d'un asset
   * \param chaine, clé d'une sprite
   * \param position de l'objet à vérifier
   * \return bool
   */
  bool cursorHover(const string & key, Position pos);

  /** \brief Vérifie si deux objets se recouvrent
   * \param chaine, clé du premier sprite
   * \param position du premier objet à vérifier
   * \param chaine, clé du second sprite
   * \param position du second objet à vérifier
   * \return bool
   */
  bool objectIntersects(const string & key1, Position pos1, const string & key2, Position pos2);

  /** \brief Vérifie si un objet entre en collision avec une explosion
   * \param réel, rayon de l'explosion à vérifier
   * \param Position, position de l'explosion à vérifier
   * \param chaine, clé du sprite à vérifier
   * \param position de l'objet à vérifier
   * \return bool
   */
  bool explosionCollides(float radius, Position explosionPos, const string & key, Position assetPos); //Pas fini

  /** \brief Vérifie si deux explosions se chevauchent
   * \param réel, rayon de la première explosion à vérifier
   * \param Position, position de la première explosion à vérifier
   * \param réel, rayon de la deuxième explosion à vérifier
   * \param Position, position de la deuxième explosion à vérifier
   * \return bool
   */
  bool explosionCollides(float radius1, Position pos1, float radius2, Position pos2);


  /* AFFICHAGE */

  /** \brief Efface les objets affichés dans la fenêtre
   */
  void	clearWindow();

  /** \brief Dessine l'objet dans la fenêtre
   * \param chaine, clé d'une sprite
   * \param Position, position de l'objet à dessiner
   */
  void	draw(const std::string & key, Position pos);

  /** \brief Dessine l'objet dans la fenêtre
   * \param chaine, clé d'un asset
   * \param Position, position de l'objet à dessiner
   * \param reel, rotation de l'objet
   */
  void	draw(const std::string & key, Position pos, double rot); // temporaire, pour les tests

    /** \brief Dessine l'objet dans la fenêtre
   * \param réel, rayon de l'explosion à dessiner
   * \param Position, position de l'explosion à dessiner
   */
   void drawExplosion(float radius, Position pos);

  /** \brief Affiche l'ensemble des objet dessinés
   */
  void  display();

  /** \brief Ferme la fenêtre
   */
  void  close();


  /* ACCESSEURS */

  /** \brief Accesseur de la fenêtre
   * \return sf::RenderWindow
   */
  sf::RenderWindow& getWindow();

  /** \brief Définit la position de la fenêtre
   * \param pos Coordonnées de la fenêtre sur le bureau
   */
  void setPosition(const PositionI &pos);

  /** \brief Retourne la taile de la fenêtre
   *  \return PositionI
   */
  PositionI	getSize() const;

  /** \brief Retourne la Position de la souris
   *  \return Position
   */
  Position	getMouse() const;
};

#endif
