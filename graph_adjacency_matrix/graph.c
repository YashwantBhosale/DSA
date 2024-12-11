#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void initGraph(Graph *graph, int vertices) {
    graph->vertices = vertices;
    graph->adjMatrix = (int **) malloc(vertices * sizeof(int *));
    for(int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *) calloc(vertices, sizeof(int));
    }
    return;
}

void addEdge(Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    // For undirected graph, we need to connect source edge to destination and destination edge to source
    graph->adjMatrix[dest][src] = 1; 
    return;
}

void removeEdge(Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 0;
    graph->adjMatrix[dest][src] = 0;
    return;
}

void displayGraph(Graph *graph) {
    if(!graph) {
        printf("Graph is not initialized\n");
        return;
    }

    printf("   ");
    for(int i = 0; i < graph->vertices; i++){
        printf("%d  ", i+1);
    }
    printf("\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d  ", i+1);
        for(int j = 0; j < graph->vertices; j++){
            printf("%d  ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void freeGraph(Graph *graph) {
    for(int i = 0; i < graph->vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    graph->adjMatrix = NULL;
}