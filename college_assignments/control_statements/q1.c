// Write a program to read 10 integers. Display these numbers by printing 3 numbers in a line seperated by commas
#include <stdio.h>

int main() {
    int arr[10];
    for(int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    for(int j = 0; j < 10; j++) {
        printf("%d", arr[j]);
        if(!((j+1)%3)) printf(",\n");
        else printf(", ");
    }
    printf("\n");
    return 0;
}