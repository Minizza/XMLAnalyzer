/* 
 * Fichier: attributInt.h
 * Auteur: nbuisson
 */

#ifndef ATTRIBUT_INT_H
#define ATTRIBUT_INT_H

//Liste des includes système/libs
#include "abstractAttribut.h"


//Liste des espaces de noms utilises 


/*
 *      La classe AttributInt blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class AttributInt: public AbstractAttribut{
    
public:
    
    //Methodes de base de la classe AttributInt
    AttributInt(){};
    
    AttributInt(const AttributInt& orig);
    
    virtual ~AttributInt();

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
    AttributInt(int aValue){value = aValue;};

    void valeurVersFlux(ostream& os) const;

private:

    int value;
};


#endif  /* ATTRIBUT_INT_H */