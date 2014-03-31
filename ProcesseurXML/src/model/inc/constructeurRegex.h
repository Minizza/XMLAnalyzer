/* 
 * Fichier: constructeurRegex.h
 * Auteur: nbuisson
 */

#ifndef CONSTRUCTEUR_REGEX_H
#define CONSTRUCTEUR_REGEX_H

//Liste des includes système/libs
#include <string>

#include "enumTypeXSD.h"
#include "enumChoiceSeqEtc.h"

//Liste des espaces de noms utilises 
using namespace std;

/*
 *      La classe ConstructeurRegex blablabla.
 * 
 *      Cette classe appartient à la partie bloblo de notre application.
 *
 */
class ConstructeurRegex{
	
public:
	
	//Constructeur par défaut
	ConstructeurRegex();
	
	//Constructeur par copie 
	ConstructeurRegex(ConstructeurRegex* orig);
	
	//Destructeur par défaut
	virtual ~ConstructeurRegex();


private:

	string regex;
	EnumTypeXSD type;
	EnumChoiceSeqEtc choiceSequence;

};


#endif  /* CONSTRUCTEUR_REGEX_H */