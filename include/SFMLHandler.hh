/** \file SFMLHandler.hh
 *  \brief Classe SFMLHandler
 */

#ifndef _SFMLHANDLER_HH_
# define _SFMLHANDLER_HH_

# include "Position.hh"

/** \brief Classe encapsulant la bibliothèque SFML
 *  \author Etienne Berrié
 */
class SFMLHhandler
{
private:
    sf::RenderWindow _window;

public:
  /** \brief Constructeur par défaut
   *
   * Arguments : largeur de la fenêtre, hauteur de la fenêtre, titre de la fenêtre, style de la fenêtre (de type sf::Style)
   */
  SFMLHandler(int width = 200, int height = 200, string title = "MissileCommand", sf::Style windowStyle = sf::Style::Default);

  /** \brief Destructeur par défaut
   */
  ~SFMLHandler();

  void	clearWindow();

  void	addAsset(const std::string & key, const std::string & filename);

  void	draw(const std::string & key, Position pos);
};

#endif
