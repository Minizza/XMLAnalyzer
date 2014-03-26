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

	/*
	 *  Ololol : Méthode de poutpout
	 *          
	 *    Paramètres : 
	 *          -Golum* pouet : passage du device servant à gérer
	 *                  l'affichage de la fenêtre
	 *          -Prout* crottin : passage du driver servant à importer 
	 *                  les textures et les modèles
	 *    Retour : 
	 *          - int : bouboubou
	 * 
	 */
	 int Ololol(int pouet, char crottin);

     virtual std::ostream& versFlux(std::ostream& os) const;

     std::string transformationXSL(AbstractElement* noeudXSL, AbstractElement* noeudXML, std::string& sortie);

	private:
		EnTete* enTete;
		ElementNoeud* racine;
		bool estXSD;

	};


#endif  /* DOCUMENT_H */