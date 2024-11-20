typedef struct heap {
    int *h;
    int size;
    int rear;
} Heap;

void init_heap(Heap *heap, int size);
void swap_heap(Heap *heap, int i, int j);
void heapify(Heap *heap, int index);
void build_max_heap(Heap *heap);