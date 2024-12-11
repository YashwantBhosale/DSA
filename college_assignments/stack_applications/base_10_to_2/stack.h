typedef struct {
    char *arr;
    int size;
    int top;
} stack;

void init_stack(stack *s, int size);
void push(stack *s, char c);
char pop(stack *s);
char peek(stack s);
short int is_empty(stack s);
void view_stack(stack s);

