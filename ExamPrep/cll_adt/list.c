#include <stdio.h>
#include <stdlib.h>
#include "cll.h"

void init_cll(list *l) {
    *l = NULL;
    return;
}

void insert_beg(list *l, int data) {
    node *nn = (node *) malloc(sizeof(node)), *p = *l;
    nn -> data = data;
    nn -> next = *l;
    if(*l == NULL) {
        *l = nn;
        nn -> next = nn;
    }else {
        while(p->next != *l)
            p = p->next;
        p -> next = nn;
        *l = nn;
    }
    return;        
}

void insert_end(list *l, int data) {
    node *nn = (node *) malloc (sizeof(node));
    nn -> data = data;
    if(*l == NULL) {
        *l = nn;
        nn -> next = nn;
    }else {
        node *p = *l;
        while(p -> next != *l) {
            p = p->next;
        }
        nn -> next = *l;
        p -> next = nn;
    }
    return;
}

void insert_pos(list *l, int pos, int data) {
    node *nn = (node *) malloc (sizeof(node)), *p = *l;
    nn -> data = data;
    int i = 0;
    while(i < pos-1 && p -> next != *l){
        i++;
        p = p->next;
    }
    if(i != pos-1)
        return; // invalid index
    
    nn->next = p->next;
    p->next = nn;
    return;
}

void remove_beg(list *l) {
    if(*l == NULL)
        return;
    node *p = *l, *q = *l;
    while(q->next != *l)
        q = q->next;
    *l = p -> next;
    q->next = *l;
    free(p);
    return;
}

void remove_end(list *l) {
    if(*l == NULL)
        return;
    node *p = *l, *q;
    while(p->next->next != *l)
        p = p->next;
    q = p->next;
    p->next = *l;
    free(q);
    return;
}

void remove_pos(list *l, int pos) {
    node *p = *l, *q = NULL; 
    int i = 0;
    while(i < pos-1 && p->next != *l){
        p = p->next;
        i++;
    }
    if(i != pos-1)
        return; //invalid index
    q = p->next;

    // Unhandled cases if pos = 0 or pos  = len-1

    p->next = q->next;
    free(q);
    return;
}

int list_len(list l) {
    node *p = l;
    int len = 0;
    while(p) {
        p = p->next;
        len++;
        if(p == l)
            break;
    }
    return len;
}

void swap(node *n1, node *n2) {
    int temp = n1 -> data;
    n1 -> data = n2 -> data;
    n2 -> data = temp;
    return;
}

void sort(list *l) {
    int len = list_len(*l);
    node *q = NULL;
    for(int i = 0; i < len-1; i++) {
        q = *l;
        int j = 0;
        while(j < (len-i-1) && q->next!=*l){
            if(q->data > q->next->data)
                swap(q, q->next);
            j++;
            q = q->next;
        }
    }
    return;
}

void display(list l) {
    if(!l){
        printf("[]");
        return;
    }
    node *p = l;
    printf("[\t");
    printf("%d\t", p->data);
    p = p->next;
    while(p != l) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("]\n");
    return;
}
