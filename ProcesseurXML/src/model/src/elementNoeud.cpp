/* 
 * Fichier: elementNoeud.cpp
 * Auteur: julien
 */

#include "elementNoeud.h"
#include <iostream>
#include <sstream>

#include <regex.h>  

static bool regex_match(string reg, string stringTest)
{
    regex_t regex;
    int reti;
    char msgbuf[100];

    /* Compile regular expression */
    reti = regcomp(&regex, reg.c_str(), REG_EXTENDED);
    if( reti ){ fprintf(stderr, "Could not compile regex\n"); exit(1); }
    /* Execute regular expression */
    reti = regexec(&regex, stringTest.c_str(), 0, NULL, 0);
    if( !reti ){
            return true;
    }
    else if( reti == REG_NOMATCH ){
            return false;
    }
    else{
            regerror(reti, &regex, msgbuf, sizeof(msgbuf));
            fprintf(stderr, "Regex match failed: %s\n", msgbuf);
            exit(1);
    }
}   

//Methodes par defaut de la classe ElementNoeud
 ElementNoeud::ElementNoeud() : ElementBurne() 
 {
 }

ElementNoeud::ElementNoeud(ElementNoeud* orig) {
	nom = orig->nom;
	estXSD = orig->estXSD;
	enfants = orig->enfants;
	//regexFils = new ConstructeurRegex(orig->regexFils);
}

 ElementNoeud::~ElementNoeud() 
 {
	//delete(regFils);
    //free(regex) dans le map regfree(&regex);
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

void ElementNoeud::nomVersFlux(ostream& os) const
{
	if(!namespaceName.empty())
	{
		os << namespaceName << ":";
	}
	os << nom;
}

void ElementNoeud::transformationXSL(AbstractElement* noeudXML, AbstractElement* racineXSL, int indent, std::ostream& os) const
{
    // cout << nom.getNom() << estVide() << endl;
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
                    indenter(os, indent);
					eltXml->donneesVersFlux(os);
                    os << endl;
				}
			}
			else
			{
				for(AbstractElement::iterator it = noeudXML->begin(); it != noeudXML->end(); it++)
				{
					AbstractElement* eltXml = *it;
					const NomCanonique* nom = eltXml->getNom();
					if(nom && nom->getNom() == select) {
                        indenter(os, indent);
						eltXml->donneesVersFlux(os);
                        os << endl;
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
						filsXsl->transformationXSL(filsXsl, racineXSL, indent, os);
					}
				}
			}
		}
		else if(nom.getNom() == "apply-templates" && estVide())
		{
			for(AbstractElement::iterator itXml = noeudXML->begin(); itXml != noeudXML->end(); itXml++)
			{

				AbstractElement* eltXml = *itXml;

                const NomCanonique* nomXml = eltXml->getNom();

				for(AbstractElement::iterator itXsl = racineXSL->begin(); itXsl != racineXSL->end(); itXsl++)
				{
					ElementBurne* eltXsl = (ElementBurne*)*itXsl;
					const NomCanonique* nomXsl = eltXsl->getNom();

					std::ostringstream oss;
					eltXsl->getAttribut("match")->valeurVersFlux(oss);
					string match = oss.str();

					if(nomXsl && nomXsl->getNamespace() == "xsl" && nomXsl->getNom() == "template" && match == nomXml->getNom())
					{
						eltXsl->transformationXSL(eltXml, racineXSL, indent, os);
					}
				}
			}
		}
		else if(nom.getNom() == "apply-templates" && !estVide())
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
							eltXsl->transformationXSL(eltXml, racineXSL, indent, os);
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
				filsXsl->transformationXSL(noeudXML, racineXSL, indent, os);
			}
		}
	}
	else {
        indenter(os, indent);
        if(nom.getNom() == "br")
        {
            os << "<br/>" << endl;
        }
        else
        {
            os << "<" << nom.getNom();
            for(deque<AbstractAttribut*>::const_iterator it = atts.begin(); it != atts.end(); it++)
            {
                AbstractAttribut* filsAtts = *it;
                filsAtts->versFlux(os);
            }
            os << ">" << endl;
            for(deque<AbstractElement*>::const_iterator itXsl = enfants.begin(); itXsl != enfants.end(); itXsl++)
            {
                AbstractElement* filsXsl = *itXsl;
                filsXsl->transformationXSL(noeudXML, racineXSL, indent+1, os);
            }
            indenter(os, indent);
            os << "</" << nom.getNom() << ">" << endl;
        }
	}
}

string ElementNoeud::creationRegex(map<string,string>& mapreg) const
{
    string reg = "";
    if (AbstractAttribut* att = getAttribut("name")) 
    {
        ostringstream oss;
        att->valeurVersFlux(oss);
        reg += "<"  + oss.str() + ">";
#ifdef DEBUG
        cout << reg << endl;
#endif
    }

        if (nom.getNom() == "complexType") 
        {
            #ifdef DEBUG
            cout << "un complexType !!!!!!!!!!!!" << endl;
            #endif
            for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
            {
                AbstractElement* elt = *it;
                reg += elt->creationRegex(mapreg);
            }
        }
        else if (getAttribut("ref")) 
        {
            #ifdef DEBUG
            cout << "une réf !!!!!!!!!!!!" << endl;
            #endif
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
                oss << ",";
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
                oss << "{1,";
                max->valeurVersFlux(oss);
                oss << "}";
            }
            reg = oss.str();
        }
        else if (nom.getNom() == "sequence") 
        {
            #ifdef DEBUG
            cout << "une séquence !!!!!!!!!!!!" << endl;
            #endif
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
            // cout << "toupoutou" << endl;
            #ifdef DEBUG
            cout << "un choice !!!!!!!!!" << endl;
            #endif
            reg += "(";
             for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
             {
                AbstractElement* elt = *it;
                reg += elt->creationRegex(mapreg);
                reg += "|";
            }
            reg.erase(reg.end()-1);
            reg += ")";
        }
        else
        {
            reg += "[^<&]*";
            for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
            {
                AbstractElement* elt = *it;
                reg += elt->creationRegex(mapreg);
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
    string stringTest = os.str();
    //trouver si le noeud à une regex associée dans mapreg
    map<string,string>::iterator it;
    it=mapreg.find(nom.getNom());
    if (it==mapreg.end())
    {
#ifdef DEBUG
        cout << nom.getNom() << " pas trouvé !!" << endl;
#endif
        return false;
    }
    else
    {
        string reg = mapreg[nom.getNom()];
#ifdef DEBUG
        cout << nom.getNom() << " : " << reg << endl;
        cout << "veut matcher avec : " << stringTest << endl << endl;
#endif
        if(regex_match(reg, stringTest))
        {
            //Traitement sur les fils
            for(deque<AbstractElement*>::const_iterator it = enfants.begin() ; it != enfants.end(); it++)
            {
                AbstractElement* fils = *it;
                fils->ValiderXML(mapreg);
            }
        }
        else
        {
            return false;
        }
    }
}

void ElementNoeud::filsDirectsVersFlux(std::ostream& os, bool recursiver) const
{
    os << "<" << nom << ">";
    for(deque<AbstractElement*>::const_iterator it = enfants.begin(); it != enfants.end(); it++)
    {
        AbstractElement* elt = *it;
        elt->filsDirectsVersFlux(os, false);
    }
    os << "</" << nom << ">";
}