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
 *      La classe AttributInt représente un attribut entier pour le parsing XML.
 * 
 *      Cette classe hérite de AbstractAttribut.
 *
 */
class AttributInt: public AbstractAttribut{
    
public:
    
    //Constructeur par défaut
    AttributInt(){};
    
    //Constructeur par copie
    AttributInt(const AttributInt& orig);
    
    //Destructeur par défaut
    virtual ~AttributInt();

    /*
     *  Redéfinition du constructeur
     *          
     *    Paramètres : 
     *          -int aValue : la valeur donnée à l'attribut
     * 
     */
    AttributInt(int aValue){value = aValue;};

    /*
     *  Méthode valeurVersFlux
     *      n'écrit dans le flux passé en paramètre uniquement la valeur de l'objet.
     *
     *      Paramètres : 
     *          -ostream& os : passage par référence du flux de sortie    
     */
    void valeurVersFlux(ostream& os) const;

private:

    int value;
};


#endif  /* ATTRIBUT_INT_H */