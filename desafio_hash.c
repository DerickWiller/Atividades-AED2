#include<stdio.h>
#include<stdlib.h>
#define TAM 1000

typedef struct No{
    int valor;
    struct No *proximo;
}No;

No* criarNo(int valor){
    No* novo=malloc(sizeof(No));
    if(!novo){
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    novo->valor=valor;
    novo->proximo=NULL;
    return novo;
}

void adicionar(No* tabela[],int valor){
    int indice=valor%TAM;
    No* atual=tabela[indice];
    while(atual){
        if(atual->valor==valor)return;
        atual=atual->proximo;
    }
    No* novo=criarNo(valor);
    novo->proximo=tabela[indice];
    tabela[indice]=novo;
}

int procurar(No* tabela[],int valor){
    int indice=valor%TAM,passos=1;
    No* atual=tabela[indice];
    while(atual){
        if(atual->valor==valor)return passos;
        atual=atual->proximo;
        passos++;
    }
    return -1;
}

void liberar(No* tabela[]){
    for(int i=0;i<TAM;i++){
        No* atual=tabela[i];
        while(atual){
            No* temp=atual;
            atual=atual->proximo;
            free(temp);
        }
    }
}

int main(){
    No* tabela[TAM]={NULL};
    int valor,usados=0,livres=0;
    FILE* arquivo=fopen("DesafioHash.txt","r"); // USEI O NOME QUE ESTAVA NO ARQUIVO ENVIADO NO SIGAA 
    if(!arquivo){
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
    while(fscanf(arquivo,"%d",&valor)!=EOF){
        adicionar(tabela,valor);
    }
    fclose(arquivo);
    for(int i=0;i<TAM;i++){
        if(tabela[i])usados++;
        else livres++;
    }
    printf("Usados: %d\nLivres: %d\n",usados,livres);
    printf("Digite um número para buscar (-1 para sair): ");
    while(scanf("%d",&valor)&&valor!=-1){
        int passos=procurar(tabela,valor);
        if(passos!=-1)printf("Encontrado em %d passos\n",passos);
        else printf("Não encontrado\n");
        printf("Digite um número para buscar (-1 para sair): ");
    }
    liberar(tabela);
    return 0;
}
