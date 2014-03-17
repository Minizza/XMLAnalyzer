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
	: element 
	;

	element
	: INF NOM SUP content
	INF SLASH NOM SUP
	| emptytag
	;

	emptytag
	: INF NOM attributs SLASH SUP
	;

	content
	: content element
	| content DONNEES
	| /* vide */
	;

	attributs
	: attributs attribut
	| /* vide */
	;

	attribut
	: NOM EGAL VALEUR
	;
