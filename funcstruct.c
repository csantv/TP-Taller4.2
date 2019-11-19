#include <string.h>

#include "funcstruct.h"
#include "func.h"

void initEstudiante(struct Estudiante* estudiante, int codigo, char* rawName)
{
    char* arr[3]; int size;
    estudiante->codigo = codigo;
    size = sacaPalabras(rawName, arr, '/');
    strcpy(estudiante->apPaterno, arr[0]);
    strcpy(estudiante->apMaterno, arr[1]);
    strcpy(estudiante->nombre, arr[2]);
    freeC(arr, size);
}
