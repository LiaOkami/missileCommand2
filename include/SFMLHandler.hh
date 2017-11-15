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
public:
  /** \brief Constructeur par défaut
   */
  SFMLHandler();

  /** \brief Destructeur par défaut
   */
  ~SFMLHandler();

  void	clearWindow();

  void	addAsset(const std::string & key, const std::string & filename);

  void	draw(const std::string & key, Position pos);
};

#endif
