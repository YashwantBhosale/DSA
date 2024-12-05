#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"


void init_table(HashTable *ht, int size) {
    ht->table = (Entry **)malloc(size * sizeof(Entry *));
    ht->count = 0;
    ht->size = size;
    ht->total_probes = 0;
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
}

unsigned hash(int key, int size) {
    return key % size;
}

unsigned hash_2(int key, int size) {
    return 1 + (key % (size - 1));
}

void insert(HashTable *ht, int key, int value) {
    unsigned h = hash(key, ht->size);
    unsigned h2 = hash_2(key, ht->size);
    unsigned i = 0;
    
    while (i < ht->size) {
        unsigned index = (h + i * h2) % ht->size; // use secondary hash function for probing
        if (ht->table[index] == NULL) {
            Entry *entry = (Entry *)malloc(sizeof(Entry));
            entry->key = key;
            entry->value = value;
            entry->hash = index;
            ht->table[index] = entry;
            ht->count++;

            return;
        }
        ht->total_probes++;
        i++;
    }
}