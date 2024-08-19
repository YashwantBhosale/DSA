#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10
void populate(float *arr, int len) {
    for(int i = 0; i < len; i++) {
        float n = ((float) (rand()%100) * i) / ((float) ((rand() % 50)));
        arr[i] = n;
    }
    return;
}

void print_array(float *arr, int len) {
    for(int i = 0; i < len; i ++) {
        printf("%f\t", arr[i]);
    }
    printf("\n");
    return;
}

int search(float *arr, int len, float element) {
    for(int i = 0; i < len; i++) {
        if(arr[i] == element)
            return i;
    }
    return -1;
}

int main() {
    float arr[ARRAY_SIZE], n;
    int result;
    populate(arr, ARRAY_SIZE);
    printf("Enter number to search: ");
    scanf("%f", &n);
    result = search(arr, ARRAY_SIZE, n);
    if(result == -1) {
        printf("Not found!\n");    
    }
    else{
        printf("Element found! index = %d\n", result);
        print_array(arr, ARRAY_SIZE); 
    }
    return 0; 
}
