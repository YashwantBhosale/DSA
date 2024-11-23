#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_sll(list *l) {
	*l = NULL;
	return;
}

/* Function to append new node at the end of the list */
void append(list *l, int data) {
	node *nn = (node *)malloc(sizeof(node));
	nn->data = data;
	nn->next = NULL; /* set next of new node to NULL as it will be last node */

	/* if list is empty, update head */
	if (*l == NULL) {
		*l = nn;
	}
	/* else traverse to the end of the list to append new node */
	else {
		node *p = *l;
		while (p->next)
			p = p->next;
		p->next = nn;
	}
	return;
}

/* Function to display elements in the list */
void traverse(list l) {
	node *p = l;
	printf("[\t");
	while (p) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("]\n");
	return;
}

/* Function to insert node at the begining of the list */
void insert_at_beg(list *l, int data) {
	node *nn = (node *)malloc(sizeof(node));
	nn->data = data;
	nn->next = *l; /* next is current head of the list, *l can be NULL or a node */
	*l = nn;
	return;
}


/* Function to remove element at specified position (Assuming indexing start at position 0) */
void remove_at_pos(list *l, int index) {
    if (index < 0 || !*l) {
        return; // Negative index or empty list
    }

    node *p = *l;

    if (index == 0) {
        // Remove the head node
        *l = p->next;
        free(p);
        return;
    }

    int i = 0;

	/* Conditions in the loop
	 * 1. i < index-1: loop will terminate at one node before the required node so we can modify next link of the previous node
	 * 2. p: this checks whether we have reached end of the list
	 */
    while (i < index - 1 && p) {
        p = p->next;
        i++;
    }

    // Check if the next node exists
    if (!p || !p->next) {
        return; // Index out of bounds
    }

    // Remove the node
    node *q = p->next; /* store address of the node to be deleted */
    p->next = q->next; /* update next node link of previous node */
    free(q);

    return;
}


void insert_at_pos(list *l, int index, int data) {
    if (index < 0) {
        return; // Negative indices are invalid
    }

    node *nn = (node *)malloc(sizeof(node));
    if (!nn) {
        return; // Memory allocation failure
    }
    nn->data = data;

    if (index == 0) {
        nn->next = *l; // Insert at the head
        *l = nn;
        return;
    }

    int i = 0;
    node *p = *l;

    // Traverse to the node before the insertion point
    while (i < index-1 && p) {
        p = p->next;
        i++;
    }

    // If we couldn't reach the correct position, free allocated memory and return
    if (i != index - 1 || !p) {
        free(nn);
        return;
    }

    // Insert the new node
    nn->next = p->next;
    p->next = nn;
    return;
}


/* Function to find out length of the list */
int len(list l) {
	node *p = l;
	int len = 0;
	while (p) {
		p = p->next;
		len++;
	}
	return len;
}
