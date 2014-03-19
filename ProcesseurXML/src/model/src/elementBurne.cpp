/* 
 * Fichier: elementBurne.cpp
 * Auteur: tgermain
 */

 #include "elementBurne.h"
#include <iostream>

//Methodes par defaut de la classe ElementBurne
ElementBurne::ElementBurne() : AbstractElement() {
}

ElementBurne::ElementBurne(ElementBurne* orig) {

}

ElementBurne::~ElementBurne() {
}


///// Redéfinition du contructeur /////
ElementBurne::ElementBurne(string* aNom, deque<AbstractAttribut*>* aAtts) : AbstractElement(aNom) {
#ifdef DEBUG
		std::cout << "Construction de <ElementBurne>" << std::endl;
#endif
    atts = *aAtts;
}

/*ConstructeurRegex* ElementBurne::getRegex() {
    return regexFils;
}*/
