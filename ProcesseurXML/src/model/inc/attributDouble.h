/* 
 * Fichier: attributDouble.h
 * Auteur: nbuisson
 */

#ifndef ATTRIBUT_DOUBLE_H
#define ATTRIBUT_DOUBLE_H

//Liste des includes système/libs
#include "abstractAttribut.h"


//Liste des espaces de noms utilises 


/*
 *      La classe AttributDouble représente un attribut double pour le parsing XML.
 * 
 *      Cette classe hérite de AbstractAttribut.
 *
 */
class AttributDouble: public AbstractAttribut{
    
public:
    
    //Constructeur par défaut
    AttributDouble(){};
    
    //Constructeur par copie
    AttributDouble(const AttributDouble& orig);
    
    //Destructeur par défaut
    virtual ~AttributDouble();

    /*
     *  Redéfinition du constructeur
     *          
     *    Paramètres : 
     *          -double aValue : la valeur donnée à l'attribut
     * 
     */
    AttributDouble(double aValue){value = aValue;};

    /*
     *  Méthode valeurVersFlux
     *      n'écrit dans le flux passé en paramètre uniquement la valeur de l'objet.
     *
     *      Paramètres : 
     *          -ostream& os : passage par référence du flux de sortie    
     */
    void valeurVersFlux(ostream& os) const;

private:

    double value;
};


#endif  /* ATTRIBUT_DOUBLE_H */