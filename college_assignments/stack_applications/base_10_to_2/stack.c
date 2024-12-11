#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init_stack(stack *s, int size) {
    if(!s) return;
    s->arr = (char *) malloc(sizeof(char) * size);
    s->size = size;
    s->top = -1;
    return;
}

void push(stack *s, char c) {
    if(s->top >= s->size-1) // if top == size-1 then stack is full
        return;
    s->arr[++s->top] = c;
    return;
}

char pop(stack *s) {
    return s->arr[s->top--];
}

char peek(stack s) {
    return s.arr[s.top];
}

short int is_empty(stack s) {
    return s.top == -1;
}

void view_stack(stack s) {
    printf("[\t");
    for(int i = 0; i<=s.top; i++) {
        printf("%c\t", s.arr[i]);
    }
    printf("]\n");
    return;
}
