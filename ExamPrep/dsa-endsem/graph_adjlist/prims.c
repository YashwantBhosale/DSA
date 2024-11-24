#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

int min_vertex(int *weights, int *visited, int vertices) {
    int min = INT_MAX, min_index = -1;

    for(int i = 0; i < vertices; i++) {
        if(!visited[i] && weights[i] < min) {
            min = weights[i];
            min_index = i;
        }
    }

    return min_index;
}

void prims(Graph *g) {
    int parent[g->vertices];
    int weights[g->vertices];
    int visited[g->vertices];

    for (int i = 0; i < g->vertices; i++) {
        visited[i] = 0;
        weights[i] = INT_MAX;
    }

    weights[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < g->vertices-1; i++) {
        int u = min_vertex(weights, visited);
        visited[u] = 1;
    
        Node *p = g->adjList[u];
        while(p) {
            if(!visited[p->dest] && p->weight < weights[p->dest]){
                parent[p->dest] = u;
                weights[p->dest] = p->weight;
            }
            p = p->next;
        }
    }

    // here we may call some display function to display result
}