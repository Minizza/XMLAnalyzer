/* 
 * Fichier: xmlDecl.h
 * Auteur: julien
 */
#ifndef XML_DECL_H
#define XML_DECL_H

//Liste des includes système/libs
#include <string>
#include "iAffichable.h"

//Liste des espaces de noms utilises
using namespace std;

/*
 *      La classe doctype blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class XmlDecl {

public:

   //Methodes de base de la classe XmlDecl
    virtual ~XmlDecl();

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
     XmlDecl(string* aNom, string* aExternalId, string* aIntSubSet);
     
     virtual std::ostream& versFlux(std::ostream& os) const;

private:

    string nom;
    string externalId;
    string intSubSet;

};

#endif /* XML_DECL_H */

