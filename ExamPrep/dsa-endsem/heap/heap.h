// Heap using array

typedef struct heap {
    int *h;
    int size, rear;
} Heap;

void init_heap(Heap *heap, int size);
void insert_heap(Heap *heap, int data);
void print_heap(Heap *heap);
void heap_sort(Heap *heap);
