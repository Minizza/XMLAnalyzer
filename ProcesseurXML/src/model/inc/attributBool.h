/* 
 * Fichier: attributBool.h
 * Auteur: nbuisson
 */

#ifndef ATTRIBUT_BOOL_H
#define ATTRIBUT_BOOL_H

//Liste des includes système/libs
#include "abstractAttribut.h"


//Liste des espaces de noms utilises 


/*
 *      La classe AttributBool blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class AttributBool: public AbstractAttribut{
    
public:
    
    //Methodes de base de la classe AttributBool
    AttributBool(){};
    
    AttributBool(const AttributBool& orig);
    
    virtual ~AttributBool();

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
    AttributBool(bool aValue){value = aValue;};

    void valeurVersFlux(ostream& os) const;

private:

    bool value;
};


#endif  /* ATTRIBUT_BOOL_H */