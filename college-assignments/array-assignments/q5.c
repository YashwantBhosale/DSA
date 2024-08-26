// You know size of integer array. Can you find number of elements in it? How?
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10

int get_size(int arr[], int size) {
    return (size / sizeof(int));
}

int main() {
    int arr[ARRAY_SIZE];
    printf("No. of elements = %d\n", get_size(arr, sizeof(arr)));
    return 0;
}