#ifndef TP_T4_2_FUNCSTRUCT_H
#define TP_T4_2_FUNCSTRUCT_H

#include "persona.h"
#include "curso.h"
#include "estudiante.h"

void initEstudiante(struct Estudiante* estudiante, int codigo, char* rawName);
void addCurso(struct Estudiante* estudiante, struct Curso* curso);

#endif //TP_T4_2_FUNCSTRUCT_H
