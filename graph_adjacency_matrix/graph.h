typedef struct Graph {
    int vertices;
    int **adjMatrix;
} Graph;

void initGraph(Graph *graph, int vertices);
void addEdge(Graph *graph, int src, int dest);
void removeEdge(Graph *graph, int src, int dest);
void displayGraph(Graph *graph);
void freeGraph(Graph *graph);