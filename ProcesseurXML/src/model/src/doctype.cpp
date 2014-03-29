/* 
 * Fichier: doctype.cpp
 * Auteur: julien
 */

 #include "doctype.h"
#include <iostream>

 Doctype::Doctype(string* aNom, deque<string*>* aListOfStrings,int aIndexOfDT){
#ifdef DEBUG
  std::cout << "Construction de <Doctype>" << std::endl;
#endif
  nom = *aNom;
  values = *aListOfStrings;
  indexOfDT = aIndexOfDT;
}
Doctype::~Doctype(){}


std::ostream& Doctype::versFlux(std::ostream& os) const
{
    
}