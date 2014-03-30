/* 
 * Fichier: enTete.h
 * Auteur: nbuisson
*/

#ifndef EN_TETE_H
#define EN_TETE_H
//Liste des includes système/libs
#include "xmlDecl.h"
#include "doctype.h"
#include "abstractElement.h"
#include "iAffichable.h"


//Liste des espaces de noms utilises 

/*
 *      La classe ElementNoeud blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
*/
 class EnTete : IAffichable {
 public:
     virtual ~EnTete();
     EnTete(XmlDecl* aDecl, Doctype* aDoctype, deque<AbstractElement*>* aHeaderpart,int aIndexOfDT);

     virtual std::ostream& versFlux(std::ostream& os) const;

     /* data */
 private:
    XmlDecl* decl;
    Doctype* doctype;
    deque<AbstractElement*> headerpart;
    //index mean where in the header part list you put the DocType line
    int indexOfDT;
}; 

#endif 
