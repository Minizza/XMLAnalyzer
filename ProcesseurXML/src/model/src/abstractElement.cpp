/* 
 * Fichier: abstractElement.cpp
 * Auteur: tgermain
 */

#include "abstractElement.h"

AbstractElement::AbstractElement(){}

AbstractElement::AbstractElement(const AbstractElement& orig){}

AbstractElement::AbstractElement(string* aNom){nom = *aNom;}

AbstractElement::~AbstractElement(){}
