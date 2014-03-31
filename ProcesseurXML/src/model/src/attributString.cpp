/* 
 * Fichier: attributString.cpp
 * Auteur: nbuisson
 */

#include "attributString.h"
#include <iostream>

AttributString::AttributString(){}

AttributString::AttributString(AttributString* orig){}

AttributString::AttributString(NomCanonique* aNom, string* aValue) : 	AbstractAttribut(aNom)
{
	#ifdef DEBUG
		std::cout << "Construction de <AttributString>" << std::endl;
	#endif
	value = *aValue;
}

AttributString::~AttributString(){}


void AttributString::valeurVersFlux(ostream& os) const
{
	os << value;
}