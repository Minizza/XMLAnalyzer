/* 
 * Fichier: document.cpp
 * Auteur: auteur
 */


 #include "document.h"
#include <iostream>
 #include <assert.h>
 #include <vector>
 
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
 bool Document::validationXSD(const Document& documentXSD) const
 {
 	bool estValide;

	//Creation de la map d'expression regulieres
 	std::map<string, string> mapRegex;
 	string out = documentXSD.racine->creationRegex(mapRegex);

	//Suppression des ref et remplacement par ce a quoi elles font reference
 	for(map<string, string>::iterator it=mapRegex.begin() ; it!=mapRegex.end() ; ++it)
 	{
 		pair<string, string> p = *it;
 		std::string noeud = p.first;
 		RemplacerRefs(noeud, mapRegex);
 	}

	//Match regex/noeuds du document XML
 	estValide = racine->ValiderXML(mapRegex);

 	return estValide;
 }

 string Document::RemplacerRefs(std::string& nom, map<string, string>& mapRegex) const
 {
 	string::size_type posBegin = mapRegex[nom].find_first_of("@");
 	if (posBegin != string::npos) {

 		string regex = "";
 		vector<string> ref;
		//On split la chaine selon "@"
 		string::size_type posEnd = mapRegex[nom].find("@", posBegin);
 		while(posEnd != string::npos) {
 			string refCourante = mapRegex[nom].substr(posBegin+1, posEnd-posBegin-1);
 			ref.push_back(refCourante);
 			posBegin = posEnd;
 			posEnd = mapRegex[nom].find("@", posBegin+1);
 		}

 		for(int i = 0 ; i < ref.size() ; i++) {
 			if (mapRegex.count(ref[i]) > 0) {
 				regex = RemplacerRefs(ref[i], mapRegex);
 				mapRegex[nom].replace(mapRegex[nom].find_first_of("@"), ref[i].size()+2, "("+regex+")");
 			} else {
 				//inquiétant ?
 			}
 		}
 	}

 	return mapRegex[nom];
 }

 ostream& operator<<(ostream& os, const Document& doc)
 {
 	doc.versFlux(os);
 }

