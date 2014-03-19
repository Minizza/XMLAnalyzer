/* 
 * Fichier: doctype.h
 * Auteur: julien
 */
#ifndef DOCTYPE_H
#define DOCTYPE_H

//Liste des includes système/libs
#include <string>

//Liste des espaces de noms utilises
using namespace std;

/*
 *      La classe doctype blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class Doctype {

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
     Doctype(string& aNom, string& aExternalId, string& aIntSubSet);

private:

    string nom;
    string externalId;
    string intSubSet;

};


