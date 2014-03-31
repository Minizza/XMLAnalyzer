/* 
 * Fichier: elementPI.cpp
 * Auteur: julien
 */


#include "elementPI.h"
#include <iostream>

//Methodes par defaut de la classe ElementPI
ElementPI::~ElementPI() {
}


///// Redéfinition du contructeur /////
ElementPI::ElementPI(string* aNom, deque<AbstractAttribut*>* aAttributs, string* aNamespace) : ElementBurne(aNom, aAttributs, aNamespace) {
		#ifdef DEBUG
			std::cout << "Construction de <ElementPI>" << std::endl;
		#endif
}


void ElementPI::versFluxIndent(std::ostream& os, int indent) const
{
    indenter(os, indent);
	os << "<?" << nom;
	for(deque<AbstractAttribut*>::const_iterator it = atts.begin(); it != atts.end(); it++)
	{
		AbstractAttribut* att = *it;
		att->versFlux(os);
	}
	os << "?>\n";
}
