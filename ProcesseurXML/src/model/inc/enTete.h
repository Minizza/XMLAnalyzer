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


//Liste des espaces de noms utilises 

/*
 *      La classe ElementNoeud blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
*/
class EnTete {
public:
     EnTete(int atest);
     virtual ~EnTete();
     EnTete(XmlDecl* aDecl, Doctype* aDoctype, deque<AbstractElement*>* aHeaderpart);

     /* data */
private:
    int test;
    XmlDecl* decl;
    Doctype* doctype;
    deque<AbstractElement*> headerpart;
 }; 

#endif 
