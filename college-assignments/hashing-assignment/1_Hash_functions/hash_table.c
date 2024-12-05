#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

int division_hash(int key, int size) {
    return key % size;
}

int multiplication_hash(int key, int size) {
    double A = 0.6180339887;
    double frac = key * A - (int)(key * A);
    return (int)(size * frac);
}

void init_table(HashTable *ht, int size) {
    ht->size = size;
    ht->table = (Entry **)calloc(size, sizeof(Entry *));

    return;
}

void insert(HashTable *ht, int key, int value) {
    int index = division_hash(key, ht->size);

    Entry *new_entry = (Entry *)malloc(sizeof(Entry));
    new_entry->key = key;
    new_entry->value = value;

    if(ht->table[index] != NULL) {
        printf("Collision detected at index %d\n", index);
        free(ht->table[index]);
    }

    ht->table[index] = new_entry;

    return;
}

void delete(HashTable *ht, int key) {
    int index = division_hash(key, ht->size);

    free(ht->table[index]);
    ht->table[index] = NULL;

    return;
}

int search(HashTable *ht, int key) {
    int index = division_hash(key, ht->size);

    if (ht->table[index] == NULL) {
        return -1;
    }

    return ht->table[index]->value;
}

void print_table(HashTable *ht) {
    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i] != NULL) {
            printf("{ Key: %d, Value: %d }\n", ht->table[i]->key, ht->table[i]->value);
        }else {
            printf("{ ___ }\n");
        }
    }
    return;
}