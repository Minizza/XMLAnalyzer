/* 
 * Fichier: elementCastre.cpp
 * Auteur: tgermain
 */

 #include "elementCastre.h"

 ElementCastre::ElementCastre(){};

 ElementCastre::ElementCastre(const ElementCastre& orig);

 ElementCastre::~ElementCastre(){};

 ElementCastre::ElementCastre(string& aNom){
 	AbstractElement(aNom);
 };