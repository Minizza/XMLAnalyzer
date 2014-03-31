/* 
 * Fichier: attributString.h
 * Auteur: nbuisson
 */

#ifndef ATTRIBUT_STRING_H
#define ATTRIBUT_STRING_H

//Liste des includes système/libs
#include <string>

#include "abstractAttribut.h"


//Liste des espaces de noms utilises 
 using namespace std;


/*
 *      La classe AttributString blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class AttributString: public AbstractAttribut{
    
public:
    
    //Methodes de base de la classe AttributString
    AttributString();
    
    AttributString(AttributString* orig);
    
    virtual ~AttributString();

    /*
     *  Redéfinition du constructeur
     *          
     *    Paramètres : 
     *          -Golum* pouet : passage du device servant à gérer
     *                  l'affichage de la fenêtre
     *          -Prout* crottin : passage du driver servant à importer 
     *                  les textures et les modèles
     * 
     */
    AttributString(string* aNom, string* aValue, string* aNamespace=new string(""));

    void valeurVersFlux(ostream& os) const;

private:

    string value;
};


#endif  /* ATTRIBUT_STRING_H */