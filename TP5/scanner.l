%top{
	#include <stdio.h>
	#include "parser.h"
	int errlex;
	char bufferNuevo[200];
}

%option header-file="scanner.h"
%option outfile="scanner.c"
%option yylineno
%option noinput
%option nounput


L 							[[:alpha:]]
D  							[[:digit:]]
LD 							[[:alnum:]]
E  							[[:space:]]
O  							[[:punct:]]{-}[();,+*#=</-]

%%
programa						return PROG;
fin							return FIN;
codigo							return COD;
definir							return DEF;
leer							return LEER;
escribir 						return ESC;
{L}{LD}*						{yylval = strdup(yytext);return ID;}
{D}+							{yylval = strdup(yytext);return CTE;}
"("							return '(';
")"							return ')';
","							return ',';
"+"							return '+';
"-"							return '-';
"*"							return '*';
";"							return ';';
"/"							return '/';
"<="							return ASIG;
{L}{LD}*{O}+({LD}|{O})*					{sprintf(bufferNuevo, "Error léxico: identificador inválido: %s",yytext);yyerror(bufferNuevo);errlex++;}
{D}+{L}+{LD}*						{sprintf(bufferNuevo, "Error léxico: constante inválida: %s",yytext);yyerror(bufferNuevo);errlex++;}
{E}+							|;
"#".*    
{O}+							|
.							{sprintf(bufferNuevo, "Error léxico: cadena desconocida: %s", yytext);yyerror(bufferNuevo);errlex++;}
                                               		
%%																											

