/* 
 * Fichier: abstractAttribut.h
 * Auteur: nbuisson
 */

#ifndef ABSTRACT_ATTRIBUT_H
#define ABSTRACT_ATTRIBUT_H

//Liste des includes système/libs
#include <string>

#include "iAffichable.h"
#include "nomCanonique.h"

//Liste des espaces de noms utilises 
 using namespace std;
 
    /*
     *      La classe AbstractAttribut est une classe abstraite représentant les 
     *          différents attributs qui composent un document XML.
     *      Cette classe implémente l'interface IAffichable.
     *
     */
class AbstractAttribut : IAffichable{
    
public:
    
    // Constructeur par défaut
    AbstractAttribut();

    //Constructeur par copie
    AbstractAttribut(AbstractAttribut* orig);

    /*
     *  Constructeur abstrait
     *          
     *    Paramètres : 
     *          -NomCanonique* aNom : le pointeur vers le nom canonique de l'objet.
     * 
     */
    AbstractAttribut(NomCanonique* aNom);

    /*
     *  Méthode virtuelle versFlux
     *      écrit dans le flux passé en paramètre tel que l'objet est censé être
     *      dans un document XML
     *
     *      Paramètres : 
     *          -ostream& os : passage par référence du flux de sortie
     *      
     *      Retour :
     *          -ostream& : retourne le flux dans lequel l'affichage de l'objet
     *              a été écrit.    
     */
    virtual ostream& versFlux(ostream& os) const;

    /*
     *  Méthode virtuelle valeurVersFlux
     *      n'écrit dans le flux passé en paramètre uniquement la valeur de l'objet.
     *
     *      Paramètres : 
     *          -ostream& os : passage par référence du flux de sortie    
     */
    virtual void valeurVersFlux(ostream& os) const=0;

    //Destructeur
    virtual ~AbstractAttribut();

    // getters
    string getNom() const;

protected:
    NomCanonique nom;
};

#endif  /* ABSTRACT_ATTRIBUT_H */
