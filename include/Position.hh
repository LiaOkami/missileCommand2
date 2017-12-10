/** \file Position.hh
 *  \brief Classe Position
 */

#ifndef _POSITION_HH_
# define _POSITION_HH_

# include <stdint.h>

/** \brief Structure représentant la Position d'un Object
 *  \author Pierrick Garcia
 */
struct Position
{
  float	x;
  float	y;
};

/** \brief Structure représentant une Position en terme d'entiers positifs
 *  \author Pierrick Garcia
 */
struct PositionI
{
  unsigned int	x;
  unsigned int	y;
};

#endif
