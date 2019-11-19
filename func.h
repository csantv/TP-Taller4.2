#ifndef TP_T4_2_FUNC_H
#define TP_T4_2_FUNC_H

#include <stdio.h>

#include "persona.h"

void Application();
FILE* openFile(char* path, char* mode);
void getDatos(struct Persona* persona);
int sacaPalabras(const char* str, char **arr, char sep);
void freeC(char** arr, int size);
void imprimirDatos(struct Persona* personas, char* cursoNombre, int horario);
void printChar(int num, char ch, int printEndl);

#endif //TP_T4_2_FUNC_H
