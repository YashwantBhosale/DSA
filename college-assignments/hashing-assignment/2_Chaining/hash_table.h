// Hash table functions
#include <stdio.h>
#include <stdlib.h>

typedef struct Entry {
    int key;
    int value;
    struct Entry *next;
} Entry;

typedef struct {
    Entry **table;
    int size;
} HashTable;

void init_table(HashTable *ht, int size);
void insert(HashTable *ht, int key, int value);
void delete(HashTable *ht, int key);
int search(HashTable *ht, int key);
void print_table(HashTable *ht);
void free_table(HashTable *ht);
int hash(int key, int size);
