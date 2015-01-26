#include <stdio.h>
#include <stdlib.h>
#include "analyseur_lexical.h"
#include "symboles.h"
#include "analyseur_syntaxique.h"

int uniteCourante;

void T(void) {
	// printf("<T>\n");
	F();
	Tprim();
	// printf("</T>\n");
}

void E(void) {
	// printf("<E>\n");
	T();
	Eprim();
	// printf("</E>\n");
}

void Eprim(void) {
	// printf("<E'>\n");
	if(uniteCourante == PLUS) {
		uniteCourante = yylex();
		E();
	}
	// printf("</E'>\n");
}

void Tprim(void) {
	// printf("<T'>\n");
	// printf("Unite = %d\n", uniteCourante);

	if(uniteCourante == FOIS) {
		uniteCourante = yylex();
		F();
	}
	// printf("</T'>\n");
}

void F(void) {
	// printf("<F>\n");
	// printf("Unite = %d\n", uniteCourante);
	if(uniteCourante == PARENTHESE_OUVRANTE) {
		uniteCourante = yylex();
		E();
		if(uniteCourante == PARENTHESE_FERMANTE)
		{
			uniteCourante = yylex();
		}
		else {
			printf("Syntaxe Error\n");
			exit(-1);
		}
	}
	else {
		if(uniteCourante == NOMBRE) {
			uniteCourante = yylex();
		}
		else {
			printf("Syntax Error\n");
			exit(-1);
		}
	}
	// printf("</F>\n");
}
