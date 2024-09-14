#include <stdio.h>
#include <stdlib.h>
#include "cll.h"

void init_cll(list *l) {
    *l = NULL;
    return;
}

void insert_beg(list *l, int data) {
    node *nn = (node *) malloc(sizeof(node)), *p = NULL;
    nn -> data = data;
    if(*l == NULL) {
        *l = nn;
        nn -> next = *l;
    } else {
        p = *l;
        nn -> next = *l;
        while(p -> next != *l) {
            p = p -> next;
        }
        p -> next = nn;
        *l = nn;
    }
    return;
}

void insert_end(list *l, int data) {
    node *nn = (node *) malloc(sizeof(node)), *p = NULL;
    nn->data = data;
    if(*l == NULL) {
        *l = nn;
        nn -> next = *l;
    } else {
        p = *l;
        while(p -> next != *l) {
            p = p->next;
        }
        p->next = nn;
        nn->next = *l;
    }
    return;
}

void insert_pos(list *l, int pos, int data) {
    int i = 0;
    node *nn = (node *) malloc(sizeof(node)), *p = NULL;
    nn -> data = data;
    p = *l;
    if(!p) {
        *l = nn;
        nn -> next = *l;
    }else {
        while(i < pos-1) {
            if(p -> next == *l)
                return; // Invalid position
            p = p->next;
            i++;
        }
        nn -> next = p->next;
        p -> next = nn;
    }
    return;
}

void remove_beg(list *l) {
    if(*l == NULL) 
        return;
    node *p = *l, *q = *l;
    while(q -> next != *l) {
        q = q->next;
    }
    *l = (*l) -> next;
    q -> next = *l;
    free(p);
    return;
}

void remove_end(list *l) {
    if(*l == NULL)
        return;
    node *p = *l, *q = NULL;
    while(p -> next != *l) {
        p = p->next;
        if(p -> next -> next == *l) {
            q = p;
        }
    }
    q -> next = *l;
    free(p);
    return;
}

void remove_pos(list *l, int pos) {
    if(*l == NULL)
        return;
    int i = 0;
    node *p = *l, *q = NULL;
    while(i < pos-1) {
        if(p -> next == *l)
            return; // Invalid positionI
        p = p->next;
        i++;
    }
    q = p -> next;
    p -> next = q -> next;
    free(q);
    return;
}

void swap(node *n1, node *n2) {
    int temp = n1 -> data;
    n1 -> data = n2 -> data;
    n2 -> data = temp;
    return;
}

/* Bubble sort on linked list O(n^2) */
void sort(list *l) {
    node *p, *q;
    p = *l;
    while(p -> next != *l) {
        q = *l;
        while(q -> next != *l) {
            if(q -> data > q -> next -> data)
                swap(q, q->next);
            q = q -> next;
        }
        p = p->next;
    }
    return;
}

void display(list l ) {
    node *p = l;
    printf("[\t");
    while(p && p -> next != l) {
        printf("%d\t", p->data);
        p = p -> next;
    }
    printf("%d\t", p->data);
    printf("]\n");
    return;
}
