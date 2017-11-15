/** \file Object.hh
 *  \brief Classe Object
 */

#ifndef _OBJECT_HH_
# define _OBJECT_HH_

# include "SFMLHandler.hh"

/** \brief Classe parente de tous les objets affichables
 *  \author Pierre-Alexandre Jozeau
 */
class Object
{
public:
  /** \brief Constructeur par défaut
   */
  Object(int x, int y, const std::string &key, const std::string &filename);

  void	draw(const SFMLHandler& handler) const;
};

#endif
