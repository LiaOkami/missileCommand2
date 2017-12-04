/** \file Object.hh
 *  \brief Classe Object
 */

#ifndef _OBJECT_HH_
# define _OBJECT_HH_

# include "SFMLHandler.hh"
# include "Position.hh"

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
     *  \param float x abcisse de l'objet
     *  \param float y ordonnée de l'objet
     *  \param const string key
     *
     *  Construction de l'objet, ayant pour attributs une position, abcisse et ordonnée, et une key
     *
     */
    Object(const Position &pos, const string &key);
    ///doxy draw
    void	draw(SFMLHandler& handler) const;

    ///doxy update

    virtual void	update(); //renvoie à l'update de niveau inferieur si update different
};

#endif
