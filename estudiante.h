#ifndef TP_T4_2_ESTUDIANTE_H
#define TP_T4_2_ESTUDIANTE_H

#include "curso.h"

struct Estudiante
{
    int codigo;
    char apMaterno[20];
    char apPaterno[20];
    char nombre[20];
    struct Curso cursos[20];
    int numCursos;
};

#endif //TP_T4_2_ESTUDIANTE_H
