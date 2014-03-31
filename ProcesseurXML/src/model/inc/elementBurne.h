/* 
 * Fichier: elementBurne.h
 * Auteur: julien
 */

#ifndef ELEMENT_BURNE_H
#define ELEMENT_BURNE_H

//Liste des includes système/libs
#include <string>
#include <deque>

#include "abstractElement.h"
#include "abstractAttribut.h"
#include "nomCanonique.h"

//Liste des espaces de noms utilises 
using namespace std;

/*
 *      La classe ElementBurne représente l'ensemble des éléments pouvant avoir des descendants.
 * 
 *      Cette classe hérite de AbstractElement.
 *
 */
class ElementBurne : public AbstractElement{
    
public:
    
    //Constructeur par défaut
    ElementBurne();
    
    //Constructeur par copie
    ElementBurne(ElementBurne* orig);
    
    //Destructeur par défaut
    virtual ~ElementBurne();

    /*
     *  Redéfinition du constructeur
     *          
     *    Paramètres : 
     *          -NomCanonique* aNom : le pointeur vers le nom canonique de l'objet.
     *          -deque<AbstractAttribut*>* aAtts : la deque des attributs de l'élément
     * 
     */
    ElementBurne(NomCanonique* aNom, deque<AbstractAttribut*>* aAtts);

    NomCanonique const * getNom() const { return &nom; }

    AbstractAttribut* getAttribut(std::string attr) const;


protected:
    deque<AbstractAttribut*> atts;
	NomCanonique nom; 
    // Savoir si l'element a des attributs
    bool estVide() const;
    // Retourne un attribut en fonction de son nom. Null si non trouvé.
    
};


#endif  /* ELEMENT_BURNE_H */
