/* 
 * Fichier: elementComz.cpp
 * Auteur: julien
 */


 #include "elementComz.h"



//Methodes par defaut de la classe ElementComz
ElementComz::ElementComz() : ElementCastre() {
}


ElementComz::~ElementComz() {
}


///// Redéfinition du contructeur /////
ElementComz::ElementComz(string* aNom, string* aTexte) {
	nom = *aNom;
	texte = *aTexte;
}