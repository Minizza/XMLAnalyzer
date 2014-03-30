/* 
 * Fichier: abstractElement.cpp
 * Auteur: tgermain
 */

#include "abstractAttribut.h"
#include <iostream>

AbstractAttribut::AbstractAttribut(){}

AbstractAttribut::AbstractAttribut(AbstractAttribut* orig){}

AbstractAttribut::AbstractAttribut(string* aNom)
{
	nom = *aNom;
    #ifdef DEBUG
        std::cout << "Construction de <AbstractAttribut>" << std::endl;
    #endif
}

AbstractAttribut::~AbstractAttribut(){}

ostream& AbstractAttribut::versFlux(ostream& os) const
{
	os << " " << nom << "=\"";
	valeurVersFlux(os);
	os << "\"";
}

string AbstractAttribut::getNom() const
{
    return nom;
}
