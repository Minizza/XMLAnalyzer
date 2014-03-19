/* 
 * Fichier: elementPI.cpp
 * Auteur: julien
 */


 #include "../inc/elementPI.h"


//Methodes par defaut de la classe ElementPI
ElementPI::ElementPI() {
}

ElementPI::ElementPI(const ElementPI& orig) {
}

ElementPI::~ElementPI() {
}


///// Redéfinition du contructeur /////
ElementPI::ElementPI(string& aNom, deque<AbstractAttribut>& aAttributs) {
    nom = aNom;
    attributs = aAttributs; 

}
