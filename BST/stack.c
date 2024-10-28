#include "bst.h"
#include "stack.h"

/* Function to initialize stack */
void init(stack *s, int size) {
	s->arr = (node **)malloc(size * sizeof(node *));
	s->top = -1;
	s->size = size;
	return;
}

/* Function to push an element in the stack */
void push(stack *s, node *n) {
	if (s->top >= s->size - 1) {
		return;  // stack full
	}

	s->top++;
	s->arr[s->top] = n;
	return;
}

/* Function to pop an element from the stack */
node *pop(stack *s) {
	if (s->top < 0) {
		return NULL;
	}

	node *n = s->arr[s->top];
	s->top--;
	return n;
}

short is_empty(stack *s) {
	return s->top == -1;
}

/* Function to peek into the stack */
node *peek(stack *s) {
	if (is_empty(s)) {
		return NULL;
	}

	return s->arr[s->top];
}

/* Function to display the stack */
void display(stack s) {
	printf("[\t");
	for (int i = s.top; i >= 0; i--) {
		printf("%d\t", s.arr[i]->month);
	}
	printf("]\n");
	return;
}