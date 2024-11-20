/*
    LINEAR SEARCH ALGORITHM

    Time Complexity: O(n)
    Space Complexity: O(1)
*/ 

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "helper_functions.h"

int linear_search(int *array, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}

/*
int array[] = {
    34,74,15,55,40,36,84,11,83,18,100,27,75,8,85,66,70,64,12,58,96,43,93,68,72,81,90,62,31,65,59,89,48,3,24,52,50,13,57,33,76,26,87,79,29,23,60,78,37,99,25,95,98,86,1,4,30,53,56,71,77,73,51,54,6,44,21,42,92,19,17,14,39,9,41,69,5,28,22,20,16,97,2,7,91,38,80,88,45,46,61,32,67,82,94,47,49,63,35,10
};
*/

int array[] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
    61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
    71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
    81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
    91, 92, 93, 94, 95, 96, 97, 98, 99, 100
};


int main() {
    int len = sizeof(array) / sizeof(array[0]);
    int key = 88;

    clock_t start, end;

    start = clock();
    int index = linear_search(array, len, key);
    end = clock();

    double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

    if (index != -1) {
        printf("Element found at index %d\n", index);
        printf("Time taken to search = %.5lfms\n", time_taken);
    } else {
        printf("Element not found\n");
    }

    return 0;
}