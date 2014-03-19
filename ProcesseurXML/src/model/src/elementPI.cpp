/* 
 * Fichier: elementPI.cpp
 * Auteur: julien
 */


 #include "elementPI.h"


//Methodes par defaut de la classe ElementPI
ElementPI::~ElementPI() {
}


///// Redéfinition du contructeur /////
ElementPI::ElementPI(string* aNom, deque<AbstractAttribut>* aAttributs) {
    nom = *aNom;
    attributs = *aAttributs; 

}
