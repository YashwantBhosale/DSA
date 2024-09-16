typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} node;

typedef struct {
    struct node *head, *tail;
} list;
void init(list *l);
void insert_end(list *l, int data);
void insert_from_begining(list *l, int data);
void insert_at_index(list *l, int data, int index);
void remove_at_index(list *l, int index);
void sort(list l);
void remove_end(list *l);
void remove_beg(list *l);
void remove_duplicates(list *l);
short int is_palindrome(list l);
void printLR(list l);
void printRL(list l);