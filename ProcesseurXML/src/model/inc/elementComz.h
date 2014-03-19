/* 
 * Fichier: elementComz.h
 * Auteur: nbuisson
 */

#ifndef ELEMENT_COMZ_H
#define ELEMENT_COMZ_H

//Liste des includes système/libs
#include <string>

#include "elementCastre.h"


//Liste des espaces de noms utilises 
using namespace std;

/*
 *      La classe ElementComz blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class ElementComz : public ElementCastre{
	
public:
	
	//Methodes de base de la classe ElementComz
	ElementComz();
	
	
	virtual ~ElementComz();

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
	ElementComz(const string& aNom, const string& aTexte);

private:

	string texte;
};


#endif  /* ELEMENT_COMZ_H */