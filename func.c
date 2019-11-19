#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "func.h"
#include "funcstruct.h"

void Application()
{
    struct Persona personas = {.numEstudiante = 0};
    getDatos(&personas);
    while (1) {
        char curso[10]; int horario;
        puts("Ingrese datos Curso y Horario, para salir escribir \"Fin\":");
        printf("Nombre del Curso: "); scanf("%s", curso);
        if (!strcmp(curso, "Fin")) break;
        printf("Horario: "); scanf("%d", &horario);
        imprimirDatos(&personas, curso, horario);
        printChar(50, '-', 1);
    }
}

void printChar(int num, char ch, int printEndl)
{
    for (int i = 0; i < num; i++) {
        printf("%c", ch);
    }
    if (printEndl) printf("\n");
}

void imprimirDatos(struct Persona* personas, char* cursoNombre, int horario)
{
    int numEstudiantes = 0, headerImpreso = 0;
    for (int i = 0; i < personas->numEstudiante; i++) {
        struct Estudiante estudiante = personas->estudiantes[i];
        for (int j = 0; j < personas->estudiantes->numCursos; j++) {
            struct Curso curso = estudiante.cursos[j];
            if (!strcmp(curso.nombre, cursoNombre) && horario == curso.horario) {
                if (!headerImpreso) {
                    puts("\nLISTA DE ALUMNOS\n");
                    puts("   CODIGO           APELLIDOS Y NOMBRES");
                    headerImpreso = 1;
                }
                numEstudiantes++;
                printf("%d) %d        %s %s,%s\n", numEstudiantes, estudiante.codigo, estudiante.apPaterno, estudiante.apMaterno, estudiante.nombre);
            }
        }
    }
    if (!numEstudiantes) {
        puts("No se encontraron estudiantes en este curso.");
    }
}

void freeC(char** arr, int size)
{
    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
}

void getDatos(struct Persona* personas)
{
    char buffer[500], *line, *datos[5];
    int size, numEstudiante = 0;
    FILE* datosFile = openFile("datos2.csv", "r");
    while ((line = fgets(buffer, 500, datosFile))) {
        size = sacaPalabras(line, datos, ',');
        struct Estudiante estudiante = {.numCursos = 0};
        initEstudiante(&estudiante, atoi(datos[0]), datos[1]);
        for (int i = 2; i < size; i += 4) {
            struct Curso curso = {.horario = atoi(datos[i + 3]), .creditos = atof(datos[i + 2])};
            strcpy(curso.nombre, datos[i + 1]);
            strcpy(curso.codigo, datos[i]);
            estudiante.cursos[estudiante.numCursos] = curso;
            estudiante.numCursos++;
        }
        personas->estudiantes[numEstudiante] = estudiante;
        numEstudiante++;
        freeC(datos, size);
    }
    personas->numEstudiante = numEstudiante;
}

int sacaPalabras(const char* str, char **arr, char sep)
{
    int i=0,j=0;
    char palabraaux[50];
    int numpalabras=0;
    while(1){
        while (str[i] == sep) i++;
        if (str[i] == 0) break;
        j=0;
        while (1){
            if (str[i] != sep && str[i] != 0)
                palabraaux[j]=str[i];
            else
                break;
            i++;
            j++;
        }
        palabraaux[j]=0;
        arr[numpalabras]=(char *)malloc(sizeof(char) * (j + 1));
        strcpy(arr[numpalabras], palabraaux);
        numpalabras++;
    }
    return numpalabras;
}

FILE* openFile(char* path, char* mode)
{
    FILE* file = fopen(path, mode);
    if (!file) {
        printf("Error al abrir el archivo %s.\n", path);
        exit(1);
    }
    return file;
}