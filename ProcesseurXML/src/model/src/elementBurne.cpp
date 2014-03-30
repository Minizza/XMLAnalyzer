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

AbstractAttribut* ElementBurne::getAttribut(std::string attrNom) const
{
    for(deque<AbstractAttribut*>::const_iterator it = atts.begin(); it != atts.end(); it++)
    {
        AbstractAttribut* attr = *it;
        if(attr->getNom() == attrNom)
        {
            return attr;
        }
    }
    return NULL;
}