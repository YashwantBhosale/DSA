typedef struct queue {
    Node **q;
    int front, rear;
    int count;
} Queue;

void init_queue(Queue *q);
void enq(Queue *q, Node *n);
Node *deq(Queue *q);
short is_qfull(Queue *q);
short is_qempty(Queue *q);