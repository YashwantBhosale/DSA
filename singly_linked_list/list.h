typedef struct node {
    int data;
    struct node *next;
} node;

typedef node* list;

void init_sll(list *l);
void append(list *l, int data);
void traverse(list l);
void insert_at_beg(list *l, int data);
void remove_at_pos(list *l, int pos);
int len(list l);
