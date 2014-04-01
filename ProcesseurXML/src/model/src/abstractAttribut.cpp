/* 
 * Fichier: abstractElement.cpp
 * Auteur: tgermain
 */

#include "abstractAttribut.h"
#include <iostream>

AbstractAttribut::AbstractAttribut(){}

AbstractAttribut::AbstractAttribut(AbstractAttribut* orig){}

AbstractAttribut::AbstractAttribut(NomCanonique* aNom) : nom(*aNom)
{
    #ifdef DEBUG
        std::cout << "Construction de <AbstractAttribut>" << std::endl;
    #endif
    delete aNom;
}

AbstractAttribut::~AbstractAttribut(){}

ostream& AbstractAttribut::versFlux(ostream& os) const
{
	os << " " << nom << "=\"";
	valeurVersFlux(os);
	os << "\"";
}