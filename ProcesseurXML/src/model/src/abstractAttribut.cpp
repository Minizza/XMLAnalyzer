/* 
 * Fichier: abstractElement.cpp
 * Auteur: tgermain
 */

#include "abstractAttribut.h"
#include <iostream>

AbstractAttribut::AbstractAttribut(){}

AbstractAttribut::AbstractAttribut(AbstractAttribut* orig){}

AbstractAttribut::AbstractAttribut(string* aNom, string* aNamespace) : nom(*aNom), namespaceName(*aNamespace)
{
    #ifdef DEBUG
        std::cout << "Construction de <AbstractAttribut>" << std::endl;
    #endif
}

AbstractAttribut::~AbstractAttribut(){}

ostream& AbstractAttribut::versFlux(ostream& os) const
{
	os << " ";
	if(!namespaceName.empty())
	{
		os << namespaceName << ":";
	}
	os << nom << "=\"";
	valeurVersFlux(os);
	os << "\"";
}
