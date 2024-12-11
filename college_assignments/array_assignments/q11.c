#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 5
void print(int *arr, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return;
}

void read_array(int *arr, int len) {
    int read_len = 0;
    printf("Enter array (%d Numbers): ", ARRAY_SIZE);
    for(int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
        read_len++;
    }
    return;
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

void reverse(int *arr, int len) {
    for(int i = 0; i < len/2; i++ ){
        swap(arr, i, len-i-1);
    }
    return;
}

int main() {
    int arr[ARRAY_SIZE];
    read_array(arr, ARRAY_SIZE);
    reverse(arr, ARRAY_SIZE);
    print(arr, ARRAY_SIZE);
    return 0;
}
