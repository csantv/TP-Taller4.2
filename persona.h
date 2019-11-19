#ifndef TP_T4_2_PERSONA_H
#define TP_T4_2_PERSONA_H

#include "curso.h"
#include "estudiante.h"

struct Persona
{
    struct Estudiante estudiantes[20];
    int numEstudiante;
};

#endif //TP_T4_2_PERSONA_H
