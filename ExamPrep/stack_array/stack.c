#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init (stack *s, int size) {
    s->arr = (int *) malloc (sizeof(int) * size);
    s->size = size;
    s->top = -1;
    return;
}

void push (stack *s, int data) {
    s->arr[++s->top] = data;
    return;
}

int pop(stack *s){
    return s->arr[s->top--];
}

int peek(stack s) {
    return s.arr[s.top];
}

void display(stack s) {
    printf("[\t");
    for (int i = s.top; i >=0; i--){
        printf("%d\t", s.arr[i]);
    }
    printf("]\n");
    return;
}
