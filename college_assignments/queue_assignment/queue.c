#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void qinit(queue *q) {
    if(!q) return;
    /* Initialize head and tail to NULL */
    q->head = NULL;
    q->tail = NULL;
    return;
}

void enq(queue *q, data d) {
    if(!q) return;
    
    node *nn = (node *) malloc(sizeof(node));

    /* If malloc fails to allocate memory the is_full flag in queue data structure will be set, so that we will be able to detect that queue is full */
    if(!nn) {
        q->is_full = 1;
        return;
    }else {
        q->is_full = 0;
    }

    nn -> d = d;
    if(q->head == NULL) {
        q->head = nn;
        q->tail = nn;
        nn->next = nn; // Point to the first node to make the circular list 
    }else {
        q->tail->next = nn;
        nn->next = q->head; // Point to the first node to make the circular list
        q->tail = nn; // Update the tail pointer
    }  
    return;
}

data deq(queue *q) {
    data d = {"", -1}; // Invalid data

    if(!q) return d; // if queue is not initilized return invalid data
    else if(qempty(q)) return d; // if queue is empty return invalid data

    node *p = q->head;
    
    // If queue contains single node
    if(q->head == q->tail) {
        d = p->d;
        q->head = q->tail = NULL;
    }else {
        q->head = p->next; // Update head
        q->tail->next = q->head; // Update next node of the tail to ensure circular queue
        d = p->d; // Removed data
    }
    
    free(p);
    return d;
}


short qempty(queue *q) {
    if(!q) return 1;

    if(q->head == NULL) 
        return 1;
    else 
        return 0;
}

short qfull(queue *q) {
    return q->is_full;
}

void print_queue(queue *q) {
    if(!q) return;

    if(qempty(q)) return;

    printf("[\t");

    node *p = q->head;
    while(p->next != q->head){
        printf("{ %s, %d }\t", p->d.name, p->d.age);
        p=p->next;
    }
    
    if(p->next == q->head)
        printf("{ %s, %d }\t", p->d.name, p->d.age);

    printf("]\n");
    return;
}
