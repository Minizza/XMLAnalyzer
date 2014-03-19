/* 
 * Fichier: elementNoeud.h
 * Auteur: nbuisson
 */

#ifndef ELEMENT_NOEUD_H
#define ELEMENT_NOEUD_H

//Liste des includes système/libs
 #include <string>
 #include <deque>

 #include "abstractElement.h"
 #include "elementBurne.h"
 #include "enTete.h"
 #include "constructeurRegex.h"

//Liste des espaces de noms utilises 


/*
 *      La classe ElementNoeud blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
 class ElementNoeud : public ElementBurne{
    
public:
    
    //Methodes de base de la classe ElementNoeud
    ElementNoeud();
    
    ElementNoeud(ElementNoeud* orig);
    
    virtual ~ElementNoeud();

    /*
     *  Redéfinition du constructeur
     *          
     *    Paramètres : 
     *          -EnTete aEnTete : passage de l'entete du document xml
     *          -ElementNoeud aElementNoeud : passage de l'element racine du document xml
     * 
     */
     ElementNoeud(string* aNom, deque<AbstractAttribut*>* aAtts, deque<AbstractElement*>* aEnfants);


     //ConstructeurRegex getRegex();


protected:

    //void construireRegex(ConstructeurRegex& regex);

private:

   bool estXSD;
   deque<AbstractElement*> enfants;
   ConstructeurRegex* regexFils;
};


#endif  /* XML_DECL_H */