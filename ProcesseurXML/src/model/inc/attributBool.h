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
 *      La classe AttributBool représente un attribut booléen pour le parsing XML.
 * 
 *      Cette classe hérite de AbstractAttribut.
 *
 */
class AttributBool: public AbstractAttribut{
    
public:

    //Constructeur par défaut
    AttributBool(){};
    
    //Constructeur par copie
    AttributBool(const AttributBool& orig);
    
    //Destructeur par défaut
    virtual ~AttributBool();

    /*
     *  Redéfinition du constructeur
     *          
     *    Paramètres : 
     *          -bool aValue : la valeur donnée à l'attribut
     * 
     */
    AttributBool(bool aValue){value = aValue;};

    /*
     *  Méthode valeurVersFlux
     *      n'écrit dans le flux passé en paramètre uniquement la valeur de l'objet.
     *
     *      Paramètres : 
     *          -ostream& os : passage par référence du flux de sortie    
     */
    void valeurVersFlux(ostream& os) const;

private:

    bool value;
};


#endif  /* ATTRIBUT_BOOL_H */