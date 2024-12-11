#include <stdio.h>
#include <stdlib.h>
#include "ascii.h"

void init_ascii(list *l) {
    l = (list *) malloc(sizeof(list));
    l -> head = NULL;
    l -> tail = NULL;
    return;
}

// Helper function to append a node in the list
void insert_beg(list *l, int d) {
    node *nn = (node *) malloc(sizeof(node)); // create new node
    nn -> d = d; // store data
    nn -> prev = NULL;
    nn -> next = l -> head;
    if(l -> head) {
        l -> head -> prev = nn;
    }
    l -> head = nn;
    return;
}

void ascii_of(list *l, char c) {
    int temp = c;
    while(temp) {
        int digit = temp%10;
        insert_beg(l, digit);
        temp /= 10;
    }
    return;
}

void traverse(list l) {
    node *p = l.head;
    printf("[\t");
    while(p) {
        printf("%d,\t", p->d);
        p = p -> next;        
    }
    printf("\b]\n");
    return;
}

void destroy(list *l) {
    node *p = l -> head;
    while(p) {
        node *next = p -> next;
        free(p);
        p = next;
    }
    l -> head = NULL;
    l -> tail = NULL;
    return;
}