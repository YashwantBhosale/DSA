#include <stdio.h>
#include "array.h"

void quick_sort(int *arr, int left, int right) {
    /* Partitioning */
    if(left >= right) {
        return;
    }
    int key = arr[left];
    int i = left+1, j = right;
    while(i < j) {
        while(arr[i]<=key && i < j)
            i++;
        while(arr[j]>key && i < j)
            j--;
        if(arr[j] <= key && arr[i] > key)
            swap(arr, i, j);
    }
    if(key > arr[j])
        swap(arr, j, left);
    quick_sort(arr, left, j==i ? j-1 : j);
    quick_sort(arr, j==i ? j : j+1 , right);
    return;
}

int main() {
    int len = 8;
    int arr[len];
    populate(arr, len);
    print_array(arr, len);
    quick_sort(arr, 0, len-1);
    print_array(arr, len);
    return 0;
}