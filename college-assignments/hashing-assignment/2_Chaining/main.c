#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

int main() {
    HashTable ht;
    init_table(&ht, 11);

    // test 1: simple sequential insertions
    for(int i = 1; i <= 10; i++) {
        insert(&ht, i, i*10);
    }
    print_table(&ht);

    // test 2: search for a key
    int key = 5;
    printf("Searching for key %d\n", key);
    int value = search(&ht, key);
    printf("Value for key %d: %d\n", key, value);

    // test 3: delete a key
    key = 5;
    printf("Deleting key %d\n", key);
    delete(&ht, key);
    print_table(&ht);

    // test 4: search for a key that was deleted
    key = 5;
    printf("Searching for key %d\n", key);
    value = search(&ht, key);
    printf("Value for key %d: %d\n", key, value);

    return 0;
}