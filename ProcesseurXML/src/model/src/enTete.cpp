/* 
 * Fichier: enTete.cpp
 * Auteur: tim
 */

#include "enTete.h"
#include <iostream>

EnTete::EnTete(int atest)
{
		#ifdef DEBUG
			std::cout << "Construction de <EnTete>" << std::endl;
		#endif
    test=atest;
}

EnTete::~EnTete(){}

EnTete::EnTete(XmlDecl* aDecl, Doctype* aDoctype, deque<AbstractElement*>* aHeaderpart)
{
    decl = aDecl;
    doctype = aDoctype;
    headerpart = *aHeaderpart;
    #ifdef DEBUG
    cout<<"construction de : <EnTete>"<<endl;
    #endif
}


std::ostream& EnTete::versFlux(std::ostream& os) const
{
    if (this->decl)
    {
        this->decl->versFlux(os);
    }
    this->doctype->versFlux(os);
    for(deque<AbstractElement*>::const_iterator it = headerpart.begin();
        it != headerpart.end(); it++)
    {
        AbstractElement* elt = *it;
        cout<<headerpart.size()<<" Yo mama so faaat !"<<endl;   
        elt->versFlux(os);
    }
}