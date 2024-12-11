#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hash_table.h"

#define TABLE_SIZE 100
#define NUM_TESTS 1000


void test_hash_functions() {
    int data_mul[TABLE_SIZE] = {0};
    int data_div[TABLE_SIZE] = {0};
    int unique_slots = 0;
    int max_collisions_div = 0;
    int max_collisions_mul = 0;

    for (int i = 0; i < NUM_TESTS; i++) {
        int key = rand() % 10000;
        int index_div = division_hash(key, TABLE_SIZE);
        int index_mul = multiplication_hash(key, TABLE_SIZE);
        data_div[index_div]++;
        data_mul[index_mul]++;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (data_div[i] > 0) unique_slots++;
        if (data_div[i] > max_collisions_div) max_collisions_div = data_div[i];
        if (data_mul[i] > max_collisions_mul) max_collisions_mul = data_mul[i];
    }

    printf("Division Hash Function\n");
    printf("Unique Slots Filled: %d/%d (%.2f%%)\n", unique_slots, TABLE_SIZE, (float)unique_slots/TABLE_SIZE * 100);
    printf("Maximum Collisions in a Slot: %d\n", max_collisions_div);

    printf("\nMultiplication Hash Function\n");
    printf("Unique Slots Filled: %d/%d (%.2f%%)\n", unique_slots, TABLE_SIZE, (float)unique_slots/TABLE_SIZE * 100);
    printf("Maximum Collisions in a Slot: %d\n", max_collisions_mul);

    return;    
}

int main() {
    srand(time(NULL));
    
    test_hash_functions();
    return 0;
}