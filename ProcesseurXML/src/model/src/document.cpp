/* 
 * Fichier: document.cpp
 * Auteur: auteur
 */


 #include "document.h"
#include <iostream>

//Methodes par defaut de la classe Document
Document::Document() {
}

Document::Document(Document* orig) {
}

Document::~Document() {
}


///// Redéfinition du contructeur /////
<<<<<<< HEAD
Document::Document(EnTete& aEnTete, ElementNoeud& aElementNoeud) {
#ifdef DEBUG
		std::cout << "Construction de <Document>" << std::endl;
#endif
    enTete = &aEnTete;
    racine = &aElementNoeud;
=======
Document::Document(EnTete* aEnTete, ElementNoeud* aElementNoeud) {
    enTete = aEnTete;
    racine = aElementNoeud;
>>>>>>> cb752b3c62130dc9c4a0fa6b9563d3e525f8de55
}


///// Définition de la méthode Ololol /////
int Document::Ololol (int pouet, char crottin) {

    return 0;
}
