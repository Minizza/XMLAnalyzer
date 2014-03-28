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

	void xmlerror(Document** datDoc,const char * msg)
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

    %parse-param {Document** datDoc}

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
	: header element {*datDoc = new Document($1, $2);}
	;

	header
	: headerdoc headerpart {$$ = new EnTete(0, $1, $2);}
    |/**/{$$=NULL;}
	;

	headerpart //il faut vérifier qu'on a bien la version du xml
	: headerpart pi {$$ = $1; $$->push_front($2);}
	| headerpart commentaire {$$ = $1; $$->push_front($2);}
    | /*vide*/{$$=new deque<AbstractElement*>();}
	;

	headerdoc
	: DOCTYPE {$$ = new Doctype(new string("doctype"), new string("none"), new string("none"));}
	| /*vide*/{$$=NULL;}
	;

	pi
	:INFSPECIAL NOM attributs SUPSPECIAL {$$ = new ElementPI(new string($2), $3);}
	;

	element
	: INF NOM attributs SUP content INF SLASH NOM SUP {$$ = new ElementNoeud(new string($2), $3, $5);}
	| emptytag
	;

	emptytag
	: INF NOM attributs SLASH SUP {$$ = new ElementNoeud(new string($2), $3, 0);}
	;

	content
	: content element {$$ = $1; $$->push_front($2);}
	| content DONNEES {$$ = $1; $$->push_front(new ElementDonnees(new string($2)));}	
	| content commentaire {$$ = $1; $$->push_front($2);}
	| content CDATABEGIN CDATAEND {$$ = $1; $$->push_front(new ElementCData(new string($3)));}
	| /* vide */{$$=new deque<AbstractElement*>();}
	;

	attributs
	: attributs attribut {$$ = $1; $$->push_front($2);}
	| /* vide */{$$=new deque<AbstractAttribut*>();}
	;

	attribut
	: NOM EGAL VALEUR {$$ = new AttributString(new string($1), new string($3));}
	;

	commentaire
	: COMMENT {$$ = new ElementComz(new string($1));}
	;
%%
