/* 
 * Fichier: elementDonnees.cpp
 * Auteur: auteur
 */


 #include "elementDonnees.h"
#include <iostream>


//Methodes par defaut de la classe ElementDonnees
ElementDonnees::ElementDonnees() : ElementCastre() {
}

ElementDonnees::~ElementDonnees() {
}

///// Redéfinition du contructeur /////
<<<<<<< HEAD
ElementDonnees::ElementDonnees(string aNom) : ElementCastre(aNom) {
	#ifdef DEBUG
		std::cout << "Construction de <ElementDonnees>" << std::endl;
	#endif
}
=======
ElementDonnees::ElementDonnees(string* aNom) {
	nom = aNom;
}
>>>>>>> cb752b3c62130dc9c4a0fa6b9563d3e525f8de55
