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
    //free(regex) dans le map regfree(&regex);
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
	// todo
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