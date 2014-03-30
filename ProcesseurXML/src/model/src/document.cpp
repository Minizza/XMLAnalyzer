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

//Valide un document XML a partir de la structure d'un document XSD
bool Document::validationXSD(Document documentXSD) const
{
	bool estValide;
	
	//Creation de la map d'expression regulieres
	std::map<string, string> mapRegex;
	string out = documentXSD.racine.creationRegex(mapRegex);
	
	//Suppression des ref et remplacement par ce a quoi elles font reference
	for(mapRegex::iterator it=mapRegex.begin() ; it!=mapRegex.end() ; ++it)
	{
		this.RemplacerRefs(it->first, mapRegex);
	}
	
	//Match regex/noeuds du document XML
	estValide = racine.ValiderXML(mapRegex);
	
	return estValide;
}

string Document::RemplacerRefs(std::string nom, map mapRegex) const
{
	//TODO
	return;
}

