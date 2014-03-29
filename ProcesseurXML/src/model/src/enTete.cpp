/* 
 * Fichier: enTete.cpp
 * Auteur: tim
 */

#include "enTete.h"
#include <iostream>


EnTete::~EnTete(){}

EnTete::EnTete(XmlDecl* aDecl, Doctype* aDoctype, deque<AbstractElement*>* aHeaderpart,int aIndexOfDT)
{
    decl = aDecl;
    doctype = aDoctype;
    headerpart = *aHeaderpart;
    indexOfDT=aIndexOfDT;
    #ifdef DEBUG
    cout<<"construction de <EnTete> "<<endl;
    #endif
}


std::ostream& EnTete::versFlux(std::ostream& os) const
{
    if (this->decl)
    {
        this->decl->versFlux(os);
    }

    if (this->doctype)
    {
        this->doctype->versFlux(os);
    }
    for(deque<AbstractElement*>::const_iterator it = headerpart.begin();
        it != headerpart.end(); it++)
    {
        AbstractElement* elt = *it;  
        elt->versFlux(os);
    }
}