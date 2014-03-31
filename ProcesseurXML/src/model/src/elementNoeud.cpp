/* 
 * Fichier: elementNoeud.cpp
 * Auteur: julien
 */

#include "elementNoeud.h"
#include <iostream>
#include <sstream>
#include <regex>

//Methodes par defaut de la classe ElementNoeud
 ElementNoeud::ElementNoeud() : ElementBurne() 
 {
 }

 ElementNoeud::ElementNoeud(ElementNoeud* orig) 
 {
 	nom = orig->nom;
 	estXSD = orig->estXSD;
 	enfants = orig->enfants;
	//regFils = new Constructeurreg(orig->regFils);
 }

 ElementNoeud::~ElementNoeud() 
 {
	//delete(regFils);
 }


///// Redéfinition du contructeur /////
 ElementNoeud::ElementNoeud(NomCanonique* aNom, deque<AbstractAttribut*>* aAtts, deque<AbstractElement*>* aEnfants): ElementBurne(aNom, aAtts), enfants(*aEnfants)
 {
	#ifdef DEBUG
 	std::cout << "Construction de <ElementNoeud>" << std::endl;
	#endif
 }

/*Constructeurreg* ElementNoeud::getreg() {
	return regFils;
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
	os << "<" << nom;
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
	os << "</" << nom << ">\n";
}

void ElementNoeud::transformationXSL(AbstractElement* noeudXML, std::ostream& os) const
{
	return;
// todo
}

string ElementNoeud::creationRegex(map<string,string>& mapreg) const
{
	string reg = "";
	if (AbstractAttribut* att = getAttribut("name")) {
		ostringstream oss;
		att->valeurVersFlux(oss);
		reg += "<"  + oss.str() + ">";

		cout << oss.str() << endl;
	}

	if (!enfants.empty()) 
	{


		for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
		{
			AbstractElement* elt = *it;
			reg += elt->creationRegex(mapreg);
		}
	} 
	else
	{


		if (nom.getNom() == "complexType") 
		{
			for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
			{
				AbstractElement* elt = *it;
				reg += elt->creationRegex(mapreg);
			}
		}
		else if (getAttribut("ref")) 
		{
			AbstractAttribut* ref = getAttribut("ref");
			AbstractAttribut* min = getAttribut("minOccurs");
			AbstractAttribut* max = getAttribut("maxOccurs");
			ostringstream oss;


			oss << "@";
			ref->valeurVersFlux(oss);
			oss << "@";

			if (min && max) 
			{		
				oss << "{";
				min->valeurVersFlux(oss);
				oss << ", ";
				max->valeurVersFlux(oss);
				oss << "}";
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
			reg = oss.str();
		}
		else if (nom.getNom() == "sequence") 
		{
			reg += "(";
				for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
				{
					AbstractElement* elt = *it;
					reg += elt->creationRegex(mapreg);
				}
				reg += ")";
		} 
		else if (nom.getNom() == "choice") 
		{
				cout << "toupoutou" << endl;
		reg += "(";
			for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
			{
				AbstractElement* elt = *it;
				reg += elt->creationRegex(mapreg);
				reg += "|";
			}
			reg.erase(reg.end());
			reg += ")";
		}
		else
		{
			reg += ".*";
			for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
			{
				AbstractElement* elt = *it;
				reg += elt->creationRegex(mapreg);
			}
		}

	}

	if (AbstractAttribut* att = getAttribut("name")) {
			ostringstream oss;
			att->valeurVersFlux(oss);
			string name = oss.str();
			reg += "</"  + name + ">";

			mapreg[name] = reg;
	}

	return reg;
}

bool ElementNoeud::ValiderXML(map<string,string>& mapreg) const
{
    ostringstream os;
    this->filsDirectsVersFlux(os);

	return true;
	// todo
}

void ElementNoeud::filsDirectsVersFlux(std::ostream& os, bool recursiver) const
{
    os << "<" << nom;
    for(deque<AbstractAttribut*>::const_iterator it = atts.begin(); it != atts.end(); it++)
    {
        AbstractAttribut* att = *it;
        att->versFlux(os);
    }
    os << ">";
    for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
    {
        AbstractElement* elt = *it;
        elt->filsDirectsVersFlux(os, false);
    }
    os << "</" << nom << ">";
}