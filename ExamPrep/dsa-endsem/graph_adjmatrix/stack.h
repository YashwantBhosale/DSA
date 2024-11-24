/* Stack using array */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int top;
} stack;

void init(stack *s, int size);
void push(stack *s, int data);
int pop(stack *s);
int peek(stack s);
void display(stack s);
short is_empty(stack *s);