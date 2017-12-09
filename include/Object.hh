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
     *  \param float x abcisse d'Object
     *  \param float y ordonnée de d'Object
     *  \param chaine, clé d'une sprite d'un Object
     *
     *  Construction de l'objet, ayant pour attributs une position, abcisse et ordonnée, et une key
     */
    Object(const Position &, const string &);


    /** \brief affichage de l'objet
    *  \param handler qui récupère la clé et affiche l'objet correspondant
    *
    *  Construction de l'objet, ayant pour attributs une position, abcisse et ordonnée, et une key
    */
    void draw(SFMLHandler& handler) const;


    void setPos(const Position &pos);/**< \brief _Position setter */

    Position getPos(const Position &pos);/**< \brief _Position getter */

    void setKey(const string &key);/**< \brief _Key setter */



};

#endif
