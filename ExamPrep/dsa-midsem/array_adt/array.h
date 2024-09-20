typedef struct array {
    int *arr;
    int len;
    int size;
} array;

void append(array *arr, int data);
void insert_at_beg(array *arr, int data);
void insert_at_index(array *arr, int data, int index);
void remove_beg(array *arr);
void remove_at_index(array *arr, int index);
void display(array arr);
