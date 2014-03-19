/* 
 * Fichier: abstractElement.cpp
 * Auteur: tgermain
 */

#include "abstractElement.h"

AbstractElement::AbstractElement(){}

AbstractElement::AbstractElement(AbstractElement* orig){}

AbstractElement::AbstractElement(string* aNom)
{
#ifdef DEBUG
		std::cout << "Construction de <AbstractElement>" << std::endl;
#endif
	nom = aNom;
}

AbstractElement::~AbstractElement(){}
