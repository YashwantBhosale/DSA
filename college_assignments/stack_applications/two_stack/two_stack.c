#include <stdio.h>
#include <stdlib.h>
#include "two_stack.h"

void init_stack(stack *s, int size) {
    if (!s) return;
    s -> arr = (int *) malloc(sizeof(int) * size);
    s-> top1 = -1;
    s-> top2 = size;
    s-> size = size;
    return;
}

void push1(stack *s, int d) {
    if(s->top1 >= s->top2-1 || s->top1 >= s->size-1) return; // stack 1 full
    s->arr[++s->top1] = d; 
    return;
}


void push2(stack *s, int d) {
    if(s->top2 <= s->top1+1 || s->top2 <= 0) return; // stack 2 full
    s->arr[--s->top2] = d;
    return;
}

int pop1(stack *s) {
    return s->arr[s->top1--];  
}

int pop2(stack *s) {
    return s->arr[s->top2++];
}

void print_stack_1(stack s) {
    printf("[\t");
    for(int i = 0; i <= s.top1; i++) {
        printf("%d\t", s.arr[i]);
    }
    printf("\b<-top\t");
    printf("]\n");
    return;
}

void print_stack_2(stack s) {
    printf("[\t");
    for(int i = s.size-1; i >= s.top2; i--) {
        printf("%d\t", s.arr[i]);
    }
    printf("\b<-top\t");
    printf("]\n");
    return;
}
