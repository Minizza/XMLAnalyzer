/* 
 * Fichier: enTete.cpp
 * Auteur: tim
 */

#include "enTete.h"
#include <iostream>

EnTete::EnTete(int atest)
{
		#ifdef DEBUG
			std::cout << "Construction de <EnTete>" << std::endl;
		#endif
    test=atest;
}

EnTete::~EnTete(){}
