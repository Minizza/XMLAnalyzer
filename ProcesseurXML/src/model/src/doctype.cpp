/* 
 * Fichier: doctype.cpp
 * Auteur: julien
 */

 #include "doctype.h"
#include <iostream>

Doctype::~Doctype()
{
	for(deque<string*>::iterator it = values.begin(); it != values.end(); delete *(it++));
}

 Doctype::Doctype(string* aNom, string* aType, deque<string*>* aListOfStrings){
#ifdef DEBUG
  std::cout << "Construction de <Doctype>" << std::endl;
#endif
  nom = *aNom;
  values = *aListOfStrings;
  type = *aType;
  delete aNom;
  delete aType;
  delete aListOfStrings;
}


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