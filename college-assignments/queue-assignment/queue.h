typedef struct data {
    char name[16];
    unsigned int age;
} data;

typedef struct node {
    data d;
    struct node *next;
} node;

typedef struct {
    node *head, *tail;
    short is_full;
} queue;

void qinit(queue *q);
void enq(queue *q, data d);
data deq(queue *q);
short qfull(queue *q);
short qempty(queue *q);
void print_queue(queue *q);
