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
 *      La classe ElementCData représente un élément CDATA d'un document XML pour le parsing.
 * 
 *      Cette classe hérite de ElementCastre.
 *
 */
class ElementCData : public ElementCastre{
	
public:
	
	// Constructeur par défaut
	ElementCData();
	
	// Méthodes héritées
	bool aDesFils() { return false; }
	iterator begin() { return AbstractElement::iterator(deque<AbstractElement*>()); } 
	iterator end() { return AbstractElement::iterator(deque<AbstractElement*>()); }
	
	virtual ~ElementCData();

	/*
	 *  Redéfinition du constructeur
	 *          
	 *    Paramètres : 
	 *          -string* aTexte : pointeur vers le texte contenu dans un CDATA
	 * 
	 */
	ElementCData(string* aTexte);

protected:

	/*
     *  Méthode versFluxIndent
     *      méthode analogue à versFlux, mais dans laquelle on spécifie une indentation
     *
     *      Paramètres : 
     *          -ostream& os : passage par référence du flux de sortie
     *			-int ident : entier spécifiant l'indentation à utiliser
     */
	virtual void versFluxIndent(std::ostream& os, int indent) const;

private:

	string texte;
};


#endif  /* ELEMENT_CDATA_H */
