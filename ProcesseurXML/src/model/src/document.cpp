/* 
 * Fichier: document.cpp
 * Auteur: auteur
 */


 #include "document.h"
#include <iostream>
 #include <assert.h>
 
 using namespace std;

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

bool Document::validationXSD(Document documentXSD) const
{
	bool estValide;
	
	std::map<string, string> mapRegex;
	//TODO
	return estValide;
}

string Document::RemplacerRefs(std::string nom, map mapRegex) const
{
	//TODO
	return;
}

