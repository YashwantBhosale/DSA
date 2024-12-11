#include <stdio.h>
#define ARRAY_SIZE 20

void read_array(int *arr, int len) {
    printf("Enter array: ");
    for(int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    return;
}

void print_results(int *arr, int len) {
    int positive=0, negative=0, odd=0, even=0, zeros=0;

    for(int i = 0; i < len; i++) {
        if(arr[i]>0){
            positive++;
        }
        if(arr[i]<0){
            negative++;
        }
        if(arr[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
        if(arr[i] == 0){
            zeros++;
        }
    }
    printf("Number of positive numbers: %d\n", positive);
    printf("Number of negative number: %d\n", negative);
    printf("Number of odd numbers: %d\n", odd);
    printf("Number of even integers: %d\n", even);
    printf("Number of zeros: %d\n", zeros);
    return;
}

int main() {
    int arr[ARRAY_SIZE];
    read_array(arr, ARRAY_SIZE);
    print_results(arr, ARRAY_SIZE);
    return 0;
}