#ifndef COMMUN_H
#define COMMUN_H

#include <deque>
#include <string>
using namespace std;

#include "abstractElement.h"
#include "elementNoeud.h"
#include "elementComz.h"
#include "elementDonnees.h"

#include "abstractAttribut.h"
#include "attributString.h"

#include "doctype.h"

//#define DEBUG
#ifdef DEBUG
#define debug(x) (x)
#else
#define debug(x) ((void) 0)
#endif

#endif
