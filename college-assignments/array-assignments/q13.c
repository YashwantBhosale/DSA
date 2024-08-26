#include <stdio.h>
#include <stdlib.h>
void print(int *arr, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return;
}

int *merge_and_sort(int arr1[], int len1, int arr2[], int len2) {
    // This function works for two arrays of variable sizes as well
    int len = len1 + len2, i = 0, j = 0, k = 0;
    int *arr3 = (int *) malloc(sizeof(int) * len);
    while (j < len1 && k < len2) {
        // insert the smaller element of the two arrays
        if (arr1[j] <= arr2[k]) {
            arr3[i++] = arr1[j++];
        } else {
            arr3[i++] = arr2[k++];
        }
    }
    // add remaining elements of the whichever array is left
    while (j < len1) {
        arr3[i++] = arr1[j++];
        if(i >= len )
            return arr3;
    }

    while (k < len2) {
        arr3[i++] = arr2[k++];
        if(i >= len )
            return arr3;
    }
    return arr3;
}

int main() {
    int arr1[] = { 45, 50, 70, 85, 90 };
    int arr2[] = { 30, 40, 60, 75, 80 };
    int *arr3 = merge_and_sort(arr1, 5, arr2, 5);
    print(arr3, 10);
    return 0;
}