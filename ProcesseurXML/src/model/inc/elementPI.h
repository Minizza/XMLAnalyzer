/* 
 * Fichier: elementPI.h
 * Auteur: julien
 */

#ifndef ELEMENT_PI_H
#define ELEMENT_PI_H

//Liste des includes système/libs
#include <string>
#include <deque>

#include "elementBurne.h"
#include "abstractAttribut.h"


//Liste des espaces de noms utilises 


/*
 *      La classe ElementPI blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class ElementPI: public ElementBurne{
    
public:
    
    //Methodes de base de la classe ElementPI
    ElementPI();
    
    ElementPI(const ElementPI& orig);
    
    virtual ~ElementPI();

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
    ElementPI(string& aNom, deque<AbstractAttribut>& aAttributs);

private:

    string texte;
    deque<AbstractAttribut> attributs;
};


#endif  /* ELEMENT_PI_H */