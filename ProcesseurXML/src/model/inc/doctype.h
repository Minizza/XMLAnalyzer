/* 
 * Fichier: doctype.h
 * Auteur: julien
 */
#ifndef DOCTYPE_H
#define DOCTYPE_H

//Liste des includes système/libs
#include <string>
#include "iAffichable.h"
#include <deque>
 
//Liste des espaces de noms utilises
using namespace std;

/*
 *      La classe doctype blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class Doctype : public IAffichable{

public:

   //Methodes de base de la classe Doctype
    virtual ~Doctype();

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
     Doctype(string* aNom, deque<string*>* aListOfStrings,int aIndexOfDT);
     virtual std::ostream& versFlux(std::ostream& os) const;

private:

    string nom;
    int indexOfDT;
    deque<string*> values;
};

#endif /* DOCTYPE_H */

