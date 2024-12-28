#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct{
    int itens[MAX];
    int topo;
} Pilha;

void inicializa(Pilha *p){
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p){
   
    return p->topo == MAX - 1;
}
void empilha(Pilha *p, int valor){
    if (!estaCheia(p)) {
        p->itens[++(p->topo)] = valor;
    }
}

int desempilha(Pilha *p){
    if (!estaVazia(p)) {
        return p->itens[(p->topo)--];
    }
    return -1;
}

int avaliaPosfixa(char *exp){
    Pilha pilha;
    inicializa(&pilha);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            empilha(&pilha, exp[i] - '0');
        } else {
            int val1 = desempilha(&pilha);
            int val2 = desempilha(&pilha);

            switch (exp[i]) {
                case '+': empilha(&pilha, val2 + val1); break;
                case '-': empilha(&pilha, val2 - val1); break;
                case '*': empilha(&pilha, val2 * val1); break;
                case '/': empilha(&pilha, val2 / val1); break;
            }
        }
    }

    return desempilha(&pilha);
}

int main() {

    char exp[MAX];
    
    printf("Digite a expressao em notacao polonesa posfixada: ");
    scanf("%s", exp);
    printf("Resultado: %d\n", avaliaPosfixa(exp));

    return 0;
}
