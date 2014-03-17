/* 
 * Fichier: fichier
 * Auteur: auteur
 */

#ifndef DOCUMENT_H
#define DOCUMENT_H

//Liste des includes système/libs


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
     *          -Golum* pouet : passage du device servant à gérer
     *                  l'affichage de la fenêtre
     *          -Prout* crottin : passage du driver servant à importer 
     *                  les textures et les modèles
     * 
     */
     Document(int pouet, char crottin);

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




#endif  /* DOCUMENT_H */