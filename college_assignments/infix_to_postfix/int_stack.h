typedef struct int_stack {
    int *arr;
    int size;
    int top;
} int_stack;

void init_int_stack(int_stack *s, int size);
void push_int(int_stack *s, int data);
int pop_int(int_stack *s);
int peek_int(int_stack s); 
short int is_int_empty(int_stack s);
void view_int_stack(int_stack s);