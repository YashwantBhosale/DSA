typedef struct {
    int *arr;
    int top1;
    int top2;
    int size;
} stack;

void init_stack(stack *s, int size);
void push1(stack *s, int d);
void push2(stack *s, int d);
int pop1(stack *s);
int pop2(stack *s);
void print_stack_1(stack s);
void print_stack_2(stack s);
