#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "stack.h"
#include "queue.h"

void init_bst(BST *bst) {
	*bst = NULL;
	return;
}

void insert(BST *bst, int data) {
	Node *nn = (Node *)malloc(sizeof(Node));
	if (!nn) return;

	nn->data = data;
	nn->lchild = nn->rchild = NULL;

	if (*bst == NULL) {
		*bst = nn;
		return;
	}

	Node *p = *bst, *q = NULL;

	while (p) {
		q = p;
		if (data < p->data) {
			p = p->lchild;
		} else if (data > p->data) {
			p = p->rchild;
		} else {
			free(nn);
			return;
		}
	}

	if (data > q->data) {
		q->rchild = nn;
	} else {
		q->rchild = nn;
	}

	return;
}

void remove(BST *bst, int data) {
	// step 1: search
	Node *p = *bst, *q = NULL;
	while (p) {
		if (p->data == data) {
			break;
		}
		q = p;

		if (p->data < data) {
			p = p->rchild;
		} else {
			p = p->lchild;
		}
	}
	if (!p) return;  // Node Not Found!

	// At this point, p points to the node to be removed and q points to the parent

	// step 2: delete the node

	// case 1: if it is the leaf node
	if (p->lchild == NULL && p->rchild == NULL) {
		// 1) if node to be removed is the root node itself
		if (q == NULL) *bst = NULL;

		// 2) if node to be removed is the left child of the parent
		else if (q->lchild == p)
			q->lchild = NULL;

		// 3) if node to be removed is the right child of the parent
		else
			q->rchild = NULL;

		free(p);
		return;
	}

	// case 2: if it is a node with single child
	if (p->lchild == NULL || p->rchild == NULL) {
		Node *child = p->lchild ? p->lchild : p->rchild;

		// 1) if node to be removed is the root node itself
		if (q == NULL) *bst = child;

		// 2) if node to be removed is left child of the parent
		else if (q->lchild == p)
			q->lchild = child;

		// 3) if node to be removed is right child of the parent
		else
			q->rchild = child;

		free(p);
		return;
	}

	// case 3: if it is a node with two children

	// step 1: find the inorder successor or inorder predeccessor
	// inorder successor is smallest element in right subtree and inorder predeccessor is largest element in left subtree

	Node *successor = p->rchild, *parent = p;

	while (successor->lchild) {
		parent = successor;
		successor = successor->lchild;
	}

	// step 2: replace the data of the node to be removed with the data of the successor
	p->data = successor->data;

	// step 3: delete the successor

	// case 1: if the initial value of successor (p->rchild) did not have the lchild
	// Basically, pointers won't update in this case, so we might accidently udate lchild of p
	if (parent == p) {
		parent->rchild = successor->rchild;
	}

	// case 2: successor had lchild and pointers were updated
	else {
		parent->lchild = successor->rchild;
	}

	free(successor);
	return;
}
void destroy(BST *bst) {
	if (!bst || *bst == NULL) return;

	destroy_tree(*bst);
	*bst = NULL;
	return;
}

void destroy_tree(BST tree) {
	if (!tree) return;

	destroy_tree(tree->lchild);
	destroy_tree(tree->rchild);

	free(tree);
	return;
}

// Traversals

// 1. inorder traversal

void inorder_recursive(BST bst) {
	if (!bst) return;

	inorder_recursive(bst->lchild);
	printf("%d  ", bst->data);
	inorder_recursive(bst->rchild);
	return;
}

void inorder(BST bst) {
	if (!bst) return;

	Node *p = bst;
	Stack s;
	init_stack(&s);

	while (p || is_empty(&s)) {
		while (p->lchild) {
			push(&s, p);
			p = p->lchild;
		}

		Node *current = pop(&s);

		if (current) {
			printf("%d ", current->data);
			p = current->rchild;
		}
	}
}

// 2. preorder
void preorder_recursive(BST bst) {
	if (!bst) return;

	printf("%d ", bst->data);
	preorder_recursive(bst->lchild);
	preorder_recursive(bst->rchild);
}

void preorder(BST bst) {
	if (!bst) return;

	Node *p = bst;
	Stack s;
	init_stack(&s);
	push(&s, p);

	while (!is_empty(&s)) {
		Node *popped = pop(&s);
		printf("%d ", popped->data);

		if (popped->rchild) {
			push(&s, popped->rchild);
		}

		if (popped->lchild) {
			push(&s, popped->lchild);
		}
	}
}

// 3. post order
void postorder_recursive(BST bst) {
	if(!bst) return;

    postorder_recursive(bst->lchild);
    postorder_recursive(bst->rchild);
    printf("%d ", bst->data);
}

void postorder(BST bst) {
    if(!bst) return;

    Node *p = bst;
    Stack s1, s2;
    init_stack(&s1);
    init_stack(&s2);

    push(&s, p);

    while(!is_empty(&s1)) {
        Node *popped = pop(&s1);
        push(&s2, popped);

        if(popped->rchild) push(&s1, popped->rchild);

        if(popped->lchild) push(&s1, popped->lchild);
    }

    while(!is_empty(&s2)) {
        printf("%d ", pop(&s)->data);
    }
}

// 4. Level order traversal / BFS
void levelorder(BST bst) {
    if(!bst) return;

    Node *p = bst;
    Queue q;

    init_queue(&q);
    enq(&q, p);

    while(is_qempty(&q)) {
        Node *popped = deq(&q);
        printf("%d ", popped->data);

        if(popped->lchild) enq(&q, popped->lchild);

        if(popped->rchild) enq(&q, popped->rchild);
    }
}