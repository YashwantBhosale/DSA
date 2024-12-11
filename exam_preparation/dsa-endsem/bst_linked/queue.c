#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "queue.h"

#define MAX_SIZE 200

void init_queue(Queue *q) {
    q->q = (Node **) malloc(sizeof(Node *) * MAX_SIZE);
    q->front = q->rear = q->count = 0;
}

void enq(Queue *q, Node *n) {
    if(is_full(q)) return;

    q->q[q->rear] = n;
    q->rear = ((q->rear) + 1) % MAX_SIZE;
    q->count++;
    return;
}

Node *deq(Queue *q) {
    if(is_empty(q)) return NULL;

    Node *n = q->q[q->front];
    q->front = ((q->front) + 1) % MAX_SIZE;
    q->count--;
    return n;
}

short is_qfull(Queue *q) {
    return q->count == MAX_SIZE;
}

short is_qempty(Queue *q) {
    return q->count == 0;
}