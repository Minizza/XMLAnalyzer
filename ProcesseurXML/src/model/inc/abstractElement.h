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
 *      La classe AbstractElement blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class AbstractElement : IAffichable {
	
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
	AbstractElement(std::string* aNom);

	virtual ~AbstractElement();

	virtual bool aDesFils()=0;
	virtual iterator begin()=0;
	virtual iterator end()=0;
	
	virtual std::ostream& versFlux(std::ostream& os) const=0;

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
	std::string nom;
};

#endif  /* ABSTRACT_ELEMENT_H */
