#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 100

void populate(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = (rand() % 999) + 1;
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
    int arr[ARRAY_SIZE], arr2[ARRAY_SIZE], len = 0;
    populate(arr, ARRAY_SIZE);

    for(int i = 0; i < ARRAY_SIZE; i++) {
        if(!(arr[i] % 8) || !(arr[i] % 15))
            arr2[len++] = arr[i];
    }
    print(arr, ARRAY_SIZE);
    printf("No.s divisible by 8 or 15: \n");
    print(arr2, len);
    return 0;
}