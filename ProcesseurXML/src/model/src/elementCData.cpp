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
ElementCData::ElementCData(string* aTexte) : ElementCastre(new string("")) {
#ifdef DEBUG
		std::cout << "Construction de <ElementCData>" << std::endl;
#endif

	texte = *aTexte;
}

std::ostream& ElementCData::versFlux(std::ostream& os) const
{
	os << "<![CDATA[" << texte << "]]>\n";
}
