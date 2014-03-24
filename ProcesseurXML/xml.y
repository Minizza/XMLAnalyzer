%{

	#include <stack>
	#include <list>
	#include <cstring>
	#include <cstdio>
	#include <cstdlib>
	using namespace std;
	#include "commun.h"

	extern char xmltext[];

	int xmllex(void);  

	void xmlerror(const char * msg)
	{
		fprintf(stderr,"%s\n",msg);
	}

	%}

	%union {
		char * s;
		deque<AbstractElement*>* abstrElements;
		ElementBurne* elementBurne;
		ElementComz* comz;
		ElementNoeud* noeud;
		deque<AbstractAttribut*>* abstrAttr;
		AttributString* attrString;
		Doctype* doctype;
	}

	%token EGAL SLASH SUP SUPSPECIAL DOCTYPE COLON INFSPECIAL INF CDATABEGIN
	%token <s> VALEUR DONNEES COMMENT NOM CDATAEND
	%type <abstrElements> content
	%type <comz> commentaire
	%type <noeud> element emptytag
	%type <abstrAttr> attributs
	%type <attrString> attribut
	%type <doctype> headerdoc

	%%

	document
	: header element
	;

	header
	: header headerpart
	| header headerdoc
	|/*vide*/
	;

	headerpart //il faut vérifier qu'on a bien la version du xml
	: pi
	| commentaire
	;

	headerdoc
	: DOCTYPE {$$ = new Doctype((string*) "doctype", (string*) "none", (string*) "none");}
	;

	pi
	:INFSPECIAL NOM attributs SUPSPECIAL
	;

	element
	: INF NOM SUP content INF SLASH NOM SUP {}
	| emptytag
	;

	emptytag
	: INF NOM attributs SLASH SUP {$$ = new ElementNoeud((string*) $2, $3, 0);}
	;

	content
	: content element {$$ = $1; $$->push_back($2);}
	| content DONNEES {$$ = $1; $$->push_back(new ElementDonnees((string*) "Données", (string*) $2));}	
	| content commentaire {$$ = $1; $$->push_back($2);}
	| CDATABEGIN CDATAEND
	| /* vide */
	;

	attributs
	: attributs attribut {$$ = $1; $$->push_back($2);}
	| /* vide */
	;

	attribut
	: NOM EGAL VALEUR {$$ = new AttributString((string*) $1, (string*) $3);}
	;

	commentaire
	: COMMENT {$$ = new ElementComz((string*) "commentaire", (string*) $1);}
	;
%%