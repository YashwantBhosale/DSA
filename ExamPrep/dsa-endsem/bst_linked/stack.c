#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "stack.h"

#define SIZE 200

void init_stack(Stack *s) {
    s->array = (Node **) malloc(sizeof(Node *) * SIZE);
    s->size = SIZE;
    s->top = -1;
}

void push(Stack *s, Node *nn) {
    if(s->top >= s->size-1) return;

    s->array[++s->top] = nn;
    return;
}

Node *pop(Stack *s){
    if(s->top < 0) return NULL;

    Node *node = s->arr[s->top--];
    return node;
}

Node *peek(Stack *s) {
    if(s->top < 0) return NULL;

    return s->arr[s->top];
}

short is_empty(Stack *s) {
    return s->top == -1;
}
