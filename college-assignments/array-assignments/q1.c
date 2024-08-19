#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10

int sum_squares(int *arr, int len) {
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += arr[i] * arr[i];
    }
    return sum;
}

void populate(int *arr, int len) {
   for(int i = 0; i < len; i++) {
        arr[i] = rand()%100;
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
    int arr[ARRAY_SIZE];
    populate(arr, ARRAY_SIZE);
    print(arr, ARRAY_SIZE);
    printf("Sum of squares= %d\n", sum_squares(arr, ARRAY_SIZE)); 
    return 0;
}
