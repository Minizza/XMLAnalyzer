/* 
 * Fichier: elementDonnees.cpp
 * Auteur: auteur
 */


 #include "../inc/elementDonnees.h"


//Methodes par defaut de la classe ElementDonnees
ElementDonnees::ElementDonnees() {
}

ElementDonnees::ElementDonnees(const ElementDonnees& orig) {
	orig.nom = nom;
}

ElementDonnees::~ElementDonnees() {
}


///// Redéfinition du contructeur /////
ElementDonnees::ElementDonnees(string aNom) {
	nom = aNom;
}