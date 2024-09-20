#include <stdlib.h>
#include "array.h"
#include <stdio.h>

void init(array *a, int size) {
    a -> arr = (int *) malloc(sizeof(int) * size);
    a -> size = size;
    a -> len = 0;
    return;
}

void append(array *a, int data) {
   if(a->len >= a->size)
       return;
   a -> arr[a->len++] = data;
   return;
}

void insert_at_beg(array *a, int data) {
    for (int i = a->size-1; i>0; i--) {
        a->arr[i] = a->arr[i-1]; 
    }
    a->arr[0] = data;
    return;
}

void remove_beg(array *a) {
    int len = a->size;
    for(int i = 0; i < len-1; i++) {
        a->arr[i] = a -> arr[i+1];
    }
    return;
}

void remove_at_index(array *a, int index) {
    if(index >= a->size)
        return;
    int len = a->size;
    for(int i = index; i < len-1; i++) {
        a->arr[i] = a->arr[i+1];
    }
    return;
}

void display(array a) {
    printf("[\t");
    for(int i = 0; i < a.size; i++){
        printf("%d\t", a.arr[i]);
    }
    printf("]\n");
    return;
}


