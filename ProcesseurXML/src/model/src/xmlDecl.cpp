/* 
 * Fichier: xmlDecl.cpp
 * Auteur: julien
 */

 #include "xmlDecl.h"


 XmlDecl::XmlDecl(string& aNom, string& aExternalId, string& aIntSubSet){
    nom = aNom;
    externalId = aExternalId;
    intSubSet = aIntSubSet;
 }


 XmlDecl::~XmlDecl()
 {
    
 }