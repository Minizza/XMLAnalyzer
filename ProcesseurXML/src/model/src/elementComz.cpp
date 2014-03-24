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
ElementComz::ElementComz(string* aTexte) : ElementCastre(new string("")) {
#ifdef DEBUG
		std::cout << "Construction de <ElementComz>" << std::endl;
#endif

	texte = *aTexte;
}

std::ostream& ElementComz::versFlux(std::ostream& os) const
{
	os << "<!--" << texte << "-->\n";
}
