#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10
void shift_by_n(int *arr, int len, int n) {
    int arr2[len];
    for(int i = 0; i < len; i++){
        arr2[(i+n)%len] = arr[i];
    }
    for(int i = 0; i < len; i++){
        arr[i] = arr2[i];
    }
    return;
}

void read_array(int *arr, int len) {
    printf("Enter array: ");
    for(int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    return;
}

void print(int *arr, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return;
}

int main() {
    int arr[ARRAY_SIZE], n;
    read_array(arr, ARRAY_SIZE);
    printf("Shift by : ");
    scanf("%d", &n);
    shift_by_n(arr, ARRAY_SIZE, n);
    print(arr, ARRAY_SIZE);
    return 0;
}