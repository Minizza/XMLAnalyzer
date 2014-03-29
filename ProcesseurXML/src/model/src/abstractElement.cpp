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

std::ostream& AbstractElement::versFlux(std::ostream& os) const
{
	this->versFluxIndent(os, 0);
}

void AbstractElement::indenter(std::ostream& os, int indent) const
{
	for(int i=0; i<indent; ++i)
	{
		os << "  ";
	}
}