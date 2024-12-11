#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

int min_distance(int *dist, int *visited, int vertices) {
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

int *dijkstra(Graph *g, int src) {
    int *dist = (int *)malloc(g->vertices * sizeof(int));
    int visited[g->vertices];
    
    for (int i = 0; i < g->vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 0; i < g->vertices - 1; i++) {
        int u = min_distance(dist, visited, g->vertices);

        if(u == -1) break; // No more vertices to visit

        visited[u] = 1;
        for(int v = 0; v < g->vertices; v++) {
            if(!visited[v] && g->adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + g->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + g->adjMatrix[u][v];
            }
        }
    }

    return dist;
}