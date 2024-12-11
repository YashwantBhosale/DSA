#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

int hash(int key, int size) {
    return key % size;
}

void init_table(HashTable *ht, int size) {
    ht->size = size;
    ht->table = (Entry **)calloc(size, sizeof(Entry *));

    return;
}

void insert(HashTable *ht, int key, int value) {
    int index = hash(key, ht->size);

    Entry *new_entry = (Entry *)malloc(sizeof(Entry));
    new_entry->key = key;
    new_entry->value = value;
    new_entry->next = NULL;

    if(ht->table[index] == NULL) {
        ht->table[index] = new_entry;
    }else {
        Entry *cursor = ht->table[index];
        while(cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = new_entry;
    }

    return;
}

void delete(HashTable *ht, int key) {
    int index = hash(key, ht->size);

    free(ht->table[index]);
    ht->table[index] = NULL;

    return;
}

int search(HashTable *ht, int key) {
    int index = hash(key, ht->size);
    int value = ht->table[index]->value;

    if (ht->table[index] == NULL) {
        return -1;
    }else {
        Entry *cursor = ht->table[index];
        while(cursor->next && cursor->key != key) {
            cursor = cursor->next;
        }
        value = cursor->value;
    }

    return value;
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