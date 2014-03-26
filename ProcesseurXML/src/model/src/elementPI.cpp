/* 
 * Fichier: elementPI.cpp
 * Auteur: julien
 */


#include "elementPI.h"
#include <iostream>

//Methodes par defaut de la classe ElementPI
ElementPI::~ElementPI() {
}


///// Redéfinition du contructeur /////
ElementPI::ElementPI(string* aNom, deque<AbstractAttribut*>* aAttributs) : ElementBurne(aNom, aAttributs) {
		#ifdef DEBUG
			std::cout << "Construction de <ElementPI>" << std::endl;
		#endif
}


std::ostream& ElementPI::versFlux(std::ostream& os) const
{
	os << "<?" << nom << "/>\n";
}
