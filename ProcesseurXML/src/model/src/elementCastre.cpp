/* 
 * Fichier: elementCastre.cpp
 * Auteur: tgermain
 */

 #include "elementCastre.h"
 #include <iostream>

 ElementCastre::ElementCastre(ElementCastre* orig){}

 ElementCastre::~ElementCastre(){}


 ElementCastre::ElementCastre() : AbstractElement(){
 #ifdef DEBUG
		std::cout << "Construction de <ElementCastre>" << std::endl;
	#endif
 }
