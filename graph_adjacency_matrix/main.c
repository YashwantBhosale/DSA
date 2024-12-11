#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    Graph graph;
    initGraph(&graph, 4);
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    displayGraph(&graph);
    removeEdge(&graph, 0, 1);
    displayGraph(&graph);
    freeGraph(&graph);
    return 0;
}