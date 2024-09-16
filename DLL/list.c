#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "list.h"

void init (list *l) {
    l -> head = NULL;
    l -> tail = NULL;
    return;
}

int isEmpty(list l) {
    if(!l.head)
        return 1;
    return 0;
}

void insert_end (list *l, int data) {
    node *nn = (node *) malloc(sizeof(node));
    nn -> next = NULL;
    if (l -> head == NULL) {
        nn -> prev = NULL;
        nn -> data = data;
        l -> tail = nn;
        l -> head = nn;
    }else {
        nn -> data = data;
        l -> tail -> next = nn;
        nn -> prev = l -> tail;
        l -> tail = nn;
    }   
    return;
}

void insert_from_begining(list *l, int data) {
    node *nn;
    nn = (node *) malloc(sizeof(node));
    nn->data = data;
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

void insert_at_index(list *l, int data, int index) {
    int i = 0;
    node *nn = (node *) malloc(sizeof(node)), *p = l->head;
    nn -> data = data;
    while(i < index-1) {  // index-1 because we want to reach just one node before the required node
        if(p->next == NULL)
            return; // invalid index
        p = p->next;
        i++;
    }
    nn -> next = p -> next;
    nn -> prev = p;
    nn -> next -> prev = nn;
    p -> next = nn;
    return;
}

void remove_at_index(list *l, int index) {
    int i = 0;
    node *p = l -> head, *q=NULL;
    while(i < index-1) { // index-1 because we want to reach just one node before the required node
        if(p->next == NULL)
            return; // invalid index
        p = p -> next;
        i++;
    }
    q = p->next;
    p -> next = q -> next;
    q -> next -> prev = p;
    free(q);
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
    return;
}

void swap(node *n1, node *n2) {
    int temp = n1 -> data;
    n1 -> data = n2 -> data;
    n2 -> data = temp;
    return;
}

int list_len(list l) {
    int len=0;
    node *p = l.head;
    while(p) {
        len++;
        p = p->next;
    }
    return len;
}

void sort(list l) {
    node *p = l.head, *q = NULL;
    int len = list_len(l), sorted = 0; // Keep track of no. of sorted elements to avoid repeated comparisons
    while(p->next) {
        q = l.head;
        int j = 0;
        while(j < (len-sorted) && q->next) {
            if(q->data > q->next->data)
                swap(q, q->next);
            q = q->next;
            j++;
        }
        p = p->next;
        sorted++;
    }
    return;
}

/* Hash map functions */
void init_ht(int *ht, int len) {
    for (int i = 0; i < len; i++) {
        ht[i] = INT_MIN;
    }
    return;
}

int hash(int key, int len) {
    int hash = key * 31; // Multiply by a prime number
    return hash % len;
}


short int insert(int *arr, int element, int index, int len) {
    if(arr[index] == INT_MIN) {
        arr[index] = element;
    }
    else {
        if(arr[index] == element)
            return 0;
        while(arr[index] != INT_MIN) {
            if(arr[index] == element)
                return 0;
            index = (index+1) % len;
        }
        arr[index] = element;
    }   
    return 1;
}
void print_array(int *arr, int len) {
    printf("[\t");
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("]\n");
    return;
}

void remove_duplicates(list *l) {
    node *p = l -> head;
    // Hash map for elements
    int len = list_len(*l);
    int hash_table[len];
    init_ht(hash_table, len);
    for (int i = 0; i < len; i++) {
        int index = hash(p -> data, len);
        node *next = p->next;
        if(!insert(hash_table, p->data, index, len)) {
            node *q = p -> prev;
            q -> next = p -> next;
            p -> next -> prev = q;
            free(p);
        }
        p = next;
    }
}
/* End of hash map declarations */

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