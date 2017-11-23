/** \file Object.hh
 *  \brief Classe Object
 */

#ifndef _OBJECT_HH_
# define _OBJECT_HH_

# include "SFMLHandler.hh"
#include "position.hh"
using namespace std;

/** \brief Classe parente de tous les objets affichables
 *  \author Pierre-Alexandre Jozeau
 */
class Object
{
private:

Position _pos;
string _key;



public:
  /** \brief Constructeur par défaut

   */
  Object(float x, float y, const std::string &key);

  void	draw(const SFMLHandler& handler) const;
};

#endif
