#ifndef CANON_HH_INCLUDED
#define CANON_HH_INCLUDED

# include "Object.hh"
# include "Missile.hh"

class Canon : public Object
{
private:

public:

    /** \brief Constructeur par défaut
     *
     *  \param Position posCan      :Position
     *
     *  Construction d'un canon, ayant en paramètre une position
     */
  Canon(const Position & posCan);

  Missile	shoot(const Position &target);
};

#endif // CANON_HH_INCLUDED
