#include <stdio.h>
#include <stdlib.h>
#include "int_stack.h"

void init_int_stack(int_stack *s, int size) {
    s->arr = (int *)malloc(sizeof(int) * size);
    s->size = size;
    s->top = -1;
    return;
}

void push_int(int_stack *s, int data) {
    s->arr[++s->top] = data;
    return;
}

int pop_int(int_stack *s) {
    int element = s->arr[s->top];
    s->top--;
    return element;
}

int peek_int(int_stack s) { return s.arr[s.top]; }

short int is_int_empty(int_stack s) { return s.top == -1; }

void view_int_stack(int_stack s) {
    printf("[\t");
    for (int i = 0; i <= s.top; i++) {
        printf("%d\t", s.arr[i]);
    }
    printf("]\n");
}
