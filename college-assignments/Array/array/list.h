#include "array.h"
typedef struct node {
	array *A;
	struct node *next;
} node;

typedef node * list;
void append_node(list *l, array *array);
void display_list (list l) ;
void init_list(list *l);