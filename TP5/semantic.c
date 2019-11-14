#include "semantic.h"
#include "symbol.h"
#include <stdio.h>
#include <string.h>

int temporal = 0;
char nombreDelTemporal[100];
char* infijo;

void comenzar(){
	printf("Load rtlib,,\n");
}

void leer(char* id){
	printf("Read %s, Integer\n",id);
}

void escribir(char* id){
	printf("Write %s, Integer\n",id);
}

void asignar(char * var1, char * var2){
	printf("Store %s,%s\n", var2, var1);
}

char* negar(char* id) {
	infijo = strdup(generarVariableTemporal());
	printf("INV %s,,%s\n", id, infijo);
	return infijo;
}

char* generarVariableTemporal() {
	temporal++;
	sprintf(nombreDelTemporal, "Temp#%d", temporal);
	definirIdentificador(strdup(nombreDelTemporal));	
	return nombreDelTemporal;
}

char* generarInfijo(char *operandoIzquierda, char *operandoDerecha,char operador) {
	infijo = strdup(generarVariableTemporal());
        switch(operador){
               case '+': printf("ADD %s, %s, %s\n", operandoIzquierda, operandoDerecha, infijo);
                         break;
	       case '-': printf("SUB %s, %s, %s\n", operandoIzquierda, operandoDerecha, infijo);
                         break;
               case '*': printf("MULT %s, %s, %s\n", operandoIzquierda, operandoDerecha, infijo);
                         break;
               case '/': printf("DIV %s, %s, %s\n", operandoIzquierda, operandoDerecha, infijo);
                         break;
               default: puts("ERROR");
      }
      return infijo;
}

void terminar(){
	printf("Exit ,\n");
}