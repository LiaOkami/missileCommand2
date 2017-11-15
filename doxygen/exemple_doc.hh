/** \file Poisson.hh
 *  \brief Classe Poisson
 */

#ifndef _POISSON_HH_
# define _POISSON_HH_

/** Représentation de l'eau douce et salée sous forme de constantes
 *  Un booléen est utilisé puisqu'il qu'il n'y a que 2 possibilités
 */
const bool      SALT = true;
const bool      FRESH = false;

# include <string>

/** \brief Classe représentant un Poisson d'un Aquarium
 *  \author Pierrick Garcia
 */
class Poisson
{
private:
  std::string   _name;
  bool          _habitat;
  float         _length;

public:
  /** \brief Constructeur avec valeurs par défaut
   *
   *  \param name Nom du poisson
   *  \param habitat Habitat du Poisson
   *  \param length Taille du Poisson (en cm)
   *
   *  Lance une exception float égale à length si la taille n'est pas positive
   *  Lance une exception int égale à 1 si le nom est vide
   */
  Poisson(const std::string & name = "poisson clown", bool habitat = SALT, float length = 10);

  /** \brief Grandit le Poisson
   *
   *  \param length float
   *  \return void
   *
   *  Augmente la taille du Poisson de length cm.\n
   *  (Ex: _length = 14, length = 12, length vaudra 26 ensuite)
   *  Lance une exception float égale à length si la taille n'est pas positive
   *  Ne fait rien avec 0 en paramètre
   */
  void grandit(float length);

  /** \brief Vérifie si le poisson peut en manger un autre
   *
   *  \param other Poisson dont la mangeabilité est testée
   *  \return bool Retourne vrai si other peut etre mangé
   *
   *  Exemples (cible - paramètre : résultat) :\n
   *  crevette - requin : false\n
   *  requin - crevette : true\n
   *  crevette - crevette : false\n
   *  requin - requin : false
   */
  bool mange(const Poisson & other) const;

  const std::string &   getName() const; /**< \brief _name getter */
  bool                  getHabitat() const; /**< \brief _habitat getter */
  float                 getLength() const; /**< \brief _length getter */
};

/** \brief Affiche un Poisson
 *
 *  Affiche other sous la forme :
 *  'nom': vie en 'habitat', 'taille'cm de long\n
 *  Exemple avec les arguments par défaut :
 *  poisson-clown: vit en eau salée, 10cm de long
 */
std::ostream&  operator<<(std::ostream& os, const Poisson &other);

#endif // _POISSON_HH_
