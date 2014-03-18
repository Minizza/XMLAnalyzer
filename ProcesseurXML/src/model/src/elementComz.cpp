/* 
 * Fichier: elementComz.cpp
 * Auteur: julien
 */


 #include "../inc/elementComz.h"


//Methodes par defaut de la classe ElementComz
ElementComz::ElementComz() {
}

ElementComz::ElementComz(const ElementComz& orig) {
	orig.nom = nom;
}

ElementComz::~ElementComz() {
}


///// Redéfinition du contructeur /////
ElementComz::ElementComz(string aNom) {
	nom = aNom;
}