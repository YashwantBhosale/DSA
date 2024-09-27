#include <stdio.h>
#include <stdlib.h>
#include "two_stack.h"

void init_stack(stack *s, int size) {
    if (!s) return;
    s -> arr = (int *) malloc(sizeof(int) * size * 2);
    s-> top1 = -1;
    s-> top2 = size-1;
    s-> size = size;
    return;
}

void push1(stack *s, int d) {
    if(s->top1 >= s->size) return;
    s->arr[++s->top1] = d; 
    return;
}


void push2(stack *s, int d) {
    if(s->top2 >= s->size*2) return;

    s->arr[++s->top2] = d;
    return;
}

int pop1(stack *s) {
    return s->arr[s->top1--];  
}

int pop2(stack *s) {
    return s->arr[s->top2--];
}

void print_stack_1(stack s) {
    printf("[\t");
    for(int i = 0; i <= s.top1; i++) {
        printf("%d\t", s.arr[i]);
    }
    printf("]\n");
    return;
}

void print_stack_2(stack s) {
    printf("[\t");
    for(int i = s.size; i <= s.top2; i++) {
        printf("%d\t", s.arr[i]);
    }
    printf("]\n");
    return;
}
