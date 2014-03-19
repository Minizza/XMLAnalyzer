/* 
 * Fichier: elementNoeud.h
 * Auteur: nbuisson
 */

#ifndef ELEMENT_NOEUD_H
#define ELEMENT_NOEUD_H

//Liste des includes système/libs
 #include <boost/lockfree/queue.hpp>
 #include "elementBurne.h"
 #include "enTete.h"


//Liste des espaces de noms utilises 


/*
 *      La classe ElementNoeud blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
 class ElementNoeud :public ElementBurne{
    
public:
    
    //Methodes de base de la classe ElementNoeud
    ElementNoeud();
    
    ElementNoeud(const ElementNoeud& orig);
    
    virtual ~ElementNoeud();

    /*
     *  Redéfinition du constructeur
     *          
     *    Paramètres : 
     *          -EnTete aEnTete : passage de l'entete du document xml
     *          -ElementNoeud aElementNoeud : passage de l'element racine du document xml
     * 
     */
     ElementNoeud(EnTete& aEnTete, ElementNoeud& aElementNoeud);

private:


};


#endif  /* XML_DECL_H */