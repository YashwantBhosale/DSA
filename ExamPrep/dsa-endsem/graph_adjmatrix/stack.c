#include "stack.h"

/* Function to initialize stack */
void init(stack *s, int size) {
    s -> arr = (int *) malloc(size * sizeof(int));
    s -> top = -1;
    s -> size = size;
    return;
}

/* Function to push an element in the stack */
void push(stack *s, int data) {
    if(s->top >= s->size-1){
        s -> arr = (int *) realloc(s->arr, (s->size+1) * sizeof(int));
    }
    s->top++;
    s->arr[s->top] = data;
    return;
}

/* Function to pop an element from the stack */
int pop(stack *s) {
    if(is_empty(s)) {
        printf("WARNING: YOU ARE TRYING TO POP FROM AN EMPTY STACK!\n");
        return INT_MIN;
    }

    int element = s->arr[s->top];
    s->top--;
    return element;
}

short is_empty(stack *s) {
    return s->top == -1;
}

/* Function to peek into the stack */
int peek(stack s) {
    return s.arr[s.top];
}

/* Function to display the stack */
void display(stack s) {
    printf("[\t");
    for(int i = s.top; i >= 0; i--) {
        printf("%d\t", s.arr[i]);
    }
    printf("]\n");
    return;
}