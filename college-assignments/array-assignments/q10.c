// Write a program to check if elements of an array are same or not it read from front or
// back.

#include <stdio.h>

int check_palindrome(int arr[], int len){
    for(int i = 0; i < len / 2 ; i++) {
        if(arr[i] != arr[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int arr[] = {2, 3, 15, 15, 3, 2};
    if(check_palindrome(arr, 6)) {
        printf("Array is palindrome!\n");
    }else {
        printf("Array is not Palindrome!");
    }
    return 0;
}