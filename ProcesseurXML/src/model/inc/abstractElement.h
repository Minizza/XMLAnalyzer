/* 
 * Fichier: abstractElement.h
 * Auteur: nbuisson
 */

#ifndef ABSTRACT_ELEMENT_H
#define ABSTRACT_ELEMENT_H

//Liste des includes système/libs
#include <string>
using namespace std;
//Liste des espaces de noms utilises 

namespace daxml
{
	/*
	 *      La classe AbstractElement blablabla.
	 * 
	 *      Cette classe appartient à la partie bloblo de notre application.
	 *
	 */
	class AbstractElement {
		
	public:
		
		/*
		 *  Constructeur abstrait
		 *          
		 *    Paramètres : 
		 *          -String name : le nom de l'élément
		 * 
		 */
		virtual AbstractElement(string& aNom) = 0;

		virtual ~AbstractElement();

		

	protected:
		string nom;
	};

}

#endif  /* ABSTRACT_ELEMENT_H */