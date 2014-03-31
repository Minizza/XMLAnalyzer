/* 
 * Fichier: NomCanonique.h
 * Auteur: nbuisson
 */

#ifndef NOM_CANONIQUE_H
#define NOM_CANONIQUE_H

//Liste des includes système/libs
#include <string>


//Liste des includes personnels
#include "iAffichable.h"

//Liste des espaces de noms utilises 

using namespace std;
/*
 *      La classe NomCanonique blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class NomCanonique : public IAffichable {
	
public:
	
	NomCanonique();
  	NomCanonique(NomCanonique* orig);
	
	/*
	 *  Constructeur abstrait
	 *          
	 *    Paramètres : 
	 *          -String name : le nom de l'élément
	 * 
	 */
	NomCanonique(string* aNom, string* aNamespace=new string(""));

	virtual ~NomCanonique();

	
	std::ostream& versFlux(std::ostream& os) const;
	//J'aurais bien aimé la mettre protégée mais c++ me chie dessus...

	const string& getNamespace() const { return namespaceNom; }
	const string& getNom() const { return nom; }

private:
	string namespaceNom;
	string nom;
};

ostream& operator<<(ostream&, const NomCanonique&);

#endif  /* NOM_CANONIQUE_H */
