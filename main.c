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

int main(void) {
    No *cabeca = NULL;
    int opcao;

    do {
         printf("\n=== LISTA ENCADEADA ===\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Buscar\n");
        printf("4 - Imprimir\n");
        printf("5 - Salvar em arquivo\n");
        printf("6 - Carregar do arquivo\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: {
                int tipo = escolher_tipo();
                void *dado = ler_dado(tipo);
                cabeca = inserir_fim(cabeca,tipo,dado);
                break;
            }

            case 2: {
                int tipo = escolher_tipo();
                void *chave = ler_dado(tipo);
                cabeca = remover(cabeca, tipo, chave);
                free(chave);
                break;
            }
            case 3: {
                int tipo = escolher_tipo();
                void *chave = ler_dado(tipo);
                int pos = buscar(cabeca, tipo, chave);
                if (pos == -1) {
                    printf("Nao encontrado.\n");
                } else {
                    printf("Achei na posicao %d.\n", pos);
                }
                free(chave);
                break;
            }
            case 4:
                imprimir_lista(cabeca);
                break;
            case 5:
                salvar_lista(cabeca, ARQUIVO);
                break;
            case 6:
                cabeca = carregar_lista(cabeca, ARQUIVO);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
    }
} while (opcao != 0);

    cabeca = liberar_lista(cabeca);
    return 0;

}

//Rapha
int escolher_tipo(void) {
    int tipo;
    do {
        printf("\nTipo do dado:\n");
        printf("1 - Inteiro\n");
        printf("2 - Texto\n");
        printf("3 - Aluno (nome e RA)\n");
        printf("Escolha: ");
        scanf("%d", &tipo);
    } while (tipo < 1 || tipo > 3);
    return tipo;
}

void *ler_dado(int tipo) {
    switch (tipo) {
        case TIPO_INT: {
            int *p = (int *) malloc(sizeof(int));
            printf("Digite o inteiro: ");
            scanf("%d", p);
            return p;
        }
        case TIPO_STRING: {
            char buffer[100];
            printf("Digite o texto: ");
            scanf(" %99[^\n]", buffer);
            char *p = (char *) malloc(strlen(buffer) + 1);
            strcpy(p, buffer);
            return p;
        }
        case TIPO_ALUNO: {
            Aluno *p = (Aluno *) malloc(sizeof(Aluno));
            printf("Nome: ");
            scanf(" %49[^\n]", p->nome);
            printf("RA: ");
            scanf("%d", &p->ra);
            return p;
        }
    }
    return NULL;
}

No *criar_no(int tipo, void *dados) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: sem memoria!\n");
        return NULL;
    }
    novo->proximo = NULL;
    novo->tipo = tipo;
    novo->dados = dados;
    return novo;
}

No *inserir_fim(No *cabeca, int tipo, void *dados) {
    No *novo = criar_no(tipo, dados);
    if (novo == NULL) {
        return cabeca;
    }
    if (cabeca == NULL) {
        return novo;
    }
    No *atual = cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return cabeca;
}

void imprimir_lista(No *cabeca) { }



//Lucas
int buscar(No *cabeca, int tipo, void *chave) {
    return -1;
}

No *remover(No *cabeca, int tipo, void *chave) {
    return cabeca;
}

No *liberar_lista(No *cabeca) { return cabeca; }

void salvar_lista(No *cabeca, const char *arquivo) { }

No *carregar_lista(No *cabeca, const char *arquivo) {
    return cabeca;
}
