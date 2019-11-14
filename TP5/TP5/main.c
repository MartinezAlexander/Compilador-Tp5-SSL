/*
TP5 - 2019
GRUPO 09

Integrantes:

Bruzzoni, Jose Ignacio: 159.839-9
Gassmann, Melany Carla: 160.480-6
Martínez, Alexander Cristian: 167.109-1
Martos, Ignacio Matías: 164.271-6
*/

#include <stdio.h>
#include "parser.h"
int errSem;

int main() {
	
	switch( yyparse() ){
		case 0:		puts("Compilacion terminada con exito"); printf("Errores sintacticos: %d - Errores léxicos: %d - Errores semanticos: %d\n",yynerrs,errlex, errSem); return 0;

		case 1: 	puts("Errores de compilacion");	printf("Errores sintacticos: %d - Errores lexicos: %d - Errores semanticos: %d\n",yynerrs,errlex,errSem); return 1;

		case 2:		puts("Memoria insuficiente"); 				return 2;
	}	
	return 0;
}



