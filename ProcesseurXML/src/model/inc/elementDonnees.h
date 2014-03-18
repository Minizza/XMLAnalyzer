/* 
 * Fichier: elementDonnees.h
 * Auteur: nbuisson
 */

#ifndef ELEMENT_DONNEES_H
#define ELEMENT_DONNEES_H

//Liste des includes système/libs
#include <string>

#include "elementCastre.h"
using namespace std;

//Liste des espaces de noms utilises 


/*
 *      La classe ElementDonnees blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class ElementDonnees: public ElementCastre{
	
public:
	
	//Methodes de base de la classe ElementDonnees
	ElementDonnees();
	
	
	virtual ~ElementDonnees();

	/*
	 *  Redéfinition du constructeur
	 *          
	 *    Paramètres : 
	 *          -Golum* pouet : passage du device servant à gérer
	 *                  l'affichage de la fenêtre
	 *          -Prout* crottin : passage du driver servant à importer 
	 *                  les textures et les modèles
	 * 
	 */
	ElementDonnees(string aNom);

private:

	string texte;
};


#endif  /* ELEMENT_DONNEES_H */