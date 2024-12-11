typedef struct node {
    int d;
    struct node *next, *prev;
} node;

typedef struct {
   node *head, *tail;
} list;

void init_ascii(list *l);
void ascii_of(list *l, char c);
void traverse(list l);
void destroy(list *l);