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
	}

	%token EGAL SLASH SUP SUPSPECIAL DOCTYPE COLON INFSPECIAL INF CDATABEGIN
	%token <s> VALEUR DONNEES COMMENT NOM CDATAEND

	%%

	document
	: header element
	;

	header
	: header headerpart
	|/*vide*/
	;

	headerpart //il faut vérifier qu'on a bien la version du xml
	: pi
	| commentaire
	| DOCTYPE
	;

	pi
	:INFSPECIAL NOM attributs SUPSPECIAL
	;

	element
	: INF NOM SUP content INF SLASH NOM SUP
	| emptytag
	;

	emptytag
	: INF NOM attributs SLASH SUP
	;

	content
	: content element
	| content DONNEES
	| content commentaire
	| CDATABEGIN CDATAEND
	| /* vide */
	;

	attributs
	: attributs attribut
	| /* vide */
	;

	attribut
	: NOM EGAL VALEUR
	;

	commentaire
	: COMMENT {/* $$ = new ElementComz("commentaire", COMMENT); */}
	;
%%