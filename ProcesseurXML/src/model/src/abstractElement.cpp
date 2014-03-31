/* 
 * Fichier: abstractElement.cpp
 * Auteur: tgermain
 */

#include "abstractElement.h"

AbstractElement::AbstractElement(AbstractElement* orig){}

AbstractElement::AbstractElement()
{
#ifdef DEBUG
		std::cout << "Construction de <AbstractElement>" << std::endl;
#endif
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

void AbstractElement::donneesVersFlux(std::ostream& os) const
{
	cout << "Je suis dans Abstract" << endl;
    return;
}

void AbstractElement::transformationXSL(AbstractElement* noeudXML, AbstractElement* racineXSL, int indent, std::ostream& os) const
{
    return;
}

std::string AbstractElement::creationRegex(std::map<std::string,std::string>& mapRegex) const
{
	return "";
}

bool AbstractElement::ValiderXML(std::map<std::string,std::string>& mapRegex) const
{
	return false;
}