/* 
 * Fichier: elementBurne.cpp
 * Auteur: tgermain
 */

 #include "elementBurne.h"
#include <iostream>

//Methodes par defaut de la classe ElementBurne
ElementBurne::ElementBurne() : AbstractElement(){
}

ElementBurne::ElementBurne(ElementBurne* orig) {

}

ElementBurne::~ElementBurne(){
}


///// Redéfinition du contructeur /////
ElementBurne::ElementBurne(NomCanonique* aNom, deque<AbstractAttribut*>* aAtts) : atts(*aAtts), nom(*aNom) {
#ifdef DEBUG
		std::cout << "Construction de <ElementBurne>" << std::endl;
#endif
}

/*ConstructeurRegex* ElementBurne::getRegex() {
    return regexFils;
}*/
