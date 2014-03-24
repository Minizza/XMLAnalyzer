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
ElementDonnees::ElementDonnees(string* aNom, string* aTexte)  : ElementCastre(aNom) {
	#ifdef DEBUG
		std::cout << "Construction de <ElementDonnees>" << std::endl;
	#endif

	texte = *aTexte;
}
