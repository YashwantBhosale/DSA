#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hash_table.h" // Include your hash table header file

#define NUM_KEYS 100

void generate_random_data(int keys[], int values[], int num_keys) {
    for (int i = 0; i < num_keys; i++) {
        keys[i] = rand() % 1000;  
        values[i] = rand() % 100; 
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    int keys[NUM_KEYS];
    int values[NUM_KEYS];
    generate_random_data(keys, values, NUM_KEYS);

    HashTable ht;
    init_table(&ht, 200);

    for (int i = 0; i < NUM_KEYS; i++) {
        insert(&ht, keys[i], values[i]);
    }

    printf("Double Hashing Results:\n");
    printf("Table Size: %d\n", ht.size);
    printf("Number of Keys: %d\n", ht.count);
    printf("Average Probes per Insertion: %.2f\n",(double)ht.total_probes / (double)ht.count);
    printf("\n");

    return 0;
}
