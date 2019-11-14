#include <stdio.h>
#include <string.h>
#include "symbol.h"
#include "parser.h"

char* tablaSimbolos[500];
int cantidadIdentificadores = 0;
char errores[400];
int errSem;

int buscarIdentificador(char* id){
	int encontro = 0;
	int i = 0;
	while(i<cantidadIdentificadores){
		if(strcmp(id, tablaSimbolos[i])==0){
			encontro = 1;
		}
		i++;
	}
	return encontro;
}

int definirIdentificador(char* id){
	int encontroId = buscarIdentificador(id);	
	if(!encontroId){
		printf("Declare %s,Integer\n", id);
		tablaSimbolos[cantidadIdentificadores] = id;
		cantidadIdentificadores++;
	}else{
		sprintf(errores,"Identificador %s ya declarado\n", id);
		yyerror(errores);
		errSem++;
	}
	return !encontroId;
}

int validarIdentificador(char* id){
	int encontroId = buscarIdentificador(id);
	if(!encontroId){
		sprintf(errores,"Identificador %s no declarado\n", id);
		yyerror(errores);
		errSem++;
	}	
	return encontroId;
} 