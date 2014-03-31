/* 
 * Fichier: elementPI.h
 * Auteur: julien
 */

#ifndef ELEMENT_PI_H
#define ELEMENT_PI_H

//Liste des includes système/libs
#include <string>
#include <deque>

#include "elementBurne.h"
#include "abstractAttribut.h"


//Liste des espaces de noms utilises 


/*
 *      La classe ElementPI blablabla.
 * 
 *      Cette classe hérite de la classe ElementBurne.
 *
 */
class ElementPI: public ElementBurne{
    
public:
    
    //Methodes de base de la classe ElementPI
    virtual ~ElementPI();

    /*
     *  Redéfinition du constructeur
     *          
     *    Paramètres : 
     *          -NomCanonique* aNom : le pointeur vers le nom canonique de l'objet.
     *          -deque<AbstractAttribut*>* aAttributs : la deque des attributs de l'élément
     * 
     */
    ElementPI(NomCanonique* nom, deque<AbstractAttribut*>* aAttributs);
    
    // Méthodes héritées
		bool aDesFils() { return false; }
		iterator begin() { return AbstractElement::iterator(deque<AbstractElement*>()); } 
		iterator end() { return AbstractElement::iterator(deque<AbstractElement*>()); }

        void filsDirectsVersFlux(std::ostream& os, bool recursiver=true) const;
    

protected:
    /*
     *  Méthode versFluxIndent
     *      méthode analogue à versFlux, mais dans laquelle on spécifie une indentation
     *
     *      Paramètres : 
     *          -ostream& os : passage par référence du flux de sortie
     *          -int ident : entier spécifiant l'indentation à utiliser
     */
    virtual void versFluxIndent(std::ostream& os, int indent) const;
    
private:
};


#endif  /* ELEMENT_PI_H */
