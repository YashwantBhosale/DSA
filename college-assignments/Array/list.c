#include <stdio.h>
#include <stdlib.h>
#include  "list.h"

void append_node(list *l, array *Array) {
	if(!(*l)) {
        printf("This is first node!\n");
		node *new_node = (node *) malloc(sizeof(node));
		*l = new_node;
		(*l) -> Array = Array; 
		(*l) -> next = NULL;
        return;
	}else {
		node *p = *l;
		while(p -> next) {
			p = p -> next;	
		}	
		node* new_node= (node *) malloc(sizeof(node));
		new_node -> Array = Array;
		new_node -> next = NULL;
        p->next = new_node;
	}	
	return;
}

void display_list (list l) {
    if(!l) {
        printf("empty list\n");
        return;
    }
	node *p = l;
	int i = 0;
	while(p) {
	    printf("Array %d: ", i);
        if(p -> Array){
            display(*(p->Array));
        }
        else
            printf("array is empty\n");
		i++;
        p = p -> next;
	}
    printf("sizse in display_list: %d\n", l->Array->size);
    printf("\n");
    return;
}

void init_list(list *l) {
	*l = NULL;	
    return;
}
