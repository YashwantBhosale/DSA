typedef struct node {
    int dest;
    int weight;
    struct node *next;
} Node;

typedef struct graph {
    Node **adjList;
    int vertices;
} Graph;

void init_graph(Graph *g, int vertices);
void add_edge(Graph *g, int u, int v);
void remove_edge(Graph *g, int u, int v);
void display_graph(Graph *g, int u, int v);
void free_graph(Graph *g);
Node *new_node(int dest);