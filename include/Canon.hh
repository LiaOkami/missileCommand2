#ifndef CANON_HH_INCLUDED
#define CANON_HH_INCLUDED


# include "Object.hh"

class Canon : public Object
{
private:

    Position _posCan;

public:

    /** \brief Constructeur par défaut
     *
     *  \param Position posCan      :Position
     *  \param const string& key    :chaine, clé d'une sprite d'un Object
     *
     *  Construction d'un canon, ayant en paramètres une position, et une key
     */
  City(Position posCan, const string& key);

};

#endif // CANON_HH_INCLUDED
