/* 
 * Fichier: elementDonnees.cpp
 * Auteur: auteur
 */


 #include "elementDonnees.h"
#include <iostream>


//Methodes par defaut de la classe ElementDonnees
ElementDonnees::ElementDonnees() : ElementCastre() {
}

ElementDonnees::~ElementDonnees() {
}

///// Redéfinition du contructeur /////
ElementDonnees::ElementDonnees(string* aTexte)  : ElementCastre() {
	#ifdef DEBUG
		std::cout << "Construction de <ElementDonnees>" << std::endl;
	#endif
	texte = *aTexte;
}

void ElementDonnees::versFluxIndent(std::ostream& os, int indent) const
{
	indenter(os, indent);
	os << texte << endl;
}

// Méthdode utilisée pour la transformationXSL
void ElementDonnees::obtenirDonnees(std::ostream& os) const
{
    os << texte;
}

void ElementDonnees::transformationXSL(AbstractElement* noeudXML, std::ostream& os) const
{
    os << texte;
}
