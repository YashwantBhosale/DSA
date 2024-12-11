#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int get_min_vertex(int *weight, int *visited, int vertices) {
    int min = INT_MAX, min_index = -1;
    for(int i = 0; i < vertices; i++) {
        if(!visited[i] && weight[i] < min) {
            min = weight[i];
            min_index = i;
        }
    }
    return min_index;
}

void prims(Graph *g) {
    int visited[g->vertices], parent[g->vertices], weight[g->vertices];

    for(int i = 0; i < g->vertices; i++) {
        weight[i] = INT_MAX;
        visited[i] = 0;
    }

    weight[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < g->vertices-1; i++) {
        int u = get_min_vertex(weight, visited, g->vertices);
        visited[u] = 1;

        for (int v = 0; v < g->vertices; v++) {
            if (g->adjMatrix[u][v] && !visited[v] && g->adjMatrix[u][v] < weight[v]) {
                parent[v] = u;
                weight[v] = g->adjMatrix[u][v];
            }
        }
    }
}