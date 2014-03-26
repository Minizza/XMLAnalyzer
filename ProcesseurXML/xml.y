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

		Document* docXML;
		EnTete* head;		
		Doctype* doctype;

		deque<AbstractElement*>* abstrElements;
		AbstractElement* abstrEle;
		ElementBurne* elementBurne;
		ElementComz* comz;
		ElementNoeud* noeud;
		ElementPI* pi;

		deque<AbstractAttribut*>* abstrAttr;
		AttributString* attrString;
	}

	%token EGAL SLASH SUP SUPSPECIAL DOCTYPE COLON INFSPECIAL INF CDATABEGIN
	%token <s> VALEUR DONNEES COMMENT NOM CDATAEND

	%type <docXML> document
	%type <head> header
	%type <doctype> headerdoc

	%type <abstrElements> content headerpart
	%type <comz> commentaire
	%type <noeud> element emptytag
	%type <pi> pi

	%type <abstrAttr> attributs
	%type <attrString> attribut

	%%

	document
	: header element {$$ = new Document($1, $2);}
	;

	header
	: headerpart headerdoc {$$ = new EnTete(0, $2, $1);}
	| /*vide*/
	;

	headerpart //il faut vérifier qu'on a bien la version du xml
	: headerpart pi {$$ = $1; $$->push_front($2);}
	| headerpart commentaire {$$ = $1; $$->push_front($2);}
    | /*vide*/
	;

	headerdoc
	: DOCTYPE {$$ = new Doctype((string*) "doctype", (string*) "none", (string*) "none");}
	| /*vide*/
	;

	pi
	:INFSPECIAL NOM attributs SUPSPECIAL {$$ = new ElementPI((string*) $2, $3);}
	;

	element
	: INF NOM attributs SUP content INF SLASH NOM SUP {$$ = new ElementNoeud((string*) $2, $3, $5);}
	| emptytag
	;

	emptytag
	: INF NOM attributs SLASH SUP {$$ = new ElementNoeud((string*) $2, $3, 0);}
	;

	content
	: content element {$$ = $1; $$->push_front($2);}
	| content DONNEES {$$ = $1; $$->push_front(new ElementDonnees((string*) $2));}	
	| content commentaire {$$ = $1; $$->push_front($2);}
	| content CDATABEGIN CDATAEND
	| /* vide */
	;

	attributs
	: attributs attribut {$$ = $1; $$->push_front($2);}
	| /* vide */
	;

	attribut
	: NOM EGAL VALEUR {$$ = new AttributString((string*) $1, (string*) $3);}
	;

	commentaire
	: COMMENT {$$ = new ElementComz((string*) $1);}
	;
%%
