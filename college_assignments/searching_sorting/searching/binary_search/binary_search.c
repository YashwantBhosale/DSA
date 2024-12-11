/*
    BINARY SEARCH ALGORITHM

    If the array is sorted:
    Time Complexity: O(log n)
    Space Complexity: O(1)

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helper_functions.h"

// Function to compare two integers for qsort
int compare_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binary_search(int *array, int size, int key) {
    if (size <= 0) return -1;
    
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == key) {
            return mid; // Key found
        } else if (array[mid] < key) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Key not found
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


int array[] = {
    34,74,15,55,40,36,84,11,83,18,100,27,75,8,85,66,70,64,12,58,96,43,93,68,72,81,90,62,31,65,59,89,48,3,24,52,50,13,57,33,76,26,87,79,29,23,60,78,37,99,25,95,98,86,1,4,30,53,56,71,77,73,51,54,6,44,21,42,92,19,17,14,39,9,41,69,5,28,22,20,16,97,2,7,91,38,80,88,45,46,61,32,67,82,94,47,49,63,35,10
};


int main() {
    int len = sizeof(array) / sizeof(array[0]);
    int key = 100;

    qsort(array, len, sizeof(int), compare_int);

    clock_t start, end;
    
    start = clock();
    int index = binary_search(array, len, key);
    end = clock();

    double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

    if (index != -1) {
        printf("Element found at index %d\n", index);
        printf("Time taken to search = %.5lfms\n", time_taken);
    } else {
        printf("Element not found\n");
    }
    return 0;
}