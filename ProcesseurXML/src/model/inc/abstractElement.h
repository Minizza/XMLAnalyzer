/* 
 * Fichier: abstractElement.h
 * Auteur: nbuisson
 */

#ifndef ABSTRACT_ELEMENT_H
#define ABSTRACT_ELEMENT_H

//Liste des includes système/libs
#include <string>
#include <deque>

//Liste des includes personnels
#include "iAffichable.h"

//Liste des espaces de noms utilises 


/*
 *      La classe AbstractElement est une classe abstraite représentant
 *			les différents éléments qui composent un document XML.
 * 
 *      Cette classe implémente l'interface IAffichable.
 *
 */
class AbstractElement : public IAffichable {
	
public:
	
	class iterator;
	
	//Constructeur par défaut
	AbstractElement();

	//Constructeur par copie
  	AbstractElement(AbstractElement* orig);
	
	//Destructeur par défaut
	virtual ~AbstractElement();

	/*
	 *	Méthode virtuelle aDesFils
	 *		renvoie un booléen indiquant si l'élément a des fils ou non
	 */
	virtual bool aDesFils()=0;
	virtual iterator begin()=0;
	virtual iterator end()=0;
	
	/*
     *  Méthode versFlux
     *      écrit dans le flux passé en paramètre tel que l'objet est censé être
     *      dans un document XML
     *
     *      Paramètres : 
     *          -ostream& os : passage par référence du flux de sortie
     *      
     *      Retour :
     *          -ostream& : retourne le flux dans lequel l'affichage de l'objet
     *              a été écrit.    
     */
	std::ostream& versFlux(std::ostream& os) const;
	
	/*
     *  Méthode versFluxIndent
     *      méthode analogue à versFlux, mais dans laquelle on spécifie une indentation
     *
     *      Paramètres : 
     *          -ostream& os : passage par référence du flux de sortie
     *			-int ident : entier spécifiant l'indentation à utiliser
     */
	virtual void versFluxIndent(std::ostream& os, int indent) const=0;

	/*
	 *	Méthode virtuelle transformationXSL
	 *		méthode permettant de transformer l'élément XML en élément XSL
	 *
	 *		Paramètres : 
	 *			-AbstractElement* noeudXML : le noeud XML supérieur à l'élément présent
	 *			-ostream& os : passage par référence du flux de sortie
	 */
	virtual void transformationXSL(AbstractElement* noeudXML, std::ostream& os) const;

	//	Itérateur de l'attribut hérité deque<AbstractElement*>
	class iterator
	{
			public:
				iterator(std::deque<AbstractElement*> listeElements);
				iterator(std::deque<AbstractElement*>::iterator it);
				
				iterator operator++(int)
				{				
					iterator copie = iterator(it);
					it++;
					return copie;
				}
				
				bool operator==(const iterator& autre) const
				{
					return this->it == autre.it;
				}
				
				bool operator!=(const iterator& autre) const
				{
					return !operator==(autre);
				}
				
				AbstractElement* operator*() const
				{
					return *it;
				}
				
			private:
				std::deque<AbstractElement*>::iterator it;
			
	};

protected:
	void indenter(std::ostream& os, int indent) const;
	virtual void obtenirDonnees(std::ostream& os) const;
};

#endif  /* ABSTRACT_ELEMENT_H */
