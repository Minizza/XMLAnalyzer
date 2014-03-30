/* 
 * Fichier: elementNoeud.cpp
 * Auteur: julien
 */

#include "elementNoeud.h"
#include <iostream>

//Methodes par defaut de la classe ElementNoeud
ElementNoeud::ElementNoeud() : ElementBurne() {
}

ElementNoeud::ElementNoeud(ElementNoeud* orig) {
	nom = orig->nom;
	estXSD = orig->estXSD;
	enfants = orig->enfants;
	//regexFils = new ConstructeurRegex(orig->regexFils);
}

ElementNoeud::~ElementNoeud() {
	//delete(regexFils);
}


///// Redéfinition du contructeur /////
ElementNoeud::ElementNoeud(string* aNom, deque<AbstractAttribut*>* aAtts, deque<AbstractElement*>* aEnfants, string* aNamespaceName): ElementBurne(aNom, aAtts), enfants(*aEnfants), namespaceName(*aNamespaceName) {
	#ifdef DEBUG
		std::cout << "Construction de <ElementNoeud>" << std::endl;
	#endif
}

/*ConstructeurRegex* ElementNoeud::getRegex() {
	return regexFils;
}*/

void ElementNoeud::ajouterFils(AbstractElement* aFils) {
	#ifdef DEBUG
			std::cout << "Ajout d'un fils" << std::endl;
	#endif
	enfants.push_back(aFils);
}

void ElementNoeud::versFluxIndent(std::ostream& os, int indent) const
{
	indenter(os, indent);
	os << "<";
	nomVersFlux(os);
	for(deque<AbstractAttribut*>::const_iterator it = atts.begin(); it != atts.end(); it++)
	{
		AbstractAttribut* att = *it;
		att->versFlux(os);
	}
	os << ">\n";
	for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
	{
		AbstractElement* elt = *it;
		elt->versFluxIndent(os, indent+1);
	}
	indenter(os, indent);
	os << "</";
	nomVersFlux(os);
	os << ">\n";
}

void ElementNoeud::nomVersFlux(ostream& os) const
{
	if(!namespaceName.empty())
	{
		os << namespaceName << ":";
	}
	os << nom;
}

void transformationXSL(AbstractElement* noeudXML, std::ostream& os) const
{
	// todo
}
