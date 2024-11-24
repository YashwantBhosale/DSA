#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"
#include "queue.h"

void init_graph(Graph *g, int vertices) {
	g->vertices = vertices;
	g->adjList = (Node **)calloc(vertices, sizeof(Node *));
	return;
}

Node *new_node(int dest) {
	Node *nn = (Node *)malloc(sizeof(Node));
	if (!nn) return NULL;

	nn->dest = dest;
	nn->next = NULL;
	return nn;
}

void add_edge(Graph *g, int u, int v) {
	Node *nn = new_node(v);
	nn->next = g->adjList[u];
	g->adjList[u] = nn;

	nn = new_node(u);
	nn->next = g->adjList[v];
	g->adjList[v] = nn;
}

void remove_edge(Graph *g, int u, int v) {
	Node *p = g->adjList[u], *q = NULL;

	if (p && p->dest == v) {
		g->adjList[u] = p->next;
		free(p);
	} else {
		while (p && p->dest != v) {
			q = p;
			p = p->next;
		}

		if (!p || !q) return;

		q->next = p->next;
		free(p);
	}

	p = g->adjList[v];
	q = NULL;

	if (p && p->dest == u) {
		g->adjList[u] = p->next;
		free(p);
	} else {
		while (p && p->dest != u) {
			q = p;
			p = p->next;
		}

		if (!p || !q) return;
		q->next = p->next;
		free(p);
	}

	return;
}

void display_graph(Graph *g) {
	for (int i = 0; i < g->vertices; i++) {
		printf("Vertex %d: ", i);
		Node *p = g->adjList[i];

		while (p) {
			printf("(%d -> %d), ", i, p->dest);
			p = p->next;
		}
		printf("\n");
	}
	return;
}

void free_graph(Graph *g) {
	for (int i = 0; i < g->vertices; i++) {
		Node *p = g->adjList[i];

		while (p) {
			Node *next = p->next;
			free(p);
			p = next;
		}

		g->adjList[i] = NULL;
	}

	free(g->adjList);
	return;
}

void DFS(Graph *g, int src) {
	stack s;
	init(&s, g->vertices);

	int *visited = (int *)calloc(g->vertices, sizeof(int));

	push(&s, src);
	visited[src] = 1;

	while (!is_empty(&s)) {
		int popped = pop(&s);
		printf("%d ", popped);

		Node *p = g->adjList[popped];
		while (p) {
			if (!visited[p->dest]) {
				push(&s, p->dest);
				visited[p->dest] = 1;
			}
			p = p->next;
		}
	}

	free(visited);
}

void BFS(Graph *g, int src) {
	queue q;
	qinit(&q);

	int *visited = (int *)calloc(g->vertices, sizeof(int));

	enq(&q, src);
	visited[src] = 1;

	while (!isEmpty(&q)) {
		int popped = deq(&q);
		printf("%d ", popped);

		Node *p = g->adjList[popped];
		while (p) {
			if (!visited[p->dest]) {
				enq(&q, p->dest);
				visited[p->dest] = 1;
			}
			p = p->next;
		}
	}

	free(visited);
}

int is_cyclic_bfs(Graph *g, int start) {
	queue q;
	qinit(&q);

	int *visited = (int *)calloc(g->vertices, sizeof(int));
	int *parent = (int *)malloc(g->vertices * sizeof(int));

	for (int i = 0; i < g->vertices; i++) {
		parent[i] = -1;
	}

	enq(&q, start);
	visited[start] = 1;

	while (!isEmpty(&q)) {
		int popped = deq(&q);

		Node *p = g->adjList[popped];
		while (p) {
			if (!visited[p->dest]) {
				enq(&q, p->dest);
				parent[p->dest] = popped;
				visited[p->dest] = 1;
			} else if (parent[popped] != p->dest) {
				free(visited);
				free(parent);
				return 1;
			}

			p = p->next;
		}
	}
	
	free(visited);
	free(parent);
	return 0;
}

int is_cyclic_dfs(Graph *g, int start) {
	stack s;
	init(&s, g->vertices);

	int *visited = (int *)calloc(g->vertices, sizeof(int));
	int *parent = (int *)malloc(g->vertices * sizeof(int));

	for (int i = 0; i < g->vertices; i++) {
		parent[i] = -1;
	}

	push(&s, start);
	visited[start] = 1;

	while (!is_empty(&s)) {
		int popped = pop(&s);

		Node *p = g->adjList[popped];
		while (p) {
			if (!visited[p->dest]) {
				push(&s, p->dest);
				parent[p->dest] = popped;
				visited[p->dest] = 1;
			} else if (parent[popped] != i) {
				free(visited);
				free(parent);
				return 1;
			}

			p = p->next;
		}
	}

	free(visited);
	free(parent);
	return 0;
}