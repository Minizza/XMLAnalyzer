/* 
 * Fichier: abstractElement.cpp
 * Auteur: tgermain
 */

#include "abstractAttribut.h"

AbstractAttribut::AbstractAttribut(){}

AbstractAttribut::AbstractAttribut(AbstractAttribut* orig){}

AbstractAttribut::AbstractAttribut(string* aNom){nom = *aNom;}

AbstractAttribut::~AbstractAttribut(){}