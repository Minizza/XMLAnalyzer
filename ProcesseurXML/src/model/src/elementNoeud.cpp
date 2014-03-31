/* 
 * Fichier: elementNoeud.cpp
 * Auteur: julien
 */

#include "elementNoeud.h"
#include <iostream>
#include <sstream>

//Methodes par defaut de la classe ElementNoeud
ElementNoeud::ElementNoeud() : ElementBurne() {
}

ElementNoeud::ElementNoeud(ElementNoeud* orig) {
	nom = orig->nom;
	estXSD = orig->estXSD;
	enfants = orig->enfants;
	//regexFils = new ConstructeurRegex(orig->regexFils);
}

ElementNoeud::~ElementNoeud() {
	//delete(regexFils);
}


///// Redéfinition du contructeur /////
ElementNoeud::ElementNoeud(NomCanonique* aNom, deque<AbstractAttribut*>* aAtts, deque<AbstractElement*>* aEnfants): ElementBurne(aNom, aAtts), enfants(*aEnfants)
{
	#ifdef DEBUG
		std::cout << "Construction de <ElementNoeud>" << std::endl;
	#endif
}

/*ConstructeurRegex* ElementNoeud::getRegex() {
	return regexFils;
}*/

void ElementNoeud::ajouterFils(AbstractElement* aFils) {
	#ifdef DEBUG
			std::cout << "Ajout d'un fils" << std::endl;
	#endif
	enfants.push_back(aFils);
}

void ElementNoeud::versFluxIndent(std::ostream& os, int indent) const
{
	indenter(os, indent);
	os << "<";
	nomVersFlux(os);
	for(deque<AbstractAttribut*>::const_iterator it = atts.begin(); it != atts.end(); it++)
	{
		AbstractAttribut* att = *it;
		att->versFlux(os);
	}
	os << ">\n";
	for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
	{
		AbstractElement* elt = *it;
		elt->versFluxIndent(os, indent+1);
	}
	indenter(os, indent);
	os << "</";
	nomVersFlux(os);
	os << ">\n";
}

void ElementNoeud::nomVersFlux(ostream& os) const
{
	if(!namespaceName.empty())
	{
		os << namespaceName << ":";
	}
	os << nom;
}

void ElementNoeud::transformationXSL(AbstractElement* noeudXML, std::ostream& os) const
{
	return;
	// todo
}

string ElementNoeud::creationRegex(map<string,string>& mapRegex) const
{
	string regex = "";
	
	if (nom.getNom() != "") {
		regex += '<' + nom.getNamespace() + ":" + nom.getNom() + '>';
	}

	if (!enfants.empty()) 
	{
		regex += ".*";
	} 
	else if (enfants.empty()) 
	{
		for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
		{
			AbstractElement* elt = *it;
			regex += elt->creationRegex(mapRegex);
		}
	}
	else if (nom.getNom() == "complexType") 
	{
		for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
		{
			AbstractElement* elt = *it;
			regex += elt->creationRegex(mapRegex);
		}
	} 
	else if (getAttribut("ref")) 
	{
		AbstractAttribut* min = getAttribut("minOccurs");
		AbstractAttribut* max = getAttribut("minOccurs");
		ostringstream oss;
		if (min && max) 
		{		
			oss << "{";
			min->valeurVersFlux(oss);
			oss << ", ";
			max->valeurVersFlux(oss);
			oss << "}";
			//TODO se servir de attribut.valeurVersFlux et d'un ostringstream !!!
		} 
		else if (min) 
		{
			oss << "{";
			min->valeurVersFlux(oss);
			oss << ",}";
		} 
		else if (max) 
		{
			oss << "{1, ";
			max->valeurVersFlux(oss);
			oss << "}";
		}
		regex = oss.str();
	}
	else if (nom.getNom() == "sequence") 
	{
		regex += "(";
		for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
		{
			AbstractElement* elt = *it;
			regex += elt->creationRegex(mapRegex);
		}
		regex += ")";
	} 
	else if (nom.getNom() == "choice") 
	{
		regex += "(";
		for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
		{
			AbstractElement* elt = *it;
			regex += elt->creationRegex(mapRegex);
			regex += "|";
		}
		regex.erase(regex.end());
		regex += ")";
	}
	
	return regex;
}

bool ElementNoeud::ValiderXML(map<string,string>& mapRegex) const
{
	return false;
	// todo
}
