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
ElementComz::ElementComz(string* aNom,string* aTexte) : ElementCastre(aNom) {
#ifdef DEBUG
		std::cout << "Construction de <ElementComz>" << std::endl;
#endif
	nom = *aNom;
	texte = *aTexte;
}

std::ostream& ElementComz::versFlux(std::ostream& os) const
{
	os << "<!--" << texte << "-->\n";
}
