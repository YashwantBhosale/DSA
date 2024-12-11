// hash table: linear probing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hash_table.h"

void init_table(HashTable *ht, int size) {
	ht->table = (Entry **)calloc(size, sizeof(Entry *));
	ht->size = size;
	ht->count = 0;
	return;
}

/*
unsigned hash (int key) {
    unsigned hash = 0;
    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        hash = (hash << 8) | (rand() & 0xFF);
    }

    return hash;
}
*/

unsigned hash(int key, int size) {
	return key % size;
}

void insert(HashTable *ht, int key, int value) {
	unsigned hash_t = hash(key, ht->size);
	int index = hash_t;
	unsigned probes = 0;

	while (ht->table[index] != NULL) {
		index = (index + 1) % ht->size;
		probes++;
	}

	ht->table[index] = (Entry *)malloc(sizeof(Entry));
	ht->table[index]->key = key;
	ht->table[index]->value = value;
	ht->count++;

    ht->total_probes += probes;

	return;
}

void delete(HashTable *ht, int key) {
	unsigned index = hash(key, ht->size);

	while (ht->table[index] != NULL) {
		if (ht->table[index]->key == key) {
			free(ht->table[index]);
			ht->table[index] = NULL;
			ht->count--;
			return;
		}
		index = (index + 1) % ht->size;
	}

	return;
}

int search(HashTable *ht, int key) {
	unsigned index = hash(key, ht->size);

	while (ht->table[index] != NULL) {
		if (ht->table[index]->key == key) {
			return ht->table[index]->value;
		}
		index = (index + 1) % ht->size;
	}
	return -1;
}

void print_table(HashTable *ht) {
	for (int i = 0; i < ht->size; i++) {
		if (ht->table[i] != NULL) {
			printf("Index: %d, Key: %d, Value: %d\n", i, ht->table[i]->key, ht->table[i]->value);
		}
	}
	return;
}

void insert_quadratic_probing(HashTable *ht, int key, int value) {
	if (ht->count == ht->size) {
		return;
	}

	unsigned hash_t = hash(key, ht->size);
	int index = hash_t;
	unsigned probes = 0;

	for (int i = 0; ht->table[index] != NULL && ht->table[index]->key != key; i++) {
		index = (hash_t + i * i) % ht->size;
		probes++;

		if (probes >= ht->size) {
			return;
		}
	}

	Entry *new_entry = (Entry *)malloc(sizeof(Entry));
	if (new_entry == NULL) {
		return;
	}

	new_entry->key = key;
	new_entry->value = value;
	ht->table[index] = new_entry;
	ht->count++;

    ht->total_probes += probes;

}
