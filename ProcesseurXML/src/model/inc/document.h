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
 *      La classe Document blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
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


     virtual std::ostream& versFlux(std::ostream& os) const;

	private:
		EnTete* enTete;
		ElementNoeud* racine;
		bool estXSD;

	};


#endif  /* DOCUMENT_H */