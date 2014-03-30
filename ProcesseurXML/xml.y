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
        deque<string*>* values;
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

	%type <abstrElements> content headerparts 
	%type <comz> commentaire
	%type <noeud> element emptytag
	%type <pi> pi
    %type <values> values
    %type <s> dttype
    %type <abstrEle> headerpart

	%type <abstrAttr> attributs
	%type <attrString> attribut

    %expect 2

	%%

	document
	: header element {*datDoc = new Document($1, $2);}
	;

	header
	: headerparts headerdoc headerparts{
        //first deque 123
        //last deque 456
        //get it, iterator on 4
        deque<AbstractElement*>::iterator it = $3->begin();
        //insert before it the first deque
        $3->insert(it,$1->begin(),$1->end());
        $$ = new EnTete($2, $3,$1->size());
    }
	;

	headerparts //il faut vérifier qu'on a bien la version du xml
	: headerparts headerpart {$$ = $1; $$->push_back($2);}
    | /*vide*/{$$=new deque<AbstractElement*>();}
	;

    headerpart
    :pi{$$=$1;}
    |commentaire{$$=$1;}
    ;

	headerdoc
	: DOCTYPE NOM dttype values SUP{$$ = new Doctype(new string($2),new string($3),$4);}
	| /*vide*/{$$=NULL;}
	;

    values
    :values VALEUR{$$ = $1; $$->push_back(new string($2));}
    |/*vide*/{$$=new deque<string*>();}
    ;

    dttype
    :NOM {$$=$1;}
    |/*vide*/{$$=NULL;}
    ;

	pi
	:INFSPECIAL NOM attributs SUPSPECIAL {$$ = new ElementPI(new string($2), $3);}
	;

	element
	: INF NOM attributs SUP content INF SLASH NOM SUP 
	{
		$$ = new ElementNoeud(new string($2), $3, $5, new string("")); 
		if(strcmp($2,$8) != 0) 
		{
			fprintf(stderr, "Non matching element names %s and %s\n", $2, $8);
		}
	}
	| INF NOM COLON NOM attributs SUP content INF SLASH NOM COLON NOM SUP 
	{
		$$ = new ElementNoeud(new string($4), $5, $7, new string($2)); 
		if(strcmp($2,$10) != 0) 
		{
			fprintf(stderr, "Non matching element namespaces %s and %s\n", $2, $10);
		}
		if(strcmp($4,$12) != 0) 
		{
			fprintf(stderr, "Non matching element names %s and %s\n", $4, $12);
		}
	}
	| emptytag
	;

	emptytag
	: INF NOM attributs SLASH SUP {$$ = new ElementNoeud(new string($2), $3, 0, new string(""));}
	;

	content
	: content element {$$ = $1; $$->push_back($2);}
	| content DONNEES {$$ = $1; $$->push_back(new ElementDonnees(new string($2)));}	
	| content commentaire {$$ = $1; $$->push_back($2);}
	| content CDATABEGIN CDATAEND {$$ = $1; $$->push_back(new ElementCData(new string($3)));}
	| /* vide */{$$=new deque<AbstractElement*>();}
	;

	attributs
	: attributs attribut {$$ = $1; $$->push_back($2);}
	| /* vide */{$$=new deque<AbstractAttribut*>();}
	;

	attribut
	: NOM EGAL VALEUR {$$ = new AttributString(new string($1), new string($3));}
	;

	commentaire
	: COMMENT {$$ = new ElementComz(new string($1));}
	;
%%
