/* Insertion sort in c */
#include <stdio.h>
#include "array.h"
// Sorted part of the array at the starting part of the array
void insertion_sort(int *arr, int len) {
    for(int i = 0; i < len-1; i++) {
        int j = i+1;
        while(j > 0) {
            if(arr[j] < arr[j-1])
                swap(arr, j, j-1);
            j--;
        }
    }
    return;
}

// Sorted part of the array at the end
void insertion_sort_v2(int *arr, int len) {
    for(int i = len-1; i > 0; i--) {
        int j = i-1;
        while(j < len-1) {
            if(arr[j] > arr[j+1])
                swap(arr, j, j+1);
            j++;
        }
    }
    return;
}

int main() {
    int arr[8], len;
    len = 8;
    populate(arr, len);
    print_array(arr, len);   
    insertion_sort(arr, len);
    // insertion_sort_v2(arr, 7);
    print_array(arr, len);
    return 0;
}