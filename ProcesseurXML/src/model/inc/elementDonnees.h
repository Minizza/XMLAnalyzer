/* 
 * Fichier: elementDonnees.h
 * Auteur: nbuisson
 */

#ifndef ELEMENT_DONNEES_H
#define ELEMENT_DONNEES_H

//Liste des includes système/libs
#include <string>

#include "elementCastre.h"


//Liste des espaces de noms utilises 
 using namespace std;


/*
 *      La classe ElementDonnees représente un élément de donnée d'un document XML pour le parsing.
 * 
 *      Cette classe hérite de ElementCastre.
 *
 */
class ElementDonnees : public ElementCastre{
	
public:
	
	//Constructeur par défaut
	ElementDonnees();
	
	// Méthodes héritées
	bool aDesFils() { return false; }
	iterator begin() { return AbstractElement::iterator(deque<AbstractElement*>()); } 
	iterator end() { return AbstractElement::iterator(deque<AbstractElement*>()); }
	
    void filsDirectsVersFlux(std::ostream& os, bool recursiver=true) const;
    
	virtual ~ElementDonnees();

	/*
	 *  Redéfinition du constructeur
	 *          
	 *    Paramètres : 
	 *          -string* aTexte : pointeur vers le texte contenu dans une donnée
	 * 
	 */
	ElementDonnees(string* aTexte);

	/*
	 *	Méthode virtuelle transformationXSL
	 *		méthode permettant de transformer l'élément XML en élément XSL
	 *
	 *		Paramètres : 
	 *			-AbstractElement* noeudXML : le noeud XML supérieur à l'élément présent
	 *			-ostream& os : passage par référence du flux de sortie
	 */
	virtual void transformationXSL(AbstractElement* noeudXML, AbstractElement* racineXSL, int indent, std::ostream& os) const;

	
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
	virtual void donneesVersFlux(std::ostream& os) const;


private:
	string texte;
};


#endif  /* ELEMENT_DONNEES_H */
