typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct Graph {
    int vertices;
    Node **adjList;
} Graph;

void init_graph(Graph *graph, int vertices);
Node *new_node(int dest);
void add_edge(Graph *graph, int src, int dest);
void remove_edge(Graph *graph, int src, int dest);
void display_graph(Graph *graph);
void free_graph(Graph *graph);