#include "stack.h"

/* Function to initialize stack */
void init(stack *s, int size) {
    s -> arr = (int *) malloc(size * sizeof(int));
    s -> top = 0;
    s -> size = size;
    return;
}

/* Function to push an element in the stack */
void push(stack *s, int data) {
    if(s->top >= s->size-1)
        return;
    s->top++;
    s->arr[s->top] = data;
    return;
}

/* Function to pop an element from the stack */
int pop(stack *s) {
    int element = s->arr[s->top];
    s->top--;
    return element;
}

/* Function to peek into the stack */
int peek(stack s) {
    return s.arr[s.top];
}

/* Function to display the stack */
void display(stack s) {
    printf("[\t");
    for(int i = 0; i <= s.top; i++) {
        printf("%d\t", s.arr[i]);
    }
    printf("]\n");
    return;
}