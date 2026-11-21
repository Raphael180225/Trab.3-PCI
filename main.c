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

//Prototipos: nosso "contrato".
//Rapha
No *criar_no(int tipo, void *dados);
No *inserir_fim(No *cabeca, int tipo, void *dados);
int escolher_tipo(void);
void *ler_dado(int tipo);
void imprimir_no(No *no);
void imprimir_lista(No *cabeca);

//Lucas
int tamanho_dado(No *no);
int comparar(No *no, int tipo, void *chave);
int buscar(No *cabeca, int tipo, void *chave);
No *remover(No *cabeca, int tipo, void *chave);
No *liberar_lista(No *cabeca);
void salvar_lista(No *cabeca, const char *arquivo);
No *carregar_lista(No *cabeca, const char *arquivo);

