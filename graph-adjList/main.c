#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



int main() {
    int vertices = 4;

    // Initialize graph structure
    Graph g;
    init_graph(&g, vertices);

    // Add edges
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 3);

    // Display the graph
    display_graph(&g);

    // Free the allocated memory
    free_graph(&g);

    return 0;
}