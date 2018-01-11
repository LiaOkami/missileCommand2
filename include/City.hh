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
     *
     *  Construction d'une ville, ayant en paramètre une position
     */
  City(const Position &posCity);

};

#endif // CITY_HH_INCLUDED
