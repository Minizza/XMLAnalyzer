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

   //Destructeur par défaut
    virtual ~Doctype();

    /*
     *  Redéfinition du constructeur
     *          
     *    Paramètres : 
     *          -string* aNom : pointeur sur le nom de l'objet
     *          -string* aType : pointeur sur la string donnant le type du document
     *          -deque<string*>* : pointeur sur la deque de la liste des valeurs du doctype
     * 
     */
     Doctype(string* aNom, string* aType, deque<string*>* aListOfStrings);
     
     /*
     *  Méthode virtuelle versFlux
     *      écrit dans le flux passé en paramètre tel que l'objet est censé être
     *      dans un document XML
     *
     *      Paramètres : 
     *          -ostream& os : passage par référence du flux de sortie
     *      
     *      Retour :
     *          -ostream& : retourne le flux dans lequel l'affichage de l'objet
     *              a été écrit.    
     */
     virtual std::ostream& versFlux(std::ostream& os) const;

private:

    string nom;
    string type;
    deque<string*> values;
};

#endif /* DOCTYPE_H */

