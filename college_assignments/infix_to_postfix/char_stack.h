typedef struct Char_stack {
    int *arr;
    int size;
    int top;
} char_stack;

void init_char_stack(char_stack *s, int size);
void push_cs(char_stack *s, int data);
int pop_cs(char_stack *s);
int peek_cs(char_stack s); 
short int is_cs_empty(char_stack s);
void view_char_stack(char_stack s);