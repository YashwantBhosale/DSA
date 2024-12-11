#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void init(array *a, int size) {
    a -> size = size;
    a -> len = 0;
    a -> arr = (int *) malloc(sizeof(int) * size);
    if(!(a -> arr))
        printf("Error: Memory allocation failed!\n");
    return;
}   

void append(array *a, int element) {
    if(!a) {
        printf("invalid array\n");
    }
    if(a->len >= a->size) {
        return;
    }
    (a->arr)[a->len] = element;
    (a->len)++;
    return;
}

void insert_at_index(array *a, int index , int element) {
    if(index>=a->size-1)
        return;
    int i;
    for(i = a->size-2; i > index; i--)
        a->arr[i+1] = a->arr[i];
    a -> arr[i] = element;
    return;
}

void remove_at_index(array *a, int index) {
    if(index>=a->size-1 || index < 0)
        return;
    for(int i = index; i < a->size-1; i++)
        a->arr[index] = a->arr[index+1];
    return;
}

void display(array a) {
    printf("[\t");
    for(int i = 0; i < a.size; i++){
        if(a.arr[i])
            printf("%d,\t", a.arr[i]);
        else
            printf("X,\t");
    }
    printf("]\n");
    return;
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
    return;
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}
void reverse(array *a) {
    for(int i = 0; i < a->size / 2; i++){
        swap(a->arr, i, a->size-i-1);
    }
    return;
}

array *merge(array a1, array a2) {
    array* a3;
    a3 = (array *) malloc(sizeof(array));
    if(!a3){
        printf("Memory was not allocated! Please try again!\n");
        return NULL;
    }
    a3->size = a1.size + a2.size;
    a3->arr = (int *)malloc(sizeof(int) * a3->size);
    int i;
    for(i = 0; i < a1.size; i++) {
        a3->arr[i] = a1.arr[i];
    }
    for(i = a1.size; i < a3->size; i++){
        a3->arr[i] = a2.arr[i-a1.size];
    }
    a3->len = 0;
    return a3;
}

void populate(array *a, int size){
    for (int i = 0; i < size; i++)
        a->arr[i] = rand() % 100;
    a->size = size;
    return;
}