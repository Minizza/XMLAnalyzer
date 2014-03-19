/* 
 * Fichier: abstractElement.h
 * Auteur: nbuisson
 */

#ifndef ABSTRACT_ELEMENT_H
#define ABSTRACT_ELEMENT_H

//Liste des includes système/libs
#include <string>

//Liste des espaces de noms utilises 
using namespace std;

/*
 *      La classe AbstractElement blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class AbstractElement {
	
public:

	AbstractElement(){};
	
	/*
	 *  Constructeur abstrait
	 *          
	 *    Paramètres : 
	 *          -String name : le nom de l'élément
	 * 
	 */
	AbstractElement(string& aNom){nom = aNom;};

	virtual ~AbstractElement()=0;

protected:
	string nom;
};

<<<<<<< HEAD
#endif  /* ABSTRACT_ELEMENT_H */
=======


#endif  /* ABSTRACT_ELEMENT_H */
>>>>>>> aabc5f9b1603ea03dff376617fab18a45457918f
