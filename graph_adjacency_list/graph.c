#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void init_graph(Graph *graph, int vertices) {
    graph->vertices = vertices;
    graph->adjList = (Node **) calloc(vertices, sizeof(Node *));
}

Node *new_node(int dest) {
    Node *nn = (Node *) malloc(sizeof(Node));
    nn->dest = dest;
    nn->next = NULL;
    return nn;
}

void add_edge(Graph *graph, int src, int dest) {
    // This is essentially insert at beg
    Node *nn = new_node(dest);
    nn->next = graph->adjList[src];
    graph->adjList[src] = nn;

    // for undirected graph we need to connect dest to source as well
    nn = new_node(src);
    nn->next = graph->adjList[dest];
    graph->adjList[dest] = nn;
}

void remove_edge(Graph *graph, int src, int dest) {
    Node *p = graph->adjList[src], *q = NULL;
    while(p && p->dest != dest) {
        q = p;
        p = p->next;
    }

    if (p && q) {
        q->next = p->next;
        free(p);
    }

    return;
}

void display_graph(Graph *graph) {
    for(int i = 0; i < graph->vertices; i++) {
        printf("Vertext %d: ", i);
        Node *p = graph->adjList[i];
        while(p) {
            printf(" (%d -> %d) ", i, p->dest);
            p = p->next;
        }
        printf("\n");
    }
}

void free_graph(Graph *graph){
    for (int i = 0; i < graph->vertices; i++) {
        Node *p = graph->adjList[i];

        while(p) {
            Node *next = p->next;
            free(p);
            p = next;
        }
    }
    free(graph->adjList);
}