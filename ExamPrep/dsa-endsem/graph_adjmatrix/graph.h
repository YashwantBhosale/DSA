typedef struct graph{
    int vertices;
    int **adjMatrix;
} Graph;

void init_graph(Graph *g);
void add_edge(Graph *g, int u, int v);
void remove_edge(Graph *g, int u, int v);
void display_graph(Graph *g);