/* 
 * Fichier: enTete.cpp
 * Auteur: tim
 */

#include "enTete.h"
#include <iostream>


EnTete::~EnTete(){}

EnTete::EnTete(Doctype* aDoctype, deque<AbstractElement*>* aHeaderpart,int aIndexOfDT)
{
    doctype = aDoctype;
    headerpart = *aHeaderpart;
    indexOfDT=aIndexOfDT;
    #ifdef DEBUG
    cout<<"construction de <EnTete> "<<endl;
    #endif
}


std::ostream& EnTete::versFlux(std::ostream& os) const
{

    int index = 0;
    for(deque<AbstractElement*>::const_iterator it = headerpart.begin();
        it != headerpart.end(); it++)
    {
        if(index == indexOfDT && this->doctype)
        {
            this->doctype->versFlux(os);
        }
        AbstractElement* elt = *it;  
        elt->versFlux(os);
        ++index;
    }
    if(index == indexOfDT && this->doctype)
    {
        this->doctype->versFlux(os);
    }
}