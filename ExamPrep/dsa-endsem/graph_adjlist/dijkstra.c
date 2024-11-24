#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

int min_dist(int *dist, int *visited, int vertices) {
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
	int *dist = (int *)calloc(g->vertices, sizeof(int));
	int visited[g->vertices];

	for (int i = 0; i < g->vertices; i++) {
		visited[i] = 0;
		dist[i] = INT_MAX;
	}

	dist[src] = 0;

	for (int i = 0; i < g->vertices - 1; i++) {
		int u = min_dist(dist, visited, g->vertices);

		if (u == -1) break;  // No more vertices to visit

		visited[u] = 1;
		Node *p = g->adjList[u];

		// Relaxation
		while (p) {
			// dist[u] != INT_MAX is essential to avoid overflow
			if (!visited[p->dest] && dist[u] != INT_MAX && (dist[u] + p->weight) < dist[p->dest]) {
				dist[p->dest] = dist[u] + p->weight;
			}
			p = p->next;
		}
	}

	return dist;
}