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
ElementBurne::ElementBurne(NomCanonique* aNom, deque<AbstractAttribut*>* aAtts) : AbstractElement(), atts(*aAtts), nom(*aNom) {
#ifdef DEBUG
		std::cout << "Construction de <ElementBurne>" << std::endl;
#endif
}

/*ConstructeurRegex* ElementBurne::getRegex() {
    return regexFils;
}*/

bool ElementBurne::estVide() const
{
    deque<AbstractAttribut*>::const_iterator it = atts.begin();
    if(it == atts.end()) {
        return true;
    }
    return false;
}

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
