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
 *      La classe ElementBurne blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class ElementBurne : public AbstractElement{
    
public:
    
    //Methodes de base de la classe ElementBurne
    ElementBurne();
    
    ElementBurne(ElementBurne* orig);
    
    virtual ~ElementBurne();

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
    ElementBurne(NomCanonique* aNom, deque<AbstractAttribut*>* aAtts);


protected:
    deque<AbstractAttribut*> atts;
	NomCanonique nom; 
    // Savoir si l'element a des attributs
    bool estVide() const;
    // Retourne un attribut en fonction de son nom. Null si non trouvé.
    AbstractAttribut* getAttribut(std::string attr) const;
};


#endif  /* ELEMENT_BURNE_H */
