#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

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
	heap->rear = -1;
	return;
}

void swap(Heap *heap, int i, int j) {
	// Make sure that the indices are valid
	if (i >= heap->size || i < 0 || j >= heap->size || j < 0) {
		return;
	}

	int temp = heap->h[i];
	heap->h[i] = heap->h[j];
	heap->h[j] = temp;

	return;
}

void insert_heap(Heap *heap, int d) {
	if (heap->rear == heap->size - 1) {
		// Heap is full
		return;
	}
	/*
	    approch for insertion:
	    1. insert the element at the end of the Heap
	    2. keep comparing the element with its parent
	    3. swap the element with its parent if the element is greater than its parent

	    At the end of this process, the parent of the element will be greater than the element
	*/
	int i;
	heap->h[++heap->rear] = d;

	i = heap->rear;
	while (i > 0 && heap->h[i] > heap->h[get_parent_index(i)]) {
		// swap the element with its parent
		swap(heap, i, get_parent_index(i));
		i = get_parent_index(i);  // update the value of i to move up the heap and keep checking
	}
	return;
}

void print_heap(Heap *heap) {
	int i;

	printf("[  ");
	for (i = 0; i <= heap->rear; i++) {
		printf("%d  ", heap->h[i]);
	}
	printf("]\n");
	return;
}

// function to heapify the heap: convert the heap into a max heap
void heapify(Heap *heap) {
	// If the heap is empty or contains single element, return as the heap is already a max heap
	if (heap->rear <= 0) {
		return;
	}

	int i = 0;
	while (i < heap->rear) {
		int lchild = lchild_index(i);
		int rchild = rchild_index(i);

		// if the lchild index is outof bounds then return
		if (lchild > heap->rear) {
			return;
		}

		// if the rchild index is outof bounds
		if (rchild > heap->rear) {
			// if the lchild is greater than the parent, swap the parent and lchild
			if (heap->h[lchild] > heap->h[i]) {
				swap(heap, lchild, i);
			}
			return;
		}

		// if the parent is greater than both the children, return
		if (heap->h[i] > heap->h[lchild] && heap->h[i] > heap->h[rchild]) {
			return;
		}

		// NOTE: Next two conditions most likely be not true as we take care of it at the time of insertion
		// if the parent is less than the left child and greater than the right child, swap the parent and left child
		if (heap->h[i] < heap->h[lchild] && heap->h[i] > heap->h[rchild]) {
			swap(heap, i, lchild);
			i = lchild;
		}

		// if the parent is less than the right child and greater than the left child, swap the parent and right child
		else if (heap->h[i] < heap->h[rchild] && heap->h[i] > heap->h[lchild]) {
			swap(heap, i, rchild);
			i = rchild;
		}

		// if the parent is less than both the children, swap the parent with the child which is greater
		else {
			if (heap->h[lchild] > heap->h[rchild]) {
				swap(heap, i, lchild);
				i = lchild;
			} else {
				swap(heap, i, rchild);
				i = rchild;
			}
		}
	}
	return;
}

void heapify_v2(Heap *heap) {
    for (int i = 1; i <= heap->rear; i++) {
        moveUp(heap, i);
    }
}

// Helper function to move up an element to maintain the max-heap property
void moveUp(Heap *heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        
        // If the current node is greater than its parent, swap them
        if (heap->h[i] > heap->h[parent]) {
            swap(heap, i, parent);
            i = parent; // Move up to the parent's index
        } else {
            break;
        }
    }
	return;
}



void heap_sort(Heap *heap) {
	// If the heap is empty or contains single element, return as there is nothign to sort
	if (heap->rear <= 0) {
		return;
	}

	int old_rear = heap->rear;
	for (int i = heap->rear; i > 0; i--) {
		swap(heap, i, 0);
		/*
		    At this point, the heap is a max heap
		    1. swap the first element with the last element
		    2. reduce the size of the heap by 1 (update the rear pointer)
		    3. heapify the heap

		    * why swap? : the largest element is considered to be sorted at each iteration so
		    we swap the largest element with the rear element pointer and reduce the  rear pointer by 1

		    * why heapify? : the heap is no longer a max heap after swapping the first element with the last element
		*/

		// update the rear pointer
		heap->rear--;

		// heapify the unsored heap
		heapify(heap);
	}

	heap->rear = old_rear;
	return;
}