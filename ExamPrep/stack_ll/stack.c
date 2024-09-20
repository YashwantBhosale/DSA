#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init(stack *s) {
    s->top = NULL;
    return;
}

void push(stack *s, int data) {
    node *nn = (node *) malloc(sizeof(node));
    nn->data = data;
    nn->next = s->top;
    s->top = nn;
    return;
}

int pop(stack *s) {
    int val = s->top->data;
    node *p = s->top;
    s->top = p->next;
    free(p);
    return val;
}

int peek (stack s) {
    return s.top->data;
}

void display(stack s) {
    node *p = s.top;
    printf("[\t");
    while(p) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("]\n"); 
    return; 
}
