#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

void init(queue *q){
    if(!q) return;

    q->head = q->tail = NULL;
    return;
}

void enq(queue *q, int data){
    if(!q) return;

    node *nn = (node *)malloc(sizeof(node));
    if(!nn) return; // Failed to allocate memory

    nn->data = data;
    nn->next = NULL;

    if(!q->head){
        q->head = q->tail = nn;
        return;
    }

    q->tail->next = nn;
    q->tail = nn;
    return;
}

int deq(queue *q){
    if(!q) return INT_MIN;

    if(!q->head) return INT_MIN; // Queue is empty

    node *temp = q->head;
    int data = temp->data;

    q->head = q->head->next;
    free(temp);
    return data;
}

int isEmpty(queue *q){
    if(!q) return 1;

    return q->head == NULL;
}

void destroy(queue *q) {
    if(!q)  return;
    
    if(isEmpty(q)) return;

    node *p = q->head, *t = NULL;

    while(p->next) {
        t = p;
        free(t);
        p = p->next;
    }
    return;
}

void print(queue *q){
    if(!q) return;
    node *p = q->head;
    printf("[  ");
    printf("head->  ");
    while(p){
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("<-tail  ");
    printf("]\n\n");
    return;
}
