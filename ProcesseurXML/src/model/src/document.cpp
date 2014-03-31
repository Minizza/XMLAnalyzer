/* 
 * Fichier: document.cpp
 * Auteur: auteur
 */


 #include "document.h"
#include <iostream>
 #include <assert.h>
#include <sstream>

//Methodes par defaut de la classe Document
Document::Document() {
}

Document::Document(Document* orig) {
}

Document::~Document() {
}


///// Redéfinition du contructeur /////
Document::Document(EnTete* aEnTete, ElementNoeud* aElementNoeud) {
    #ifdef DEBUG
        std::cout << "Construction de <Document>" << std::endl;
    #endif
    assert(aElementNoeud!=NULL);
    if (aEnTete)
    {
        enTete = aEnTete;
    }
    racine = aElementNoeud;

}


std::ostream& Document::versFlux(std::ostream& os) const
{
    if (this->enTete)
    {
        this->enTete->versFlux(os);
    }
    this->racine->versFlux(os);
    return os;
}

std::string Document::transformationXSL(const Document& documentXSL)
{
    std::ostringstream os;
    for(AbstractElement::iterator it = documentXSL.racine->begin(); it != documentXSL.racine->end(); it++)
    {
        ElementBurne* elt = (ElementBurne*)*it;
        const NomCanonique* nom = elt->getNom();

        std::ostringstream oss;
        elt->getAttribut("match")->valeurVersFlux(oss);
        string match = oss.str();

        if(nom && nom->getNamespace() == "xsl" && nom->getNom() == "template" && match == "/")
        {   
            elt->transformationXSL(racine, elt, os);
            break;
        }
    }
    return os.str();
}