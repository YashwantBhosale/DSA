#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

void print_array(int *arr, int len) {
    printf("[\t");
    for(int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("]\n");
    return;
}

void populate(int *arr, int len) {
    for(int i = 0; i < len; i++) {
        arr[i] = (unsigned int)(rand() * 2319 + 37) % 100;
    }   
    return;
}