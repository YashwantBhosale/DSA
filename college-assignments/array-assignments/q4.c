#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 5

void populate(int *arr, int len) {
   for(int i = 0; i < len; i++) {
        arr[i] = rand()%100;
    } 
    return;
}

void print_triangular(int *arr, int len) {
    printf("%d\n", arr[0]);
    for (int i = 0; i < len-1; i++) {
        for(int j = 0; j <= i+1; j++){
            printf("%d\t", arr[j]);
        }
        printf("\n");
    }
    return;
}

int main() {
    int arr[ARRAY_SIZE];
    populate(arr, ARRAY_SIZE);
    print_triangular(arr, ARRAY_SIZE);
    return 0;
}