/*
Write a Menu Driven Program in C to implement the following operations on an array of integers using functions by passing the array and its size to the function. Populate the array elements using rand( ).
Operations:
1. init()
2. append()
3. insert_at_index()
4. remove_at_index()
5. display()
6. max() /min () // Displays maximum/minimum element of an array
7. reverse() //Reverse the elements of array
8. merge() // Merges two arrays
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct array {
    int *arr;
    int size;
    int len;
} array;

void init(array *a, int size) {
    a -> arr = (int *) malloc(sizeof(int) * size);
    a -> size = size;
    a -> len = 0;
}

void append(array *a, int element) {
    if(a -> len > a -> size)
        return;
    a -> arr[a -> len] = element;
    a -> len++;
}

void insert_at_index(array *a, int index , int element) {
    if(index>=a->size-1)
        return;
    int i;
    for(i = a->size-2; i > index; i--)
        a->arr[i+1] = a->arr[i];
    a -> arr[i] = element;
}

void remove_at_index(array *a, int index) {
    for(int i = index; i < a->size-1; i++)
        a->arr[index] = a->arr[index+1];
}

void display(array a) {
    printf("\n");
    for(int i = 0; i < a.size; i++) {
        if(a.arr[i])
            printf("%d\t", a.arr[i]);
        else
            printf("X\t");
    }
    printf("\n");
}

void max_min(array a) {
    int max = a.arr[0], min = a.arr[0];
    for(int i = 0; i < a.size; i++) {
        if(a.arr[i] > max)
            max = a.arr[i];
        if(a.arr[i] < min)
            min = a.arr[i];
    }
    printf("\nminimum: %d, maximum: %d\n", min, max);
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void reverse(array *a) {
    for(int i = 0; i < a->size / 2; i++){
        swap(a->arr, i, a->size-i-1);
    }
}

array *merge(array a1, array a2) {
    array* a3;
    a3 = (array *) malloc(sizeof(array));
    a3->size = a1.size + a2.size;
    a3->arr = (int *)malloc(sizeof(int) * a3->size);
    int i;
    for(i = 0; i < a1.size; i++) {
        a3->arr[i] = a1.arr[i];
    }
    for(i = a1.size; i <= a3->size; i++){
        a3->arr[i] = a2.arr[i-a1.size];
    }
    a3->len = 0;
    return a3;
}

void populate(array *a, int size){
    for (int i = 0; i < size; i++)
        a->arr[i] = rand() % 100;
    a->size = size;
}

int main() {
    /*
    array a1;
    init(&a1, 9);
    append(&a1, 5);
    append(&a1, 8);
    insert_at_index(&a1, 4, 90);
    insert_at_index(&a1, 5, 97);
    insert_at_index(&a1, 6, 87);
    // remove_at_index(&a1, 5);
    reverse(&a1);
    max_min(a1);
    display(a1);
    */
    array a1, a2;
    init(&a1, 5);
    init(&a2, 5);
    populate(&a1, 5);
    display(a1);
    populate(&a2, 5);
    display(a2);
    array *a3 = merge(a1, a2);
    display(*a3);
    return 0;
}