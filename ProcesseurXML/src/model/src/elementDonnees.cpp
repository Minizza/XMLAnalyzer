/* 
 * Fichier: elementDonnees.cpp
 * Auteur: auteur
 */


 #include "elementDonnees.h"



//Methodes par defaut de la classe ElementDonnees
ElementDonnees::ElementDonnees() {
}

ElementDonnees::~ElementDonnees() {
}

///// Redéfinition du contructeur /////
ElementDonnees::ElementDonnees(string* aNom) {
	nom = aNom;
}