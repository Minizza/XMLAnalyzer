/* 
 * Fichier: elementCastre.cpp
 * Auteur: tgermain
 */

 #include "elementCastre.h"

 ElementCastre::ElementCastre() : AbstractElement() {}

 ElementCastre::ElementCastre(ElementCastre* orig){}

 ElementCastre::~ElementCastre(){}


 ElementCastre::ElementCastre(string* aNom) : AbstractElement(aNom){

 };