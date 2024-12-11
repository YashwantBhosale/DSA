// Hash table functions
#include <stdio.h>
#include <stdlib.h>

/*
    EXPERIMENT:
    Implement a simple hash function using the division method.
    Write a small program that hashes integers using your function, then observe
    how data is distributed across an array of a fixed size.
*/

typedef struct {
    int key;
    int value;
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
int multiplication_hash(int key, int size);
int division_hash(int key, int size);
