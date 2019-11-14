%{
#include <stdio.h>
#include "scanner.h"
#include "symbol.h"
#include "semantic.h"
%}

%code provides {
void yyerror (char const *s);
extern int errSem; 
extern int errlex;
extern int yynerrs;	
}

%defines "parser.h"
%output "parser.c"
%start lenguajeMini 
%define parse.error verbose 
%define api.value.type{char *}
%token FDT PROG FIN COD DEF LEER ESC ID CTE
%token ASIG "<="

%left  '-'  '+'
%left  '*'  '/'
%precedence NEG

%%

lenguajeMini : 		  	PROG {comenzar();} definiciones  COD  codigo {terminar();} FIN {if (errlex+yynerrs > 0) YYABORT;else YYACCEPT;};

definiciones : 			%empty
						| definiciones DEF ID ';'  {if(!definirIdentificador($3)){YYERROR;};}  
						| error';'					;


codigo : 			  	codigo sentencia
                        | sentencia;

sentencia : 		  	 lectura
                        | asignar
						| escritura
						| error';'					;

lectura:				LEER '(' listaIdentificadores')' ';' 	;
 
escritura:				ESC '('listaExpresiones')' ';' 			;

asignar:				id "<=" expresion ';'						{asignar($1,$3);};

listaExpresiones : 	  	 listaExpresiones',' expresion				{escribir($3);}
                        |expresion 									{escribir($1);};

listaIdentificadores : 	  listaIdentificadores',' id 				{leer($3);}
                        | id 										{leer($1);};


expresion : 		  		valor
                        	| '-'expresion %prec NEG	{($$ = negar($2));}
                        	| '('expresion')' 		  {($$ = ($2));}
                        	| expresion '+' expresion {($$ = generarInfijo($1,$3,'+'));}
                        	| expresion '-' expresion {($$ = generarInfijo($1,$3,'-'));}
                        	| expresion '*' expresion {($$ = generarInfijo($1,$3,'*'));}
                        	| expresion '/' expresion {($$ = generarInfijo($1,$3,'/'));}
							| '(' error ')';

valor : 		  			CTE		
                        	| id;

id : 						ID {validarIdentificador($1);};

%%

/* Informa error. */
void yyerror(char const *s){
        printf("linea #%d: %s\n", yylineno, s);
        return;
}
