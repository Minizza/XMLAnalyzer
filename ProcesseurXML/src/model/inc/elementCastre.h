/* 
 * Fichier: elementCastre.h
 * Auteur: nbuisson
 */

#ifndef ELEMENT_CASTRE_H
#define ELEMENT_CASTRE_H

//Liste des includes système/libs
#include <string>

#include "abstractElement.h"

//Liste des espaces de noms utilises 
using namespace std;

/*
 *      La classe ElementCastre blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class ElementCastre : public AbstractElement{
	
public:
	
	//Methodes de base de la classe ElementCastre
	ElementCastre();
	
	ElementCastre(const ElementCastre& orig);
	
	virtual ~ElementCastre();

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
	ElementCastre(string& aNom);

};


#endif  /* ELEMENT_CASTRE_H */