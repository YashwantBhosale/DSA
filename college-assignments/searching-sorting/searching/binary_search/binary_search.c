/*
    BINARY SEARCH ALGORITHM

    If the array is sorted:
    Time Complexity: O(log n)
    Space Complexity: O(1)

*/

#include <stdio.h>
#include <stdlib.h>
#include "helper_functions.h"

int binary_search(int *array, int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (array[mid] == key) {
            return mid;
        } else if (array[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// recursive binary search
int binary_search_v2(int *array, int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == key) {
            return mid;
        } else if (array[mid] < key) {
            return binary_search_v2(array, mid + 1, right, key);
        } else {
            return binary_search_v2(array, left, mid - 1, key);
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
    int index = binary_search(array, size, key);
    if (index == -1) {
        printf("Key not found in the array\n");
    } else {
        printf("Key found at index %d\n", index);
    }
    free(array);
    return 0;
}