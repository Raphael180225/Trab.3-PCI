#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "lista.bin"
#define TIPO_INT 1
#define TIPO_STRING 2
#define TIPO_ALUNO 3

typedef struct {
    char nome[50];
    int ra;
} Aluno;

typedef struct No {
    struct No *proximo;
    int tipo;
    void *dados;
} No;

