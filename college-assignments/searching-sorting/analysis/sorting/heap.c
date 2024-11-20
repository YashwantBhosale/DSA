#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "helper_functions.h"

// utility functions used throughout the program
int get_parent_index(int index) {
	return (index - 1) / 2;
}
int lchild_index(int index) {
	return 2 * index + 1;
}
int rchild_index(int index) {
	return 2 * index + 2;
}

void init_heap(Heap *heap, int size) {
	heap->h = (int *)malloc(sizeof(int) * size);
	heap->size = size;
	heap->rear = size-1;
	return;
}

void swap_heap(Heap *heap, int i, int j) {
	// Make sure that the indices are valid
	if (i >= heap->size || i < 0 || j >= heap->size || j < 0) {
		return;
	}

	int temp = heap->h[i];
	heap->h[i] = heap->h[j];
	heap->h[j] = temp;

	return;
}


/*
    * Heapify function
    It takes two arguments:
    1. Heap pointer
    2. Index of the node to heapify

    The function recursively heapifies the subtree formed by the node at the given index.
    It assumes that the subtrees rooted at the left and right children of the node are already max-heaps.

    Why this is useful?
    this is useful when we want to build a max heap from an array of elements in O(n) time complexity.
    We can start from the last non-leaf node and heapify all the nodes in reverse order.
    This way, we can build a max heap in O(n) time complexity.
*/
void heapify(Heap *heap, int index) {
    int left = lchild_index(index);
    int right = rchild_index(index);
    int largest = index;

    // Find the largest element among the current node, left child, and right child
    if (left <= heap->rear && heap->h[left] > heap->h[largest]) {
        largest = left;
    }
    if (right <= heap->rear && heap->h[right] > heap->h[largest]) {
        largest = right;
    }

    // If the largest element is not the current node, swap the current node with the largest element
    if (largest != index) {
        swap_heap(heap, index, largest);
        heapify(heap, largest);
    }
    return;
}



void build_max_heap(Heap *heap) {
    /*
        Why heap->rear / 2?
        So generally heap array is divided into two parts:
        1. internal nodes
        2. leaf nodes
        leaf nodes are already max-heaps, so we don't need to heapify them.
        We only need to heapify the internal nodes.
        The last internal node is at index heap->rear / 2.
        So we start from this node and heapify all the nodes in reverse order.

        Why reverse order?
        Because we are building a max heap, and the heapify function assumes that the left and right subtrees are already max-heaps.
        So we need to start from the last internal node and move towards the root.
    */
    for (int i = heap->rear / 2; i >= 0; i--) {
        heapify(heap, i);
    }
    return;
}

