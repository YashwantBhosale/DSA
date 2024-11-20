#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "helper_functions.h"

int main() {
    int arr[] = {37, 47, 7, 5, 29, 43, 25, 49, 12, 35, 6, 23, 31, 27, 45, 33, 41, 11, 13, 39};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, n);

    heap_sort(arr, n);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}