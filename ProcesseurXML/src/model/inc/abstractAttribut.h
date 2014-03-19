/* 
 * Fichier: abstractAttribut.h
 * Auteur: nbuisson
 */

#ifndef ABSTRACT_ATTRIBUT_H
#define ABSTRACT_ATTRIBUT_H

//Liste des includes système/libs
#include <string>
 

//Liste des espaces de noms utilises 
 using namespace std;

namespace daxml
{
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

}

#endif  /* ABSTRACT_ATTRIBUT_H */