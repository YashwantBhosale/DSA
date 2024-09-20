#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_sll(list *l) {
    *l = NULL;
    return;
}

void append(list *l, int data) {
    node *nn = (node *) malloc(sizeof(node));
    nn -> data = data;
    nn -> next = NULL; // As this will be last node
    if(*l == NULL) {
        *l = nn;
    }else {
        node *p = *l;
        while(p -> next) {
            p = p->next;
        }
        p -> next = nn;
    }
    return;
}

void insert_at_beg(list *l, int data) {
    node *nn = (node *) malloc(sizeof(node));
    nn -> data = data;
    if(*l == NULL) {
        nn -> next = NULL;
        *l = nn;
    }else {
        nn -> next = *l;
        *l = nn;
    } 
    return;
}

void insert_at_pos(list *l, int data, int pos) {
    node *nn = (node *) malloc(sizeof(node)), *p = *l;
    nn -> data = data;
    int i = 0;
    while(i < pos-1 && p -> next) {
        p = p->next;
        i++;
    } 
    // we are at pos - 1
    nn->next = p->next;
    p->next = nn;
    return;
}

void remove_at_pos(list *l, int pos) {
    int i = 0;
    node *p = *l, *q;
    while(i < pos-1 && p->next) {
        p = p -> next;
        i++;
    }
    if(i != pos-1)
        return;
    q = p->next;
    p->next = p->next->next;
    free(q);
    return;
}

int len(list l) {
    node *p = l;
    int length = 0;
    while(p){
        p = p->next;
        length++;
    }
    return length;
}

void traverse(list l) {
    node *p = l;
    printf("[\t");
    while(p) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("]\n");
    return;
}

