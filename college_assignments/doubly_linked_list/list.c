#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init (list *l) {
    l -> head = NULL;
    l -> tail = NULL;
    return;
}

void insert_end (list *l, int data) {
    if (l -> head == NULL) {
        node *nn = (node *) malloc(sizeof(node));
        nn -> next = NULL;
        nn -> prev = NULL;
        nn -> data = data;
        l -> tail = nn;
        l -> head = nn;
    }else {
        node *nn = (node *) malloc(sizeof(node));
        nn -> next = NULL;
        nn -> data = data;
        l -> tail -> next = nn;
        nn -> prev = l -> tail;
        l -> tail = nn;
    }   
    return;
}

void insert_beg(list *l, int data) {
    node *nn;
    nn = (node *) malloc(sizeof(node));
    if(l -> head == NULL) {
        nn -> next = NULL;
        nn -> prev = NULL;
        l ->head = nn;
    }else {
        nn -> next = l -> head;
        nn -> prev = NULL;
        l -> head -> prev = nn;
        l -> head = nn;
    }
    return;
}

int isEmpty(list l) {
    if(!l.head)
        return 1;
    return 0;
}

void printLR(list l) {
    node *p;
    p = l.head;
    printf("[\t");
    if(!p){
        printf("]");
        return;
    }
    while(p) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("]\n");
    return;
}


void printRL(list l) {
    node *p;
    p = l.tail;
    printf("[\t");
    if(!p) {
        printf("]\n");
        return;
    }
    while(p) {
        printf("%d\t", p -> data);
        p = p->prev;
    }
    printf("]\n");
    return;
}

void remove_end(list *l) {
    node *p = l -> tail;
    if (!p) {
        return;
    }
    if(p -> prev){
        l -> tail = p -> prev;
        p -> prev -> next = NULL;
    }
    else 
        l -> tail = NULL;
    free(p);
    return;
}

void remove_beg(list *l) {
    node *p = l -> head;
    if(!p) {
        return;
    }
    if(p -> next){
        l -> head = p -> next;
        p -> next -> prev = NULL;
    }
    else
        l -> head = NULL;
    free(p);
    
}