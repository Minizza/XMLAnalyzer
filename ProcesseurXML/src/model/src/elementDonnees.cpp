/* 
 * Fichier: elementDonnees.cpp
 * Auteur: auteur
 */


 #include "elementDonnees.h"
#include <iostream>


//Methodes par defaut de la classe ElementDonnees
ElementDonnees::ElementDonnees() : ElementCastre() {
}

ElementDonnees::~ElementDonnees() {
}

///// Redéfinition du contructeur /////
ElementDonnees::ElementDonnees(string* aTexte)  : ElementCastre(new string("")) {
	#ifdef DEBUG
		std::cout << "Construction de <ElementDonnees>" << std::endl;
	#endif
	texte = *aTexte;
}

std::ostream& ElementDonnees::versFlux(std::ostream& os) const
{
	os << texte;
}
