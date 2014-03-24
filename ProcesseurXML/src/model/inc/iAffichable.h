/* 
 * Fichier: iAffichable.h
 * Auteur: qbonnet
 */

#ifndef IAFFICHABLE_H
#define IAFFICHABLE_H

//Liste des includes système/libs
#include <iostream>

class IAffichable
{
	virtual std::ostream& versFlux(std::ostream& os) const=0;
};

#endif
