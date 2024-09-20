#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init(list *l) {
    l -> head = NULL;
    l -> tail = NULL;
    return;
}

void insert_end(list *l, int data) {
    node *nn = (node *) malloc(sizeof(node));
    nn -> data = data;
    if (!l->head) {
        l -> head = nn;
        nn -> prev = NULL;
        nn -> next = NULL;
        l -> tail = nn;
    } else {
        l -> tail -> next = nn;
        nn -> prev = l -> tail;
        l -> tail = nn;
        nn -> next = NULL;
    }
    return;
}

void insert_from_begining(list *l, int data) {
    node *nn = (node *) malloc(sizeof(node));
    nn -> data = data;
    nn -> prev = NULL;
    if(!l->head) {
        l -> head = nn;
        nn -> next = NULL;
        l -> tail = nn;
    }else {
        nn -> next = l -> head;
        l -> head -> prev = nn;
        l -> head = nn;
    }
    return;
}

void insert_at_index(list *l, int data, int index) {
    int i = 0; 
    node *nn = (node *) malloc(sizeof(node)), *p = l->head;
    nn -> data = data;
    while( i < index - 1 && p -> next) {
        p = p -> next;
        i++;
    }
    
    if(i != index-1) 
        return;

    p -> next -> prev = nn;
    nn -> next = p -> next;
    nn -> prev = p;
    p -> next = nn;
    return;
}

void remove_at_index(list *l, int index) {
    node *p = l->head, *q = NULL;
    int i = 0;
    while(i < index-1 && p -> next) {
        p = p->next;
        i++;
    }
    if(i != index-1)
        return;
    
    q = p->next;
    if(!q)
        return;
    p -> next = q -> next;
    
    if(q->next)
        q -> next -> prev = p;
    free(q);
    return;
}

void swap(node *n1, node *n2) {
    if(!n1 || !n2)
        return;
    int temp = n1 -> data;
    n1 -> data = n2 -> data;
    n2 -> data = temp;
    return;
}

int len(list l) {
    int length = 0;
    node *p = l.head;
    while(p) {
        p  = p -> next;
        length++;
    }
    return length;
}

void sort(list l) {
    node *p = l.head, *q = NULL;
    int list_len = len(l), sorted = 0; // keep track of sorted elements to avoid repeated comparisons
    while(p -> next) {
        q = l.head;
        int j = 0;
        while(j < (list_len - sorted - 1) && q -> next) {
            if(q -> data > q -> next -> data)
                swap(q, q->next);
            j++;
            q = q->next;
        }
        sorted++;
        p = p->next;
    } 
    return;
}

void remove_end(list *l) {
    if (!l->tail)
        return;
    node *p = l -> tail;
    l -> tail = p -> prev;
    l -> tail -> next = NULL;
    free(p);
    return;
}

void remove_beg(list *l) {
    if(!l->head)
        return;
    node *p = l -> head;
    l -> head = p -> next;
    l -> head -> prev = NULL;
    free(p);
    return;
}

void remove_duplicates(list *l) {
    int list_len = len(*l);
    node *p = l->head, *q=NULL;
    for(int i = 0; i < list_len-1; i++) {
        q = p->next;
        for(int j = i+1; j < list_len; j++) {
            if(q->data == p->data)
                remove_at_index(l, j);
            q = q->next;
        }
        list_len = len(*l);
        p = p->next;
    }
    return;
}

short int is_palindrome(list l) {
    node *p = l.head, *q = l.tail;
    while(p != q){
        if(p -> data != q ->data)
            return 0;
        p = p->next;
        q = q->prev;
    }
    return 1;
}

void printLR(list l) {
    node *p = l.head;
    printf("[\t");
    while(p) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("]\n");
    return;
}

void printRL(list l) {
    node *p = l.tail;
    printf("[\t");
    while(p) {
        printf("%d\t", p->data);
        p = p->prev;
    }
    printf("]\n");
    return;
}
