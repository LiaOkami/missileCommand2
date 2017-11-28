/** \file Object.hh
 *  \brief Classe Object
 */

#ifndef _OBJECT_HH_
# define _OBJECT_HH_

# include "SFMLHandler.hh"
#include "Position.hh"
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
    *
    *\param float x abcisse de l'objet
    *\param float y ordonnée de l'objet
    *\param const string key
    *\return
    *Construction de l'objet, ayant pour attributs une position, abcisse et ordonnée, et une key
    *
    */
    Object(float x, float y, const std::string &key);

    void	draw(SFMLHandler& handler) const;
};

#endif
