/* 
 * Fichier: abstractElement.cpp
 * Auteur: tgermain
 */

#include "abstractElement.h"

AbstractElement::AbstractElement(){}

AbstractElement::AbstractElement(AbstractElement* orig){}

AbstractElement::AbstractElement(std::string* aNom)
{
#ifdef DEBUG
		std::cout << "Construction de <AbstractElement>" << std::endl;
#endif
	nom = *aNom;
}


AbstractElement::~AbstractElement(){}

AbstractElement::iterator::iterator(std::deque<AbstractElement*> listeElements)
{
	it = listeElements.begin();
}

AbstractElement::iterator::iterator(std::deque<AbstractElement*>::iterator it)
{
	this->it = it;
}
