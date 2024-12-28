#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *esquerda, *direita;
}No;

No* novoNo(int valor){
    No* no=(No*)malloc(sizeof(No));
    no->valor=valor;
    no->esquerda=no->direita=NULL;
    return no;
}

No* inserir(No* raiz, int valor){
    if(raiz==NULL) return novoNo(valor);
    if(valor<raiz->valor) raiz->esquerda=inserir(raiz->esquerda, valor);
    else if(valor>raiz->valor) raiz->direita=inserir(raiz->direita, valor);
    return raiz;
}

int buscar(No* raiz, int valor){
    int passos=0;
    while(raiz!=NULL){
        passos++;
        if(valor==raiz->valor) return passos;
        else if(valor<raiz->valor) raiz=raiz->esquerda;
        else raiz=raiz->direita;
    }
    return -1;
}

int main(){
    No* raiz=NULL;
    int valor;

    printf("Digite os valores para inserir na árvore (valor negativo para encerrar):\n");
    while(1){
        scanf("%d", &valor);
        if(valor<0) break;
        raiz=inserir(raiz, valor);
    }

    printf("Digite o valor que deseja buscar:\n");
    scanf("%d", &valor);
    int resultado=buscar(raiz, valor);
    if(resultado==-1) printf("Valor nao encontrado na arvore\n");
    else printf("Valor encontrado em %d passos\n", resultado);

    return 0;
}
