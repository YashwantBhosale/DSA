typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct {
    node *top;
} stack;

void init(stack *s);
void push(stack *s, int data);
int pop(stack *s);
int peek(stack s);
void display(stack s);
