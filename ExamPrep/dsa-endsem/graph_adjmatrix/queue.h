typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct queue{
    node *head, *tail;
} queue;

void qinit(queue *q);
void enq(queue *q, int data);
int deq(queue *q);
int isEmpty(queue *q);
void print(queue *q);
void destroy(queue *q);
