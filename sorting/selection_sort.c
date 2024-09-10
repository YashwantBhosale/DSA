/* Selection sort in c */
#include <stdio.h>
#include "array.h"

void selection_sort(int *arr, int len) {
    for(int i = 0; i < len-1; i++) {
        int min = arr[i], min_index = i;
        for(int j = i+1; j < len; j++) {
            if(arr[j] < min){
                min = arr[j];
                min_index = j;
            }
        }
        swap(arr, i, min_index);
    }
    return;
}

int main() {
    int len = 8;
    int arr[len];
    populate(arr, len);
    print_array(arr, len);
    selection_sort(arr, len);
    print_array(arr, len);
    return 0;
}