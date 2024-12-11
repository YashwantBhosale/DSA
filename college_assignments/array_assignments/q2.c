#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10
void display_in_reverse(int *arr, int len) {
    for(int j = len-1; j >= 0; j--) {
        printf("%d\t", arr[j]);
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

int main() {
    int arr[ARRAY_SIZE];
    read_array(arr, ARRAY_SIZE);
    display_in_reverse(arr, ARRAY_SIZE);
    return 0;
}
