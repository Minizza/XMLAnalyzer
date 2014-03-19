/* 
 * Fichier: elementComz.cpp
 * Auteur: julien
 */


 #include "elementComz.h"
#include <iostream>


//Methodes par defaut de la classe ElementComz
ElementComz::ElementComz() : ElementCastre() {
}


ElementComz::~ElementComz() {
}


///// Redéfinition du contructeur /////
<<<<<<< HEAD
ElementComz::ElementComz(const string& aNom, const string& aTexte) : ElementCastre(aNom) {
#ifdef DEBUG
		std::cout << "Construction de <ElementComz>" << std::endl;
#endif
=======
ElementComz::ElementComz(const string* aNom, const string* aTexte) {
	nom = aNom;
>>>>>>> cb752b3c62130dc9c4a0fa6b9563d3e525f8de55
	texte = aTexte;
}
