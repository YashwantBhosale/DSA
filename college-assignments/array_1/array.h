typedef struct array {
    int *arr;
    int size;
    int len;
} array;

void init(array *a);
void append(array *a, int element);
void insert_at_index(array *a, int index , int element);
void remove_at_index(array *a, int index);
void display(array a);
void max_min(array a);
void swap(int arr[], int i, int j);
void reverse(array *a);
array *merge(array a1, array a2);
void populate(array *a, int size);