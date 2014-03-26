/* 
 * Fichier: elementCData.h
 * Auteur: nbuisson
 */

#ifndef ELEMENT_CDATA_H
#define ELEMENT_CDATA_H

//Liste des includes système/libs
#include <string>

#include "elementCastre.h"


//Liste des espaces de noms utilises 
using namespace std;

/*
 *      La classe ElementCData blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class ElementCData : public ElementCastre{
	
public:
	
	//Methodes de base de la classe ElementCData
	ElementCData();
	
	// Méthodes héritées
	bool aDesFils() { return false; }
	iterator begin() { return AbstractElement::iterator(deque<AbstractElement*>()); } 
	iterator end() { return AbstractElement::iterator(deque<AbstractElement*>()); }
	
	virtual std::ostream& versFlux(std::ostream& os) const;
	
	virtual ~ElementCData();

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
	ElementCData(string* aTexte);

private:

	string texte;
};


#endif  /* ELEMENT_CDATA_H */
