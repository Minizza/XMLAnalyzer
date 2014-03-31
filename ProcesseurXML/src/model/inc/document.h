/* 
 * Fichier: document.h
 * Auteur: nbuisson
 */

#ifndef DOCUMENT_H
#define DOCUMENT_H

//Liste des includes système/libs
 #include "elementNoeud.h"
 #include "enTete.h"
 #include "iAffichable.h"


//Liste des espaces de noms utilises 


/*
 *      La classe Document représente un document XML, composé donc d'une en-tête et d'un corps.
 * 
 *      Cette classe implémente l'interface IAffichable.
 *
 */
 class Document : IAffichable {
 	
 public:
 	
	//Methodes de base de la classe Document
 	Document();
 	
 	Document(Document* orig);
 	
 	virtual ~Document();

	/*
	 *  Redéfinition du constructeur
	 *          
	 *    Paramètres : 
	 *          -EnTete aEnTete : passage de l'entete du document xml
	 *          -ElementNoeud aElementNoeud : passage de l'element racine du document xml
	 * 
	 */
	 Document(EnTete* aEnTete, ElementNoeud* aElementNoeud);

	 /*
     *  Méthode virtuelle versFlux
     *      écrit dans le flux passé en paramètre tel que l'objet est censé être
     *      dans un document XML
     *
     *      Paramètres : 
     *          -ostream& os : passage par référence du flux de sortie
     *      
     *      Retour :
     *          -ostream& : retourne le flux dans lequel l'affichage de l'objet
     *              a été écrit.    
     */
     virtual std::ostream& versFlux(std::ostream& os) const;

	private:
		EnTete* enTete;
		ElementNoeud* racine;
		bool estXSD;

	};


#endif  /* DOCUMENT_H */