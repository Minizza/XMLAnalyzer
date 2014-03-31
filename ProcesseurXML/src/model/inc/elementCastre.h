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
 *      Cette classe hérite de AbstractElement.
 *
 */
class ElementCastre : public AbstractElement{
	
public:
	
	//Constructeur par défaut
	ElementCastre();
	
	//Constructeur par copie
	ElementCastre(ElementCastre* orig);
	
	//Destructeur par défaut
	virtual ~ElementCastre();

	NomCanonique const * getNom() const { return NULL; }

};


#endif  /* ELEMENT_CASTRE_H */