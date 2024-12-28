#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    int matriz[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Grafo;

void inicializarGrafo(Grafo *g, int vertices){
    g->numVertices = vertices;
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            g->matriz[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
}

void inserirAresta(Grafo *g, int origem, int destino, int peso){
    if(origem >= 0 && origem < g->numVertices && destino >= 0 && destino < g->numVertices){
        g->matriz[origem][destino] = peso;
    }
}

int menorDistancia(int dist[], int visitado[], int numVertices){
    int min = INT_MAX, indice = -1;
    for(int i = 0; i < numVertices; i++){
        if(!visitado[i] && dist[i] <= min){
            min = dist[i];
            indice = i;
        }
    }
    return indice;
}

void dijkstra(Grafo *g, int origem, int destino){
    int dist[MAX_VERTICES], visitado[MAX_VERTICES], anterior[MAX_VERTICES];
    for(int i = 0; i < g->numVertices; i++){
        dist[i] = INT_MAX;
        visitado[i] = 0;
        anterior[i] = -1;
    }
    dist[origem] = 0;
    for(int i = 0; i < g->numVertices - 1; i++){
        int u = menorDistancia(dist, visitado, g->numVertices);
        if(u == -1) break;
        visitado[u] = 1;
        for(int v = 0; v < g->numVertices; v++){
            if(!visitado[v] && g->matriz[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + g->matriz[u][v] < dist[v]){
                dist[v] = dist[u] + g->matriz[u][v];
                anterior[v] = u;
            }
        }
    }
    if(dist[destino] == INT_MAX){
        printf("Nao existe caminho possivel entre os pontos %d e %d\n", origem, destino);
    } else {
        printf("Menor caminho de %d para %d: ", origem, destino);
        int caminho[MAX_VERTICES], tamanho = 0;
        for(int v = destino; v != -1; v = anterior[v]){
            caminho[tamanho++] = v;
        }
        for(int i = tamanho - 1; i >= 0; i--){
            printf("%d", caminho[i]);
            if(i > 0) printf(" -> ");
        }
        printf("\n");
    }
}

int main(){
    Grafo g;
    int numVertices, numArestas, origem, destino, peso;
    printf("Digite o numero de vertices: ");
    scanf("%d", &numVertices);
    inicializarGrafo(&g, numVertices);
    printf("Digite o numero de arestas: ");
    scanf("%d", &numArestas);
    for(int i = 0; i < numArestas; i++){
        printf("Digite a origem, o destino e o peso da aresta %d: ", i + 1);
        scanf("%d %d %d", &origem, &destino, &peso);
        inserirAresta(&g, origem, destino, peso);
    }
    printf("Digite o ponto de origem: ");
    scanf("%d", &origem);
    printf("Digite o ponto de destino: ");
    scanf("%d", &destino);
    dijkstra(&g, origem, destino);
    return 0;
}