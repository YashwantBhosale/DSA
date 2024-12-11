#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void init(array *a, int size) {
    a -> arr = (int *) malloc(sizeof(int) * size);
    if(!(a -> arr))
        printf("error in memory allocation!\n");
    printf("setting arr: %p\n", a->arr);
    a -> size = size;
    a -> len = 0;
}

void append(array *a, int element) {
    if(!a) {
        printf("Invalid array");
        return;
    }
    printf("arr: %p\n", a->arr);
    printf("size in append funcion: %d\n", a->size);
    if((a -> len) > (a -> size))
        return;
    if(!(a->arr)){
        printf("array not defined!\n");
        return;
    }
    (a -> arr)[(a -> len)] = element;
    (a -> len)++;
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
    if(a.size <= 0)
        return;
    printf("array size: %d\n", a.size);
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