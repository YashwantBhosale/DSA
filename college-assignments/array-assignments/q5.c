// You know size of integer array. Can you find number of elements in it? How?
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10

void populate(int *arr, int len) {
   for(int i = 0; i < len; i++) {
        arr[i] = rand()%100;
    } 
    return;
}


int get_size(int arr[], int size) {
    return (size / sizeof(int));
}

int main() {
    int arr[ARRAY_SIZE];
    populate(arr, 5);
    printf("No. of elements = %d\n", get_size(arr, 5*sizeof(int)));
    return 0;
}