#include "array.h"
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void init(array *a, int size);
void append(array *a, int data);
void insert_at_beg(array *a, int data);
void remove_beg(array *a);
void remove_at_index(array *a, int index);
void display(array a);

int main() {
    // Create an array of size 5
    array a;
    init(&a, 5);

    // Test appending elements
    append(&a, 10);
    append(&a, 20);
    append(&a, 30);
    append(&a, 40);
    append(&a, 50);
    printf("Array after appending elements: ");
    display(a); // Expected output: [ 10  20  30  40  50 ]

    // Test inserting at the beginning
    insert_at_beg(&a, 5);
    printf("Array after inserting 5 at the beginning: ");
    display(a); // Expected output: [ 5  10  20  30  40 ]

    // Test removing from the beginning
    remove_beg(&a);
    printf("Array after removing from the beginning: ");
    display(a); // Expected output: [ 10  20  30  40  40 ]

    // Test removing at a specific index
    remove_at_index(&a, 2);
    printf("Array after removing element at index 2: ");
    display(a); // Expected output: [ 10  20  40  40 ]

    // Test appending more elements after removal
    append(&a, 60);
    printf("Array after appending 60: ");
    display(a); // Expected output: [ 10  20  40  40  60 ]

    // Free the allocated memory
    free(a.arr);

    return 0;
}

