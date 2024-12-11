/* Stack using array */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    node **arr;
    int size;
    int top;
} stack;

void init(stack *s, int size);
void push(stack *s, node *n);
node *pop(stack *s);
node *peek(stack *s);
void display(stack s);
short is_empty(stack *s);