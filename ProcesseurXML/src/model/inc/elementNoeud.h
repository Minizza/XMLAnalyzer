/* 
 * Fichier: elementNoeud.h
 * Auteur: nbuisson
 */

#ifndef ELEMENT_NOEUD_H
#define ELEMENT_NOEUD_H

//Liste des includes système/libs
 #include <string>
 #include <deque>
 #include <map>
 #include <regex>

 #include "abstractElement.h"
 #include "elementBurne.h"
 #include "enTete.h"
 #include "constructeurRegex.h"

//Liste des espaces de noms utilises 


/*
 *      La classe ElementNoeud représente tout élément étant un noeud d'un document XML.
 * 
 *      Cette classe hérite de la classe ElementBurne.
 *
 */
 class ElementNoeud : public ElementBurne{
    
public:
    
    //Constructeur par défaut
    ElementNoeud();
    
    //Constructeur par copie
    ElementNoeud(ElementNoeud* orig);
    
    //Destructeur par défaut
    virtual ~ElementNoeud();

    /*
     *  Redéfinition du constructeur
     *          
     *    Paramètres : 
     *          -NomCanonique* aNom : le pointeur vers le nom canonique de l'objet.
     *          -deque<AbstractAttribut*>* aAtts : la deque des attributs de l'élément
     *          -deque<AbstractElement*>* aEnfants : la deque des enfants du noeud.
     * 
     */
     ElementNoeud(NomCanonique* nom, deque<AbstractAttribut*>* aAtts, deque<AbstractElement*>* aEnfants);


     //ConstructeurRegex getRegex();
		
		// Méthodes héritées
		virtual bool aDesFils() { return enfants.size() > 0; }
		virtual AbstractElement::iterator begin() { return AbstractElement::iterator(enfants.begin()); } 
		virtual AbstractElement::iterator end() { return AbstractElement::iterator(enfants.end()); }


    void ajouterFils(AbstractElement* aFils);

  /*
   *  Méthode virtuelle transformationXSL
   *    méthode permettant de transformer l'élément XML en élément XSL
   *
   *    Paramètres : 
   *      -AbstractElement* noeudXML : le noeud XML supérieur à l'élément présent
   *      -ostream& os : passage par référence du flux de sortie
   */
    virtual void transformationXSL(AbstractElement* noeudXML, AbstractElement* racineXSL, std::ostream& os) const;

	virtual string creationRegex(map<string,string>& mapRegex) const;
	
    virtual bool ValiderXML(map<string,string>& mapRegex) const;
    
	void filsDirectsVersFlux(std::ostream& os, bool recursiver=true) const;

protected:

    //void construireRegex(ConstructeurRegex& regex);

    /*
     *  Méthode versFluxIndent
     *      méthode analogue à versFlux, mais dans laquelle on spécifie une indentation
     *
     *      Paramètres : 
     *          -ostream& os : passage par référence du flux de sortie
     *      -int ident : entier spécifiant l'indentation à utiliser
     */
    virtual void versFluxIndent(std::ostream& os, int indent) const;

private:

   bool estXSD;
   deque<AbstractElement*> enfants;
   ConstructeurRegex* regexFils;
   string namespaceName;

   void nomVersFlux(ostream& os) const;
};


#endif  /* XML_DECL_H */
