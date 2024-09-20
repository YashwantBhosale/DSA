typedef struct node {
    int data;
    struct node *next;
} node;

typedef node *list;

void init_cll(list *l);
void insert_beg(list *l, int data);
void insert_end(list *l, int data);
void insert_pos(list *l, int pos, int data);
void remove_beg(list *l);
void remove_end(list *l);
void remove_pos(list *l, int pos);
void sort(list *l);
void display(list l);
