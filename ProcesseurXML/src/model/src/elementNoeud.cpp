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
	regexFils = new ConstructeurRegex(orig->regexFils);
}

ElementNoeud::~ElementNoeud() {
	delete(regexFils);
}


///// Redéfinition du contructeur /////
ElementNoeud::ElementNoeud(string* aNom, deque<AbstractAttribut*>* aAtts, deque<AbstractElement*>* aEnfants): ElementBurne(aNom, aAtts) {
	#ifdef DEBUG
		std::cout << "Construction de <ElementNoeud>" << std::endl;
	#endif
	ElementBurne(aNom, aAtts);
	enfants = *aEnfants;
}

/*ConstructeurRegex* ElementNoeud::getRegex() {
	return regexFils;
}*/
