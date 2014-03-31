/* 
 * Fichier: elementComz.cpp
 * Auteur: julien
 */


 #include "elementComz.h"
#include <iostream>


//Methodes par defaut de la classe ElementComz
ElementComz::ElementComz() : ElementCastre() {
}


ElementComz::~ElementComz() {
}


///// Redéfinition du contructeur /////
ElementComz::ElementComz(string* aTexte) : ElementCastre() {
#ifdef DEBUG
		std::cout << "Construction de <ElementComz>" << std::endl;
#endif

	texte = *aTexte;
}

void ElementComz::versFluxIndent(std::ostream& os, int indent) const
{
	os << "<!--" << texte << "-->" << endl << endl;
}

void ElementComz::filsDirectsVersFlux(std::ostream& os, bool recursiver) const
{
    os << "<!--" << texte << "-->";
}