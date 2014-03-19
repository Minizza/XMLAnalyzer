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
	#ifdef DEBUG
		std::cout << "Construction de <AbstractAttribut>" << std::endl;
	#endif
	nom = aNom;
}

AbstractAttribut::~AbstractAttribut(){}
