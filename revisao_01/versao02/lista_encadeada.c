#include <stdio.h>
#include <stdlib.h>

#define FREQUENCIA_MINIMA 75
#define NOTA_MINIMA 6.0

typedef struct Aluno {
    double nota;
    int frequencia;
    struct Aluno* proximo;
} Aluno;

Aluno* adicionar_aluno(Aluno* lista, double nota, int frequencia) {
    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
    novo_aluno->nota = nota;
    novo_aluno->frequencia = frequencia;
    novo_aluno->proximo = lista;
    return novo_aluno;
}

void liberar_lista(Aluno* lista) {
    Aluno* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->proximo;
        free(temp);
    }
}

void processar_alunos(Aluno* lista, int* aprovados, int* reprovados, int* reprovados_frequencia, int* reprovados_nota, int* reprovados_ambos, double* soma_notas) {
    Aluno* atual = lista;
    while (atual != NULL) {
        *soma_notas += atual->nota;
        if (atual->frequencia < FREQUENCIA_MINIMA && atual->nota < NOTA_MINIMA) {
            (*reprovados)++;
            (*reprovados_ambos)++;
        } else if (atual->frequencia < FREQUENCIA_MINIMA) {
            (*reprovados)++;
            (*reprovados_frequencia)++;
        } else if (atual->nota < NOTA_MINIMA) {
            (*reprovados)++;
            (*reprovados_nota)++;
        } else {
            (*aprovados)++;
        }
        atual = atual->proximo;
    }
}
