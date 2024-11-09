/*
    LINEAR SEARCH ALGORITHM

    Time Complexity: O(n)
    Space Complexity: O(1)
*/ 

#include <stdio.h> 
#include <stdlib.h>
#include "helper_functions.h"

int linear_search(int *array, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *array = (int *)malloc(size * sizeof(int));
    printf("Enter the elements of the array: ");
    read_array(array, size);
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int index = linear_search(array, size, key);
    if (index == -1) {
        printf("Key not found in the array\n");
    } else {
        printf("Key found at index %d\n", index);
    }
    free(array);
    return 0;
}