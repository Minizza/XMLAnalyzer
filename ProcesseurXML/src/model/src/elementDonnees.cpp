/* 
 * Fichier: elementDonnees.cpp
 * Auteur: auteur
 */


<<<<<<< HEAD
 #include "elementDonnees.h"
=======
 #include "../inc/elementDonnees.h"
>>>>>>> c53701b77d9fa58f68bbe55c0acde0efc0463c42


//Methodes par defaut de la classe ElementDonnees
ElementDonnees::ElementDonnees() {
}

ElementDonnees::~ElementDonnees() {
}

///// Redéfinition du contructeur /////
ElementDonnees::ElementDonnees(string aNom) {
	nom = aNom;
}