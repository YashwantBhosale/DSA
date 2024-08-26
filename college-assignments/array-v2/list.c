#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(list *head) {
    *head = NULL;
    return;
}

void append_node(list *head, array *a) {
    node *p, *new_node;
    new_node = (node *) malloc(sizeof(node));
    if(new_node){
        new_node -> A = a;
        new_node -> next = NULL;
    }else {
        return;
    }
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    p = *head;
    while((p -> next)!=NULL) 
        p = p->next;
    p -> next = new_node;
    return;
}

void display_list(list head) {
    printf("{\n");
    node *p;
    p = head;
    int i = 0;
    while(p) {
        printf("array: %d\t", i+1);
        display(*(p->A));
        i++;
        p = p->next;
    }
    printf("}\n");
    return;
}