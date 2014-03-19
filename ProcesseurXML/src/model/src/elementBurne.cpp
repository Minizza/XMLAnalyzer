/* 
 * Fichier: elementBurne.cpp
 * Auteur: tgermain
 */

 #include "elementBurne.h"


//Methodes par defaut de la classe ElementBurne
ElementBurne::ElementBurne() : AbstractElement() {
}

ElementBurne::ElementBurne(const ElementBurne& orig) {

}

ElementBurne::~ElementBurne() {
}


///// Redéfinition du contructeur /////
ElementBurne::ElementBurne(string& aNom, deque<AbstractAttribut*>& aAtts) : AbstractElement(nom) {
    atts = aAtts;
}

/*ConstructeurRegex* ElementBurne::getRegex() {
    return regexFils;
}*/