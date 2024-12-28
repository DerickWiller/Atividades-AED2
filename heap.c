#include <stdio.h>
#define MAX 100

typedef struct{
    int heap[MAX];
    int qtd;
}Heap;

void iniciarHeap(Heap *h){
    h->qtd=0;
}

void troca(int *x,int *y){
    int aux=*x;
    *x=*y;
    *y=aux;
}

void adiciona(Heap *h,int num){
    if(h->qtd>=MAX){
        printf("Cheio!\n");
        return;
    }
    h->heap[h->qtd]=num;
    int atual=h->qtd;
    while(atual>0&&h->heap[atual]>h->heap[(atual-1)/2]){
        troca(&h->heap[atual],&h->heap[(atual-1)/2]);
        atual=(atual-1)/2;
    }
    h->qtd++;
}

void removerTopo(Heap *h){
    if(h->qtd==0){
        printf("Vazio!\n");
        return;
    }
    h->heap[0]=h->heap[h->qtd-1];
    h->qtd--;
    int atual=0;
    while(1){
        int maior=atual;
        int esq=2*atual+1,dir=2*atual+2;
        if(esq<h->qtd&&h->heap[esq]>h->heap[maior]){
            maior=esq;
        }
        if(dir<h->qtd&&h->heap[dir]>h->heap[maior]){
            maior=dir;
        }
        if(maior==atual){
            break;
        }
        troca(&h->heap[atual],&h->heap[maior]);
        atual=maior;
    }
}

void busca(Heap *h,int num){
    for(int i=0;i<h->qtd;i++){
        if(h->heap[i]==num){
            int pai=(i-1)/2;
            int esq=2*i+1;
            int dir=2*i+2;
            printf("Achou: %d\n",num);
            if(i>0) printf("Pai: %d\n",h->heap[pai]);
            if(esq<h->qtd) printf("Esq: %d\n",h->heap[esq]);
            if(dir<h->qtd) printf("Dir: %d\n",h->heap[dir]);
            return;
        }
    }
    printf("Não achou!\n");
}

int main(){
    Heap meuHeap;
    iniciarHeap(&meuHeap);
    int opcao,valor;
    do{
        printf("1.Adicionar\n2.Remover Topo\n3.Buscar\n4.Sair\nOpção: ");
        scanf("%d",&opcao);
        if(opcao==1){
            printf("Número: ");
            scanf("%d",&valor);
            adiciona(&meuHeap,valor);
        }else if(opcao==2){
            removerTopo(&meuHeap);
        }else if(opcao==3){
            printf("Número: ");
            scanf("%d",&valor);
            busca(&meuHeap,valor);
        }
    }while(opcao!=4);
    return 0;
}
