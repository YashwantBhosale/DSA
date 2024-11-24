#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"

int lchild(int i) {
    return (2*i + 1);
}

int rchild(int i) {
    return (2*i + 2);
}

int parent(int i) {
    return (i-1)/2;
}

void init_heap(Heap *heap, int size) {
    heap->size = size;
    heap->h = (int *) malloc(sizeof(int) * size);
    heap->rear = -1;
    
    for(int i=0; i<size; i++) {
        heap->h[i] = INT_MIN;
    }

    return;
}

void swap_heap(Heap *heap, int i, int j) {
    if(i < 0 || i >= heap->size || j < 0 || j >= heap->size) 
        return;
    
    int temp = heap->h[i];
    heap->h[i] = heap->h[j];
    heap->h[j] = temp;
    return;
}

void insert_heap(Heap *heap, int data) {
    /*
     * APPROACH
     * we will insert element at the end and move up untill it is placed at the correct position
     * Time Complexity of this operation is O(log n). as max height of tree is log n
    */
    if(heap->rear >= heap->size-1) {
        return; // heap is full
    }

    heap->h[++heap->rear] = data;

    int i = heap->rear;

    while(i > 0 && heap->h[i] > heap->h[parent(i)]) {
        swap(heap, i, parent(i));
        i = parent(i);
    }

    return;
}

// ith node needs to be rearranged in order to make a max heap
// except for ith node the whole tree is a max heap
void heapify_recursive(Heap *heap, int i) {
    int left = lchild(i);
    int right = rchild(i);
    int largest = i;

    if(left <= heap->rear && heap->h[left] > heap->h[largest]) {
        largest = left;
    }

    if(right <= heap->rear && heap->h[right] > heap->h[largest]){
        largest = right;
    }

    if(largest != i) {
        swap(heap, i, largest);
        heapify_recursive(heap, largest);
    }
    
    // here the base condition for the recursion is basically largest == i, i.e largest element is parent of the two subtrees so everything else must be correct.
    return;
}

// This can be done in O(n) time complexity 
// little unintuitive but true
void build_max_heap(Heap *heap) {
    // iterate over internal nodes starting from the last internal node
    for(int i = heap->rear / 2; i >= 0; i--) {
        heapify_recursive(heap, i);
    }
    return;
}

void heap_sort(int *arr, int len) {
    Heap h;
    init_heap(&heap, len);
    free(heap.h);

    heap.h = arr;
    h.rear = len-1;
    build_max_heap(&h);
    
    int old_rear = h.rear;

    for(int i = h.rear; i>=0 ;i--) {
        swap_heap(&h, i, 0);
        h.rear--;
        heapify(&h, 0); 
    }
    
    heap.rear = old_rear;
    return;
}

