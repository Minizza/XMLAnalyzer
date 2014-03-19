/* 
 * Fichier: xmlDecl.cpp
 * Auteur: julien
 */

 #include "xmlDecl.h"


 Doctype::Doctype(string& aNom, string& aExternalId, string& aIntSubSet){
    nom = aNom;
    externalId = aExternalId;
    intSubSet = aIntSubSet;
 }