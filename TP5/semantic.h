#ifndef SEMANTIC_H
#define SEMANTIC_H

void comenzar();

void leer(char* id);

void escribir(char* id);

void asignar(char * var1, char * var2);

char* negar(char* id);

char* generarVariableTemporal();

char* generarInfijo(char *operandoIzquierda, char *operandoDerecha,char operador);

void terminar();

#endif