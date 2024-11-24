#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"
#include "queue.h"

void init_graph(Graph *g, int vertices) {
	g->vertices = vertices;
	g->adjMatrix = (int **)calloc(vertices, sizeof(int));

	for (int i = 0; i < vertices; i++) {
		g->adjMatrix[i] = (int *)calloc(vertices, sizeof(int));
	}
	return;
}

void add_edge(Graph *g, int u, int v) {
	g->adjMatrix[u][v] = 1;
	g->adjMatrix[v][u] = 1;  // Undirected graph
	return;
}

void remove_edge(Graph *g, int u, int v) {
	g->adjMatrix[u][v] = 0;
	g->adjMatrix[u][v] = 0;
	return;
}

void display_graph(Graph *g) {
	printf("Adj Matrix: \n");
	for (int i = 0; i < g->vertices; i++) {
		for (int j = 0; j < g->vertices; j++) {
			printf("%d ", g->adjMatrix[i][j]);
		}
		printf("\n");
	}
	return;
}

void free_graph(Graph *g) {
	for (int i = 0; i < g->vertices; i++) {
		free(g->adjMatrix[i]);
	}
	free(g->adjMatrix);
	g->adjMatrix = NULL;
	return;
}

void DFS(Graph *g, int start) {
	stack s;
	init(&s, g->vertices);
	push(&s, start);
	int *visited = (int *)calloc(g->vertices, sizeof(int));
	visited[start] = 1;

	while (!is_empty(&s)) {
		int popped = pop(&s);
		printf("%d ", popped);

		for (int i = 0; i < g->vertices; i++) {
			if (g->adjMatrix[popped][i] && !visited[i]) {
				push(&s, i);
				visited[i] = 1;
			}
		}
	}

	free(visited);
	return;
}

void BFS(Graph *g, int start) {
	queue q;
	qinit(&q);
	enq(&q, start);
	int *visited = (int *)calloc(g->vertices, sizeof(int));
	visited[start] = 1;

	while (!isEmpty(&q)) {
		int popped = deq(&q);
		printf("%d ", popped);

		for (int i = 0; i < g->vertices; i++) {
			if (g->adjMatrix[popped][i] && !visited[i]) {
				enq(&q, i);
				visited[i] = 1;
			}
		}
	}

	free(visited);
	return;
}

// for undirected graph
int is_cyclic_bfs(Graph *g, int start) {
	queue q;
	qinit(&q);
	enq(&q, start);

	int *visited = (int *)calloc(g->vertices, sizeof(int));
	visited[start] = 1;

	while (!isEmpty(&q)) {
		int current = deq(&q);

		for (int i = 0; i < g->vertices; i++) {
			if (g->adjMatrix[current][i]) {
				if (!visited[i]) {
					enq(&q, i);
					visited[i] = 1;
				} else {
					free(visited);
					return 1;
				}
			}
		}
	}
	return 0;
}

int is_cyclic_bfs_v2(Graph *g, int start) {
	queue q;
	qinit(&q);
	enq(&q, start);

	int *visited = (int *)calloc(g->vertices, sizeof(int));
	visited[start] = 1;

	int *parent = (int *)malloc(sizeof(int) * g->vertices);
	for (int i = 0; i < g->vertices; i++) {
		parent[i] = -1;
	}

	while (!isEmpty(&q)) {
		int current = deq(&q);

		for (int i = 0; i < g->vertices; i++) {
			if (g->adjMatrix[current][i]) {
				if (!visited[i]) {
					enq(&q, i);
					parent[i] = current;
					visited[i] = 1;
				} else if (parent[current] != i) {
					free(visited);
					free(parent);
					return 1;
				}
			}
		}
	}

	free(visited);
	free(parent);
	return 0;
}

int is_cyclic_dfs(Graph *g, int start) {
	Stack s;
	init(&s, g->vertices);
	push(&s, start);

	int *visited = (int *)calloc(g->vertices, sizeof(int));
	visited[start] = 1;

	while (!is_empty(&s)) {
		int popped = pop(&s);

		for (int i = 0; i < g->vertices; i++) {
			if (!visited[i]) {
				push(&s, i);
				visited[i] = 1;
			} else {
				free(visited);
				return 1;
			}
		}
	}

	free(visited);
	return 0;
}


int is_cyclic_dfs_v2(Graph *g, int start) {
	Stack s;
	init(&s, g->vertices);
	push(&s, start);

	int *visited = (int *)calloc(g->vertices, sizeof(int));
	visited[start] = 1;

	int *parent = (int *)malloc(sizeof(int) * g->vertices);
	for (int i = 0; i < g->vertices; i++) {
		parent[i] = -1;
	}

	while (!is_empty(&s)) {
		int popped = pop(&s);

		for (int i = 0; i < g->vertices; i++) {
			if (!visited[i]) {
				push(&s, i);
                parent[i] = popped;
				visited[i] = 1;
			} else if(parent[popped] != i) {
				free(visited);
                free(parent);
				return 1;
			}
		}
	}

    free(parent);
	free(visited);
	return 0;
}

