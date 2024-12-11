#include <stdio.h>
#include <stdlib.h>
#include "char_stack.h"

void init_char_stack(char_stack *s, int size) {
    s->arr = (int *)malloc(sizeof(int) * size);
    s->size = size;
    s->top = -1;
    return;
}

void push_cs(char_stack *s, int data) {
    s->arr[++s->top] = data;
    return;
}

int pop_cs(char_stack *s) {
    int element = s->arr[s->top];
    s->top--;
    return element;
}

int peek_cs(char_stack s) { return s.arr[s.top]; }

short int is_cs_empty(char_stack s) { return s.top == -1; }

void view_char_stack(char_stack s) {
    printf("[\t");
    for (int i = 0; i <= s.top; i++) {
        printf("%c\t", s.arr[i]);
    }
    printf("]\n");
}