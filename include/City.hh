#ifndef CITY_HH_INCLUDED
#define CITY_HH_INCLUDED

# include "Object.hh"

class City : public Object
{
private:

    Position _posCity;

public:

    /** \brief Constructeur par défaut
     *
     *  \param Position posCity      :Position
     *  \param const string& key     :chaine, clé d'une sprite d'un Object
     *
     *  Construction d'une ville, ayant en paramètres une position, et une key
     */
  City(Position posCity, const string& key);

};
#endif // CITY_HH_INCLUDED
