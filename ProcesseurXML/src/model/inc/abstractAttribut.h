/* 
 * Fichier: abstractAttribut.h
 * Auteur: nbuisson
 */

#ifndef ABSTRACT_ATTRIBUT_H
#define ABSTRACT_ATTRIBUT_H

//Liste des includes système/libs
#include <string>

#include "iAffichable.h"

//Liste des espaces de noms utilises 
 using namespace std;
 
    /*
     *      La classe AbstractAttribut blablabla.
     * 
     *      Cette classe appartient à la partie bloblo de notre application.
     *
     */
class AbstractAttribut : IAffichable{
    
public:
    
    AbstractAttribut();
    AbstractAttribut(AbstractAttribut* orig);
    /*
     *  Constructeur abstrait
     *          
     *    Paramètres : 
     *          -String name : le nom de l'élément
     * 
     */
    AbstractAttribut(string* aNom);

    virtual ostream& versFlux(ostream& os) const;
    virtual void valeurVersFlux(ostream& os) const=0;
    virtual ~AbstractAttribut();

    

protected:
    string nom;
};

#endif  /* ABSTRACT_ATTRIBUT_H */
