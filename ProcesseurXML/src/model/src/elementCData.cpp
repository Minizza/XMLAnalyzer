/* 
 * Fichier: elementCData.cpp
 * Auteur: nbuisson
 */


#include "elementCData.h"
#include <iostream>


//Methodes par defaut de la classe ElementCData
ElementCData::ElementCData() : ElementCastre() {
}


ElementCData::~ElementCData() {
}


///// Redéfinition du contructeur /////
ElementCData::ElementCData(string* aTexte) : ElementCastre() {
#ifdef DEBUG
		std::cout << "Construction de <ElementCData>" << std::endl;
#endif

	texte = *aTexte;
}

void ElementCData::versFluxIndent(std::ostream& os, int indent) const
{
	indenter(os, indent);
	os << "<![CDATA[" << texte << "]]>";
}
