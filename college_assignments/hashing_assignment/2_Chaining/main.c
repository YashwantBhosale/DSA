#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

void calculate(HashTable *ht, double *avg_chain_length, int *max_chain_length);

int main() {
    int table_size = 150;
    int num_elements =100;

    for (int test = 1; test <= 5; test++) {
        HashTable ht;
        init_table(&ht, table_size);

        for (int i = 0; i < num_elements; i++) {
            int key = rand() % 1000; 
            int value = rand() % 1000;
            insert(&ht, key, value);
        }

        double avg_chain_length;
        int max_chain_length;
        calculate(&ht, &avg_chain_length, &max_chain_length);

        // Print result
        printf("Test %d:\n", test);
        printf("Table Size: %d\n", table_size);
        printf("Number of Elements: %d\n", num_elements);
        printf("Average Chain Length: %.2f\n", avg_chain_length);
        printf("Maximum Chain Length: %d\n\n", max_chain_length);
    }

    return 0;
}

void calculate(HashTable *ht, double *avg_chain_length, int *max_chain_length) {
    int total_chains = 0;
    int total_elements = 0;
    *max_chain_length = 0;

    for (int i = 0; i < ht->size; i++) {
        int chain_length = 0;
        Entry *current = ht->table[i];
        while (current) {
            chain_length++;
            current = current->next;
        }
        if (chain_length > *max_chain_length) {
            *max_chain_length = chain_length;
        }
        if (chain_length > 0) {
            total_chains++;
        }
        total_elements += chain_length;
    }

    *avg_chain_length = total_chains ? total_elements / (double)total_chains : 0.0;
}
