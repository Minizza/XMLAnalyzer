/* 
 * Fichier: document.h
 * Auteur: nbuisson
 */

#ifndef DOCUMENT_H
#define DOCUMENT_H

//Liste des includes système/libs
 #include elementNoeud.h
 #include enTete.h


//Liste des espaces de noms utilises 


/*
 *      La classe Document blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
 class Document {
    
public:
    
    //Methodes de base de la classe Document
    Document();
    
    Document(const Document& orig);
    
    virtual ~Document();

    /*
     *  Redéfinition du constructeur
     *          
     *    Paramètres : 
     *          -EnTete aEnTete : passage de l'entete du document xml
     *          -ElementNoeud aElementNoeud : passage de l'element racine du document xml
     * 
     */
     Document(EnTete aEnTete, ElementNoeud aElementNoeud);

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

private:
    EnTete enTete;
    ElementNoeud elementNoeud;

};


#endif  /* DOCUMENT_H */