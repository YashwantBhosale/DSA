#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hash_table.h"
/*
int main() {
    HashTable ht;
    init_table(&ht, 100);

    printf("============LINEAR PROBING============\n");
    insert(&ht, 15, 0);
    insert(&ht, 23, 1);
    insert(&ht, 37, 2);
    insert(&ht, 42, 3);
    insert(&ht, 56, 4);
    insert(&ht, 68, 5);
    insert(&ht, 79, 6);
    insert(&ht, 81, 7);
    insert(&ht, 92, 8);
    insert(&ht, 99, 9);

    printf("============QUADRATIC PROBING============\n");

    HashTable ht2;
    init_table(&ht2, 100);

    insert_quadratic_probing(&ht2, 15, 0);
    insert_quadratic_probing(&ht2, 23, 1);
    insert_quadratic_probing(&ht2, 37, 2);
    insert_quadratic_probing(&ht2, 42, 3);
    insert_quadratic_probing(&ht2, 56, 4);
    insert_quadratic_probing(&ht2, 68, 5);
    insert_quadratic_probing(&ht2, 79, 6);
    insert_quadratic_probing(&ht2, 81, 7);
    insert_quadratic_probing(&ht2, 92, 8);
    insert_quadratic_probing(&ht2, 99, 9);
    
    // print_table(&ht);
    return 0;
}
*/

/*
int main() {
    HashTable ht1, ht2;
    init_table(&ht1, 10); // Table size is 10
    init_table(&ht2, 10);

    printf("============LINEAR PROBING============\n");
    insert(&ht1, 15, 1);
    insert(&ht1, 25, 2);
    insert(&ht1, 35, 3);
    insert(&ht1, 45, 4);
    insert(&ht1, 55, 5);

    printf("============QUADRATIC PROBING============\n");
    insert_quadratic_probing(&ht2, 15, 1);
    insert_quadratic_probing(&ht2, 25, 2);
    insert_quadratic_probing(&ht2, 35, 3);
    insert_quadratic_probing(&ht2, 45, 4);
    insert_quadratic_probing(&ht2, 55, 5);

    printf("\nLinear Probing Table:\n");
    print_table(&ht1);
    printf("\nQuadratic Probing Table:\n");
    print_table(&ht2);

    return 0;
}
*/

/*
int main() {
    HashTable ht1, ht2;
    init_table(&ht1, 1000); // Large table with size 1000
    init_table(&ht2, 1000);

    printf("============LINEAR PROBING============\n");
    int keys[] = {105, 205, 305, 1005, 2005, 3005, 4005, 5005, 6005, 7005};
    for (int i = 0; i < 10; i++) {
        insert(&ht1, keys[i], i);
    }

    printf("============QUADRATIC PROBING============\n");
    for (int i = 0; i < 10; i++) {
        insert_quadratic_probing(&ht2, keys[i], i);
    }

    printf("\nLinear Probing Table:\n");
    print_table(&ht1);
    printf("\nQuadratic Probing Table:\n");
    print_table(&ht2);

    return 0;
}
*/

#define NUM_TESTS 5

int main() {
    HashTable ht1, ht2;

    srand(time(NULL));
    int table_sizes[NUM_TESTS] = {1000, 5000, 10000, 20000, 25000};
    int num_elements[NUM_TESTS] = {800, 4500, 6500, 15000, 12500};

    for(int i = 0; i < NUM_TESTS; i++) {
        init_table(&ht1, table_sizes[i]);
        init_table(&ht2, table_sizes[i]);

        for (int j = 0; j < num_elements[i]; j++) {
            insert(&ht1, rand(), j);
        }

        for (int j = 0; j < num_elements[i]; j++) {
            insert_quadratic_probing(&ht2, rand(), j);
        }

        printf("Test %d\n", i + 1);
        printf("Table size: %d, Elements: %d\n", table_sizes[i], num_elements[i]);
        printf("Total probes for Linear Probing: %u\n", ht1.total_probes);
        printf("Total probes for Quadratic Probing: %u\n", ht2.total_probes);
        printf("\n");    
    }    
    return 0;
}