typedef struct stack {
    Node **array;
    int size, top;
} Stack;

void init_stack(Stack *s);
void push(Stack *s, Node *nn);
Node *pop(Stack *s);
Node *peek(Stack *s);
short is_empty(Stack *s);
