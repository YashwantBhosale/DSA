/* Insertion sort in c */
#include <stdio.h>

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

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

void print_array(int *arr, int len) {
    printf("[\t");
    for(int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("]\n");
    return;
}

int main() {
    int arr[] = {9, 5, 2, 1, 3,  4, 6};
    insertion_sort(arr, 7);
    // insertion_sort_v2(arr, 7);
    print_array(arr, 7);
    return 0;
}