#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void init_bst(bst *t) {
	t->root = NULL;
	t->count = 0;
	return;
}

void insertNode(bst *t, int month) {
	node *nn = (node *)malloc(sizeof(node));
	if (!nn) {
		return;  // Memory allocation failed
	}

	nn->month = month;
	nn->lchild = nn->rchild = NULL;

	// Case 1: Empty tree
	if (t->root == NULL) {
		t->root = nn;
		nn->parent = NULL;  // Root has no parent
		t->count++;
		return;
	}

	// Case 2: Non-empty tree
	node *p = t->root, *q = NULL;
	while (p) {
		q = p;
		if (month < p->month) {
			p = p->lchild;
		} else if (month > p->month) {
			p = p->rchild;
		} else {
			// Duplicate value
			free(nn);
			return;
		}
	}

	// Set the new node as a child of q
	if (month > q->month) {
		q->rchild = nn;
	} else {
		q->lchild = nn;
	}

	// Set the parent of the new node
	nn->parent = q;
	t->count++;
    return;
}

void print_month(int month) {
    switch (month) {
        case January:
            printf("January, ");
            break;
        case February:
            printf("February, ");
            break;
        case March:
            printf("March, ");
            break;
		case April:
			printf("April, ");
			break;
		case May:
			printf("May, ");
			break;
        case June:
            printf("June, ");
            break;
        case July:
            printf("July, ");
            break;
        case August:
            printf("August, ");
            break;
        case September:
            printf("September, ");
            break;
        case October:
            printf("October, ");
            break;
        case November:
            printf("November, ");
            break;
        case December:
            printf("December, ");
            break;
        default:
            printf("%d is Invalid month, ", month);
    }
    return;
}

void inorder(bst *t) {
	stack s;
	init(&s, t->count);
	node *p = t->root;
	while (p != NULL || !is_empty(&s)) {
		// Traverse to the leftmost node

		while (p != NULL) {
			push(&s, p);
			p = p->lchild;
		}

		// Pop from the stack and print the month
		node *popped = pop(&s);
		if(popped){
        	print_month(popped->month);
			// Move to the right child
			p = popped->rchild;
		}

	}

    printf("\n");
	return;
}

void inorder_v2(bst *t) {
    stack s;
    init(&s, t->count);
    node *p = t->root;

    while(1) {
        if(p != NULL) {
            push(&s, p);
            p = p->lchild;
        }else {
            if(is_empty(&s)) break;

            node *popped = pop(&s);
            print_month(popped->month);
            p = popped->rchild;
        }
    }

	printf("\n");
    return;
}

void postorder(bst *t) {
	/*
		approach: 
		1. Push the root to s1
		2. Pop the stack and push the popped node to s2
		3. Push the left child first and then the right child
		4. Repeat step 2 and 3 until the stack is empty
	*/

	stack s1, s2;
	init(&s1, t->count);
	init(&s2, t->count);

	node *p = t->root;
	push(&s1, p); // Push the root to s1

	while(!is_empty(&s1)) {
		node *popped = pop(&s1);
		push(&s2, popped); // push the popped node to s2

		if(popped->lchild) {
			push(&s1, popped->lchild);
		}

		if(popped->rchild) {
			push(&s1, popped->rchild);
		}
	}

	// print the postorder traversal
	while(!is_empty(&s2)) {
		node *popped = pop(&s2);
		print_month(popped->month);
	}

	printf("\n");
	return;
}

void preorder(bst *t) {
	/*
		approach:
		1. Push the root to the stack
		2. Pop the stack and print the month
		3. Push the right child first and then the left child
		4. Repeat step 2 and 3 until the stack is empty

	*/	


	stack s;
	init(&s, t->count);

	node *p = t->root;
	push(&s, p);

	while(!is_empty(&s)) {
		node *popped = pop(&s);
		print_month(popped->month);

		// push the right child first, as stack is LIFO
		if(popped->rchild) {
			push(&s, popped->rchild);
		}

		// push the left child
		if(popped->lchild) {
			push(&s, popped->lchild);
		}
	}

	printf("\n");
	return;
}

/*
	approach for level order traversal:
	1. Create a queue
	2. Enqueue the root
	3. Dequeue the node and print the month
	4. Enqueue the left child first and then the right child
	5. Repeat step 3 and 4 until the queue is empty
*/

void removeNode(bst *t, int month) {
	/*
	    3 cases:
	    1. node with no children (leaf node)
	    2. node with single child
	    3. node with two children

	    for node with no children:
	    we can simply detach the link and free the node

	    for node with single child:
	    we can replace the node with its child and free the node

	    for node with two children:
	    1. Search the node
	    2. Find inorder successor
	    3. Replace the node with inorder successor
	    4. Delete the inorder successor

	    Inorder successor is the leftmost node of the right subtree or minimum of the right subtree
	    Inorder predecessor is the rightmost node of the left subtree or maximum of the left subtree
	*/
	node *p = t->root, *q = NULL;

	// search the node
	while (p) {
		if (p->month == month) {
			break;
		}
		q = p;
		if (p->month < month) {
			p = p->rchild;
		} else {
			p = p->lchild;
		}
	}

	if (p == NULL) {
		return;  // Node not found
	}

	// case 1: node with no children
	if (p->lchild == NULL && p->rchild == NULL) {
		if (q == NULL) {
			t->root = NULL;
		} else if (q->lchild == p) {
			q->lchild = NULL;
		} else {
			q->rchild = NULL;
		}
		free(p);
		t->count--;
		return;
	}

	// case 2: node with single child
	if (p->lchild == NULL || p->rchild == NULL) {
		node *child = p->lchild ? p->lchild : p->rchild;
		if (q == NULL) {
			t->root = child;
		} else if (q->lchild == p) {
			q->lchild = child;
		} else {
			q->rchild = child;
		}
		free(p);
		t->count--;
		return;
	}

	// case 3: node with two children
	node *successor = p->rchild, *successor_parent = p;  // Here, we may drop the parent pointer, as we have the parent pointer in the node structure

	while (successor->lchild) {
		successor_parent = successor;
		successor = successor->lchild;
	}

	// Replace the node with the successor
	p->month = successor->month;

	/*
	    important case: if the successor's lchild is null, that is pointers did not move in the above while loop
	    e.g. suppose 30 is the node to be deleted and 40 is the successor
	        50
	        /\
	       30 60
	      /\
	     20 40
	         \
	         45
	         /\
	        43 44

	    Here, we need to replace 30 with 40 and 40's right child should be 45

        incorrect code:
        // If the successor has a right child, then replace the successor with its right child
	    if(successor->rchild) {
	        successor_parent->lchild = successor->rchild; // As the successor was the left child of the parent
	    }
	    else {
	        successor_parent->lchild = NULL;
	    }
        
	*/

    // pointer did not move in the above while loop
	if (successor_parent == p) {
		successor_parent->rchild = successor->rchild;
	} 
    
    // pointer moved in the above while loop
    else {
		successor_parent->lchild = successor->rchild;
	}

	free(successor);
	t->count--;

	return;
}

void destroyTree(bst *t) {
    node *p = t->root;
    
    stack s;
    init(&s, t->count);


    // similar to inorder traversal: visit each node in inorder fashion and free the node instead of printing
    while(p != NULL || !is_empty(&s)) {
        while(p != NULL) {
            push(&s, p);
            p = p->lchild;
        }

        node *popped = pop(&s);
        node *right = popped->rchild;
        free(popped);
        p = right;
    }

    t->root = NULL;
    t->count = 0;
    return;
}
