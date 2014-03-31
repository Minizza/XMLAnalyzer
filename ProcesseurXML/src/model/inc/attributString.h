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
 *      La classe AttributString représente un attribut chaine de caractères pour le parsing XML.
 * 
 *      Cette classe hérite de AbstractAttribut.
 */
class AttributString: public AbstractAttribut{
    
public:
    
    //Constructeur par défaut
    AttributString();
    
    //Constructeur par copie
    AttributString(AttributString* orig);
    
    //Destructeur par défaut
    virtual ~AttributString();

    /*
     *  Redéfinition du constructeur
     *          
     *    Paramètres : 
     *          -NomCanonique* aNom : le pointeur vers le nom canonique de l'objet.
     *          -string* aValue : pointeur vers la valeur donnée à l'attribut
     * 
     */
    AttributString(NomCanonique* aNom, string* aValue);

    /*
     *  Méthode valeurVersFlux
     *      n'écrit dans le flux passé en paramètre uniquement la valeur de l'objet.
     *
     *      Paramètres : 
     *          -ostream& os : passage par référence du flux de sortie    
     */
    void valeurVersFlux(ostream& os) const;

private:

    string value;
};


#endif  /* ATTRIBUT_STRING_H */