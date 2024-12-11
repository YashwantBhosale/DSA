// Write a program to print the count of even numbers between 1 - 200. Also print their sum.

#include <stdio.h>

int main() {
    int count = 0, sum = 0;

    for(int i = 1; i < 200; i++) {
        if(!(i%2)) {
            sum += i;
            count++;    
        }
    }
    printf("count: %d, sum: %d\n", count, sum);
    return 0;
}