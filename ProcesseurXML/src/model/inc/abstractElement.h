/* 
 * Fichier: abstractElement.h
 * Auteur: nbuisson
 */

#ifndef ABSTRACT_ELEMENT_H
#define ABSTRACT_ELEMENT_H

//Liste des includes système/libs
#include <string>
#include <deque>
#include <map>

//Liste des includes personnels
#include "iAffichable.h"

//Liste des espaces de noms utilises 


/*
 *      La classe AbstractElement blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class AbstractElement : public IAffichable {
	
public:
	
	class iterator;
	
	AbstractElement();
  	AbstractElement(AbstractElement* orig);
	
	/*
	 *  Constructeur abstrait
	 *          
	 *    Paramètres : 
	 *          -String name : le nom de l'élément
	 * 
	 */

	virtual ~AbstractElement();

	virtual bool aDesFils()=0;
	virtual iterator begin()=0;
	virtual iterator end()=0;
	
	std::ostream& versFlux(std::ostream& os) const;
	//J'aurais bien aimé la mettre protégée mais c++ me chie dessus...
	virtual void versFluxIndent(std::ostream& os, int indent) const=0;

	virtual void transformationXSL(AbstractElement* noeudXML, std::ostream& os) const;
	
	virtual bool ValiderXML(std::map<std::string,std::string>& mapRegex) const;
	
	virtual std::string creationRegex(std::map<std::string,std::string>& mapRegex) const;

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
