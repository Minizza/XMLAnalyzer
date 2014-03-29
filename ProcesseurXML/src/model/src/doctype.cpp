/* 
 * Fichier: doctype.cpp
 * Auteur: julien
 */

 #include "doctype.h"
#include <iostream>

 Doctype::Doctype(string* aNom, string* aType, deque<string*>* aListOfStrings){
#ifdef DEBUG
  std::cout << "Construction de <Doctype>" << std::endl;
#endif
  nom = *aNom;
  values = *aListOfStrings;
  type = *aType;
}
Doctype::~Doctype(){}


std::ostream& Doctype::versFlux(std::ostream& os) const
{
	os << "<!DOCTYPE " << nom;
	if(!this->type.empty())
	{
		os << " " << this->type;
	}
	for(deque<string*>::const_iterator it = values.begin(); it != values.end(); it++)
	{
		string* value = *it;
		os << " \"" << *value << "\"";
	}
	os << ">" << endl;
}