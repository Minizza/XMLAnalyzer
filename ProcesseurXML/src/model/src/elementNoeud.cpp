/* 
 * Fichier: elementNoeud.cpp
 * Auteur: julien
 */

#include "elementNoeud.h"
#include <iostream>
#include <sstream>
#include <regex>

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

void ElementNoeud::transformationXSL(AbstractElement* noeudXML, AbstractElement* racineXSL, std::ostream& os) const
{
	if(nom.getNamespace() == "xsl")
	{
		if(nom.getNom() == "value-of")
		{
			std::ostringstream oss;
			getAttribut("select")->valeurVersFlux(oss);
			string select = oss.str();

			if(select == ".") {
				for(AbstractElement::iterator it = noeudXML->begin(); it != noeudXML->end(); it++)
				{
					AbstractElement* eltXml = *it;
					eltXml->donneesVersFlux(os);
				}
			}
			else
			{
				for(AbstractElement::iterator it = noeudXML->begin(); it != noeudXML->end(); it++)
				{
					AbstractElement* eltXml = *it;
					const NomCanonique* nom = eltXml->getNom();
					if(nom && nom->getNom() == select) {
						eltXml->donneesVersFlux(os);
					}
				}
			}
		}
		else if(nom.getNom() == "for-each")
		{
			std::ostringstream oss;
			getAttribut("select")->valeurVersFlux(oss);
			string select = oss.str();

			for(AbstractElement::iterator itXml = noeudXML->begin(); itXml != noeudXML->end(); itXml++)
			{
				AbstractElement* eltXml = *itXml;
				const NomCanonique* nom = eltXml->getNom();
				if(nom && nom->getNom() == select) {
					for(deque<AbstractElement*>::const_iterator itXsl = enfants.begin(); itXsl != enfants.end(); itXsl++)
					{
						AbstractElement* filsXsl = *itXsl;
						filsXsl->transformationXSL(filsXsl, racineXSL, os);
					}
				}
			}
		}
		else if(nom.getNom() == "apply-template" && estVide())
		{
			for(AbstractElement::iterator itXml = noeudXML->begin(); itXml != noeudXML->end(); itXml++)
			{
				AbstractElement* eltXml = *itXml;
				for(AbstractElement::iterator itXsl = racineXSL->begin(); itXsl != racineXSL->end(); itXsl++)
				{
					ElementBurne* eltXsl = (ElementBurne*)*itXsl;
					const NomCanonique* nom = eltXsl->getNom();

					std::ostringstream oss;
					eltXsl->getAttribut("match")->valeurVersFlux(oss);
					string match = oss.str();

					if(nom && nom->getNamespace() == "xsl" && nom->getNom() == "template" && match == nom->getNom())
					{
						eltXsl->transformationXSL(eltXml, racineXSL, os);
					}
				}
			}
		}
		else if(nom.getNom() == "apply-template" && !estVide())
		{
			std::ostringstream oss;
			getAttribut("select")->valeurVersFlux(oss);
			string select = oss.str();

			for(AbstractElement::iterator itXsl = racineXSL->begin(); itXsl != racineXSL->end(); itXsl++)
			{
				ElementBurne* eltXsl = (ElementBurne*)*itXsl;
				const NomCanonique* nomXsl = eltXsl->getNom();

				std::ostringstream oss;
				eltXsl->getAttribut("match")->valeurVersFlux(oss);
				string match = oss.str();	

				if(nomXsl && nomXsl->getNamespace() == "xsl" && nomXsl->getNom() == "template" && match == select)
				{
					for(AbstractElement::iterator itXml = noeudXML->begin(); itXml != noeudXML->end(); itXml++)
					{
						AbstractElement* eltXml = *itXml;
						const NomCanonique* nomXml = eltXml->getNom();
						if(nomXml && nomXml->getNom() == select)
						{
							eltXsl->transformationXSL(eltXml, racineXSL, os);
						}
					}
					break;
				}
			}

		}
		else if(nom.getNom() == "template")
		{
			for(deque<AbstractElement*>::const_iterator itXsl = enfants.begin(); itXsl != enfants.end(); itXsl++)
			{
				AbstractElement* filsXsl = *itXsl;
				filsXsl->transformationXSL(noeudXML, racineXSL, os);
			}
		}
	}
	else {
		os << "<" << nom.getNom();
		for(deque<AbstractAttribut*>::const_iterator it = atts.begin(); it != atts.end(); it++)
		{
			AbstractAttribut* filsAtts = *it;
			filsAtts->versFlux(os);
		}
		os << ">";
		for(deque<AbstractElement*>::const_iterator itXsl = enfants.begin(); itXsl != enfants.end(); itXsl++)
		{
			AbstractElement* filsXsl = *itXsl;
			filsXsl->transformationXSL(noeudXML, racineXSL, os);
		}
		os << "</" << nom.getNom() << ">";
	}
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
