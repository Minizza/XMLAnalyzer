/* 
 * Fichier: xmlDecl.cpp
 * Auteur: julien
 */

 #include "xmlDecl.h"
#include <iostream>

 XmlDecl::XmlDecl(string* aNom, string* aExternalId, string* aIntSubSet){
 #ifdef DEBUG
		std::cout << "Construction de <XmlDecl>" << std::endl;
	#endif
    nom = *aNom;
    externalId = *aExternalId;
    intSubSet = *aIntSubSet;
 }


 XmlDecl::~XmlDecl()
 {
    
 }

 std::ostream& XmlDecl::versFlux(std::ostream& os) const
 {
    
 }