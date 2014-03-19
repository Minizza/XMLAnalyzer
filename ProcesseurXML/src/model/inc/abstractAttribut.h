/* 
 * Fichier: abstractAttribut.h
 * Auteur: nbuisson
 */

#ifndef ABSTRACT_ATTRIBUT_H
#define ABSTRACT_ATTRIBUT_H

//Liste des includes système/libs
#include <string>
<<<<<<< HEAD
 

//Liste des espaces de noms utilises 
 using namespace std;
=======

>>>>>>> 4afec1f152d935f926b4c845f6d6b23f7fe5b177

//Liste des espaces de noms utilises 
 using namespace std;
 
    /*
     *      La classe AbstractAttribut blablabla.
     * 
     *      Cette classe appartient à la partie bloblo de notre application.
     *
     */
class AbstractAttribut {
    
public:
    
    /*
     *  Constructeur abstrait
     *          
     *    Paramètres : 
     *          -String name : le nom de l'élément
     * 
     */
    virtual AbstractAttribut(string& aNom);

    virtual ~AbstractAttribut();

    

protected:
    string nom;
};

#endif  /* ABSTRACT_ATTRIBUT_H */
