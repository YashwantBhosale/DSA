#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void populate(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        int n = rand() % 51 + 50;
        arr[i] = n;
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
    return  0;
}