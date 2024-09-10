/* Bubble sort in c */
#include <stdio.h>
#include "array.h"

void bubble_sort(int *arr, int len) {
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len-i-1; j++)
            if(arr[j] > arr[j+1])
                swap(arr, j, j+1);
    }
    return;
}

int main() {
    int len = 8;
    int arr[len];
    populate(arr, len);
    print_array(arr, len);
    bubble_sort(arr, len);
    print_array(arr, len);
    return 0;
}