/* 
 * Fichier: doctype.cpp
 * Auteur: julien
 */

 #include "doctype.h"
#include <iostream>

 Doctype::Doctype(string* aNom, string* aExternalId, string* aIntSubSet){
#ifdef DEBUG
		std::cout << "Construction de <Doctype>" << std::endl;
#endif
    nom = aNom;
    externalId = aExternalId;
    intSubSet = aIntSubSet;
 }
 Doctype::~Doctype(){}
